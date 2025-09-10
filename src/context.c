/*
  +----------------------------------------------------------------------+
  | For PHP Version 8                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 2015 Elizabeth M Smith, 2022 Swen Zanon                |
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
#include "context_arginfo.h"

zend_class_entry *ce_cairo_context;
zend_class_entry *ce_cairo_fillrule;
zend_class_entry *ce_cairo_linecap;
zend_class_entry *ce_cairo_linejoin;
zend_class_entry *ce_cairo_operator;


static zend_object_handlers cairo_context_object_handlers;

cairo_context_object *cairo_context_fetch_object(zend_object *object) {
    return (cairo_context_object *) ((char*) (object) - XtOffsetOf(cairo_context_object, std));
}

cairo_context_object *cairo_context_object_get(zval *zv) {

    cairo_context_object *object = Z_CAIRO_CONTEXT_P(zv);

    if (object->context == NULL) {
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Internal context object missing in %s, you must call parent::__construct in extended classes.",
            ZSTR_VAL(Z_OBJCE_P(zv)->name));
        return NULL;
    }

    return object;
}


/* ----------------------------------------------------------------
    Cairo\Context C API
------------------------------------------------------------------*/

/* {{{ */
cairo_t *cairo_context_object_get_context(zval *zv) {
    cairo_context_object *context_object = cairo_context_object_get(zv);
    return context_object->context;
}
/* }}} */

zend_class_entry* php_cairo_get_context_ce() {
    return ce_cairo_context;
}

extern cairo_t * php_cairo_context_reference(cairo_t *context) {
    return cairo_reference(context);
}


/* ----------------------------------------------------------------
    Cairo\Context Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_context_free_obj(zend_object *object)
{
    cairo_context_object *intern = cairo_context_fetch_object(object);

    if (!intern) {
        return;
    }

    zval_ptr_dtor(&intern->surface);
    zval_ptr_dtor(&intern->matrix);
    zval_ptr_dtor(&intern->pattern);
    zval_ptr_dtor(&intern->font_face);
    zval_ptr_dtor(&intern->font_matrix);
    zval_ptr_dtor(&intern->font_options);
    zval_ptr_dtor(&intern->scaled_font);

    if (intern->context) {
        cairo_destroy(intern->context);
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* cairo_context_obj_ctor(zend_class_entry *ce, cairo_context_object **intern)
{
    cairo_context_object *object = ecalloc(1, sizeof(cairo_context_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->surface);
    ZVAL_UNDEF(&object->matrix);
    ZVAL_UNDEF(&object->pattern);
    ZVAL_UNDEF(&object->font_face);
    ZVAL_UNDEF(&object->font_matrix);
    ZVAL_UNDEF(&object->scaled_font);

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &cairo_context_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
zend_object* cairo_context_create_object(zend_class_entry *ce)
{
    cairo_context_object *context = NULL;
    zend_object *return_value = cairo_context_obj_ctor(ce, &context);

    object_properties_init(&context->std, ce);
    return return_value;
}
/* }}} */


/* ----------------------------------------------------------------
    Cairo\Context Class API
------------------------------------------------------------------*/

/* Basic Context */

/* {{{ proto void __construct(object surface)
   Returns new CairoContext object on the requested surface */
PHP_METHOD(Cairo_Context, __construct)
{
    zval *surface_zval;
    cairo_context_object *context_object;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(surface_zval, ce_cairo_surface)
    ZEND_PARSE_PARAMETERS_END();

    context_object = Z_CAIRO_CONTEXT_P(getThis());
    if (!context_object) {
        RETURN_NULL();
    }

    surface_object = cairo_surface_object_get(surface_zval);
    if (!surface_object) {
        RETURN_THROWS();
    }

    context_object->context = cairo_create(surface_object->surface);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    ZVAL_COPY(&context_object->surface, surface_zval);
}
/* }}} */

/* {{{ proto \Cairo\Status \Cairo\Context::getStatus()
   Returns the current integer status of the CairoContext */
