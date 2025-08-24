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

zend_class_entry *ce_cairo_svgsurface;
zend_class_entry *ce_cairo_svgversion;
zend_class_entry *ce_cairo_svgunit;

/* ----------------------------------------------------------------
    \Cairo\Surface\Svg Class API
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO(CairoSvgSurface___construct_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, file)
    ZEND_ARG_INFO(0, width)
    ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

/* {{{ proto void __construct(string|resource file, float width, float height)
       Creates a SVG surface of the specified size in points to be written to filename. */
PHP_METHOD(CairoSvgSurface, __construct)
{
    zval *stream_zval = NULL;
    stream_closure *closure;
    php_stream *stream = NULL;
    double width, height;
    zend_bool owned_stream = 0;
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

ZEND_BEGIN_ARG_INFO(CairoSvgSurface_restrictToVersion_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Svg\\Version, 0)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\Surface\Svg::restrictToVersion(\Cairo\Surface\Svg\Version version)
       Restricts the generated SVG file to version. This should be called before any drawing takes place on the surface */
PHP_METHOD(CairoSvgSurface, restrictToVersion)
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

ZEND_BEGIN_ARG_INFO(CairoSvgSurface_versionToString_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Svg\\Version, 0)
ZEND_END_ARG_INFO()

/* {{{ proto string \Cairo\Surface\Svg::versionToString(\Cairo\Surface\Svg\Version version)
       Get the string representation of the given version id. This function will return NULL if version isn't valid. */
PHP_METHOD(CairoSvgSurface, versionToString)
{
    zval *version;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(version, ce_cairo_svgversion)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_STRING(cairo_svg_version_to_string(Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(version)))));
}
/* }}} */


ZEND_BEGIN_ARG_INFO(CairoSvgSurface_method_no_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ proto array \Cairo\Surface\Svg::getVersions()
       Used to retrieve the list of supported versions */
PHP_METHOD(CairoSvgSurface, getVersions)
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

ZEND_BEGIN_ARG_INFO(CairoSvgSurface_setDocumentUnit_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_OBJ_INFO(0, unit, Cairo\\Surface\\Svg\\Unit, 0)
ZEND_END_ARG_INFO()

/* {{{ proto array \Cairo\Surface\Svg::setDocumentUnit(\Cairo\Surface\Svg\Unit unit)
       ... */
PHP_METHOD(CairoSvgSurface, setDocumentUnit)
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
PHP_METHOD(CairoSvgSurface, getDocumentUnit)
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

/* {{{ cairo_svg_surface_methods[] */
static const zend_function_entry cairo_svg_surface_methods[] = {
    PHP_ME(CairoSvgSurface, __construct, CairoSvgSurface___construct_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(CairoSvgSurface, restrictToVersion, CairoSvgSurface_restrictToVersion_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoSvgSurface, versionToString, CairoSvgSurface_versionToString_args, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
    PHP_ME(CairoSvgSurface, getVersions, CairoSvgSurface_method_no_args, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    PHP_ME(CairoSvgSurface, setDocumentUnit, CairoSvgSurface_setDocumentUnit_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoSvgSurface, getDocumentUnit, CairoSvgSurface_method_no_args, ZEND_ACC_PUBLIC)
#endif
    ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_svg_surface)
{
    zend_class_entry surface_ce;

    /* Svg-Surface */
    INIT_NS_CLASS_ENTRY(surface_ce, CAIRO_NAMESPACE, ZEND_NS_NAME("Surface", "Svg"), cairo_svg_surface_methods);
    ce_cairo_svgsurface = zend_register_internal_class_ex(&surface_ce, ce_cairo_surface);

    /* Svg-Version */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Surface", ZEND_NS_NAME("Svg", "Version")), ce_cairo_svgversion);

#define CAIRO_SVG_VERSION_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_svgversion, CAIRO_SVG)

    CAIRO_SVG_VERSION_DECLARE_ENUM_CASE(VERSION_1_1);
    CAIRO_SVG_VERSION_DECLARE_ENUM_CASE(VERSION_1_2);

    /* Svg-Unit */
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Surface", ZEND_NS_NAME("Svg", "Unit")), ce_cairo_svgunit);

#define CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_svgunit, CAIRO_SVG_UNIT)

    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(USER);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(EM);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(EX);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(PX);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(IN);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(CM);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(MM);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(PT);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(PC);
    CAIRO_SVG_UNIT_DECLARE_ENUM_CASE(PERCENT);
#endif

    return SUCCESS;
}

#endif
