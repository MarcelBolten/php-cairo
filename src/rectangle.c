/*
  +----------------------------------------------------------------------+
  | For PHP Version 8                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 2015 Elizabeth M Smith                                 |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  | Also available in LICENSE                                            |
  +----------------------------------------------------------------------+
  | Authors: Elizabeth M Smith <auroraeosrose@gmail.com>                 |
  |          Swen Zanon <swen.zanon@geoglis.de>                          |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cairo.h>
#include <php.h>
#include <zend_exceptions.h>

#include "php_cairo.h"
#include "php_cairo_internal.h"
#include "rectangle_arginfo.h"

zend_class_entry *ce_cairo_rectangle;

static zend_object_handlers cairo_rectangle_object_handlers;

cairo_rectangle_object *cairo_rectangle_fetch_object(zend_object *object)
{
    return (cairo_rectangle_object *) ((char*)(object) - XtOffsetOf(cairo_rectangle_object, std));
}

static inline double cairo_rectangle_get_property_default(zend_class_entry *ce, char * name) {
    zend_property_info *property_info;
    double value = 0;
    zend_string *key = zend_string_init(name, strlen(name), 0);

    property_info = zend_get_property_info(ce, key, 1);
    if (property_info) {
        zval *val = (zval*)((char*)ce->default_properties_table + property_info->offset - OBJ_PROP_TO_OFFSET(0));
        if (val) {
            value = zval_get_double(val);
        }
    }
    zend_string_release(key);
    return value;
}

static inline long cairo_rectangle_get_property_value(zend_object *object, char *name) {
    zval *prop, rv;

    prop = zend_read_property(object->ce, object, name, strlen(name), 1, &rv);
    return zval_get_double(prop);
}

#define CAIRO_ALLOC_RECT(rect_value) if (!rect_value) \
    { rect_value = ecalloc(1, sizeof(cairo_rectangle_t)); }

#define CAIRO_VALUE_FROM_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        value = rectangle_object->rect->n; \
        break; \
    }

#define CAIRO_VALUE_TO_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        rectangle_object->rect->n = zval_get_double(value); \
        break; \
    }

#define CAIRO_ADD_STRUCT_VALUE(n) \
    ZVAL_DOUBLE(&tmp, rectangle_object->rect->n); \
    zend_hash_str_update(props, #n, sizeof(#n)-1, &tmp);

/* ----------------------------------------------------------------
    \Cairo\Rectangle C API
------------------------------------------------------------------*/

/* {{{ */
cairo_rectangle_t *cairo_rectangle_object_get_rect(zval *zv)
{
    cairo_rectangle_object *rect_object = Z_CAIRO_RECTANGLE_P(zv);

    if (rect_object->rect == NULL) {
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Internal rectangle object missing in %s, you must call parent::__construct in extended classes.",
            ZSTR_VAL(Z_OBJCE_P(zv)->name));
        return NULL;
    }

    return rect_object->rect;
}
/* }}} */

zend_class_entry* php_cairo_get_rectangle_ce()
{
    return ce_cairo_rectangle;
}

void cairo_expand_to_rectangle_int(cairo_rectangle_t *rect_double, cairo_rectangle_int_t *rect_int) {
    if (rect_double == NULL) {
        rect_int = NULL;
        return;
    }

    // Expand rectangle to contain all fractional parts
    double x0 = rect_double->x;
    double y0 = rect_double->y;
    double x1 = rect_double->x + rect_double->width;
    double y1 = rect_double->y + rect_double->height;

    // expand outward
    rect_int->x = (int) floor(x0);
    rect_int->y = (int) floor(y0);

    // Ceiling for right/bottom, then calculate width/height
    int new_x1 = (int) ceil(x1);
    int new_y1 = (int) ceil(y1);

    rect_int->width = new_x1 - rect_int->x;
    rect_int->height = new_y1 - rect_int->y;
}

void cairo_rectangle_int_to_double(cairo_rectangle_int_t *rect_int, cairo_rectangle_t *rect_double) {
    if (rect_int == NULL) {
        rect_double = NULL;
        return;
    }

    rect_double->x = (double) rect_int->x;
    rect_double->y = (double) rect_int->y;
    rect_double->width = (double) rect_int->width;
    rect_double->height = (double) rect_int->height;
}


/* ----------------------------------------------------------------
    \Cairo\Rectangle Class API
------------------------------------------------------------------*/

/* {{{ proto void __construct([int x, int y, int width, int height])
    Creates a new rectangle with the properties populated */
PHP_METHOD(Cairo_Rectangle, __construct)
{
    cairo_rectangle_object *rectangle_object;
    zend_object *object = Z_OBJ_P(getThis());

    /* read defaults from object */
    double x = cairo_rectangle_get_property_value(object, "x");
    double y = cairo_rectangle_get_property_value(object, "y");
    double width = cairo_rectangle_get_property_value(object, "width");
    double height = cairo_rectangle_get_property_value(object, "height");

    /* Now allow constructor to overwrite them if desired */
    ZEND_PARSE_PARAMETERS_START(0, 4)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    rectangle_object = cairo_rectangle_fetch_object(object);

    rectangle_object->rect->x = (int) x;
    rectangle_object->rect->y = (int) y;
    rectangle_object->rect->width = (int) width;
    rectangle_object->rect->height = (int) height;
}
/* }}} */

