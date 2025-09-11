/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8fef52b7ce4b72f58fdf18863f38f07ae1366155 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_FontFace_Win32___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, font_options, IS_ARRAY, 1, "null")
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_FontFace_Win32, __construct);

static const zend_function_entry class_Cairo_FontFace_Win32_methods[] = {
	ZEND_ME(Cairo_FontFace_Win32, __construct, arginfo_class_Cairo_FontFace_Win32___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_FontFace_Win32(zend_class_entry *class_entry_Cairo_FontFace)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\FontFace", "Win32", class_Cairo_FontFace_Win32_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_FontFace, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_FontFace);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontFace_Win32_FontWeight(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontFace\\Win32\\FontWeight", IS_LONG, NULL);

	zval enum_case_Dontcare_value;
	ZVAL_LONG(&enum_case_Dontcare_value, FW_DONTCARE);
	zend_enum_add_case_cstr(class_entry, "Dontcare", &enum_case_Dontcare_value);

	zval enum_case_Thin_value;
	ZVAL_LONG(&enum_case_Thin_value, FW_THIN);
	zend_enum_add_case_cstr(class_entry, "Thin", &enum_case_Thin_value);

	zval enum_case_Extralight_value;
	ZVAL_LONG(&enum_case_Extralight_value, FW_EXTRALIGHT);
	zend_enum_add_case_cstr(class_entry, "Extralight", &enum_case_Extralight_value);

	zval enum_case_Ultralight_value;
	ZVAL_LONG(&enum_case_Ultralight_value, FW_ULTRALIGHT);
	zend_enum_add_case_cstr(class_entry, "Ultralight", &enum_case_Ultralight_value);

	zval enum_case_Light_value;
	ZVAL_LONG(&enum_case_Light_value, FW_LIGHT);
	zend_enum_add_case_cstr(class_entry, "Light", &enum_case_Light_value);

	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, FW_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);

	zval enum_case_Regular_value;
	ZVAL_LONG(&enum_case_Regular_value, FW_REGULAR);
	zend_enum_add_case_cstr(class_entry, "Regular", &enum_case_Regular_value);

	zval enum_case_Medium_value;
	ZVAL_LONG(&enum_case_Medium_value, FW_MEDIUM);
	zend_enum_add_case_cstr(class_entry, "Medium", &enum_case_Medium_value);

	zval enum_case_Semibold_value;
	ZVAL_LONG(&enum_case_Semibold_value, FW_SEMIBOLD);
	zend_enum_add_case_cstr(class_entry, "Semibold", &enum_case_Semibold_value);

	zval enum_case_Demibold_value;
	ZVAL_LONG(&enum_case_Demibold_value, FW_DEMIBOLD);
	zend_enum_add_case_cstr(class_entry, "Demibold", &enum_case_Demibold_value);

	zval enum_case_Bold_value;
	ZVAL_LONG(&enum_case_Bold_value, FW_BOLD);
	zend_enum_add_case_cstr(class_entry, "Bold", &enum_case_Bold_value);

	zval enum_case_Extrabold_value;
	ZVAL_LONG(&enum_case_Extrabold_value, FW_EXTRABOLD);
	zend_enum_add_case_cstr(class_entry, "Extrabold", &enum_case_Extrabold_value);

	zval enum_case_Ultrabold_value;
	ZVAL_LONG(&enum_case_Ultrabold_value, FW_ULTRABOLD);
	zend_enum_add_case_cstr(class_entry, "Ultrabold", &enum_case_Ultrabold_value);

	zval enum_case_Heavy_value;
	ZVAL_LONG(&enum_case_Heavy_value, FW_HEAVY);
	zend_enum_add_case_cstr(class_entry, "Heavy", &enum_case_Heavy_value);

	zval enum_case_Black_value;
	ZVAL_LONG(&enum_case_Black_value, FW_BLACK);
	zend_enum_add_case_cstr(class_entry, "Black", &enum_case_Black_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontFace_Win32_FontCharset(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontFace\\Win32\\FontCharset", IS_LONG, NULL);

	zval enum_case_Ansi_value;
	ZVAL_LONG(&enum_case_Ansi_value, ANSI_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Ansi", &enum_case_Ansi_value);

	zval enum_case_Baltic_value;
	ZVAL_LONG(&enum_case_Baltic_value, BALTIC_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Baltic", &enum_case_Baltic_value);

	zval enum_case_ChineseBig5_value;
	ZVAL_LONG(&enum_case_ChineseBig5_value, CHINESEBIG5_CHARSET);
	zend_enum_add_case_cstr(class_entry, "ChineseBig5", &enum_case_ChineseBig5_value);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, DEFAULT_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_Easteurope_value;
	ZVAL_LONG(&enum_case_Easteurope_value, EASTEUROPE_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Easteurope", &enum_case_Easteurope_value);

	zval enum_case_GB2312_value;
	ZVAL_LONG(&enum_case_GB2312_value, GB2312_CHARSET);
	zend_enum_add_case_cstr(class_entry, "GB2312", &enum_case_GB2312_value);

	zval enum_case_Greek_value;
	ZVAL_LONG(&enum_case_Greek_value, GREEK_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Greek", &enum_case_Greek_value);

	zval enum_case_Hangul_value;
	ZVAL_LONG(&enum_case_Hangul_value, HANGUL_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Hangul", &enum_case_Hangul_value);

	zval enum_case_Mac_value;
	ZVAL_LONG(&enum_case_Mac_value, MAC_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Mac", &enum_case_Mac_value);

	zval enum_case_Oem_value;
	ZVAL_LONG(&enum_case_Oem_value, OEM_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Oem", &enum_case_Oem_value);

	zval enum_case_Russian_value;
	ZVAL_LONG(&enum_case_Russian_value, RUSSIAN_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Russian", &enum_case_Russian_value);

	zval enum_case_ShiftJIS_value;
	ZVAL_LONG(&enum_case_ShiftJIS_value, SHIFTJIS_CHARSET);
	zend_enum_add_case_cstr(class_entry, "ShiftJIS", &enum_case_ShiftJIS_value);

	zval enum_case_Symbol_value;
	ZVAL_LONG(&enum_case_Symbol_value, SYMBOL_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Symbol", &enum_case_Symbol_value);

	zval enum_case_Turkish_value;
	ZVAL_LONG(&enum_case_Turkish_value, TURKISH_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Turkish", &enum_case_Turkish_value);

	zval enum_case_Vietnamese_value;
	ZVAL_LONG(&enum_case_Vietnamese_value, VIETNAMESE_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Vietnamese", &enum_case_Vietnamese_value);

#if (WINVER >= 0x0400)
	zval enum_case_Johab_value;
	ZVAL_LONG(&enum_case_Johab_value, JOHAB_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Johab", &enum_case_Johab_value);
#endif

#if (WINVER >= 0x0400)
	zval enum_case_Arabic_value;
	ZVAL_LONG(&enum_case_Arabic_value, ARABIC_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Arabic", &enum_case_Arabic_value);
#endif

#if (WINVER >= 0x0400)
	zval enum_case_Hebrew_value;
	ZVAL_LONG(&enum_case_Hebrew_value, HEBREW_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Hebrew", &enum_case_Hebrew_value);
#endif

#if (WINVER >= 0x0400)
	zval enum_case_Thai_value;
	ZVAL_LONG(&enum_case_Thai_value, THAI_CHARSET);
	zend_enum_add_case_cstr(class_entry, "Thai", &enum_case_Thai_value);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontFace_Win32_FontOutputPrecision(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontFace\\Win32\\FontOutputPrecision", IS_LONG, NULL);

	zval enum_case_Character_value;
	ZVAL_LONG(&enum_case_Character_value, OUT_CHARACTER_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Character", &enum_case_Character_value);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, OUT_DEFAULT_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_Device_value;
	ZVAL_LONG(&enum_case_Device_value, OUT_DEVICE_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Device", &enum_case_Device_value);

	zval enum_case_Outline_value;
	ZVAL_LONG(&enum_case_Outline_value, OUT_OUTLINE_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Outline", &enum_case_Outline_value);

	zval enum_case_PsOnly_value;
	ZVAL_LONG(&enum_case_PsOnly_value, OUT_PS_ONLY_PRECIS);
	zend_enum_add_case_cstr(class_entry, "PsOnly", &enum_case_PsOnly_value);

	zval enum_case_Raster_value;
	ZVAL_LONG(&enum_case_Raster_value, OUT_RASTER_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Raster", &enum_case_Raster_value);

	zval enum_case_String_value;
	ZVAL_LONG(&enum_case_String_value, OUT_STRING_PRECIS);
	zend_enum_add_case_cstr(class_entry, "String", &enum_case_String_value);

	zval enum_case_Stroke_value;
	ZVAL_LONG(&enum_case_Stroke_value, OUT_STROKE_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Stroke", &enum_case_Stroke_value);

	zval enum_case_TtOnly_value;
	ZVAL_LONG(&enum_case_TtOnly_value, OUT_TT_ONLY_PRECIS);
	zend_enum_add_case_cstr(class_entry, "TtOnly", &enum_case_TtOnly_value);

	zval enum_case_Tt_value;
	ZVAL_LONG(&enum_case_Tt_value, OUT_TT_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Tt", &enum_case_Tt_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontFace_Win32_FontClipPrecision(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontFace\\Win32\\FontClipPrecision", IS_LONG, NULL);

	zval enum_case_Character_value;
	ZVAL_LONG(&enum_case_Character_value, CLIP_CHARACTER_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Character", &enum_case_Character_value);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, CLIP_DEFAULT_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
	zval enum_case_DfaDisable_value;
	ZVAL_LONG(&enum_case_DfaDisable_value, CLIP_DFA_DISABLE);
	zend_enum_add_case_cstr(class_entry, "DfaDisable", &enum_case_DfaDisable_value);
#endif

	zval enum_case_Embedded_value;
	ZVAL_LONG(&enum_case_Embedded_value, CLIP_EMBEDDED);
	zend_enum_add_case_cstr(class_entry, "Embedded", &enum_case_Embedded_value);

	zval enum_case_LhAngles_value;
	ZVAL_LONG(&enum_case_LhAngles_value, CLIP_LH_ANGLES);
	zend_enum_add_case_cstr(class_entry, "LhAngles", &enum_case_LhAngles_value);

	zval enum_case_Mask_value;
	ZVAL_LONG(&enum_case_Mask_value, CLIP_MASK);
	zend_enum_add_case_cstr(class_entry, "Mask", &enum_case_Mask_value);

	zval enum_case_Stroke_value;
	ZVAL_LONG(&enum_case_Stroke_value, CLIP_STROKE_PRECIS);
	zend_enum_add_case_cstr(class_entry, "Stroke", &enum_case_Stroke_value);

	zval enum_case_TtAlways_value;
	ZVAL_LONG(&enum_case_TtAlways_value, CLIP_TT_ALWAYS);
	zend_enum_add_case_cstr(class_entry, "TtAlways", &enum_case_TtAlways_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontFace_Win32_FontQuality(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontFace\\Win32\\FontQuality", IS_LONG, NULL);

	zval enum_case_Antialiased_value;
	ZVAL_LONG(&enum_case_Antialiased_value, ANTIALIASED_QUALITY);
	zend_enum_add_case_cstr(class_entry, "Antialiased", &enum_case_Antialiased_value);

	zval enum_case_Cleartype_value;
	ZVAL_LONG(&enum_case_Cleartype_value, CLEARTYPE_QUALITY);
	zend_enum_add_case_cstr(class_entry, "Cleartype", &enum_case_Cleartype_value);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, DEFAULT_QUALITY);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_Draft_value;
	ZVAL_LONG(&enum_case_Draft_value, DRAFT_QUALITY);
	zend_enum_add_case_cstr(class_entry, "Draft", &enum_case_Draft_value);

	zval enum_case_NonAntialiased_value;
	ZVAL_LONG(&enum_case_NonAntialiased_value, NONANTIALIASED_QUALITY);
	zend_enum_add_case_cstr(class_entry, "NonAntialiased", &enum_case_NonAntialiased_value);

	zval enum_case_Proof_value;
	ZVAL_LONG(&enum_case_Proof_value, PROOF_QUALITY);
	zend_enum_add_case_cstr(class_entry, "Proof", &enum_case_Proof_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontFace_Win32_FontPitch(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontFace\\Win32\\FontPitch", IS_LONG, NULL);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, DEFAULT_PITCH);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_Fixed_value;
	ZVAL_LONG(&enum_case_Fixed_value, FIXED_PITCH);
	zend_enum_add_case_cstr(class_entry, "Fixed", &enum_case_Fixed_value);

	zval enum_case_Variable_value;
	ZVAL_LONG(&enum_case_Variable_value, VARIABLE_PITCH);
	zend_enum_add_case_cstr(class_entry, "Variable", &enum_case_Variable_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontFace_Win32_FontFamily(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontFace\\Win32\\FontFamily", IS_LONG, NULL);

	zval enum_case_Decorative_value;
	ZVAL_LONG(&enum_case_Decorative_value, FF_DECORATIVE);
	zend_enum_add_case_cstr(class_entry, "Decorative", &enum_case_Decorative_value);

	zval enum_case_Dontcare_value;
	ZVAL_LONG(&enum_case_Dontcare_value, FF_DONTCARE);
	zend_enum_add_case_cstr(class_entry, "Dontcare", &enum_case_Dontcare_value);

	zval enum_case_Modern_value;
	ZVAL_LONG(&enum_case_Modern_value, FF_MODERN);
	zend_enum_add_case_cstr(class_entry, "Modern", &enum_case_Modern_value);

	zval enum_case_Roman_value;
	ZVAL_LONG(&enum_case_Roman_value, FF_ROMAN);
	zend_enum_add_case_cstr(class_entry, "Roman", &enum_case_Roman_value);

	zval enum_case_Script_value;
	ZVAL_LONG(&enum_case_Script_value, FF_SCRIPT);
	zend_enum_add_case_cstr(class_entry, "Script", &enum_case_Script_value);

	zval enum_case_Swiss_value;
	ZVAL_LONG(&enum_case_Swiss_value, FF_SWISS);
	zend_enum_add_case_cstr(class_entry, "Swiss", &enum_case_Swiss_value);

	return class_entry;
}
