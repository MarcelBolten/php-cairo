/*
  +----------------------------------------------------------------------+
  | For PHP Version 8                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 2022 Swen Zanon                                        |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  | Also available in LICENSE                                            |
  +----------------------------------------------------------------------+
  | Authors: Swen Zanon <swen.zanon@geoglis.de>                          |
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
#include "text_cluster_arginfo.h"

zend_class_entry *ce_cairo_text_cluster;

static zend_object_handlers cairo_text_cluster_object_handlers;

cairo_text_cluster_object *cairo_text_cluster_fetch_object(zend_object *object)
{
    return (cairo_text_cluster_object *) ((char*)(object) - XtOffsetOf(cairo_text_cluster_object, std));
}

static inline long cairo_text_cluster_get_property_default(zend_class_entry *ce, char * name) {
    zend_property_info *property_info;
    long value = 0;
    zend_string *key = zend_string_init(name, strlen(name), 0);

    property_info = zend_get_property_info(ce, key, 1);
    if (property_info) {
        zval *val = (zval*)((char*)ce->default_properties_table + property_info->offset - OBJ_PROP_TO_OFFSET(0));
        if (val) {
            value = zval_get_long(val);
        }
    }
    zend_string_release(key);
    return value;
}

#define CAIRO_ALLOC_TEXT_CLUSTER(text_cluster_value) if (!text_cluster_value) \
    { text_cluster_value = ecalloc(1, sizeof(cairo_text_cluster_t)); }

#define CAIRO_VALUE_FROM_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        value = text_cluster_object->text_cluster->n; \
        break; \
    }

#define CAIRO_VALUE_TO_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        text_cluster_object->text_cluster->n = zval_get_long(value); \
        break; \
    }

#define CAIRO_ADD_STRUCT_VALUE(n) \
    ZVAL_LONG(&tmp, text_cluster_object->text_cluster->n); \
    zend_hash_str_update(props, #n, sizeof(#n)-1, &tmp);

/* ----------------------------------------------------------------
    \Cairo\TextCluster C API
------------------------------------------------------------------*/

/* {{{ */
cairo_text_cluster_t *cairo_text_cluster_object_get_text_cluster(zval *zv)
{
    cairo_text_cluster_object *text_cluster_object = Z_CAIRO_TEXT_CLUSTER_P(zv);

    return text_cluster_object->text_cluster;
}
/* }}} */

zend_class_entry* php_cairo_get_text_cluster_ce()
{
    return ce_cairo_text_cluster;
}

/* ----------------------------------------------------------------
    \Cairo\TextCluster Class API
------------------------------------------------------------------*/

/* {{{ proto void __construct(int num_bytes, int num_glyphs)
    Creates a new text_cluster with the properties populated */
PHP_METHOD(Cairo_TextCluster, __construct)
{
    cairo_text_cluster_object *text_cluster_object;

    /* read defaults from object */
    long num_bytes;
    long num_glyphs;

    /* Now allow constructor to overwrite them if desired */
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(num_bytes)
        Z_PARAM_LONG(num_glyphs)
    ZEND_PARSE_PARAMETERS_END();

    text_cluster_object = Z_CAIRO_TEXT_CLUSTER_P(getThis());

    text_cluster_object->text_cluster->num_bytes = num_bytes;
    text_cluster_object->text_cluster->num_glyphs = num_glyphs;
}
/* }}} */

