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
#define LFONT_FIND_LONGB(name, defaultval) \
    if ((tmp = zend_hash_str_find(Z_ARRVAL_P(font_options), #name, sizeof(#name)-1)) != NULL) { \
        if (Z_TYPE_P(tmp) != IS_LONG) \
            zend_error(E_WARNING, "cairo_win32_font_face_create() expects key '" #name "' to be of type long"); \
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

/**
 * CairoWin32FontFace::__construct takes 1 optional argument
 */
ZEND_BEGIN_ARG_INFO_EX(CairoWin32FontFace_construct_args, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
    ZEND_ARG_TYPE_INFO(0, font_options, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

/* {{{ proto CairoWin32FontFace::__construct([array font_options])
       Creates a new font face for the Win32 backend */
PHP_METHOD(CairoWin32FontFace, __construct)
{
    cairo_font_face_object *font_face;
    LOGFONT     lfont;
    HFONT       hfont;
    zval        *font_options = NULL;
    zval        *tmp;
    // char        *font_name = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_ARRAY(font_options)
    ZEND_PARSE_PARAMETERS_END();

    if (font_options) {
        /** Find values in font_options array and set them. Otherwise set defaults */
        LFONT_FIND_LONG(lfHeight, 0);
        LFONT_FIND_LONG(lfWidth, 0);
        LFONT_FIND_LONG(lfWeight, FW_DONTCARE);
        LFONT_FIND_LONG(lfOrientation, 0);
        LFONT_FIND_BOOL(lfItalic, FALSE);
        LFONT_FIND_BOOL(lfUnderline, FALSE);
        LFONT_FIND_BOOL(lfStrikeOut, FALSE);
        LFONT_FIND_LONGB(lfCharSet, DEFAULT_CHARSET);
        LFONT_FIND_LONGB(lfOutPrecision, OUT_DEFAULT_PRECIS);
        LFONT_FIND_LONGB(lfClipPrecision, CLIP_DEFAULT_PRECIS);
        LFONT_FIND_LONGB(lfQuality, DEFAULT_QUALITY);
        LFONT_FIND_LONGB(lfPitchAndFamily, FIXED_PITCH | FF_DONTCARE);

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
        lfont.lfOrientation = 0;
        lfont.lfEscapement = 0;
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

const zend_function_entry cairo_win32_font_methods[] = {
    PHP_ME(CairoWin32FontFace, __construct, CairoWin32FontFace_construct_args, \
        ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    ZEND_FE_END
};

PHP_MINIT_FUNCTION(cairo_win32_font)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce,
        ZEND_NS_NAME(CAIRO_NAMESPACE, "FontFace"), "Win32",
        cairo_win32_font_methods);
    ce_cairo_win32font = zend_register_internal_class_ex(&ce, ce_cairo_fontface);

    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("FontFace", ZEND_NS_NAME("Win32", "FontWeight")), ce_cairo_win32fontweight);

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(NORMAL, ce_cairo_win32fontweight, FW_NORMAL);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DONTCARE, ce_cairo_win32fontweight, FW_DONTCARE);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(THIN, ce_cairo_win32fontweight, FW_THIN);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(EXTRALIGHT, ce_cairo_win32fontweight, FW_EXTRALIGHT);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(ULTRALIGHT, ce_cairo_win32fontweight, FW_ULTRALIGHT);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(LIGHT, ce_cairo_win32fontweight, FW_LIGHT);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(REGULAR, ce_cairo_win32fontweight, FW_REGULAR);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(MEDIUM, ce_cairo_win32fontweight, FW_MEDIUM);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(SEMIBOLD, ce_cairo_win32fontweight, FW_SEMIBOLD);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DEMIBOLD, ce_cairo_win32fontweight, FW_DEMIBOLD);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(BOLD, ce_cairo_win32fontweight, FW_BOLD);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(EXTRABOLD, ce_cairo_win32fontweight, FW_EXTRABOLD);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(ULTRABOLD, ce_cairo_win32fontweight, FW_ULTRABOLD);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(HEAVY, ce_cairo_win32fontweight, FW_HEAVY);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(BLACK, ce_cairo_win32fontweight, FW_BLACK);


    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("FontFace", ZEND_NS_NAME("Win32", "FontCharset")), ce_cairo_win32fontcharset);

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(ANSI, ce_cairo_win32fontcharset, ANSI_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(BALTIC, ce_cairo_win32fontcharset, BALTIC_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(CHINESEBIG5, ce_cairo_win32fontcharset, CHINESEBIG5_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DEFAULT, ce_cairo_win32fontcharset, DEFAULT_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(EASTEUROPE, ce_cairo_win32fontcharset, EASTEUROPE_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(GB2312, ce_cairo_win32fontcharset, GB2312_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(GREEK, ce_cairo_win32fontcharset, GREEK_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(HANGUL, ce_cairo_win32fontcharset, HANGUL_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(MAC, ce_cairo_win32fontcharset, MAC_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(OEM, ce_cairo_win32fontcharset, OEM_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(RUSSIAN, ce_cairo_win32fontcharset, RUSSIAN_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(SHIFTJIS, ce_cairo_win32fontcharset, SHIFTJIS_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(SYMBOL, ce_cairo_win32fontcharset, SYMBOL_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(TURKISH, ce_cairo_win32fontcharset, TURKISH_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(VIETNAMESE, ce_cairo_win32fontcharset, VIETNAMESE_CHARSET);
#if (WINVER >= 0x0400)
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(JOHAB, ce_cairo_win32fontcharset, JOHAB_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(ARABIC, ce_cairo_win32fontcharset, ARABIC_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(HEBREW, ce_cairo_win32fontcharset, HEBREW_CHARSET);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(THAI, ce_cairo_win32fontcharset, THAI_CHARSET);
#endif /** WINVER */


    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("FontFace", ZEND_NS_NAME("Win32", "FontOutputPrecision")), ce_cairo_win32fontoutprec);

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(CHARACTER, ce_cairo_win32fontoutprec, OUT_CHARACTER_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DEFAULT, ce_cairo_win32fontoutprec, OUT_DEFAULT_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DEVICE, ce_cairo_win32fontoutprec, OUT_DEVICE_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(OUTLINE, ce_cairo_win32fontoutprec, OUT_OUTLINE_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(PS_ONLY, ce_cairo_win32fontoutprec, OUT_PS_ONLY_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(RASTER, ce_cairo_win32fontoutprec, OUT_RASTER_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(STRING, ce_cairo_win32fontoutprec, OUT_STRING_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(STROKE, ce_cairo_win32fontoutprec, OUT_STROKE_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(TT_ONLY, ce_cairo_win32fontoutprec, OUT_TT_ONLY_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(TT, ce_cairo_win32fontoutprec, OUT_TT_PRECIS);


    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("FontFace", ZEND_NS_NAME("Win32", "FontClipPrecision")), ce_cairo_win32fontclipprec);

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(CHARACTER, ce_cairo_win32fontclipprec, CLIP_CHARACTER_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DEFAULT, ce_cairo_win32fontclipprec, CLIP_DEFAULT_PRECIS);

#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DFA_DISABLE, ce_cairo_win32fontclipprec, CLIP_DFA_DISABLE);
#endif /** _WIN32_WINNT >= _WIN32_WINNT_LONGHORN */

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(EMBEDDED, ce_cairo_win32fontclipprec, CLIP_EMBEDDED);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(LH_ANGLES, ce_cairo_win32fontclipprec, CLIP_LH_ANGLES);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(MASK, ce_cairo_win32fontclipprec, CLIP_MASK);

#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
    /* https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-logfontw */
    /* CLIP_DFA_OVERRIDE: Turns off font association for the font. This is identical to CLIP_DFA_DISABLE, but it can have problems in some situations; the recommended flag to use is CLIP_DFA_DISABLE. */
    /* CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DFA_OVERRIDE, ce_cairo_win32fontclipprec, CLIP_DFA_OVERRIDE); */
#endif /** _WIN32_WINNT >= _WIN32_WINNT_LONGHORN */

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(STROKE, ce_cairo_win32fontclipprec, CLIP_STROKE_PRECIS);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(TT_ALWAYS, ce_cairo_win32fontclipprec, CLIP_TT_ALWAYS);


    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("FontFace", ZEND_NS_NAME("Win32", "FontQuality")), ce_cairo_win32fontquality);

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(ANTIALIASED, ce_cairo_win32fontquality, ANTIALIASED_QUALITY);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(CLEARTYPE, ce_cairo_win32fontquality, CLEARTYPE_QUALITY);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DEFAULT, ce_cairo_win32fontquality, DEFAULT_QUALITY);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DRAFT, ce_cairo_win32fontquality, DRAFT_QUALITY);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(NONANTIALIASED, ce_cairo_win32fontquality, NONANTIALIASED_QUALITY);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(PROOF, ce_cairo_win32fontquality, PROOF_QUALITY);


    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("FontFace", ZEND_NS_NAME("Win32", "FontPitch")), ce_cairo_win32fontpitch);

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DEFAULT, ce_cairo_win32fontpitch, DEFAULT_PITCH);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(FIXED, ce_cairo_win32fontpitch, FIXED_PITCH);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(VARIABLE, ce_cairo_win32fontpitch, VARIABLE_PITCH);


    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("FontFace", ZEND_NS_NAME("Win32", "FontFamily")), ce_cairo_win32fontfamily);

    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DECORATIVE, ce_cairo_win32fontfamily, FF_DECORATIVE);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(DONTCARE, ce_cairo_win32fontfamily, FF_DONTCARE);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(MODERN, ce_cairo_win32fontfamily, FF_MODERN);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(ROMAN, ce_cairo_win32fontfamily, FF_ROMAN);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(SCRIPT, ce_cairo_win32fontfamily, FF_SCRIPT);
    CAIRO_WIN_GENERIC_LONG_ENUM_CASE(SWISS, ce_cairo_win32fontfamily, FF_SWISS);

    return SUCCESS;
}

#endif /** CAIRO_HAS_WIN32_FONT */
