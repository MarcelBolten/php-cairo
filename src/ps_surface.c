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

#if CAIRO_HAS_PS_SURFACE
#include <cairo-ps.h>
#include "ps_surface_arginfo.h"

zend_class_entry *ce_cairo_pssurface;
zend_class_entry *ce_cairo_pslevel;

/* ----------------------------------------------------------------
    Cairo\Surface\Ps Class API
------------------------------------------------------------------*/

/* {{{ proto void CairoPsSurface->__construct(string|resource file, int|float width, int|float height)
       Creates a PS surface of the specified size in points to be written to filename. */
PHP_METHOD(Cairo_Surface_Ps, __construct)
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

    /* special case - a NULL file is like an "in memory" surface
       notice it uses the regular create cairo method, not create for stream */
    if (Z_TYPE_P(stream_zval) == IS_NULL) {
        surface_object->surface = cairo_ps_surface_create(NULL, width, height);
    }
    /* Otherwise it can be a filename or a PHP stream */
    else {
        if (Z_TYPE_P(stream_zval) == IS_STRING) {
            stream = php_stream_open_wrapper(Z_STRVAL_P(stream_zval), "w+b", REPORT_ERRORS, NULL);
            owned_stream = 1;
        } else if (Z_TYPE_P(stream_zval) == IS_RESOURCE) {
            php_stream_from_zval(stream, stream_zval);
        } else {
            zend_throw_exception(zend_ce_type_error, "Cairo\\Surface\\Ps::__construct() expects parameter 1 to be null, a string, or a stream resource", 0);
            RETURN_THROWS();
        }

        /* Pack stream into struct */
        closure = ecalloc(1, sizeof(stream_closure));
        closure->stream = stream;
        closure->owned_stream = owned_stream;

        surface_object->closure = closure;
        surface_object->surface = cairo_ps_surface_create_for_stream(php_cairo_write_func, (void *)closure, width, height);
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void CairoPsSurface->setSize(double width, double height)
       Changes the size of a PS surface for the current (and subsequent) pages.
       This should be called before any drawing takes place on the surface */
PHP_METHOD(Cairo_Surface_Ps, setSize)
{
    double width = 0.0, height = 0.0;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_ps_surface_set_size(surface_object->surface, width, height);

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void CairoPsSurface->restrictToLevel(int level)
       Restricts the generated PostScript file to level. */
PHP_METHOD(Cairo_Surface_Ps, restrictToLevel)
{
    cairo_surface_object *surface_object;
    zval *level = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(level, ce_cairo_pslevel)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_ps_surface_restrict_to_level(
        surface_object->surface,
        level
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(level)))
            : CAIRO_PS_LEVEL_2
    );

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void CairoPsSurface->setEps(boolean eps)
       If eps is TRUE, the PostScript surface will output Encapsulated PostScript. */
PHP_METHOD(Cairo_Surface_Ps, setEps)
{
    bool eps = false;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(eps)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_ps_surface_set_eps(surface_object->surface, eps);

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto boolean CairoPsSurface->getEps(void)
       Check whether the PostScript surface will output Encapsulated PostScript. */
PHP_METHOD(Cairo_Surface_Ps, getEps)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_ps_surface_get_eps(surface_object->surface));
}
/* }}} */

/* {{{ proto void CairoPsSurface->dscBeginSetup(void)
       This function indicates that subsequent calls to cairo_ps_surface_dsc_comment() should
       direct comments to the Setup section of the PostScript output. */
PHP_METHOD(Cairo_Surface_Ps, dscBeginSetup)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_ps_surface_dsc_begin_setup(surface_object->surface);
}
/* }}} */

/* {{{ proto void CairoPsSurface->dscBeginPageSetup(void)
       This indicates that subsequent calls to cairo_ps_surface_dsc_comment()
       should direct comments to the PageSetup section of the PostScript output.

       This function call is only needed for the first page of a surface.
       It should be called after any call to cairo_ps_surface_dsc_begin_setup()
       and before any drawing is performed to the surface. */
PHP_METHOD(Cairo_Surface_Ps, dscBeginPageSetup)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_ps_surface_dsc_begin_page_setup(surface_object->surface);
}
/* }}} */

/* {{{ proto void CairoPsSurface->dscComment(string comment)
       Emit a comment into the PostScript output for the given surface. */
PHP_METHOD(Cairo_Surface_Ps, dscComment)
{
    cairo_surface_object *surface_object;
    char *comment, *cairo_comment;
    size_t comment_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(comment, comment_len)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_comment = estrdup(comment);
    cairo_ps_surface_dsc_comment(surface_object->surface, cairo_comment);
    efree(cairo_comment);

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array CairoPsSurface::getLevels(void)
       Used to retrieve the list of supported levels. See cairo_ps_surface_restrict_to_level(). */
PHP_METHOD(Cairo_Surface_Ps, getLevels)
{
    const cairo_ps_level_t *levels;
    int num_levels, i;
    zend_object *ps_level_case;

    ZEND_PARSE_PARAMETERS_NONE();

    cairo_ps_get_levels(&levels, &num_levels);

    array_init(return_value);
    for (i = 0; i < num_levels; i++) {
        if (zend_enum_get_case_by_value(&ps_level_case, ce_cairo_pslevel, levels[i], NULL, false) == SUCCESS) {
            GC_ADDREF(ps_level_case);
            add_next_index_object(return_value, ps_level_case);
        }
    }
}
/* }}} */

/* {{{ proto string \Cairo\Surface\Ps::levelToString(Cairo\Surface\Ps\Level level)
       Get the string representation of the given level id. */
PHP_METHOD(Cairo_Surface_Ps, levelToString)
{
    zval *level;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(level, ce_cairo_pslevel)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_STRING(cairo_ps_level_to_string(Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(level)))));
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\Surface\ps Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_ps_surface)
{
    ce_cairo_pssurface = register_class_Cairo_Surface_Ps(ce_cairo_surface);

    /* Ps Level */
    ce_cairo_pslevel = register_class_Cairo_Surface_Ps_Level();

    return SUCCESS;
}

#endif
