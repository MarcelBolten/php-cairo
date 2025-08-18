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

zend_class_entry *ce_cairo_quartzfont;
zend_class_entry *ce_cairo_quartzatsufontnamecode;
zend_class_entry *ce_cairo_quartzatsufontnameplatform;
zend_class_entry *ce_cairo_quartzatsufontnamescript;
zend_class_entry *ce_cairo_quartzatsufontnamelanguage;

/* {{{ proto CairoQuartzFontFace CairoQuartzFontFace::createForAtsuFontId(string font_name[, int code, int platform, int script, int language])
   Takes parameters from the user an attempts to look up an atsu font id
   If that is successful it creates a new quartz font face from the resulting Id
   http://developer.apple.com/documentation/Carbon/Reference/ATSUI_Reference/Reference/reference.html#/apple_ref/c/func/ATSUFindFontFromName
   https://developer.apple.com/documentation/applicationservices/applicationservices_functions
   */
PHP_METHOD(CairoQuartzFontFace, createForAtsuFontId)
{
    ATSUFontID fontID;
    // OSStatus error;
    char *font_name;
    size_t font_name_length;
    zval code; // = kFontFullName;
    zval platform; // = kFontNoPlatformCode;
    zval script; // = kFontRomanScript;
    zval language; // = kFontNoLanguageCode;

    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_START(1, 5)
        Z_PARAM_STRING(font_name, font_name_length)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(code, ce_cairo_quartzatsufontnamecode)
        Z_PARAM_OBJECT_OF_CLASS(platform, ce_cairo_quartzatsufontnameplatform)
        Z_PARAM_OBJECT_OF_CLASS(script, ce_cairo_quartzatsufontnamescript)
        Z_PARAM_OBJECT_OF_CLASS(language, ce_cairo_quartzatsufontnamelanguage)
    ZEND_PARSE_PARAMETERS_END();

    ATSUFindFontFromName(
        (const char *)font_name,
        (int)font_name_length,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(code))),
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(platform))),
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(script))),
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(language))),
        &fontID
    );

    if (fontID == kATSUInvalidFontID)
    {
        php_cairo_throw_exception("Atsu Font could not be retrieved");
        return;
    }

    font_face_object = Z_CAIRO_FONT_FACE_P(getThis());

    if (!font_face_object)
    {
        return;
    }

    object_init_ex(return_value, ce_cairo_quartzfont);

    font_face_object->font_face = cairo_quartz_font_face_create_for_atsu_font_id(fontID);
    php_cairo_throw_exception(cairo_font_face_status(font_face_object->font_face));
}

/* {{{ proto CairoQuartzFontFace CairoQuartzFontFace::createForCgfont(string font_name[, int code, int platform, int script, int language])
   Takes parameters from the user and attempts to create a ctfontref
   If that is successful it creates a new quartz font face from the resulting Id
   http://developer.apple.com/documentation/graphicsimaging/Reference/CGFont/Reference/reference.html#/apple_ref/c/func/CGFontCreateWithFontName
   */
PHP_METHOD(CairoQuartzFontFace, createForCgfont)
{
    CFStringRef font_name;
    char *c_font_name;
    size_t c_font_name_len;
    cairo_font_face_object *font_face_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(c_font_name, c_font_name_len)
    ZEND_PARSE_PARAMETERS_END();

    font_face_object = Z_CAIRO_FONT_FACE_P(getThis());

    if (!font_face_object)
    {
        return;
    }

    object_init_ex(return_value, ce_cairo_quartzfont);

    /* Create our CFStringRef for the call */
    font_name = CFStringCreateWithCString(NULL, c_font_name, kCFStringEncodingMacRoman);

    /* Try to grab our new font ref */
    font_face_object->quartzref = CGFontCreateWithFontName(font_name);

    /* We are done with our CFStringRef so we free it - the null check is so we don't crash*/
    if (font_name != NULL)
        CFRelease(font_name);

    /* Now actually do the cairo call */
    font_face_object->font_face = cairo_quartz_font_face_create_for_cgfont(font_face_object->quartzref);
    php_cairo_throw_exception(cairo_font_face_status(font_face_object->font_face));
}

/* }}} */

