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


#if defined(CAIRO_HAS_WIN32_FONT) && defined(HAVE_WIN32_FONT)

#include <Windows.h>
#include <Wingdi.h>
#include <cairo/cairo-win32.h>
#include "win32_font_arginfo.h"

/** Not sure why these are not being defined in Wingdi.h
    Must investigate */
#ifndef CLEARTYPE_QUALITY
# define CLEARTYPE_QUALITY 5
#endif
#ifndef CLEARTYPE_NATURAL_QUALITY
# define CLEARTYPE_NATURAL_QUALITY 6
#endif


#define LFONT_FIND_LONG(name, defaultval) \
    if ((tmp = zend_hash_str_find(Z_ARRVAL_P(font_options), #name, sizeof(#name)-1)) != NULL) { \
        if (Z_TYPE_P(tmp) != IS_LONG) \
            zend_error(E_WARNING, "cairo_win32_font_face_create() expects key '" #name "' to be of type long"); \
        else \
            lfont. ## name = Z_LVAL_P(tmp); \
    } \
    else \
        lfont. ## name = defaultval;

/** Same as before but casts return to BYTE */
#define LFONT_FIND_LONG_TO_BYTE(name, defaultval) \
    if ((tmp = zend_hash_str_find(Z_ARRVAL_P(font_options), #name, sizeof(#name)-1)) != NULL) { \
        if (Z_TYPE_P(tmp) != IS_LONG) \
            zend_error(E_WARNING, "cairo_win32_font_face_create() expects key '" #name "' to be of type int"); \
        else \
            lfont. ## name = (BYTE)Z_LVAL_P(tmp); \
    } \
    else \
        lfont. ## name = (BYTE)defaultval;

#define LFONT_FIND_BOOL(name, defaultval) \
    if ((tmp = zend_hash_str_find(Z_ARRVAL_P(font_options), #name, sizeof(#name)-1)) != NULL) { \
        if (Z_TYPE_P(tmp) != IS_TRUE && Z_TYPE_P(tmp) != IS_FALSE) \
            zend_error(E_WARNING, "cairo_win32_font_face_create() expects key '" #name "' to be of type bool"); \
        else \
            lfont. ## name = Z_TYPE_P(tmp) == IS_TRUE ? 1 : 0; \
    } \
    else \
        lfont. ## name = defaultval;

zend_class_entry *ce_cairo_win32font;
/** These classes are containers for constants defined in WinGdi.h, etc. */
static zend_class_entry *ce_cairo_win32fontweight;
static zend_class_entry *ce_cairo_win32fontcharset;
/** output precision constants */
static zend_class_entry *ce_cairo_win32fontoutprec;
/** clip precision constants */
static zend_class_entry *ce_cairo_win32fontclipprec;
static zend_class_entry *ce_cairo_win32fontquality;
static zend_class_entry *ce_cairo_win32fontpitch;
static zend_class_entry *ce_cairo_win32fontfamily;
static zend_object_handlers cairo_win32_font_face_object_handlers;

/* {{{ proto CairoWin32FontFace::__construct([array font_options])
       Creates a new font face for the Win32 backend */
PHP_METHOD(Cairo_FontFace_Win32, __construct)
{
    cairo_font_face_object *font_face;
    LOGFONT     lfont;
    HFONT       hfont;
    zval        *font_options = NULL;
    zval        *tmp;
    // char        *font_name = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_ARRAY_OR_NULL(font_options)
    ZEND_PARSE_PARAMETERS_END();

    if (font_options && Z_TYPE_P(font_options) == IS_ARRAY) {
        /** Find values in font_options array and set them. Otherwise set defaults */
        LFONT_FIND_LONG(lfHeight, 0);
        LFONT_FIND_LONG(lfWidth, 0);
        LFONT_FIND_LONG(lfEscapement, 0);
        LFONT_FIND_LONG(lfOrientation, 0);
        LFONT_FIND_LONG(lfWeight, FW_DONTCARE);
        LFONT_FIND_BOOL(lfItalic, FALSE);
        LFONT_FIND_BOOL(lfUnderline, FALSE);
        LFONT_FIND_BOOL(lfStrikeOut, FALSE);
        LFONT_FIND_LONG_TO_BYTE(lfCharSet, DEFAULT_CHARSET);
        LFONT_FIND_LONG_TO_BYTE(lfOutPrecision, OUT_DEFAULT_PRECIS);
        LFONT_FIND_LONG_TO_BYTE(lfClipPrecision, CLIP_DEFAULT_PRECIS);
        LFONT_FIND_LONG_TO_BYTE(lfQuality, DEFAULT_QUALITY);
        LFONT_FIND_LONG_TO_BYTE(lfPitchAndFamily, FIXED_PITCH | FF_DONTCARE);

        if ((tmp = zend_hash_str_find(Z_ARRVAL_P(font_options), "lfFaceName", sizeof("lfFaceName")-1)) != NULL) {
            if (Z_TYPE_P(tmp) != IS_STRING) {
                zend_error(E_WARNING, "cairo\\FontFace\\Win32::__construct() expects key 'lfFaceName' to be of type string");
            } else {
                lstrcpy(lfont.lfFaceName, Z_STRVAL_P(tmp));
            }
        } else {
            lstrcpy(lfont.lfFaceName, "");
        }
    } else {
        /** Arbitrary defaults */
        lfont.lfHeight = 0;
        lfont.lfWidth = 0;
        lfont.lfEscapement = 0;
        lfont.lfOrientation = 0;
        lfont.lfWeight = FW_DONTCARE;
        lfont.lfItalic = FALSE;
        lfont.lfUnderline = FALSE;
        lfont.lfStrikeOut = FALSE;
        lfont.lfCharSet = DEFAULT_CHARSET;
        lfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
        lfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;
        lfont.lfQuality = DEFAULT_QUALITY;
        lfont.lfPitchAndFamily = FIXED_PITCH | FF_DONTCARE;
        lstrcpy(lfont.lfFaceName, "");
    }

    hfont = CreateFontIndirect(&lfont);

    font_face = Z_CAIRO_FONT_FACE_P(getThis());
    font_face->font_face = cairo_win32_font_face_create_for_hfont(hfont);

    if (php_cairo_throw_exception(cairo_font_face_status(font_face->font_face))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\Win32FontFace Definition and registration
------------------------------------------------------------------*/

PHP_MINIT_FUNCTION(cairo_win32_font)
{
    ce_cairo_win32font = register_class_Cairo_FontFace_Win32(ce_cairo_fontface);

    // enums
    ce_cairo_win32fontweight = register_class_Cairo_FontFace_Win32_FontWeight();
    ce_cairo_win32fontcharset = register_class_Cairo_FontFace_Win32_FontCharset();
    ce_cairo_win32fontoutprec = register_class_Cairo_FontFace_Win32_FontOutputPrecision();
    ce_cairo_win32fontclipprec = register_class_Cairo_FontFace_Win32_FontClipPrecision();
    ce_cairo_win32fontquality = register_class_Cairo_FontFace_Win32_FontQuality();
    ce_cairo_win32fontpitch = register_class_Cairo_FontFace_Win32_FontPitch();
    ce_cairo_win32fontfamily = register_class_Cairo_FontFace_Win32_FontFamily();

    return SUCCESS;
}

#endif /** CAIRO_HAS_WIN32_FONT */
