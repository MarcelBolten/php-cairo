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

zend_class_entry *ce_cairo_fontoptions;
zend_class_entry *ce_cairo_subpixelorder;
zend_class_entry *ce_cairo_hintstyle;
zend_class_entry *ce_cairo_hintmetrics;
zend_class_entry *ce_cairo_antialias;
zend_class_entry *ce_cairo_color_mode;

static zend_object_handlers cairo_font_options_object_handlers;

//typedef struct _cairo_font_options_object {
//    cairo_font_options_t *font_options;
//    zend_object std;
//} cairo_font_options_object;

cairo_font_options_object *cairo_font_options_fetch_object(zend_object *object)
{
    return (cairo_font_options_object *) ((char*)(object) - XtOffsetOf(cairo_font_options_object, std));
}

static inline cairo_font_options_object *cairo_font_options_object_get(zval *zv)
{
    cairo_font_options_object *object = Z_CAIRO_FONT_OPTIONS_P(zv);
    if (object->font_options == NULL) {
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Internal font options object missing in %s, you must call parent::__construct in extended classes",
            ZSTR_VAL(Z_OBJCE_P(zv)->name));
        return NULL;
    }
    return object;
}

/* ----------------------------------------------------------------
    Cairo\FontOptions Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_font_options_free_obj(zend_object *object)
{
    cairo_font_options_object *intern = cairo_font_options_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->font_options) {
        cairo_font_options_destroy(intern->font_options);
        intern->font_options = NULL;
    }

    zend_object_std_dtor(&intern->std);
}

/* {{{ */
static zend_object* cairo_font_options_obj_ctor(zend_class_entry *ce, cairo_font_options_object **intern)
{
    cairo_font_options_object *object = ecalloc(1, sizeof(cairo_font_options_object) + zend_object_properties_size(ce));

    object->font_options = NULL;

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &cairo_font_options_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* cairo_font_options_create_object(zend_class_entry *ce)
{
    cairo_font_options_object *font_options_obj = NULL;
    zend_object *return_value = cairo_font_options_obj_ctor(ce, &font_options_obj);

    object_properties_init(&font_options_obj->std, ce);
    return return_value;
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\FontOptions C API
------------------------------------------------------------------*/

/* {{{ */
zend_class_entry * php_cairo_get_fontoptions_ce()
{
    return ce_cairo_fontoptions;
}
/* }}} */

/* {{{ */
cairo_font_options_t *cairo_font_options_object_get_font_options(zval *zv)
{
    cairo_font_options_object *font_options_object = Z_CAIRO_FONT_OPTIONS_P(zv);
    return font_options_object->font_options;
}
/* }}} */


/* ----------------------------------------------------------------
    Cairo\FontOptions Class API
------------------------------------------------------------------*/
/* {{{ proto void __contruct(void)
       Creates a new \Cairo\FontOptions object with all options initialized to default values.*/
PHP_METHOD(CairoFontOptions, __construct)
{
    cairo_font_options_object *font_options_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = Z_CAIRO_FONT_OPTIONS_P(getThis());
    if (!font_options_object) {
        RETURN_NULL();
    }

    font_options_object->font_options = cairo_font_options_create();
    if (php_cairo_throw_exception(cairo_font_options_status(font_options_object->font_options))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\FontOptions::getStatus(void)
        Checks whether an error has previously occurred for this font options object.*/
PHP_METHOD(CairoFontOptions, getStatus)
{
    cairo_font_options_object *font_options_object;
    zval status_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    status_case = php_enum_from_cairo_c_enum(
        ce_cairo_status,
        cairo_font_options_status(font_options_object->font_options)
    );

    if (Z_TYPE(status_case) == IS_OBJECT) {
        RETURN_ZVAL(&status_case, 1, 1);
    }
}
/* }}} */

ZEND_BEGIN_ARG_INFO(CairoFontOptions_fontoptions_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_OBJ_INFO(0, other, Cairo\\FontOptions, 0)
    //ZEND_ARG_INFO(0, other)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\FontOptions::merge(\Cairo\FontOptions other)
        Merges non-default options from other into options, replacing existing values.*/
PHP_METHOD(CairoFontOptions, merge)
{
    zval *other_zval = NULL;
    cairo_font_options_object *options_object, *other_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(other_zval, ce_cairo_fontoptions)
    ZEND_PARSE_PARAMETERS_END();

    options_object = cairo_font_options_object_get(getThis());
    if (!options_object) {
        RETURN_THROWS();
    }

    other_object = cairo_font_options_object_get(other_zval);
    if (!other_object) {
        RETURN_THROWS();
    }

    cairo_font_options_merge(options_object->font_options, other_object->font_options);
    if (php_cairo_throw_exception(cairo_font_options_status(options_object->font_options))) {
        RETURN_THROWS();
    }
}
/* }}} */


/* {{{ proto long \Cairo\FontOptions::hash(void)
        Compute a hash for the font options object.*/
PHP_METHOD(CairoFontOptions, hash)
{
    cairo_font_options_object *font_options_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    RETURN_LONG(cairo_font_options_hash(font_options_object->font_options));
}
/* }}} */


/* {{{ proto boolean \Cairo\FontOptions::equal(\Cairo\FontOptions other)
        Compares two font options objects for equality.*/
PHP_METHOD(CairoFontOptions, equal)
{
    zval *other_zval = NULL;
    cairo_font_options_object *options_object_a, *options_object_b;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(other_zval, ce_cairo_fontoptions)
    ZEND_PARSE_PARAMETERS_END();

    options_object_a = cairo_font_options_object_get(getThis());
    if (!options_object_a) {
        RETURN_THROWS();
    }

    options_object_b = cairo_font_options_object_get(other_zval);
    if (!options_object_b) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_font_options_equal(options_object_a->font_options, options_object_b->font_options));
}
/* }}} */

ZEND_BEGIN_ARG_INFO(CairoFontOptions_setAntialias_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, antialias)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\FontOptions::setAntialias(\Cairo\Antialias::Good)
        Sets the antialiasing mode for the font options object.*/
PHP_METHOD(CairoFontOptions, setAntialias)
{
    cairo_font_options_object *font_options_object;
    zval *antialias_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(antialias_case, ce_cairo_antialias)
    ZEND_PARSE_PARAMETERS_END();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    cairo_font_options_set_antialias(
        font_options_object->font_options,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(antialias_case)))
    );
    if (php_cairo_throw_exception(cairo_font_options_status(font_options_object->font_options))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\FontOptions::getAntialias(void)
        Gets the antialiasing mode for the font options object.*/
PHP_METHOD(CairoFontOptions, getAntialias)
{
    cairo_font_options_object *font_options_object;
    zval antialias_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    antialias_case = php_enum_from_cairo_c_enum(
        ce_cairo_antialias,
        cairo_font_options_get_antialias(font_options_object->font_options)
    );

    if (Z_TYPE(antialias_case) == IS_OBJECT) {
        RETURN_ZVAL(&antialias_case, 1, 1);
    }
}
/* }}} */


ZEND_BEGIN_ARG_INFO_EX(CairoFontOptions_setSubpixelOrder_args, ZEND_SEND_BY_VAL, 0, 0)
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, subpixel_order, Cairo\\SubpixelOrder, 0, "Cairo\\SubpixelOrder::Default")
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\FontOptions::setSubpixelOrder(void)
        Sets the subpixel order for the font options object.*/
PHP_METHOD(CairoFontOptions, setSubpixelOrder)
{
    cairo_font_options_object *font_options_object;
    zval *subpixel_order_case = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(subpixel_order_case, ce_cairo_subpixelorder)
    ZEND_PARSE_PARAMETERS_END();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    cairo_font_options_set_subpixel_order(
        font_options_object->font_options,
        subpixel_order_case
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(subpixel_order_case)))
            : CAIRO_SUBPIXEL_ORDER_DEFAULT
    );
    if (php_cairo_throw_exception(cairo_font_options_status(font_options_object->font_options))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\FontOptions::getSubpixelOrder(void)
        Gets the subpixel order for the font options object.*/
PHP_METHOD(CairoFontOptions, getSubpixelOrder)
{
    cairo_font_options_object *font_options_object;
    zval subpixel_order_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    subpixel_order_case = php_enum_from_cairo_c_enum(
        ce_cairo_subpixelorder,
        cairo_font_options_get_subpixel_order(font_options_object->font_options)
    );

    if (Z_TYPE(subpixel_order_case) == IS_OBJECT) {
        RETURN_ZVAL(&subpixel_order_case, 1, 1);
    }
}
/* }}} */

ZEND_BEGIN_ARG_INFO_EX(CairoFontOptions_setHintStyle_args, ZEND_SEND_BY_VAL, 0, 0)
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, hint_style, Cairo\\HintStyle, 0, "Cairo\\HintStyle::Default")
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\FontOptions::setHintStyle(void)
        Sets the hint style for font outlines for the font options object.*/
PHP_METHOD(CairoFontOptions, setHintStyle)
{
    cairo_font_options_object *font_options_object;
    zval *hint_style_case = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(hint_style_case, ce_cairo_hintstyle)
    ZEND_PARSE_PARAMETERS_END();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    cairo_font_options_set_hint_style(
        font_options_object->font_options,
        hint_style_case
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(hint_style_case)))
            : CAIRO_HINT_STYLE_DEFAULT
    );
    if (php_cairo_throw_exception(cairo_font_options_status(font_options_object->font_options))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\FontOptions::getHintStyle(void)
        Gets the hint style for font outlines for the font options object.*/
PHP_METHOD(CairoFontOptions, getHintStyle)
{
    cairo_font_options_object *font_options_object;
    zval hint_style_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    hint_style_case = php_enum_from_cairo_c_enum(
        ce_cairo_hintstyle,
        cairo_font_options_get_hint_style(font_options_object->font_options)
    );

    if (Z_TYPE(hint_style_case) == IS_OBJECT) {
        RETURN_ZVAL(&hint_style_case, 1, 1);
    }
}
/* }}} */

ZEND_BEGIN_ARG_INFO_EX(CairoFontOptions_setHintMetrics_args, ZEND_SEND_BY_VAL, 0, 0)
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, hint_metrics, Cairo\\HintMetrics, 0, "Cairo\\HintMetrics::Default")
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\FontOptions::setHintMetrics(void)
        Sets the metrics hinting mode for the font options object.*/
PHP_METHOD(CairoFontOptions, setHintMetrics)
{
    cairo_font_options_object *font_options_object;
    zval *hint_metrics_case = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(hint_metrics_case, ce_cairo_hintmetrics)
    ZEND_PARSE_PARAMETERS_END();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    cairo_font_options_set_hint_metrics(
        font_options_object->font_options,
        hint_metrics_case
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(hint_metrics_case)))
            : CAIRO_HINT_METRICS_DEFAULT
    );
    if (php_cairo_throw_exception(cairo_font_options_status(font_options_object->font_options))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\FontOptions::getHintMetrics(void)
        Gets the metrics hinting mode for the font options object.*/
PHP_METHOD(CairoFontOptions, getHintMetrics)
{
    cairo_font_options_object *font_options_object;
    zval hint_metrics_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    hint_metrics_case = php_enum_from_cairo_c_enum(
        ce_cairo_hintmetrics,
        cairo_font_options_get_hint_metrics(font_options_object->font_options)
    );

    if (Z_TYPE(hint_metrics_case) == IS_OBJECT) {
        RETURN_ZVAL(&hint_metrics_case, 1, 1);
    }
}
/* }}} */


#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)

ZEND_BEGIN_ARG_INFO(CairoFontOptions_setVariations_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, variations)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\FontOptions::setVariations(string variations)
       Sets the OpenType font variations for the font options object.
       Font variations are specified as a string with a format that is similar to the CSS font-variation-settings.
       The string contains a comma-separated list of axis assignments, which each assignment consists of a
       4-character axis name and a value, separated by whitespace and optional equals sign. */
PHP_METHOD(CairoFontOptions, setVariations)
{
    cairo_font_options_object *font_options_object;
    char *variations;
    size_t variations_len;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_STRING(variations, variations_len)
    ZEND_PARSE_PARAMETERS_END();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    cairo_font_options_set_variations(font_options_object->font_options, (const char *)variations);
    if (php_cairo_throw_exception(cairo_font_options_status(font_options_object->font_options))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto string \Cairo\FontOptions::getVariations()
       Returns the font variations for the font options object.
       Gets the OpenType font variations for the font options object.
       The returned string belongs to the options and must not be modified. */
PHP_METHOD(CairoFontOptions, getVariations)
{
    cairo_font_options_object *font_options_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_options_object = cairo_font_options_object_get(getThis());
    if (!font_options_object) {
        RETURN_THROWS();
    }

    RETURN_STRING(cairo_font_options_get_variations(font_options_object->font_options));
}
/* }}} */
#endif


/* ----------------------------------------------------------------
    Cairo\FontOptions Definition and registration
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO(CairoFontOptions_method_no_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ cairo_pattern_methods[] */
static const zend_function_entry cairo_font_options_methods[] = {
    PHP_ME(CairoFontOptions, __construct, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(CairoFontOptions, getStatus, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, merge, CairoFontOptions_fontoptions_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, hash, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, equal, CairoFontOptions_fontoptions_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, setAntialias, CairoFontOptions_setAntialias_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, getAntialias, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, setSubpixelOrder, CairoFontOptions_setSubpixelOrder_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, getSubpixelOrder, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, setHintStyle, CairoFontOptions_setHintStyle_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, getHintStyle, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, setHintMetrics, CairoFontOptions_setHintMetrics_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, getHintMetrics, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    PHP_ME(CairoFontOptions, setVariations, CairoFontOptions_setVariations_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontOptions, getVariations, CairoFontOptions_method_no_args, ZEND_ACC_PUBLIC)
#endif
    ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_font_options)
{
    zend_class_entry fontoptions_ce;

    memcpy(
        &cairo_font_options_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    /* FontOptions */
    cairo_font_options_object_handlers.offset = XtOffsetOf(cairo_font_options_object, std);
    cairo_font_options_object_handlers.free_obj = cairo_font_options_free_obj;

    INIT_NS_CLASS_ENTRY(fontoptions_ce, CAIRO_NAMESPACE, "FontOptions", cairo_font_options_methods);
    fontoptions_ce.create_object = cairo_font_options_create_object;
    ce_cairo_fontoptions = zend_register_internal_class(&fontoptions_ce);


    /* Antialias */
    CAIRO_REGISTER_ENUM_LONG("Antialias", ce_cairo_antialias);

#define CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_antialias, CAIRO_ANTIALIAS)

    CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(DEFAULT);
    CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(NONE);
    CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(GRAY);
    CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(SUBPIXEL);
    CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(FAST);
    CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(GOOD);
    CAIRO_ANTIALIAS_DECLARE_ENUM_CASE(BEST);


    /* SubPixelOrder */
    CAIRO_REGISTER_ENUM_LONG("SubPixelOrder", ce_cairo_subpixelorder);

#define CAIRO_SUBPIXEL_ORDER_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_subpixelorder, CAIRO_SUBPIXEL_ORDER)

    CAIRO_SUBPIXEL_ORDER_DECLARE_ENUM_CASE(DEFAULT);
    CAIRO_SUBPIXEL_ORDER_DECLARE_ENUM_CASE(RGB);
    CAIRO_SUBPIXEL_ORDER_DECLARE_ENUM_CASE(BGR);
    CAIRO_SUBPIXEL_ORDER_DECLARE_ENUM_CASE(VRGB);
    CAIRO_SUBPIXEL_ORDER_DECLARE_ENUM_CASE(VBGR);


    /* HintStyle */
    CAIRO_REGISTER_ENUM_LONG("HintStyle", ce_cairo_hintstyle);

#define CAIRO_HINT_STYLE_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_hintstyle, CAIRO_HINT_STYLE)

    CAIRO_HINT_STYLE_DECLARE_ENUM_CASE(DEFAULT);
    CAIRO_HINT_STYLE_DECLARE_ENUM_CASE(NONE);
    CAIRO_HINT_STYLE_DECLARE_ENUM_CASE(SLIGHT);
    CAIRO_HINT_STYLE_DECLARE_ENUM_CASE(MEDIUM);
    CAIRO_HINT_STYLE_DECLARE_ENUM_CASE(FULL);


    /* HintMetrics */
    CAIRO_REGISTER_ENUM_LONG("HintMetrics", ce_cairo_hintmetrics);

#define CAIRO_HINT_METRICS_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_hintmetrics, CAIRO_HINT_METRICS)

    CAIRO_HINT_METRICS_DECLARE_ENUM_CASE(DEFAULT);
    CAIRO_HINT_METRICS_DECLARE_ENUM_CASE(OFF);
    CAIRO_HINT_METRICS_DECLARE_ENUM_CASE(ON);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    /* HintMetrics */
    CAIRO_REGISTER_ENUM_LONG("ColorMode", ce_cairo_color_mode);

#define CAIRO_COLOR_MODE_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_color_mode, CAIRO_COLOR_MODE)

    CAIRO_COLOR_MODE_DECLARE_ENUM_CASE(DEFAULT);
    CAIRO_COLOR_MODE_DECLARE_ENUM_CASE(NO_COLOR);
    CAIRO_COLOR_MODE_DECLARE_ENUM_CASE(COLOR);
#endif

    return SUCCESS;
}
/* }}} */
