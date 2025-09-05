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
#include "font_arginfo.h"


zend_class_entry *ce_cairo_fontslant;
zend_class_entry *ce_cairo_fontweight;
zend_class_entry *ce_cairo_toyfontface;

/* ----------------------------------------------------------------
    \Cairo\FontFace\Toy Class API
------------------------------------------------------------------*/

/* {{{ proto void __construct(string family, \Cairo\FontSlant slant, \Cairo\FontWeight weight)
       Creates a font face from a triplet of family, slant, and weight. These font
       faces are used in implementation of the the "toy" font API.*/
PHP_METHOD(Cairo_FontFace_Toy, __construct)
{
    char *family;
    size_t family_len;
    zval *slant = NULL;
    zval *weight = NULL;
    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_START(1, 3)
        Z_PARAM_STRING(family, family_len)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(slant, ce_cairo_fontslant)
        Z_PARAM_OBJECT_OF_CLASS(weight, ce_cairo_fontweight)
    ZEND_PARSE_PARAMETERS_END();

    font_face_object = Z_CAIRO_FONT_FACE_P(getThis());
    if (!font_face_object) {
        RETURN_NULL();
    }

    font_face_object->font_face = cairo_toy_font_face_create(
        (const char *)family,
        slant
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(slant)))
            : CAIRO_FONT_SLANT_NORMAL,
        weight
            ? Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(weight)))
            : CAIRO_FONT_WEIGHT_NORMAL
    );

    if (php_cairo_throw_exception(cairo_font_face_status(font_face_object->font_face))) {
        RETURN_THROWS();
    }
}

/* {{{ proto string \Cairo\FontFace\Toy::getFamily()
        Gets the family name of a toy font. */
PHP_METHOD(Cairo_FontFace_Toy, getFamily)
{
    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = cairo_font_face_object_get(getThis());
    if (!font_face_object) {
        RETURN_THROWS();
    }

    RETURN_STRING(cairo_toy_font_face_get_family(font_face_object->font_face));
}
/* }}} */

/* {{{ proto \Cairo\FontSlant \Cairo\FontFace\Toy::getSlant()
        Gets the slant of a toy font. */
PHP_METHOD(Cairo_FontFace_Toy, getSlant)
{
    cairo_font_face_object *font_face_object;
    zval slant_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = cairo_font_face_object_get(getThis());
    if (!font_face_object) {
        RETURN_THROWS();
    }

    slant_case = php_enum_from_cairo_c_enum(
        ce_cairo_fontslant,
        cairo_toy_font_face_get_slant(font_face_object->font_face)
    );

    if (Z_TYPE(slant_case) == IS_OBJECT) {
        RETURN_ZVAL(&slant_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto long \Cairo\FontFace\Toy::getWeight()
        Gets the weight of a toy font. */
PHP_METHOD(Cairo_FontFace_Toy, getWeight)
{
    cairo_font_face_object *font_face_object;
    zval weight_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = cairo_font_face_object_get(getThis());
    if (!font_face_object) {
        RETURN_THROWS();
    }

    weight_case = php_enum_from_cairo_c_enum(
        ce_cairo_fontweight,
        cairo_toy_font_face_get_weight(font_face_object->font_face)
    );

    if (Z_TYPE(weight_case) == IS_OBJECT) {
        RETURN_ZVAL(&weight_case, 1, 1);
    }
}
/* }}} */

/* ----------------------------------------------------------------
    \Cairo\FontFace\Toy Definition and registration
------------------------------------------------------------------*/


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_font)
{
    ce_cairo_toyfontface = register_class_Cairo_FontFace_Toy(ce_cairo_fontface);
    ce_cairo_toyfontface->create_object = cairo_font_face_create_object;

    /* FontSlant */
    ce_cairo_fontslant = register_class_Cairo_FontSlant();

    /* FontWeight */
    ce_cairo_fontweight = register_class_Cairo_FontWeight();

    return SUCCESS;
}
/* }}} */
