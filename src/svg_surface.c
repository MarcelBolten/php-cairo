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

#if CAIRO_HAS_SVG_SURFACE
#include <cairo-svg.h>
#include "svg_surface_arginfo.h"

zend_class_entry *ce_cairo_svgsurface;
zend_class_entry *ce_cairo_svgversion;
zend_class_entry *ce_cairo_svgunit;

/* ----------------------------------------------------------------
    \Cairo\Surface\Svg Class API
------------------------------------------------------------------*/

/* {{{ proto void __construct(string|resource file, float width, float height)
       Creates a SVG surface of the specified size in points to be written to filename. */
PHP_METHOD(Cairo_Surface_Svg, __construct)
{
    zval *stream_zval = NULL;
    stream_closure *closure;
    php_stream *stream = NULL;
    double width, height;
    bool owned_stream = false;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_ZVAL(stream_zval)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = Z_CAIRO_SURFACE_P(getThis());
    if (!surface_object) {
            RETURN_NULL();
        }

    /* special case - a NULL file is like an "in memory" svg */
    if (Z_TYPE_P(stream_zval) == IS_NULL) {
        surface_object->surface = cairo_svg_surface_create(NULL, width, height);
    }
    /* Otherwise it can be a filename or a PHP stream */
    else {
        if (Z_TYPE_P(stream_zval) == IS_STRING) {
            stream = php_stream_open_wrapper(Z_STRVAL_P(stream_zval), "w+b", REPORT_ERRORS, NULL);
            owned_stream = 1;
        } else if (Z_TYPE_P(stream_zval) == IS_RESOURCE) {
            php_stream_from_zval(stream, stream_zval);
        } else {
            zend_throw_exception(ce_cairo_exception, "Cairo\\Surface\\Svg::__construct() expects parameter 1 to be null, a string, or a stream resource", 0);
            RETURN_THROWS();
        }

        /* Pack stream into struct */
        closure = ecalloc(1, sizeof(stream_closure));
        closure->stream = stream;
        closure->owned_stream = owned_stream;

        surface_object->closure = closure;
        surface_object->surface = cairo_svg_surface_create_for_stream(php_cairo_write_func, (void *)closure, width, height);
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Surface\Svg::restrictToVersion(\Cairo\Surface\Svg\Version version)
       Restricts the generated SVG file to version. This should be called before any drawing takes place on the surface */
PHP_METHOD(Cairo_Surface_Svg, restrictToVersion)
{
    cairo_surface_object *surface_object;
    zval *version;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(version, ce_cairo_svgversion)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_svg_surface_restrict_to_version(
        surface_object->surface,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(version)))
    );

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto string \Cairo\Surface\Svg::versionToString(\Cairo\Surface\Svg\Version version)
       Get the string representation of the given version id. This function will return NULL if version isn't valid. */
PHP_METHOD(Cairo_Surface_Svg, versionToString)
{
    zval *version;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(version, ce_cairo_svgversion)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_STRING(cairo_svg_version_to_string(Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(version)))));
}
/* }}} */

/* {{{ proto array \Cairo\Surface\Svg::getVersions()
       Used to retrieve the list of supported versions */
PHP_METHOD(Cairo_Surface_Svg, getVersions)
{
    const cairo_svg_version_t *versions = 0;
    int version_count = 0, i = 0;
    zval svg_version_case;

    ZEND_PARSE_PARAMETERS_NONE();

    cairo_svg_get_versions(&versions, &version_count);
    array_init(return_value);

    for (i = 0; i < version_count; i++) {
        svg_version_case = php_enum_from_cairo_c_enum(ce_cairo_svgversion, versions[i]);
        add_next_index_zval(return_value, &svg_version_case);
    }
}
/* }}} */


#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
/* {{{ proto array \Cairo\Surface\Svg::setDocumentUnit(\Cairo\Surface\Svg\Unit unit)
       ... */
PHP_METHOD(Cairo_Surface_Svg, setDocumentUnit)
{
    cairo_surface_object *surface_object;
    zval *unit;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(unit, ce_cairo_svgunit)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_svg_surface_set_document_unit(
        surface_object->surface,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(unit)))
    );
}
/* }}} */

/* {{{ proto \Cairo\Surface\SVG\Unit \Cairo\Surface\Svg::getDocumentUnit()
       ... */
PHP_METHOD(Cairo_Surface_Svg, getDocumentUnit)
{
    cairo_surface_object *surface_object;
    zval svg_unit_case;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    svg_unit_case = php_enum_from_cairo_c_enum(
        ce_cairo_svgunit,
        cairo_svg_surface_get_document_unit(surface_object->surface)
    );

    if (Z_TYPE(svg_unit_case) == IS_OBJECT) {
        RETURN_ZVAL(&svg_unit_case, 1, 1);
    }
}
/* }}} */
#endif

/* ----------------------------------------------------------------
    \Cairo\Surface\Svg Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_svg_surface)
{
    /* Svg-Surface */
    ce_cairo_svgsurface = register_class_Cairo_Surface_Svg(ce_cairo_surface);

    /* Svg-Version */
    ce_cairo_svgversion = register_class_Cairo_Surface_Svg_Version();

    /* Svg-Unit */
    ce_cairo_svgunit = register_class_Cairo_Surface_Svg_Unit();

    return SUCCESS;
}

#endif