PHP_METHOD(Cairo_Context, getStatus)
{
    cairo_context_object *context_object;
    zval status_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    status_case = php_enum_from_cairo_c_enum(
        ce_cairo_status,
        cairo_status(context_object->context)
    );

    if (Z_TYPE(status_case) == IS_OBJECT) {
        RETURN_ZVAL(&status_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::save()
   Makes a copy of the current state of the context and saves it on an internal stack of saved states */
PHP_METHOD(Cairo_Context, save)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_save(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::restore()
   Restores the context to the state saved and removes that state from the stack of saved states */
PHP_METHOD(Cairo_Context, restore)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_restore(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::pushGroup()
   Temporarily redirects drawing to an intermediate surface known as a group. */
PHP_METHOD(Cairo_Context, pushGroup)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_push_group(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::pushGroupWithContent(\Cairo\Surface\Content content)
   Temporarily redirects drawing to an intermediate surface known as a group. */
PHP_METHOD(Cairo_Context, pushGroupWithContent)
{
    cairo_context_object *context_object;
    zval *content;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(content, ce_cairo_content)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_push_group_with_content(
        context_object->context,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(content)))
    );
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto Cairo\Pattern object \Cairo\Context::popGroup()
   Terminates the redirection and returns a new pattern containing the results of all drawing operations performed to the group. */
PHP_METHOD(Cairo_Context, popGroup)
{
    cairo_pattern_t *pattern;
    cairo_context_object *context_object;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    pattern = cairo_pop_group(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_cairo_get_pattern_ce(pattern));
    pattern_object = Z_CAIRO_PATTERN_P(return_value);
    pattern_object->pattern = pattern;
    cairo_pattern_reference(pattern_object->pattern);
}
/* }}} */

/* {{{ proto void \Cairo\Context::popGroupToSource()
   Terminates the redirection and installs the resulting pattern as the source pattern in the given cairo context. */
PHP_METHOD(Cairo_Context, popGroupToSource)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_pop_group_to_source(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto Cairo\Surface object \Cairo\Context::getGroupSurface()
   previous method-name was getGroupTarget()
   Gets the current destination surface for the context. */
PHP_METHOD(Cairo_Context, getGroupSurface)
{
    cairo_context_object *context_object;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    object_init_ex(
        return_value,
        php_cairo_get_surface_ce(cairo_get_group_target(context_object->context))
    );
    surface_object = Z_CAIRO_SURFACE_P(return_value);
    surface_object->surface = cairo_get_group_target(context_object->context);
    cairo_surface_reference(surface_object->surface);
}
/* }}} */

// /* {{{ proto void \Cairo\Context::setSourceRGB(float red, float green, float blue)
//    Sets the source pattern within context to an opaque color.
//    This opaque color will then be used for any subsequent drawing operation
//    until a new source pattern is set. */
// PHP_METHOD(Cairo_Context, setSourceRGB)
// {
//     double red = 0.0, green = 0.0, blue = 0.0;
//     cairo_context_object *context_object;

//     ZEND_PARSE_PARAMETERS_START(3, 3)
//         Z_PARAM_DOUBLE(red)
//         Z_PARAM_DOUBLE(green)
//         Z_PARAM_DOUBLE(blue)
//     ZEND_PARSE_PARAMETERS_END();

//     context_object = cairo_context_object_get(getThis());
//     if (!context_object) {
//         RETURN_THROWS();
//     }

//     cairo_set_source_rgb(context_object->context, red, green, blue);
//     if (php_cairo_throw_exception(cairo_status(context_object->context))) {
//         RETURN_THROWS();
//     }
// }
// /* }}} */

/* {{{ proto void \Cairo\Context::setSourceRgba(float red, float green, float blue, float alpha)
   Sets the source pattern within context to an translucent  color. This opaque color will then be used for any subsequent drawing operation until a new source pattern is set. */
PHP_METHOD(Cairo_Context, setSourceRgba)
{
    double red = 0.0, green = 0.0, blue = 0.0, alpha = 1.0;
    bool alpha_is_null = true;

    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(3, 4)
        Z_PARAM_DOUBLE(red)
        Z_PARAM_DOUBLE(green)
        Z_PARAM_DOUBLE(blue)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE_OR_NULL(alpha, alpha_is_null)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    if (alpha_is_null) {
        cairo_set_source_rgb(context_object->context, red, green, blue);
    } else {
        cairo_set_source_rgba(context_object->context, red, green, blue, alpha);
    }

    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::setSurface(object surface [, float x, float y])
       previous method-name was setSourceSurface()
       This is a convenience function for creating a pattern from surface and setting it as the source. */
PHP_METHOD(Cairo_Context, setSurface)
{
    zval *surface_zval;
    cairo_context_object *context_object;
    cairo_surface_object *surface_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_OBJECT_OF_CLASS(surface_zval, ce_cairo_surface)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    surface_object = cairo_surface_object_get(surface_zval);
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (context_object->context == NULL) {
        context_object->context = cairo_create(surface_object->surface);
        if (php_cairo_throw_exception(cairo_status(context_object->context))) {
            RETURN_THROWS();
        }
    }

    cairo_set_source_surface(context_object->context, surface_object->surface, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If there's already a pattern, then we deref and remove it because we just overwrote it */
    CAIRO_UNREF_AND_UNDEF(context_object->pattern)

    /* If there's already a surface, then we deref and remove it */
    CAIRO_UNREF_AND_UNDEF(context_object->surface)

    /* we need to be able to get this zval out later, so ref and store */
    ZVAL_COPY(&context_object->surface, surface_zval);
}
/* }}} */

/* {{{ proto CairoSurface object \Cairo\Context::getSurface
   previous method-name was getTarget()
   Gets the target surface for the cairo context that was set on creation */
PHP_METHOD(Cairo_Context, getSurface)
{
    cairo_surface_t *surface;
    cairo_context_object *context_object;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* If we have a surface stored, grab that zval to use */
    CAIRO_RETURN_IF_REF(context_object->surface);

    /* Otherwise we spawn a new object */
    surface = cairo_get_target(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_cairo_get_surface_ce(surface));
    surface_object = Z_CAIRO_SURFACE_P(return_value);
    surface_object->surface = surface;
    cairo_surface_reference(surface_object->surface);
}
/* }}} */

/* {{{ proto void \Cairo\Context::setPattern(CairoPattern object)
   previous method-name was setSource()
   Sets the source pattern within context to source.
   This pattern will then be used for any subsequent drawing operation until a new source pattern is set. */
PHP_METHOD(Cairo_Context, setPattern)
{
    zval *pattern_zval = NULL;
    cairo_context_object *context_object;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(pattern_zval, ce_cairo_pattern)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    pattern_object = Z_CAIRO_PATTERN_P(pattern_zval);
    cairo_set_source(context_object->context, pattern_object->pattern);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If there's already a pattern, then we deref and remove it */
    CAIRO_UNREF_AND_UNDEF(context_object->pattern)

    /* we need to be able to get this zval out later, so ref and store */
    ZVAL_COPY(&context_object->pattern, pattern_zval);
}
/* }}} */

/* {{{ proto CairoPattern object \Cairo\Context::getPattern()
   previous method-name was getSource()
   Gets the current source pattern for the context. */
PHP_METHOD(Cairo_Context, getPattern)
{
    cairo_pattern_t *pattern;
    cairo_context_object *context_object;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* If we have a patter/source object stored, grab that zval to use */
    CAIRO_RETURN_IF_REF(context_object->pattern);

    /* Otherwise we spawn a new object */
    pattern = cairo_get_source(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_cairo_get_pattern_ce(pattern));
    pattern_object = Z_CAIRO_PATTERN_P(return_value);
    pattern_object->pattern = pattern;
    cairo_pattern_reference(pattern_object->pattern);
}
/* }}} */

/* {{{ proto void \Cairo\Context::setAntialias(\Cairo\Antialias antialias)
   Set the antialiasing mode of the rasterizer used for drawing shapes. */
PHP_METHOD(Cairo_Context, setAntialias)
{
    cairo_context_object *context_object;
    cairo_antialias_t antialias;
    zval *antialias_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(antialias_case, ce_cairo_antialias)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    antialias = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(antialias_case)));

    cairo_set_antialias(context_object->context, antialias);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\Context::getAntialias()
   Gets the current shape antialiasing mode */
PHP_METHOD(Cairo_Context, getAntialias)
{
    cairo_context_object *context_object;
    cairo_antialias_t antialias;
    zval antialias_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    antialias = cairo_get_antialias(context_object->context);

    antialias_case = php_enum_from_cairo_c_enum(ce_cairo_antialias, antialias);

    if (Z_TYPE(antialias_case) == IS_OBJECT) {
        RETURN_ZVAL(&antialias_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::setDash(array dashes [, float offset])
   Sets the dash pattern to be used by cairo_stroke() */
PHP_METHOD(Cairo_Context, setDash)
{
    cairo_context_object *context_object;
    double offset = 0.0;
    long num_dashes = 0;
    double *dashes_array;
    zval * dashes = NULL, *pzval;
    HashTable *dashes_hash = NULL;
    int i = 0;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_ARRAY(dashes)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(offset)
    ZEND_PARSE_PARAMETERS_END();

    /* Grab the zend hash and see how big our array will be */
    dashes_hash = Z_ARRVAL_P(dashes);
    num_dashes = zend_hash_num_elements(dashes_hash);
    dashes_array = emalloc(num_dashes * sizeof(double));

    /* iterate the array, make sure we JUGGLE the value to a double */
    ZEND_HASH_FOREACH_VAL(dashes_hash, pzval) {
        if (Z_TYPE_P(pzval) != IS_DOUBLE) {
            convert_to_double(pzval);
        }
        dashes_array[i++] = Z_DVAL_P(pzval);
    }
    ZEND_HASH_FOREACH_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* we use i in case we had a bad issue while iterating the array */
    cairo_set_dash(context_object->context, dashes_array, i, offset);
    efree(dashes_array);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\Context::getDashCount()
   This function returns the length of the dash array or 0 */
PHP_METHOD(Cairo_Context, getDashCount)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_LONG(cairo_get_dash_count(context_object->context));
}
/* }}} */

/* {{{ proto array \Cairo\Context::getDash()
   Gets the current dash array and offset */
PHP_METHOD(Cairo_Context, getDash)
{
    zval sub_array;
    cairo_context_object *context_object;
    double *dashes = NULL;
    double offset = 0;
    int num_dashes, i;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* Setup container for dashes */
    num_dashes = cairo_get_dash_count(context_object->context);
    dashes = emalloc(num_dashes * sizeof(double));

    /* Get dashes and push into PHP array */
    cairo_get_dash(context_object->context, dashes, &offset);

    array_init(&sub_array);
    for (i = 0; i < num_dashes; i++) {
        add_next_index_double(&sub_array, dashes[i]);
    }
    efree(dashes);

    /* Put dashes and offset into return */
    array_init(return_value);
    add_assoc_zval(return_value, "dashes", &sub_array);
    add_assoc_double(return_value, "offset", offset);
}
/* }}} */

/* {{{ proto void \Cairo\Context::setFillRule(int setting)
   Set the current fill rule within the cairo context. The fill rule is used
   to determine which regions are inside or outside a complex path */
PHP_METHOD(Cairo_Context, setFillRule)
{
    cairo_context_object *context_object;
    cairo_fill_rule_t fillrule;
    zval *fillrule_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(fillrule_case, ce_cairo_fillrule)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    fillrule = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(fillrule_case)));

    cairo_set_fill_rule(context_object->context, fillrule);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\Context::getFillRule()
   Gets the current fill rule */
PHP_METHOD(Cairo_Context, getFillRule)
{
    cairo_context_object *context_object;
    cairo_fill_rule_t fillrule;
    zval fillrule_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    fillrule = cairo_get_fill_rule(context_object->context);

    fillrule_case = php_enum_from_cairo_c_enum(ce_cairo_fillrule, fillrule);

    if (Z_TYPE(fillrule_case) == IS_OBJECT) {
        RETURN_ZVAL(&fillrule_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::setLineCap(\Cairo\LineCap::Butt)
   Sets the current line cap style within the cairo context. */
PHP_METHOD(Cairo_Context, setLineCap)
{
    cairo_context_object *context_object;
    zval *linecap_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(linecap_case, ce_cairo_linecap)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_set_line_cap(
        context_object->context,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(linecap_case)))
    );
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\Context::getLineCap()
   Gets the current line cap style */
PHP_METHOD(Cairo_Context, getLineCap)
{
    cairo_context_object *context_object;
    zval linecap_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    linecap_case = php_enum_from_cairo_c_enum(
        ce_cairo_linecap,
        cairo_get_line_cap(context_object->context)
    );

    if (Z_TYPE(linecap_case) == IS_OBJECT) {
        RETURN_ZVAL(&linecap_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::setLineJoin(\Cairo\LineJoin::Miter)
   Sets the current line join style within the cairo context. */
PHP_METHOD(Cairo_Context, setLineJoin)
{
    cairo_context_object *context_object;
    cairo_line_join_t linejoin;
    zval *linejoin_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(linejoin_case, ce_cairo_linejoin)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    linejoin = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(linejoin_case)));

    cairo_set_line_join(context_object->context, linejoin);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\Context::getLineJoin()
   Gets the current line join style */
PHP_METHOD(Cairo_Context, getLineJoin)
{
    cairo_context_object *context_object;
    cairo_line_join_t linejoin;
    zval linejoin_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    linejoin = cairo_get_line_join(context_object->context);

    linejoin_case = php_enum_from_cairo_c_enum(ce_cairo_linejoin, linejoin);

    if (Z_TYPE(linejoin_case) == IS_OBJECT) {
        RETURN_ZVAL(&linejoin_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::setLineWidth(float width)
   Sets the current line width within the cairo context. The line width value
   specifies the diameter of a pen that is circular in user space */
PHP_METHOD(Cairo_Context, setLineWidth)
{
    cairo_context_object *context_object;
    double width = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(width)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_set_line_width(context_object->context, width);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto double \Cairo\Context::getLineWidth()
   This function returns the current line width value exactly as set by cairo_set_line_width() */
PHP_METHOD(Cairo_Context, getLineWidth)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_DOUBLE(cairo_get_line_width(context_object->context));
}
/* }}} */

/* {{{ proto void \Cairo\Context::setMiterLimit(float limit)
   Sets the current miter limit within the cairo context. */
PHP_METHOD(Cairo_Context, setMiterLimit)
{
    cairo_context_object *context_object;
    double limit = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(limit)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_set_miter_limit(context_object->context, limit);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto double \Cairo\Context::getMiterLimit()
   Gets the current miter limit */
PHP_METHOD(Cairo_Context, getMiterLimit)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_DOUBLE(cairo_get_miter_limit(context_object->context));
}
/* }}} */

/* {{{ proto void \Cairo\Context::setOperator(\Cairo\Operator::Over)
   Sets the compositing operator to be used for all drawing operations. */
PHP_METHOD(Cairo_Context, setOperator)
{
    cairo_context_object *context_object;
    cairo_operator_t operator;
    zval *operator_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(operator_case, ce_cairo_operator)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    operator = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(operator_case)));

    cairo_set_operator(context_object->context, operator);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\Context::getOperator()
   Gets the current compositing operator for a cairo context. */
PHP_METHOD(Cairo_Context, getOperator)
{
    cairo_context_object *context_object;
    cairo_operator_t operator;
    zval operator_case;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    operator = cairo_get_operator(context_object->context);

    operator_case = php_enum_from_cairo_c_enum(ce_cairo_operator, operator);

    if (Z_TYPE(operator_case) == IS_OBJECT) {
        RETURN_ZVAL(&operator_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::setTolerance(float tolerance)
   Sets the tolerance used when converting paths into trapezoids.
   The default value is 0.1. A larger value will give better performance, a smaller value, better appearance. */
PHP_METHOD(Cairo_Context, setTolerance)
{
    cairo_context_object *context_object;
    double tolerance = 0.1;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(tolerance)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_set_tolerance(context_object->context, tolerance);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto double \Cairo\Context::getTolerance()
   Gets the current tolerance value */
PHP_METHOD(Cairo_Context, getTolerance)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_DOUBLE(cairo_get_tolerance(context_object->context));
}
/* }}} */

/* {{{ proto void \Cairo\Context::clip()
   Establishes a new clip region by intersecting the current clip region with the current path as it
   would be filled by cairo_fill() and according to the current fill rule */
PHP_METHOD(Cairo_Context, clip)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_clip(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto boolean \Cairo\Context::inClip(double x, double y)
   Tests whether the given point is inside the area that would be visible
   through the current clip
 */
PHP_METHOD(Cairo_Context, inClip)
{
    cairo_context_object *context_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_in_clip(context_object->context, x, y));
}
/* }}} */

/* {{{ proto void \Cairo\Context::clipPreserve()
   Establishes a new clip region by intersecting the current clip region with the current path as it
   would be filled by cairo_fill() and according to the current fill rule
   Unlike cairo_clip(), cairo_clip_preserve() preserves the path within the cairo context. */
PHP_METHOD(Cairo_Context, clipPreserve)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_clip_preserve(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::resetClip()
   Reset the current clip region to its original, unrestricted state. */
PHP_METHOD(Cairo_Context, resetClip)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_reset_clip(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Context::getClipExtents()
   previous method-name was clipExtents()
   Computes a bounding box in user coordinates covering the area inside the current clip. */
PHP_METHOD(Cairo_Context, getClipExtents)
{
    cairo_context_object *context_object;
    double x1, y1, x2, y2;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_clip_extents(context_object->context, &x1, &y1, &x2, &y2);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x1", x1);
    add_assoc_double(return_value, "y1", y1);
    add_assoc_double(return_value, "x2", x2);
    add_assoc_double(return_value, "y2", y2);}
/* }}} */

/* {{{ proto array \Cairo\Context::clipRectangleList()
   Gets the current stroke region as a list of rectangles in user coordinates. */
PHP_METHOD(Cairo_Context, getClipRectangleList)
{
    cairo_context_object *context_object;
    cairo_rectangle_list_t *rectangles;
    cairo_rectangle_t rectangle;
    zval rectangle_zv;
    cairo_rectangle_object *rectangle_object;
    int i;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    rectangles = cairo_copy_clip_rectangle_list(context_object->context);
    if (php_cairo_throw_exception(rectangles->status)) {
        RETURN_THROWS();
    }

    array_init(return_value);

    for (i = 0; i < rectangles->num_rectangles; i++) {
        rectangle = rectangles->rectangles[i];

        object_init_ex(&rectangle_zv, php_cairo_get_rectangle_ce());
        rectangle_object = Z_CAIRO_RECTANGLE_P(&rectangle_zv);
        *rectangle_object->rect = rectangle;

        add_next_index_zval(return_value, &rectangle_zv);
    }

    cairo_rectangle_list_destroy(rectangles);
}
/* }}} */

/* {{{ proto void \Cairo\Context::fill()
   A drawing operator that fills the current path according to the current fill rule,
   (each sub-path is implicitly closed before being filled). */
PHP_METHOD(Cairo_Context, fill)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_fill(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::fillPreserve()
   A drawing operator that fills the current path according to the current fill rule,
   (each sub-path is implicitly closed before being filled). Unlike cairo_fill(),
   cairo_fill_preserve() preserves the path within the cairo context. */
PHP_METHOD(Cairo_Context, fillPreserve)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_fill_preserve(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Context::getFillExtents()
   previous method-name was fillExtents()
   Computes a bounding box in user coordinates covering the area that would be affected,
   (the "inked" area), by a cairo_fill() operation given the current path and fill parameters. */
PHP_METHOD(Cairo_Context, getFillExtents)
{
    cairo_context_object *context_object;
    double x1, y1, x2, y2;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_fill_extents(context_object->context, &x1, &y1, &x2, &y2);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x1", x1);
    add_assoc_double(return_value, "y1", y1);
    add_assoc_double(return_value, "x2", x2);
    add_assoc_double(return_value, "y2", y2);}
/* }}} */

/* {{{ proto bool \Cairo\Context::inFill(int x, int y)
   Tests whether the given point is inside the area that would be affected by a cairo_fill()
   operation given the current path and filling parameters. */
PHP_METHOD(Cairo_Context, inFill)
{
    cairo_context_object *context_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_in_fill(context_object->context, x, y));
}
/* }}} */

/* {{{ proto void \Cairo\Context::mask(CairoPattern object)
   A drawing operator that paints the current source using the alpha channel of pattern as a mask. */
PHP_METHOD(Cairo_Context, mask)
{
    zval *pattern_zval = NULL;
    cairo_context_object *context_object;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(pattern_zval, ce_cairo_pattern)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    pattern_object = Z_CAIRO_PATTERN_P(pattern_zval);
    cairo_mask(context_object->context, pattern_object->pattern);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::maskSurface(object surface [, float x, float y])
       A drawing operator that paints the current source using the alpha channel of surface as a mask.
 */
PHP_METHOD(Cairo_Context, maskSurface)
{
    zval *surface_zval = NULL;
    cairo_context_object *context_object;
    cairo_surface_object *surface_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_OBJECT_OF_CLASS(surface_zval, ce_cairo_surface)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    surface_object = Z_CAIRO_SURFACE_P(surface_zval);
    cairo_mask_surface(context_object->context, surface_object->surface, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::paint()
   A drawing operator that paints the current source everywhere within the current clip region. */
PHP_METHOD(Cairo_Context, paint)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_paint(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::paintWithAlpha(float alpha)
   A drawing operator that paints the current source everywhere within the current clip region using a mask of constant alpha value alpha. */
PHP_METHOD(Cairo_Context, paintWithAlpha)
{
    cairo_context_object *context_object;
    double alpha = 0.0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(alpha)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_paint_with_alpha(context_object->context, alpha);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::stroke()
   A drawing operator that strokes the current path according to the current line width, line join, line cap, and dash settings. */
PHP_METHOD(Cairo_Context, stroke)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_stroke(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::strokePreserve()
   A drawing operator that strokes the current path according to the current line width, line join, line cap, and dash settings.
   Unlike cairo_stroke(), cairo_stroke_preserve() preserves the path within the cairo context. */
PHP_METHOD(Cairo_Context, strokePreserve)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_stroke_preserve(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Context::strokeExtents()
   Computes a bounding box in user coordinates covering the area that would be affected, (the "inked" area), by a cairo_stroke()
   operation operation given the current path and stroke parameters. */
PHP_METHOD(Cairo_Context, getStrokeExtents)
{
    cairo_context_object *context_object;
    double x1, y1, x2, y2;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_stroke_extents(context_object->context, &x1, &y1, &x2, &y2);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x1", x1);
    add_assoc_double(return_value, "y1", y1);
    add_assoc_double(return_value, "x2", x2);
    add_assoc_double(return_value, "y2", y2);}
/* }}} */

/* {{{ proto bool \Cairo\Context::inStroke(int x, int y)
   Tests whether the given point is inside the area that would be affected by a cairo_stroke()
   operation given the current path and stroking parameters. */
PHP_METHOD(Cairo_Context, inStroke)
{
    cairo_context_object *context_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_in_stroke(context_object->context, x, y));
}
/* }}} */

/* {{{ proto void \Cairo\Context::copyPage()
   Emits the current page for backends that support multiple pages, but doesn't clear it,
   so, the contents of the current page will be retained for the next page too.*/
PHP_METHOD(Cairo_Context, copyPage)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_copy_page(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::showPage()
   Emits and clears the current page for backends that support multiple pages.
   Use cairo_copy_page() if you don't want to clear the page. */
PHP_METHOD(Cairo_Context, showPage)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_show_page(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
/* {{{ proto void \Cairo\Context::setHairline(bool hairline)
   Sets whether to use hairline mode for stroking.
   Hairline mode is disabled by default. */
PHP_METHOD(Cairo_Context, setHairline)
{
    cairo_context_object *context_object;
    bool hairline = false;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_BOOL(hairline)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_set_hairline(context_object->context, hairline);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto bool \Cairo\Context::getHairline()
   Gets whether hairline mode is enabled for stroking. */
PHP_METHOD(Cairo_Context, getHairline)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_get_hairline(context_object->context));
}
/* }}} */
#endif

/*
 * Transformations
 */

/* {{{ proto void \Cairo\Context::translate(float x, float y)
   Modifies the current transformation matrix by translating the user-space origin by (x, y) */
PHP_METHOD(Cairo_Context, translate)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_translate(context_object->context, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::scale(float x, float y)
   Modifies the current transformation matrix by scaling the X and Y user-space axes by x and y respectively */
PHP_METHOD(Cairo_Context, scale)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_scale(context_object->context, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::rotate(float angle)
   Modifies the current transformation matrix by rotating the user-space axes by angle radians */
PHP_METHOD(Cairo_Context, rotate)
{
    double angle = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(angle)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }
    cairo_rotate(context_object->context, angle);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::transform(\Cairo\Matrix matrix)
   Modifies the current transformation matrix by applying a matrix as an additional transformation */
PHP_METHOD(Cairo_Context, transform)
{
    zval *matrix_zval = NULL;
    cairo_context_object *context_object;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(matrix_zval, ce_cairo_matrix)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    matrix_object = Z_CAIRO_MATRIX_P(matrix_zval);
    cairo_transform(context_object->context, matrix_object->matrix);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::setMatrix(\Cairo\Matrix matrix)
   Sets the current transformation matrix */
PHP_METHOD(Cairo_Context, setMatrix)
{
    zval *matrix_zval = NULL;
    cairo_context_object *context_object;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(matrix_zval, ce_cairo_matrix)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    matrix_object = Z_CAIRO_MATRIX_P(matrix_zval);
    cairo_set_matrix(context_object->context, matrix_object->matrix);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If there's already a matrix, then we deref and remove it */
    CAIRO_UNREF_AND_UNDEF(context_object->matrix)

    /* we need to be able to get this zval out later, so ref and store */
    ZVAL_COPY(&context_object->matrix, matrix_zval);
}
/* }}} */

/* {{{ proto \Cairo\Matrix matrix \Cairo\Context::getMatrix()
   Returns the current transformation matrix */
PHP_METHOD(Cairo_Context, getMatrix)
{
    cairo_context_object *context_object;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* If we have a matrix object stored, grab that zval to use */
    CAIRO_RETURN_IF_REF(context_object->matrix);

    /* Otherwise we spawn a new object */
    object_init_ex(return_value, php_cairo_get_matrix_ce());
    matrix_object = Z_CAIRO_MATRIX_P(return_value);
    cairo_get_matrix(context_object->context, matrix_object->matrix);
}
/* }}} */

/* {{{ proto void \Cairo\Context::identityMatrix()
   Resets the current transformation matrix by setting it equal to the identity matrix */
PHP_METHOD(Cairo_Context, identityMatrix)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_identity_matrix(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array cairo_user_to_device(CairoContext object, int x, int y)
   proto array \Cairo\Context::userToDevice(int x, int y)
   Transform a coordinate from user space to device space by multiplying the given point by the current transformation matrix */
PHP_METHOD(Cairo_Context, userToDevice)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_user_to_device(context_object->context, &x, &y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ proto array \Cairo\Context::userToDeviceDistance(int x, int y)
   Transform a coordinate from user space to device space by multiplying the
   given point by the current transformation matrix except that the translation components
   are ignored */
PHP_METHOD(Cairo_Context, userToDeviceDistance)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_user_to_device_distance(context_object->context, &x, &y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ proto array \Cairo\Context::deviceToUser(int x, int y)
   Transform a coordinate from device space to user space by multiplying the given
   point by the inverse of the current transformation matrix */
PHP_METHOD(Cairo_Context, deviceToUser)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_device_to_user(context_object->context, &x, &y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ proto void \Cairo\Context::deviceToUserDistance(int x, int y)
   Transform a distance vector from device space to user space. */
PHP_METHOD(Cairo_Context, deviceToUserDistance)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_device_to_user_distance(context_object->context, &x, &y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/*
 * Paths
 */

/* {{{ proto CairoPath object \Cairo\Context::copyPath()
   Creates a copy of the current path and returns it to the user as a CairoPath object */
PHP_METHOD(Cairo_Context, copyPath)
{
    cairo_path_object *path_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_cairo_get_path_ce());
    path_object = Z_CAIRO_PATH_P(return_value);
    path_object->path = cairo_copy_path(context_object->context);
    if (php_cairo_throw_exception(path_object->path->status)) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto CairoPath object \Cairo\Context::copyPathFlat()
   Creates a copy of the current path and returns it to the user as a CairoPath object
   any curves in the path will be approximated with piecewise-linear approximations*/
PHP_METHOD(Cairo_Context, copyPathFlat)
{
    cairo_path_object *path_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_cairo_get_path_ce());
    path_object = Z_CAIRO_PATH_P(return_value);
    path_object->path = cairo_copy_path_flat(context_object->context);
    if (php_cairo_throw_exception(path_object->path->status)) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::appendPath(CairoPath object)
   Append the path onto the current path. */
PHP_METHOD(Cairo_Context, appendPath)
{
    zval *path_zval = NULL;
    const cairo_path_t *path;
    cairo_path_object *path_object;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(path_zval, ce_cairo_path)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    path_object = Z_CAIRO_PATH_P(path_zval);
    path = path_object->path;
    cairo_append_path(context_object->context, path);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto bool \Cairo\Context::hasCurrentPoint()
   Returns whether a current point is defined on the current path. */
PHP_METHOD(Cairo_Context, hasCurrentPoint)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_has_current_point(context_object->context));
}
/* }}} */

/* {{{ proto array \Cairo\Context::getCurrentPoint()
   Gets the current point of the current path, which is conceptually the final point reached by the path so far. */
PHP_METHOD(Cairo_Context, getCurrentPoint)
{
    double x, y;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    cairo_get_current_point(context_object->context, &x, &y);
    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ proto void \Cairo\Context::newPath()
   Clears the current path. After this call there will be no path and no current point. */
PHP_METHOD(Cairo_Context, newPath)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_new_path(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::newSubPath()
   Begin a new sub-path. Note that the existing path is not affected. After this call there will be no current point. */
PHP_METHOD(Cairo_Context, newSubPath)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_new_sub_path(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::closePath()
   Adds a line segment to the path from the current point to the beginning of the current sub-path,
   and closes this sub-path. After this call the current point will be at the joined endpoint of the sub-path. */
PHP_METHOD(Cairo_Context, closePath)
{
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_close_path(context_object->context);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::arc(float x, float y, float radius, float angle1, float angle2)
   Adds a circular arc of the given radius to the current path.
   The arc is centered at (x, y), begins at angle1 and proceeds in the direction of increasing angles to end at angle2*/
PHP_METHOD(Cairo_Context, arc)
{
    double x = 0.0, y = 0.0, radius = 0.0, angle1 = 0.0, angle2 = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(5, 5)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
        Z_PARAM_DOUBLE(radius)
        Z_PARAM_DOUBLE(angle1)
        Z_PARAM_DOUBLE(angle2)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_arc(context_object->context, x, y, radius, angle1, angle2);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::arcNegative(float x, float y, float radius, float angle1, float angle2)
   Adds a circular arc of the given radius to the current path.
   The arc is centered at (x, y), begins at angle1 and proceeds in the direction of decreasing angles to end at angle2.*/
PHP_METHOD(Cairo_Context, arcNegative)
{
    double x = 0.0, y = 0.0, radius = 0.0, angle1 = 0.0, angle2 = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(5, 5)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
        Z_PARAM_DOUBLE(radius)
        Z_PARAM_DOUBLE(angle1)
        Z_PARAM_DOUBLE(angle2)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_arc_negative(context_object->context, x, y, radius, angle1, angle2);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void cairo_curve_to(CairoContext object, float x1, float y1, float x2, float y2, float x3, float y3)
   proto void \Cairo\Context::curveTo(float x1, float y1, float x2, float y2, float x3, float y3)
   Adds a cubic Bézier spline to the path from the current point to position (x3, y3) in user-space coordinates, using (x1, y1) and (x2, y2) as the control points.
   After this call the current point will be (x3, y3). */
PHP_METHOD(Cairo_Context, curveTo)
{
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(6, 6)
        Z_PARAM_DOUBLE(x1)
        Z_PARAM_DOUBLE(y1)
        Z_PARAM_DOUBLE(x2)
        Z_PARAM_DOUBLE(y2)
        Z_PARAM_DOUBLE(x3)
        Z_PARAM_DOUBLE(y3)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_curve_to(context_object->context, x1, y1, x2, y2, x3, y3);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void cairo_line_to(CairoContext object, float x, float y)
   proto void \Cairo\Context::lineTo(float x, float y)
   Adds a line to the path from the current point to position (x, y) in user-space coordinates. After this call the current point will be (x, y). */
PHP_METHOD(Cairo_Context, lineTo)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }
    cairo_line_to(context_object->context, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void cairo_move_to(CairoContext object, float x, float y)
   proto void \Cairo\Context::moveTo(float x, float y)
   Begin a new sub-path. After this call the current point will be (x, y) */
PHP_METHOD(Cairo_Context, moveTo)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_move_to(context_object->context, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::rectangle(float x, float y, float width, float height)
   Adds a closed sub-path rectangle of the given size to the current path at position (x, y) in user-space coordinates. */
PHP_METHOD(Cairo_Context, rectangle)
{
    double x = 0.0, y = 0.0, width = 0.0, height = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_rectangle(context_object->context, x, y, width, height);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::glyphPath(array glyphs)
   Adds closed paths for the glyphs to the current path. */
PHP_METHOD(Cairo_Context, glyphPath)
{
    cairo_context_object *context_object;
    cairo_glyph_t *glyphs_array;
    int num_glyphs = 0;
    zval *php_glyphs = NULL, *pzval;
    HashTable *glyphs_hash = NULL;
    int i = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(php_glyphs)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* Grab the zend hash */
    glyphs_hash = Z_ARRVAL_P(php_glyphs);
    num_glyphs = zend_hash_num_elements(glyphs_hash);
    glyphs_array = ecalloc(num_glyphs, sizeof(cairo_glyph_t));

    /* iterate over the array, each value inside MUST be an instance of CairoGlyph */
    ZEND_HASH_FOREACH_VAL(glyphs_hash, pzval) {
        if (Z_TYPE_P(pzval) != IS_OBJECT || Z_OBJCE_P(pzval) != ce_cairo_glyph) {
            zend_throw_exception(zend_ce_type_error, "Cairo\\Context::glyphPath(): Argument #1 ($glyphs) must be an array of Cairo\\Glyph objects.", 0);
            efree(glyphs_array);
            RETURN_THROWS();
        }
        glyphs_array[i++] = *(cairo_glyph_object_get_glyph(pzval));
    }
    ZEND_HASH_FOREACH_END();

    cairo_glyph_path(context_object->context, glyphs_array, num_glyphs);
    efree(glyphs_array);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::textPath(string text)
   Adds closed paths for text to the current path
   NOTE: text must be UTF-8 charset or results will be unexpected */
PHP_METHOD(Cairo_Context, textPath)
{
    char *text;
    size_t text_len;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_text_path(context_object->context, (const char *)text);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::relCurveTo(float x1, float y1, float x2, float y2, float x3, float y3)
   Adds a cubic Bézier spline to the path from the current point to a point offset from the current point by (x3, y3),
   using points offset by (x1, y1) and (x2, y2) as the control points. */
PHP_METHOD(Cairo_Context, relCurveTo)
{
    double x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 0.0, x3 = 0.0, y3 = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(6, 6)
        Z_PARAM_DOUBLE(x1)
        Z_PARAM_DOUBLE(y1)
        Z_PARAM_DOUBLE(x2)
        Z_PARAM_DOUBLE(y2)
        Z_PARAM_DOUBLE(x3)
        Z_PARAM_DOUBLE(y3)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_rel_curve_to(context_object->context, x1, y1, x2, y2, x3, y3);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::relLineTo(float x, float y)
   Adds a line to the path from the current point to a point that is offset from the current point by (x, y) in user space */
PHP_METHOD(Cairo_Context, relLineTo)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_rel_line_to(context_object->context, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::relMoveTo(float x, float y)
   Begin a new sub-path. After this call the current point will offset by (x, y). */
PHP_METHOD(Cairo_Context, relMoveTo)
{
    double x = 0.0, y = 0.0;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_rel_move_to(context_object->context, x, y);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Context::getPathExtents()
   previous name was pathExtents()
   Computes a bounding box in user-space coordinates covering the points on the current path */
PHP_METHOD(Cairo_Context, getPathExtents)
{
    double x1, y1, x2, y2;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    cairo_path_extents(context_object->context, &x1, &y1, &x2, &y2);
    array_init(return_value);
    add_assoc_double(return_value, "x1", x1);
    add_assoc_double(return_value, "y1", y1);
    add_assoc_double(return_value, "x2", x2);
    add_assoc_double(return_value, "y2", y2);
}
/* }}} */

/*
 * Text items
 */

/* {{{ proto void \Cairo\Context::selectFontFace(string family, CairoFontSlant slant, CairoFontWeight weight)
        Selects a family and style of font from a simplified description as a family name, slant and weight. */
PHP_METHOD(Cairo_Context, selectFontFace)
{
    zval *slant = NULL;
    zval *weight = NULL;
    size_t family_len;
    char *family, *cairo_family;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_STRING(family, family_len)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(slant, ce_cairo_fontslant)
        Z_PARAM_OBJECT_OF_CLASS(weight, ce_cairo_fontweight)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_family = estrdup(family);
    cairo_select_font_face(
        context_object->context,
        family,
        slant
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(slant)))
            : CAIRO_FONT_SLANT_NORMAL,
        weight
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(weight)))
            : CAIRO_FONT_WEIGHT_NORMAL
    );
    efree(cairo_family);
}
/* }}} */

/* {{{ proto void \Cairo\Context::setFontSize(double size)
        Sets the current font matrix to a scale by a factor of size, replacing any font matrix previously
        set with cairo_set_font_size() or cairo_set_font_matrix() */
PHP_METHOD(Cairo_Context, setFontSize)
{
    double size;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(size)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_set_font_size(context_object->context, size);

    /* If there's a font matrix stored, we've just reset it */
    CAIRO_UNREF_AND_UNDEF(context_object->font_matrix)
}
/* }}} */

/* {{{ proto void \Cairo\Context::setFontMatrix(\Cairo\Matrix matrix)
   Sets the current transformation matrix for fonts */
PHP_METHOD(Cairo_Context, setFontMatrix)
{
    zval *matrix_zval = NULL;
    cairo_context_object *context_object;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(matrix_zval, ce_cairo_matrix)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    matrix_object = Z_CAIRO_MATRIX_P(matrix_zval);
    cairo_set_font_matrix(context_object->context, matrix_object->matrix);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If there's already a matrix, then we deref and remove it */
    CAIRO_UNREF_AND_UNDEF(context_object->font_matrix)

    /* we need to be able to get this zval out later, so ref and store */
    ZVAL_COPY(&context_object->font_matrix, matrix_zval);
}
/* }}} */

/* {{{ proto \Cairo\Matrix matrix \Cairo\Context::getFontMatrix()
   Returns the current transformation matrix fot the font*/
PHP_METHOD(Cairo_Context, getFontMatrix)
{
    cairo_context_object *context_object;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* If we have a matrix object stored, grab that zval to use */
    CAIRO_RETURN_IF_REF(context_object->font_matrix);

    /* Otherwise we spawn a new object */
    object_init_ex(return_value, php_cairo_get_matrix_ce());
    matrix_object = Z_CAIRO_MATRIX_P(return_value);
    cairo_get_font_matrix(context_object->context, matrix_object->matrix);
}
/* }}} */

/* {{{ proto void \Cairo\Context::setFontOptions(CairoFontOptions object)
       Sets the font options to be used with the context */
PHP_METHOD(Cairo_Context, setFontOptions)
{
    zval *font_options_zval = NULL;
    cairo_context_object *context_object;
    cairo_font_options_object *font_options_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_options_zval, ce_cairo_fontoptions)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    font_options_object = Z_CAIRO_FONT_OPTIONS_P(font_options_zval);
    cairo_set_font_options(context_object->context, font_options_object->font_options);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If there's already a font options, then we deref and remove it */
    CAIRO_UNREF_AND_UNDEF(context_object->font_options)

    /* we need to be able to get this zval out later, so ref and store */
    ZVAL_COPY(&context_object->font_options, font_options_zval);
}
/* }}} */

/* {{{ proto CairoFontOptions object \Cairo\Context::getFontOptions()
       Retrieves the font options selected by the context.
       If no font options have been selected or set then the default options will be returned. */
PHP_METHOD(Cairo_Context, getFontOptions)
{
    cairo_context_object *context_object;
    cairo_font_options_object *font_options_object;
    cairo_font_options_t *font_options = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* Grab the font options properly */
    cairo_get_font_options(context_object->context, font_options);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If we have a font face object stored, grab that zval to use */
    CAIRO_RETURN_IF_REF(context_object->font_options);

    /* Otherwise we spawn a new object */
    object_init_ex(return_value, php_cairo_get_fontoptions_ce());
    font_options_object = Z_CAIRO_FONT_OPTIONS_P(return_value);
    font_options_object->font_options = font_options;
}
/* }}} */

/* {{{ proto void \Cairo\Context::setFontFace(CairoFontFace object)
       Sets the font face to be used with the context */
PHP_METHOD(Cairo_Context, setFontFace)
{
    zval *font_face_zval = NULL;
    cairo_context_object *context_object;
    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(font_face_zval, ce_cairo_fontface)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    font_face_object = Z_CAIRO_FONT_FACE_P(font_face_zval);
    cairo_set_font_face(context_object->context, font_face_object->font_face);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If there's already a font face, then we deref and remove it */
    CAIRO_UNREF_AND_UNDEF(context_object->font_face)

    /* we need to be able to get this zval out later, so ref and store */
    ZVAL_COPY(&context_object->font_face, font_face_zval);
}
/* }}} */

/* {{{ proto CairoFontFace object \Cairo\Context::getFontFace()
       Retrieves the font face selected by the context.  If no font face has been selected or set then the default face
       will be returned. */
PHP_METHOD(Cairo_Context, getFontFace)
{
    cairo_context_object *context_object;
    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* If we have a font face object stored, grab that zval to use */
    CAIRO_RETURN_IF_REF(context_object->font_face);

    /* Otherwise we spawn a new object */
    object_init_ex(return_value, php_cairo_get_toyfontface_ce());
    font_face_object = Z_CAIRO_FONT_FACE_P(return_value);
    font_face_object->font_face = cairo_get_font_face(context_object->context);
    cairo_font_face_reference(font_face_object->font_face);
}
/* }}} */

/* {{{ proto void \Cairo\Context::setScaledFont(CairoScaledFont object)
       Replaces the current font face, font matrix, and font options in the context with those of the scaled font. */
PHP_METHOD(Cairo_Context, setScaledFont)
{
    zval *scaled_font_zval = NULL;
    cairo_context_object *context_object;
    cairo_scaled_font_object *scaled_font_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(scaled_font_zval, ce_cairo_scaled_font)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    scaled_font_object = Z_CAIRO_SCALED_FONT_P(scaled_font_zval);
    cairo_set_scaled_font(context_object->context, scaled_font_object->scaled_font);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }

    /* If there's already a font face, font matrix, scaled font, and or font options stored, then we deref and remove them */
    CAIRO_UNREF_AND_UNDEF(context_object->font_face)
    CAIRO_UNREF_AND_UNDEF(context_object->font_matrix)
    CAIRO_UNREF_AND_UNDEF(context_object->font_options)
    CAIRO_UNREF_AND_UNDEF(context_object->scaled_font)

    /* if the scaled font has a font_face, matrix, or option zvals stored, move them to context as well and ref again */
    CAIRO_ZVAL_COPY(context_object->font_face, scaled_font_object->font_face);
    CAIRO_ZVAL_COPY(context_object->font_matrix, scaled_font_object->matrix);
    CAIRO_ZVAL_COPY(context_object->font_options, scaled_font_object->font_options);

    /* we need to be able to get this zval out later, so ref and store */
    ZVAL_COPY(&context_object->scaled_font, scaled_font_zval);
}
/* }}} */

/* {{{ proto CairoScaledFont object \Cairo\Context::getScaledFont()
       Retrieves the scaled font face selected by the context.
       If no scaled font has been selected or set then the default face will be returned. */
PHP_METHOD(Cairo_Context, getScaledFont)
{
    cairo_context_object *context_object;
    cairo_scaled_font_object *scaled_font_object;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* If we have a scaled font object stored, grab that zval to use */
    CAIRO_RETURN_IF_REF(context_object->scaled_font);

    /* Otherwise we spawn a new object */
    object_init_ex(return_value, php_cairo_get_scaled_font_ce());
    scaled_font_object = Z_CAIRO_SCALED_FONT_P(return_value);
    scaled_font_object->scaled_font = cairo_get_scaled_font(context_object->context);
    cairo_scaled_font_reference(scaled_font_object->scaled_font);
}
/* }}} */

/* {{{ proto array \Cairo\Context::showText(string text)
   A drawing operator that generates the shape from a string of UTF-8 characters,
   rendered according to the current font_face, font_size (font_matrix), and font_options. */
PHP_METHOD(Cairo_Context, showText)
{
    char *text, *cairo_text;
    size_t text_len;
    cairo_context_object *context_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_text = estrdup(text);
    cairo_show_text(context_object->context, text);
    efree(cairo_text);
}
/* }}} */

/* {{{ proto void \Cairo\Context::showGlyphs(array glyphs)
   A drawing operator that generates the shape from an array of glyphs,
   rendered according to the current font face, font size (font matrix),
   and font options. */
PHP_METHOD(Cairo_Context, showGlyphs)
{
    cairo_context_object *context_object;
    cairo_glyph_t *glyphs_array;
    int num_glyphs = 0;
    zval *php_glyphs = NULL, *pzval;
    HashTable *glyphs_hash = NULL;
    int i = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(php_glyphs)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* Grab the zend hash */
    glyphs_hash = Z_ARRVAL_P(php_glyphs);
    num_glyphs = zend_hash_num_elements(glyphs_hash);
    glyphs_array = ecalloc(num_glyphs, sizeof(cairo_glyph_t));

    /* iterate over the array, each value inside MUST be an instance of CairoGlyph */
    ZEND_HASH_FOREACH_VAL(glyphs_hash, pzval) {
        if (Z_TYPE_P(pzval) != IS_OBJECT || Z_OBJCE_P(pzval) != ce_cairo_glyph) {
            zend_throw_exception(zend_ce_type_error, "Cairo\\Context::showGlyphs(): Argument #1 ($glyphs) must be an array of Cairo\\Glyph objects.", 0);
            efree(glyphs_array);
            RETURN_THROWS();
        }
        glyphs_array[i++] = *(cairo_glyph_object_get_glyph(pzval));
    }
    ZEND_HASH_FOREACH_END();

    cairo_show_glyphs(context_object->context, glyphs_array, num_glyphs);
    efree(glyphs_array);
    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Context::showTextGlyphs(string text, array glyphs, array clusters)
   This operation has rendering effects similar to cairo_show_glyphs() but, if
   the target surface supports it, uses the provided text and cluster mapping to
   embed the text for the glyphs shown in the output. If the target does not
   support the extended attributes, this function acts like the basic
   cairo_show_glyphs() as if it had been passed glyphs and num_glyphs. */
PHP_METHOD(Cairo_Context, showTextGlyphs)
{
    cairo_context_object *context_object;
    char *utf8Str;
    size_t utf8Str_len = 0;
    cairo_glyph_t *glyphs_array;
    int num_glyphs = 0;
    cairo_text_cluster_t *clusters_array;
    int num_clusters = 0;
    zval *php_glyphs = NULL, *pzval;
    zval *php_clusters = NULL;
    long cluster_flags;
    HashTable *glyphs_hash = NULL;
    HashTable *clusters_hash = NULL;
    int i = 0;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_STRING(utf8Str, utf8Str_len)
        Z_PARAM_ARRAY(php_glyphs)
        Z_PARAM_ARRAY(php_clusters)
        Z_PARAM_LONG(cluster_flags)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* Glyphs */
    glyphs_hash = Z_ARRVAL_P(php_glyphs);
    num_glyphs = zend_hash_num_elements(glyphs_hash);
    glyphs_array = ecalloc(num_glyphs, sizeof(cairo_glyph_t));

    /* iterate over the array, each value inside MUST be an instance of CairoGlyph */
    ZEND_HASH_FOREACH_VAL(glyphs_hash, pzval) {
        if (Z_TYPE_P(pzval) != IS_OBJECT || Z_OBJCE_P(pzval) != ce_cairo_glyph) {
            zend_throw_exception(zend_ce_type_error, "Cairo\\Context::showTextGlyphs(): Argument #2 ($glyphs) must be an array of Cairo\\Glyph objects.", 0);
            efree(glyphs_array);
            RETURN_THROWS();
        }
        glyphs_array[i++] = *(cairo_glyph_object_get_glyph(pzval));
    }
    ZEND_HASH_FOREACH_END();

    /* Clusters */
    i = 0;
    clusters_hash = Z_ARRVAL_P(php_clusters);
    num_clusters = zend_hash_num_elements(clusters_hash);
    clusters_array = ecalloc(num_clusters, sizeof(cairo_text_cluster_t));

    /* iterate over the array, each value inside MUST be an instance of Cairo\\TextCluster */
    ZEND_HASH_FOREACH_VAL(clusters_hash, pzval) {
        if (Z_TYPE_P(pzval) != IS_OBJECT || Z_OBJCE_P(pzval) != ce_cairo_text_cluster) {
            zend_throw_exception(zend_ce_type_error, "Cairo\\Context::showTextGlyphs(): Argument #3 ($clusters) must be an array of Cairo\\TextCluster objects.", 0);
            efree(glyphs_array);
            efree(clusters_array);
            RETURN_THROWS();
        }
        clusters_array[i++] = *(cairo_text_cluster_object_get_text_cluster(pzval));
    }
    ZEND_HASH_FOREACH_END();

    cairo_show_text_glyphs(context_object->context, utf8Str, utf8Str_len, glyphs_array, num_glyphs, clusters_array, num_clusters, (cairo_text_cluster_flags_t) cluster_flags);
    efree(glyphs_array);
    efree(clusters_array);

    if (php_cairo_throw_exception(cairo_status(context_object->context))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Context::getFontExtents()
       previous name was fontExtents
       Gets the metrics for a font in an assoc array. */
PHP_METHOD(Cairo_Context, getFontExtents)
{
    cairo_context_object *context_object;
    cairo_font_extents_t extents;

    ZEND_PARSE_PARAMETERS_NONE();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_font_extents(context_object->context, &extents);

    array_init(return_value);
    add_assoc_double(return_value, "ascent", extents.ascent);
    add_assoc_double(return_value, "descent", extents.descent);
    add_assoc_double(return_value, "height", extents.height);
    add_assoc_double(return_value, "max_x_advance", extents.max_x_advance);
    add_assoc_double(return_value, "max_y_advance", extents.max_y_advance);
}
/* }}} */

/* {{{ proto array \Cairo\Context::getTextExtents(string text)
       previous name was textExtents
       Gets the extents for a string of text. */
PHP_METHOD(Cairo_Context, getTextExtents)
{
    char *text, *cairo_text;
    size_t text_len;
    cairo_context_object *context_object;
    cairo_text_extents_t extents;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(text, text_len)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    cairo_text = estrdup(text);
    cairo_text_extents(context_object->context, cairo_text, &extents);
    efree(cairo_text);

    array_init(return_value);
    add_assoc_double(return_value, "x_bearing", extents.x_bearing);
    add_assoc_double(return_value, "y_bearing", extents.y_bearing);
    add_assoc_double(return_value, "width", extents.width);
    add_assoc_double(return_value, "height", extents.height);
    add_assoc_double(return_value, "x_advance", extents.x_advance);
    add_assoc_double(return_value, "y_advance", extents.y_advance);
}
/* }}} */

/* {{{ proto array \Cairo\Context::getGlyphExtents(array glyphs)
       previous name was glyphExtents
       Gets the extents for an array of glyphs. */
PHP_METHOD(Cairo_Context, getGlyphExtents)
{
    cairo_context_object *context_object;
    cairo_glyph_t *glyphs_array;
    int num_glyphs = 0;
    zval *php_glyphs = NULL, *pzval;
    HashTable *glyphs_hash = NULL;
    int i = 0;
    cairo_text_extents_t extents;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ARRAY(php_glyphs)
    ZEND_PARSE_PARAMETERS_END();

    context_object = cairo_context_object_get(getThis());
    if (!context_object) {
        RETURN_THROWS();
    }

    /* Grab the zend hash */
    glyphs_hash = Z_ARRVAL_P(php_glyphs);
    num_glyphs = zend_hash_num_elements(glyphs_hash);
    glyphs_array = ecalloc(num_glyphs, sizeof(cairo_glyph_t));

    /* iterate over the array, each value inside MUST be an instance of CairoGlyph */
    ZEND_HASH_FOREACH_VAL(glyphs_hash, pzval) {
        if (Z_TYPE_P(pzval) != IS_OBJECT || Z_OBJCE_P(pzval) != ce_cairo_glyph) {
            zend_throw_exception(zend_ce_type_error, "Cairo\\Context::getGlyphExtents(): Argument #1 ($glyphs) must be an array of Cairo\\Glyph objects.", 0);
            efree(glyphs_array);
            RETURN_THROWS();
        }
        glyphs_array[i++] = *(cairo_glyph_object_get_glyph(pzval));
    }
    ZEND_HASH_FOREACH_END();

    cairo_glyph_extents(context_object->context, glyphs_array, num_glyphs, &extents);
    efree(glyphs_array);

    array_init(return_value);
    add_assoc_double(return_value, "x_bearing", extents.x_bearing);
    add_assoc_double(return_value, "y_bearing", extents.y_bearing);
    add_assoc_double(return_value, "width", extents.width);
    add_assoc_double(return_value, "height", extents.height);
    add_assoc_double(return_value, "x_advance", extents.x_advance);
    add_assoc_double(return_value, "y_advance", extents.y_advance);
}
/* }}} */


/* ----------------------------------------------------------------
    Cairo\Context Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_context)
{
    memcpy(
        &cairo_context_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(cairo_context_object_handlers)
    );

    /* Context */
    cairo_context_object_handlers.offset = XtOffsetOf(cairo_context_object, std);
    cairo_context_object_handlers.free_obj = cairo_context_free_obj;

    ce_cairo_context = register_class_Cairo_Context();
    ce_cairo_context->create_object = cairo_context_create_object;

    /* FillRule */
    ce_cairo_fillrule = register_class_Cairo_FillRule();

    /* LineCap */
    ce_cairo_linecap = register_class_Cairo_LineCap();

    /* LineJoin */
    ce_cairo_linejoin = register_class_Cairo_LineJoin();

    /* Operator */
    ce_cairo_operator = register_class_Cairo_Operator();

    return SUCCESS;
}
/* }}} */