/* {{{ cairo_quartz_font_methods[] */
const zend_function_entry cairo_quartz_font_methods[] = {
    PHP_ME(CairoQuartzFontFace, createForCgfont, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(CairoQuartzFontFace, createForAtsuFontId, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_quartz_font)
{
    zend_class_entry quartz_font_face_ce;

    INIT_NS_CLASS_ENTRY(quartz_font_face_ce, CAIRO_NAMESPACE, ZEND_NS_NAME("FontFace", "Quartz"), cairo_quartz_font_methods);
    ce_cairo_quartzfont = zend_register_internal_class_ex(&quartz_font_face_ce, ce_cairo_fontface);

    /* FontNameCode */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Quartz", "AtsuFontNameCode"), ce_cairo_quartzatsufontnamecode);

#define CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(name) \
    zval enum_case_ ## kFont ## _ ## name ## _value; \
    ZVAL_LONG(&enum_case_ ## kFont ## _ ## name ## _value, kFont ## name); \
    zend_enum_add_case_cstr(ce_cairo_quartzatsufontnamecode, #name, &enum_case_ ## kFont ## _ ## name ## _value);

    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(CopyrightName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(FamilyName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(StyleName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(UniqueName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(FullName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(VersionName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(PostscriptName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(TrademarkName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(ManufacturerName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(DesignerName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(DescriptionName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(VendorURLName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(DesignerURLName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(LicenseDescriptionName);
    CAIRO_QUARTZ_FONT_CODE_DECLARE_ENUM_CASE(LicenseInfoURLName);

    /* PlatformCode */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Quartz", "AtsuFontPlatformCode"), ce_cairo_quartzatsufontnamescript);

#define CAIRO_QUARTZ_FONT_PLATFORM_DECLARE_ENUM_CASE(name) \
    zval enum_case_ ## kFont ## _ ## name ## _value; \
    ZVAL_LONG(&enum_case_ ## kFont ## _ ## name ## _value, kFont ## name); \
    zend_enum_add_case_cstr(ce_cairo_quartzatsufontnameplatform, #name, &enum_case_ ## kFont ## _ ## name ## _value);

    CAIRO_QUARTZ_FONT_PLATFORM_DECLARE_ENUM_CASE(UnicodePlatform);
    CAIRO_QUARTZ_FONT_PLATFORM_DECLARE_ENUM_CASE(MacintoshPlatform);
    CAIRO_QUARTZ_FONT_PLATFORM_DECLARE_ENUM_CASE(ReservedPlatform);
    CAIRO_QUARTZ_FONT_PLATFORM_DECLARE_ENUM_CASE(MicrosoftPlatform);
    CAIRO_QUARTZ_FONT_PLATFORM_DECLARE_ENUM_CASE(CustomPlatform);

    /* ScriptCode */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Quartz", "AtsuFontScriptCode"), ce_cairo_quartzatsufontnamescript);

#define CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(name) \
    zval enum_case_ ## kFont ## _ ## name ## _value; \
    ZVAL_LONG(&enum_case_ ## kFont ## _ ## name ## _value, kFont ## name); \
    zend_enum_add_case_cstr(ce_cairo_quartzatsufontnamescript, #name, &enum_case_ ## kFont ## _ ## name ## _value);

    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(RomanScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(JapaneseScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(TraditionalChineseScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(ChineseScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(KoreanScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(ArabicScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(HebrewScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(GreekScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(CyrillicScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(Russian);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(RSymbolScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(DevanagariScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(GurmukhiScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(GujaratiScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(OriyaScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(BengaliScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(TamilScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(TeluguScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(KannadaScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(MalayalamScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(SinhaleseScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(BurmeseScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(KhmerScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(ThaiScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(LaotianScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(GeorgianScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(ArmenianScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(SimpleChineseScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(TibetanScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(MongolianScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(GeezScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(EthiopicScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(AmharicScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(SlavicScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(EastEuropeanRomanScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(VietnameseScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(ExtendedArabicScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(SindhiScript);
    CAIRO_QUARTZ_FONT_SCRIPT_DECLARE_ENUM_CASE(UninterpretedScript);

    /* LanguageCode */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Quartz", "AtsuFontLanguageCode"), ce_cairo_quartzatsufontnamelanguage);

#define CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(name) \
    zval enum_case_ ## kFont ## _ ## name ## _value; \
    ZVAL_LONG(&enum_case_ ## kFont ## _ ## name ## _value, kFont ## name); \
    zend_enum_add_case_cstr(ce_cairo_quartzatsufontnamelanguage, #name, &enum_case_ ## kFont ## _ ## name ## _value);

    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(EnglishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(FrenchLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(GermanLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(ItalianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(DutchLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SwedishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SpanishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(DanishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(PortugueseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(NorwegianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(HebrewLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(JapaneseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(ArabicLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(FinnishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(GreekLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(IcelandicLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MalteseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TurkishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(CroatianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TradChineseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(UrduLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(HindiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(ThaiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(KoreanLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(LithuanianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(PolishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(HungarianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(EstonianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(LettishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(LatvianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SaamiskLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(LappishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(FaeroeseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(FarsiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(PersianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(RussianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SimpChineseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(FlemishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(IrishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(AlbanianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(RomanianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(CzechLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SlovakLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SlovenianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(YiddishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SerbianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MacedonianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(BulgarianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(UkrainianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(ByelorussianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(UzbekLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(KazakhLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(AzerbaijaniLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(AzerbaijanArLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(ArmenianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(GeorgianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MoldavianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(KirghizLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TajikiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TurkmenLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MongolianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MongolianCyrLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(PashtoLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(KurdishLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(KashmiriLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SindhiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TibetanLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(NepaliLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SanskritLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MarathiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(BengaliLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(AssameseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(GujaratiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(PunjabiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(OriyaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MalayalamLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(KannadaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TamilLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TeluguLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SinhaleseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(BurmeseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(KhmerLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(LaoLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(VietnameseLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(IndonesianLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TagalogLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MalayRomanLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MalayArabicLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(AmharicLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TigrinyaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(GallaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(OromoLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SomaliLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SwahiliLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(RuandaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(RundiLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(ChewaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(MalagasyLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(EsperantoLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(WelshLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(BasqueLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(CatalanLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(LatinLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(QuechuaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(GuaraniLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(AymaraLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(TatarLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(UighurLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(DzongkhaLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(JavaneseRomLanguage);
    CAIRO_QUARTZ_FONT_LANGUAGE_DECLARE_ENUM_CASE(SundaneseRomLanguage);

    /* TODO: register these too - ugh
enum {
  kFontRomanScript              = 0,
  kFontJapaneseScript           = 1,
  kFontTraditionalChineseScript = 2,
  kFontChineseScript            = kFontTraditionalChineseScript,
  kFontKoreanScript             = 3,
  kFontArabicScript             = 4,
  kFontHebrewScript             = 5,
  kFontGreekScript              = 6,
  kFontCyrillicScript           = 7,
  kFontRussian                  = kFontCyrillicScript,
  kFontRSymbolScript            = 8,
  kFontDevanagariScript         = 9,
  kFontGurmukhiScript           = 10,
  kFontGujaratiScript           = 11,
  kFontOriyaScript              = 12,
  kFontBengaliScript            = 13,
  kFontTamilScript              = 14,
  kFontTeluguScript             = 15,
  kFontKannadaScript            = 16,
  kFontMalayalamScript          = 17,
  kFontSinhaleseScript          = 18,
  kFontBurmeseScript            = 19,
  kFontKhmerScript              = 20,
  kFontThaiScript               = 21,
  kFontLaotianScript            = 22,
  kFontGeorgianScript           = 23,
  kFontArmenianScript           = 24,
  kFontSimpleChineseScript      = 25,
  kFontTibetanScript            = 26,
  kFontMongolianScript          = 27,
  kFontGeezScript               = 28,
  kFontEthiopicScript           = kFontGeezScript,
  kFontAmharicScript            = kFontGeezScript,
  kFontSlavicScript             = 29,
  kFontEastEuropeanRomanScript  = kFontSlavicScript,
  kFontVietnameseScript         = 30,
  kFontExtendedArabicScript     = 31,
  kFontSindhiScript             = kFontExtendedArabicScript,
  kFontUninterpretedScript      = 32
};

enum {
  kFontEnglishLanguage          = 0,
  kFontFrenchLanguage           = 1,
  kFontGermanLanguage           = 2,
  kFontItalianLanguage          = 3,
  kFontDutchLanguage            = 4,
  kFontSwedishLanguage          = 5,
  kFontSpanishLanguage          = 6,
  kFontDanishLanguage           = 7,
  kFontPortugueseLanguage       = 8,
  kFontNorwegianLanguage        = 9,
  kFontHebrewLanguage           = 10,
  kFontJapaneseLanguage         = 11,
  kFontArabicLanguage           = 12,
  kFontFinnishLanguage          = 13,
  kFontGreekLanguage            = 14,
  kFontIcelandicLanguage        = 15,
  kFontMalteseLanguage          = 16,
  kFontTurkishLanguage          = 17,
  kFontCroatianLanguage         = 18,
  kFontTradChineseLanguage      = 19,
  kFontUrduLanguage             = 20,
  kFontHindiLanguage            = 21,
  kFontThaiLanguage             = 22,
  kFontKoreanLanguage           = 23,
  kFontLithuanianLanguage       = 24,
  kFontPolishLanguage           = 25,
  kFontHungarianLanguage        = 26,
  kFontEstonianLanguage         = 27,
  kFontLettishLanguage          = 28,
  kFontLatvianLanguage          = kFontLettishLanguage,
  kFontSaamiskLanguage          = 29,
  kFontLappishLanguage          = kFontSaamiskLanguage,
  kFontFaeroeseLanguage         = 30,
  kFontFarsiLanguage            = 31,
  kFontPersianLanguage          = kFontFarsiLanguage,
  kFontRussianLanguage          = 32,
  kFontSimpChineseLanguage      = 33,
  kFontFlemishLanguage          = 34,
  kFontIrishLanguage            = 35,
  kFontAlbanianLanguage         = 36,
  kFontRomanianLanguage         = 37,
  kFontCzechLanguage            = 38,
  kFontSlovakLanguage           = 39,
  kFontSlovenianLanguage        = 40,
  kFontYiddishLanguage          = 41,
  kFontSerbianLanguage          = 42,
  kFontMacedonianLanguage       = 43,
  kFontBulgarianLanguage        = 44,
  kFontUkrainianLanguage        = 45,
  kFontByelorussianLanguage     = 46,
  kFontUzbekLanguage            = 47,
  kFontKazakhLanguage           = 48,
  kFontAzerbaijaniLanguage      = 49,
  kFontAzerbaijanArLanguage     = 50,
  kFontArmenianLanguage         = 51,
  kFontGeorgianLanguage         = 52,
  kFontMoldavianLanguage        = 53,
  kFontKirghizLanguage          = 54,
  kFontTajikiLanguage           = 55,
  kFontTurkmenLanguage          = 56,
  kFontMongolianLanguage        = 57,
  kFontMongolianCyrLanguage     = 58,
  kFontPashtoLanguage           = 59,
  kFontKurdishLanguage          = 60,
  kFontKashmiriLanguage         = 61,
  kFontSindhiLanguage           = 62,
  kFontTibetanLanguage          = 63,
  kFontNepaliLanguage           = 64,
  kFontSanskritLanguage         = 65,
  kFontMarathiLanguage          = 66,
  kFontBengaliLanguage          = 67,
  kFontAssameseLanguage         = 68,
  kFontGujaratiLanguage         = 69,
  kFontPunjabiLanguage          = 70,
  kFontOriyaLanguage            = 71,
  kFontMalayalamLanguage        = 72,
  kFontKannadaLanguage          = 73,
  kFontTamilLanguage            = 74,
  kFontTeluguLanguage           = 75,
  kFontSinhaleseLanguage        = 76,
  kFontBurmeseLanguage          = 77,
  kFontKhmerLanguage            = 78,
  kFontLaoLanguage              = 79,
  kFontVietnameseLanguage       = 80,
  kFontIndonesianLanguage       = 81,
  kFontTagalogLanguage          = 82,
  kFontMalayRomanLanguage       = 83,
  kFontMalayArabicLanguage      = 84,
  kFontAmharicLanguage          = 85,
  kFontTigrinyaLanguage         = 86,
  kFontGallaLanguage            = 87,
  kFontOromoLanguage            = kFontGallaLanguage,
  kFontSomaliLanguage           = 88,
  kFontSwahiliLanguage          = 89,
  kFontRuandaLanguage           = 90,
  kFontRundiLanguage            = 91,
  kFontChewaLanguage            = 92,
  kFontMalagasyLanguage         = 93,
  kFontEsperantoLanguage        = 94,
  kFontWelshLanguage            = 128,
  kFontBasqueLanguage           = 129,
  kFontCatalanLanguage          = 130,
  kFontLatinLanguage            = 131,
  kFontQuechuaLanguage          = 132,
  kFontGuaraniLanguage          = 133,
  kFontAymaraLanguage           = 134,
  kFontTatarLanguage            = 135,
  kFontUighurLanguage           = 136,
  kFontDzongkhaLanguage         = 137,
  kFontJavaneseRomLanguage      = 138,
  kFontSundaneseRomLanguage     = 139
};
*/
    return SUCCESS;
}
/* }}} */

#endif
