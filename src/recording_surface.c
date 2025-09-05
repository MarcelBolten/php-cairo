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
#include "recording_surface_arginfo.h"

#ifdef CAIRO_HAS_RECORDING_SURFACE

zend_class_entry *ce_cairo_recordingsurface;

static double php_cairo_get_double_from_array(zval *val, const char *name)
{
    zval *tmp;

    // zend_string *key = zend_string_init_fast(name, strlen(name));
    // tmp = zend_hash_find(Z_ARR_P(val), key);
    tmp = zend_hash_str_find(Z_ARRVAL_P(val), name, strlen(name));
    if (tmp != NULL) {
        if (Z_TYPE_P(tmp) != IS_DOUBLE) {
            convert_to_double(tmp);
        }

        return Z_DVAL_P(tmp);
    }

    zend_error(E_WARNING, "Key '%s' does not exist", name);

    return 0;
}

static cairo_rectangle_t *php_cairo_make_rectangle(zval *val)
{
    cairo_rectangle_t *rectangle = ecalloc(1, sizeof(cairo_rectangle_t));

    rectangle->x = php_cairo_get_double_from_array(val, "x");
    rectangle->y = php_cairo_get_double_from_array(val, "y");
    rectangle->width = php_cairo_get_double_from_array(val, "width");
    rectangle->height = php_cairo_get_double_from_array(val, "height");
    return rectangle;
}

/* ----------------------------------------------------------------
    Cairo\Surface\Recording Class API
------------------------------------------------------------------*/

/* {{{ proto \Cairo\RecordingSurface::__construct(\Cairo\Surface\Content content, array extents)
       Returns new CairoRecordingSurface */
PHP_METHOD(Cairo_Surface_Recording, __construct)
{
    zval *content;
    cairo_surface_object *surface_object;
    cairo_rectangle_t *rectangle = NULL;
    zval *extents = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT_OF_CLASS(content, ce_cairo_content)
        Z_PARAM_OPTIONAL
        Z_PARAM_ARRAY(extents)
    ZEND_PARSE_PARAMETERS_END();

    if (extents != NULL) {
        rectangle = php_cairo_make_rectangle(extents);
    }

    surface_object = Z_CAIRO_SURFACE_P(getThis());
    if (!surface_object) {
        RETURN_NULL();
    }

    surface_object->surface = cairo_recording_surface_create(
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(content))),
        rectangle
    );

    if (rectangle != NULL) {
        efree(rectangle);
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto \Cairo\RecordingSurface::inkExtents()
       Measures the extents of the operations stored within the recording-surface.
       This is useful to compute the required size of an image surface (or equivalent)
       into which to replay the full sequence of drawing operations.
       Returns array(x, y, width, height) */
PHP_METHOD(Cairo_Surface_Recording, inkExtents)
{
    cairo_surface_object *surface_object;
    double x, y, width, height;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_recording_surface_ink_extents(surface_object->surface, &x, &y, &width, &height);
    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
    add_assoc_double(return_value, "width", width);
    add_assoc_double(return_value, "height", height);
}
/* }}} */


/* {{{ proto \Cairo\RecordingSurface::getExtents()
       Get the extents of the recording-surface.
       Returns \Cairo\Rectangle if the surface is bounded and not in an error state, otherwise FALSE */
PHP_METHOD(Cairo_Surface_Recording, getExtents)
{
    cairo_surface_object *surface_object;
    cairo_rectangle_object *rectangle_object;
    cairo_rectangle_t *rectangle;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    rectangle = ecalloc(1, sizeof(cairo_rectangle_t));

    if (cairo_recording_surface_get_extents(surface_object->surface, rectangle) == IS_FALSE) {
        efree(rectangle);
        //php_cairo_throw_exception(cairo_surface_status(surface_object->surface));
        RETURN_FALSE;
    }

    object_init_ex(return_value, ce_cairo_rectangle);
    rectangle_object = Z_CAIRO_RECTANGLE_P(return_value);
    rectangle_object->rect->x = rectangle->x;
    rectangle_object->rect->y = rectangle->y;
    rectangle_object->rect->width = rectangle->width;
    rectangle_object->rect->height = rectangle->height;
    efree(rectangle);
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\RecordingSurface Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_recording_surface)
{
    ce_cairo_recordingsurface = register_class_Cairo_Surface_Recording(ce_cairo_surface);

    return SUCCESS;
}

#endif
