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

#if defined(CAIRO_HAS_QUARTZ_FONT)

#include <cairo-quartz.h>
#include <ApplicationServices/ApplicationServices.h>
#include "quartz_font_arginfo.h"

zend_class_entry *ce_cairo_quartzfont;

/* {{{ proto CairoQuartzFontFace CairoQuartzFontFace::createForCgfont(string font_name[, int code, int platform, int script, int language])
   Takes parameters from the user and attempts to create a ctfontref
   If that is successful it creates a new quartz font face from the resulting Id
   http://developer.apple.com/documentation/graphicsimaging/Reference/CGFont/Reference/reference.html#/apple_ref/c/func/CGFontCreateWithFontName
   */
PHP_METHOD(Cairo_FontFace_Quartz, createForCGFont)
{
    CFStringRef font_name;
    char *c_font_name;
    size_t c_font_name_len;
    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(c_font_name, c_font_name_len)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_cairo_quartzfont);
    font_face_object = Z_CAIRO_FONT_FACE_P(return_value);

    /* Create our CFStringRef for the call */
    font_name = CFStringCreateWithCString(NULL, c_font_name, kCFStringEncodingMacRoman);

    /* Try to grab our new font ref */
    font_face_object->quartzref = CGFontCreateWithFontName(font_name);

    /* We are done with our CFStringRef so we free it - the null check is so we don't crash*/
    if (font_name != NULL) {
        CFRelease(font_name);
    }

    /* Now actually do the cairo call */
    font_face_object->font_face = cairo_quartz_font_face_create_for_cgfont(font_face_object->quartzref);
    if (php_cairo_throw_exception(cairo_font_face_status(font_face_object->font_face))) {
        RETURN_THROWS();
    }
}

/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_quartz_font)
{
    ce_cairo_quartzfont = register_class_Cairo_FontFace_Quartz(ce_cairo_fontface);

    return SUCCESS;
}
/* }}} */

#endif
