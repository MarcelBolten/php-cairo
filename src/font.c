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


zend_class_entry *ce_cairo_fontslant;
zend_class_entry *ce_cairo_fontweight;
zend_class_entry *ce_cairo_toyfontface;

/* ----------------------------------------------------------------
    \Cairo\FontFace\Toy Class API
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO_EX(CairoToyFontFace___construct_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
    ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, slant, Cairo\\FontSlant, 0, "Cairo\\FontSlant::NORMAL")
    ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, weight, Cairo\\FontWeight, 0, "Cairo\\FontWeight::NORMAL")
ZEND_END_ARG_INFO()

/* {{{ proto void __construct(string family, \Cairo\FontSlant slant, \Cairo\FontWeight weight)
       Creates a font face from a triplet of family, slant, and weight. These font
       faces are used in implementation of the the "toy" font API.*/
PHP_METHOD(CairoToyFontFace, __construct)
{
    char *family;
    size_t family_len;
    zval *slant = NULL;
    zval *weight = NULL;
    cairo_font_face_object *fontface_object;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_STRING(family, family_len)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(slant, ce_cairo_fontslant)
        Z_PARAM_OBJECT_OF_CLASS(weight, ce_cairo_fontweight)
    ZEND_PARSE_PARAMETERS_END();

    fontface_object = Z_CAIRO_FONT_FACE_P(getThis());
    if (!fontface_object)
    {
        return;
    }

    fontface_object->font_face = cairo_toy_font_face_create(
        (const char *)family,
        slant
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(slant)))
            : CAIRO_FONT_SLANT_NORMAL,
        weight
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(weight)))
            : CAIRO_FONT_WEIGHT_NORMAL
    );
    php_cairo_throw_exception(cairo_font_face_status(fontface_object->font_face));
}

/* {{{ proto string \Cairo\FontFace\Toy::getFamily()
        Gets the family name of a toy font. */
PHP_METHOD(CairoToyFontFace, getFamily)
{
    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = Z_CAIRO_FONT_FACE_P(getThis());
    if (!font_face_object)
    {
        return;
    }

    RETURN_STRING(cairo_toy_font_face_get_family(font_face_object->font_face));
}
/* }}} */

/* {{{ proto \Cairo\FontSlant \Cairo\FontFace\Toy::getSlant()
        Gets the slant of a toy font. */
PHP_METHOD(CairoToyFontFace, getSlant)
{
    cairo_font_face_object *font_face_object;
    zval slant_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = Z_CAIRO_FONT_FACE_P(getThis());
    if (!font_face_object)
    {
        return;
    }

    slant_case = php_enum_from_cairo_c_enum(
        ce_cairo_fontslant,
        cairo_toy_font_face_get_slant(font_face_object->font_face)
    );

    if (Z_TYPE(slant_case) == IS_OBJECT) {
        RETURN_ZVAL(&slant_case, 1, 1);
    } else {
        RETURN_NULL();
    }
}
/* }}} */

/* {{{ proto long \Cairo\FontFace\Toy::getWeight()
        Gets the weight of a toy font. */
PHP_METHOD(CairoToyFontFace, getWeight)
{
    cairo_font_face_object *font_face_object;
    zval weight_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = Z_CAIRO_FONT_FACE_P(getThis());
    if (!font_face_object)
    {
        return;
    }

    weight_case = php_enum_from_cairo_c_enum(
        ce_cairo_fontweight,
        cairo_toy_font_face_get_weight(font_face_object->font_face)
    );

    if (Z_TYPE(weight_case) == IS_OBJECT) {
        RETURN_ZVAL(&weight_case, 1, 1);
    } else {
        RETURN_NULL();
    }
}
/* }}} */

/* ----------------------------------------------------------------
    \Cairo\FontFace\Toy Definition and registration
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO(CairoToyFontFace_method_no_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ cairo_toy_font_face_methods */
static const zend_function_entry cairo_toy_font_face_methods[] = {
    PHP_ME(CairoToyFontFace, __construct, CairoToyFontFace___construct_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(CairoToyFontFace, getFamily, CairoToyFontFace_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoToyFontFace, getSlant, CairoToyFontFace_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoToyFontFace, getWeight, CairoToyFontFace_method_no_args, ZEND_ACC_PUBLIC)
    ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_font)
{
    zend_class_entry toyfont_ce;

    INIT_NS_CLASS_ENTRY(toyfont_ce, CAIRO_NAMESPACE, ZEND_NS_NAME("FontFace", "Toy"), cairo_toy_font_face_methods);
    ce_cairo_toyfontface = zend_register_internal_class_ex(&toyfont_ce, ce_cairo_fontface);
    ce_cairo_toyfontface->create_object = cairo_font_face_create_object;

    /* FontSlant */
    CAIRO_REGISTER_ENUM_LONG("FontSlant", ce_cairo_fontslant);

#define CAIRO_FONT_SLANT_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_fontslant, CAIRO_FONT_SLANT)

    CAIRO_FONT_SLANT_DECLARE_ENUM_CASE(NORMAL);
    CAIRO_FONT_SLANT_DECLARE_ENUM_CASE(ITALIC);
    CAIRO_FONT_SLANT_DECLARE_ENUM_CASE(OBLIQUE);

    /* FontWeight */
    CAIRO_REGISTER_ENUM_LONG("FontWeight", ce_cairo_fontweight);

#define CAIRO_FONTWEIGHT_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_fontweight, CAIRO_FONT_WEIGHT)

    CAIRO_FONTWEIGHT_DECLARE_ENUM_CASE(NORMAL);
    CAIRO_FONTWEIGHT_DECLARE_ENUM_CASE(BOLD);
}
/* }}} */