/* ----------------------------------------------------------------
    \Cairo\Rectangle Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_rectangle_free_obj(zend_object *object)
{
    cairo_rectangle_object *intern = cairo_rectangle_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->rect) {
        efree(intern->rect);
        intern->rect = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* cairo_rectangle_obj_ctor(zend_class_entry *ce, cairo_rectangle_object **intern)
{
    cairo_rectangle_object *object = ecalloc(1, sizeof(cairo_rectangle_object) + zend_object_properties_size(ce));
    CAIRO_ALLOC_RECT(object->rect);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &cairo_rectangle_object_handlers;
    *intern = object;

    /* We need to read in any default values and set them if applicable */
    if (ce->default_properties_count) {
        object->rect->x = cairo_rectangle_get_property_default(ce, "x");
        object->rect->y = cairo_rectangle_get_property_default(ce, "y");
        object->rect->width = cairo_rectangle_get_property_default(ce, "width");
        object->rect->height = cairo_rectangle_get_property_default(ce, "height");
    }

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* cairo_rectangle_create_object(zend_class_entry *ce)
{
    cairo_rectangle_object *intern = NULL;
    zend_object *return_value = cairo_rectangle_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* cairo_rectangle_clone_obj(zend_object *zobj)
{
    cairo_rectangle_object *new_rectangle;
    cairo_rectangle_object *old_rectangle = cairo_rectangle_fetch_object(zobj);
    zend_object *return_value = cairo_rectangle_obj_ctor(zobj->ce, &new_rectangle);
    CAIRO_ALLOC_RECT(new_rectangle->rect);

    *new_rectangle->rect = *old_rectangle->rect;

    zend_objects_clone_members(&new_rectangle->std, &old_rectangle->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *cairo_rectangle_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    zval *retval;
    double value;
    cairo_rectangle_object *rectangle_object = cairo_rectangle_fetch_object(object);

    if (!rectangle_object) {
        return rv;
    }

    do {
        CAIRO_VALUE_FROM_STRUCT(x);
        CAIRO_VALUE_FROM_STRUCT(y);
        CAIRO_VALUE_FROM_STRUCT(width);
        CAIRO_VALUE_FROM_STRUCT(height);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->read_property(object, member, type, cache_slot, rv);

        return retval;
    } while(0);

    retval = rv;
    ZVAL_DOUBLE(retval, value);

    return retval;
}
/* }}} */

/* {{{ */
static zval *cairo_rectangle_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    cairo_rectangle_object *rectangle_object = cairo_rectangle_fetch_object(object);
        zval *retval = NULL;

    if (!rectangle_object) {
        return retval;
    }

    do {
        CAIRO_VALUE_TO_STRUCT(x);
        CAIRO_VALUE_TO_STRUCT(y);
        CAIRO_VALUE_TO_STRUCT(width);
        CAIRO_VALUE_TO_STRUCT(height);

    } while(0);

    /* not a struct member */
    retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot);

        return retval;
}
/* }}} */

/* {{{ */
static HashTable *cairo_rectangle_object_get_properties(zend_object *object)
{
    HashTable *props;
    // used in CAIRO_ADD_STRUCT_VALUE below
    zval tmp;
    cairo_rectangle_object *rectangle_object = cairo_rectangle_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!rectangle_object->rect) {
        return props;
    }

    CAIRO_ADD_STRUCT_VALUE(x);
    CAIRO_ADD_STRUCT_VALUE(y);
    CAIRO_ADD_STRUCT_VALUE(width);
    CAIRO_ADD_STRUCT_VALUE(height);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Cairo\Rectangle Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_rectangle)
{
    memcpy(
        &cairo_rectangle_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    cairo_rectangle_object_handlers.offset = XtOffsetOf(cairo_rectangle_object, std);
    cairo_rectangle_object_handlers.free_obj = cairo_rectangle_free_obj;
    cairo_rectangle_object_handlers.clone_obj = cairo_rectangle_clone_obj;
    cairo_rectangle_object_handlers.read_property = cairo_rectangle_object_read_property;
    cairo_rectangle_object_handlers.write_property = cairo_rectangle_object_write_property;
    cairo_rectangle_object_handlers.get_property_ptr_ptr = NULL;
    cairo_rectangle_object_handlers.get_properties = cairo_rectangle_object_get_properties;

    ce_cairo_rectangle = register_class_Cairo_Rectangle();
    ce_cairo_rectangle->create_object = cairo_rectangle_create_object;

    return SUCCESS;
}
/* }}} */