/* ----------------------------------------------------------------
    \Cairo\TextCluster Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_text_cluster_free_obj(zend_object *zobj)
{
    cairo_text_cluster_object *intern = cairo_text_cluster_fetch_object(zobj);

    if (!intern) {
        return;
    }

    if (intern->text_cluster) {
        efree(intern->text_cluster);
        intern->text_cluster = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* cairo_text_cluster_obj_ctor(zend_class_entry *ce, cairo_text_cluster_object **intern)
{
    cairo_text_cluster_object *object = ecalloc(1, sizeof(cairo_text_cluster_object) + zend_object_properties_size(ce));
    CAIRO_ALLOC_TEXT_CLUSTER(object->text_cluster);

    zend_object_std_init(&object->std, ce);

    object->std.handlers = &cairo_text_cluster_object_handlers;
    *intern = object;

    /* We need to read in any default values and set them if applicable */
    if (ce->default_properties_count) {
        object->text_cluster->num_bytes = cairo_text_cluster_get_property_default(ce, "num_bytes");
        object->text_cluster->num_glyphs = cairo_text_cluster_get_property_default(ce, "num_glyphs");
    }

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* cairo_text_cluster_create_object(zend_class_entry *ce)
{
    cairo_text_cluster_object *intern = NULL;
    zend_object *return_value = cairo_text_cluster_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* cairo_text_cluster_clone_obj(zend_object *zobj)
{
    cairo_text_cluster_object *new_text_cluster;
    cairo_text_cluster_object *old_text_cluster = cairo_text_cluster_fetch_object(zobj);
    zend_object *return_value = cairo_text_cluster_obj_ctor(zobj->ce, &new_text_cluster);
    CAIRO_ALLOC_TEXT_CLUSTER(new_text_cluster->text_cluster);

    new_text_cluster->text_cluster->num_bytes = old_text_cluster->text_cluster->num_bytes;
    new_text_cluster->text_cluster->num_glyphs = old_text_cluster->text_cluster->num_glyphs;

    zend_objects_clone_members(&new_text_cluster->std, &old_text_cluster->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *cairo_text_cluster_object_read_property(zend_object *zobj, zend_string *member, int type, void **cache_slot, zval *rv)
{
    zval *retval;
    long value;
    cairo_text_cluster_object *text_cluster_object = cairo_text_cluster_fetch_object(zobj);

    if (!text_cluster_object) {
        return rv;
    }

    do {
        CAIRO_VALUE_FROM_STRUCT(num_bytes);
        CAIRO_VALUE_FROM_STRUCT(num_glyphs);

        // not a struct member
        retval = (zend_get_std_object_handlers())->read_property(zobj, member, type, cache_slot, rv);

        return retval;
    } while(0);

    retval = rv;
    ZVAL_LONG(retval, value);

    return retval;
}
/* }}} */

/* {{{ */
static zval *cairo_text_cluster_object_write_property(zend_object *zobj, zend_string *member, zval *value, void **cache_slot)
{
    cairo_text_cluster_object *text_cluster_object = cairo_text_cluster_fetch_object(zobj);
    zval *retval = NULL;

    if (!text_cluster_object) {
        return retval;
    }

    do {
        CAIRO_VALUE_TO_STRUCT(num_bytes);
        CAIRO_VALUE_TO_STRUCT(num_glyphs);
    } while(0);

    // not a struct member
    retval = (zend_get_std_object_handlers())->write_property(zobj, member, value, cache_slot);

    return retval;
}
/* }}} */

/* {{{ */
static HashTable *cairo_text_cluster_object_get_properties(zend_object *zobj)
{
    HashTable *props;
    // used in CAIRO_ADD_STRUCT_VALUE below
    zval tmp;
    cairo_text_cluster_object *text_cluster_object = cairo_text_cluster_fetch_object(zobj);

    props = zend_std_get_properties(zobj);

    if (!text_cluster_object->text_cluster) {
        return props;
    }

    CAIRO_ADD_STRUCT_VALUE(num_bytes);
    CAIRO_ADD_STRUCT_VALUE(num_glyphs);

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    \Cairo\TextCluster Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_text_cluster)
{
    zend_class_entry ce;

    memcpy(
        &cairo_text_cluster_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    cairo_text_cluster_object_handlers.offset = XtOffsetOf(cairo_text_cluster_object, std);
    cairo_text_cluster_object_handlers.free_obj = cairo_text_cluster_free_obj;
    cairo_text_cluster_object_handlers.clone_obj = cairo_text_cluster_clone_obj;
    cairo_text_cluster_object_handlers.read_property = cairo_text_cluster_object_read_property;
    cairo_text_cluster_object_handlers.write_property = cairo_text_cluster_object_write_property;
    cairo_text_cluster_object_handlers.get_property_ptr_ptr = NULL;
    cairo_text_cluster_object_handlers.get_properties = cairo_text_cluster_object_get_properties;

    ce_cairo_text_cluster = register_class_Cairo_TextCluster();
    ce_cairo_text_cluster->create_object = cairo_text_cluster_create_object;

    return SUCCESS;
}
/* }}} */
