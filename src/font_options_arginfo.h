/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 099b6106a48dc7af1672490d5b3b02c1673a308b */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_FontOptions___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontOptions_getStatus, 0, 0, Cairo\\Status, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_merge, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, other, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_hash, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_equal, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, other, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setAntialias, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, antialias, Cairo\\Antialias, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontOptions_getAntialias, 0, 0, Cairo\\Antialias, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setSubpixelOrder, 0, 0, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, subpixel_order, Cairo\\SubPixelOrder, 0, "Cairo\\SubPixelOrder::Default")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontOptions_getSubpixelOrder, 0, 0, Cairo\\SubPixelOrder, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setHintStyle, 0, 0, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, hint_style, Cairo\\HintStyle, 0, "Cairo\\HintStyle::Default")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontOptions_getHintStyle, 0, 0, Cairo\\HintStyle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setHintMetrics, 0, 0, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, hint_metrics, Cairo\\HintMetrics, 0, "Cairo\\HintMetrics::Default")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontOptions_getHintMetrics, 0, 0, Cairo\\HintMetrics, 0)
ZEND_END_ARG_INFO()

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setVariations, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, variations, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_getVariations, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontOptions_getColorMode, 0, 0, Cairo\\ColorMode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setColorMode, 0, 0, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, color_mode, Cairo\\ColorMode, 0, "Cairo\\ColorMode::Default")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_getColorPalette, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setColorPalette, 0, 0, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, palette, IS_LONG, 0, "Cairo\\FontOptions::PALETTE_DEFAULT")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_setCustomPaletteColor, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, color_id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, alpha, IS_DOUBLE, 0, "1.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontOptions_getCustomPaletteColor, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, color_id, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(Cairo_FontOptions, __construct);
ZEND_METHOD(Cairo_FontOptions, getStatus);
ZEND_METHOD(Cairo_FontOptions, merge);
ZEND_METHOD(Cairo_FontOptions, hash);
ZEND_METHOD(Cairo_FontOptions, equal);
ZEND_METHOD(Cairo_FontOptions, setAntialias);
ZEND_METHOD(Cairo_FontOptions, getAntialias);
ZEND_METHOD(Cairo_FontOptions, setSubpixelOrder);
ZEND_METHOD(Cairo_FontOptions, getSubpixelOrder);
ZEND_METHOD(Cairo_FontOptions, setHintStyle);
ZEND_METHOD(Cairo_FontOptions, getHintStyle);
ZEND_METHOD(Cairo_FontOptions, setHintMetrics);
ZEND_METHOD(Cairo_FontOptions, getHintMetrics);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_METHOD(Cairo_FontOptions, setVariations);
ZEND_METHOD(Cairo_FontOptions, getVariations);
#endif
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_METHOD(Cairo_FontOptions, getColorMode);
ZEND_METHOD(Cairo_FontOptions, setColorMode);
ZEND_METHOD(Cairo_FontOptions, getColorPalette);
ZEND_METHOD(Cairo_FontOptions, setColorPalette);
ZEND_METHOD(Cairo_FontOptions, setCustomPaletteColor);
ZEND_METHOD(Cairo_FontOptions, getCustomPaletteColor);
#endif

static const zend_function_entry class_Cairo_FontOptions_methods[] = {
	ZEND_ME(Cairo_FontOptions, __construct, arginfo_class_Cairo_FontOptions___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getStatus, arginfo_class_Cairo_FontOptions_getStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, merge, arginfo_class_Cairo_FontOptions_merge, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, hash, arginfo_class_Cairo_FontOptions_hash, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, equal, arginfo_class_Cairo_FontOptions_equal, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, setAntialias, arginfo_class_Cairo_FontOptions_setAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getAntialias, arginfo_class_Cairo_FontOptions_getAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, setSubpixelOrder, arginfo_class_Cairo_FontOptions_setSubpixelOrder, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getSubpixelOrder, arginfo_class_Cairo_FontOptions_getSubpixelOrder, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, setHintStyle, arginfo_class_Cairo_FontOptions_setHintStyle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getHintStyle, arginfo_class_Cairo_FontOptions_getHintStyle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, setHintMetrics, arginfo_class_Cairo_FontOptions_setHintMetrics, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getHintMetrics, arginfo_class_Cairo_FontOptions_getHintMetrics, ZEND_ACC_PUBLIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	ZEND_ME(Cairo_FontOptions, setVariations, arginfo_class_Cairo_FontOptions_setVariations, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getVariations, arginfo_class_Cairo_FontOptions_getVariations, ZEND_ACC_PUBLIC)
#endif
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	ZEND_ME(Cairo_FontOptions, getColorMode, arginfo_class_Cairo_FontOptions_getColorMode, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, setColorMode, arginfo_class_Cairo_FontOptions_setColorMode, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getColorPalette, arginfo_class_Cairo_FontOptions_getColorPalette, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, setColorPalette, arginfo_class_Cairo_FontOptions_setColorPalette, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, setCustomPaletteColor, arginfo_class_Cairo_FontOptions_setCustomPaletteColor, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontOptions, getCustomPaletteColor, arginfo_class_Cairo_FontOptions_getCustomPaletteColor, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_FontOptions(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "FontOptions", class_Cairo_FontOptions_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)

	zval const_PALETTE_DEFAULT_value;
	ZVAL_LONG(&const_PALETTE_DEFAULT_value, CAIRO_COLOR_PALETTE_DEFAULT);
	zend_string *const_PALETTE_DEFAULT_name = zend_string_init_interned("PALETTE_DEFAULT", sizeof("PALETTE_DEFAULT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_PALETTE_DEFAULT_name, &const_PALETTE_DEFAULT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_PALETTE_DEFAULT_name);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Antialias(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Antialias", IS_LONG, NULL);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, CAIRO_ANTIALIAS_DEFAULT);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, CAIRO_ANTIALIAS_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Gray_value;
	ZVAL_LONG(&enum_case_Gray_value, CAIRO_ANTIALIAS_GRAY);
	zend_enum_add_case_cstr(class_entry, "Gray", &enum_case_Gray_value);

	zval enum_case_Subpixel_value;
	ZVAL_LONG(&enum_case_Subpixel_value, CAIRO_ANTIALIAS_SUBPIXEL);
	zend_enum_add_case_cstr(class_entry, "Subpixel", &enum_case_Subpixel_value);

	zval enum_case_Fast_value;
	ZVAL_LONG(&enum_case_Fast_value, CAIRO_ANTIALIAS_FAST);
	zend_enum_add_case_cstr(class_entry, "Fast", &enum_case_Fast_value);

	zval enum_case_Good_value;
	ZVAL_LONG(&enum_case_Good_value, CAIRO_ANTIALIAS_GOOD);
	zend_enum_add_case_cstr(class_entry, "Good", &enum_case_Good_value);

	zval enum_case_Best_value;
	ZVAL_LONG(&enum_case_Best_value, CAIRO_ANTIALIAS_BEST);
	zend_enum_add_case_cstr(class_entry, "Best", &enum_case_Best_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_SubPixelOrder(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\SubPixelOrder", IS_LONG, NULL);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, CAIRO_SUBPIXEL_ORDER_DEFAULT);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_RGB_value;
	ZVAL_LONG(&enum_case_RGB_value, CAIRO_SUBPIXEL_ORDER_RGB);
	zend_enum_add_case_cstr(class_entry, "RGB", &enum_case_RGB_value);

	zval enum_case_BGR_value;
	ZVAL_LONG(&enum_case_BGR_value, CAIRO_SUBPIXEL_ORDER_BGR);
	zend_enum_add_case_cstr(class_entry, "BGR", &enum_case_BGR_value);

	zval enum_case_VRGB_value;
	ZVAL_LONG(&enum_case_VRGB_value, CAIRO_SUBPIXEL_ORDER_VRGB);
	zend_enum_add_case_cstr(class_entry, "VRGB", &enum_case_VRGB_value);

	zval enum_case_VBGR_value;
	ZVAL_LONG(&enum_case_VBGR_value, CAIRO_SUBPIXEL_ORDER_VBGR);
	zend_enum_add_case_cstr(class_entry, "VBGR", &enum_case_VBGR_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_HintStyle(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\HintStyle", IS_LONG, NULL);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, CAIRO_HINT_STYLE_DEFAULT);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, CAIRO_HINT_STYLE_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Slight_value;
	ZVAL_LONG(&enum_case_Slight_value, CAIRO_HINT_STYLE_SLIGHT);
	zend_enum_add_case_cstr(class_entry, "Slight", &enum_case_Slight_value);

	zval enum_case_Medium_value;
	ZVAL_LONG(&enum_case_Medium_value, CAIRO_HINT_STYLE_MEDIUM);
	zend_enum_add_case_cstr(class_entry, "Medium", &enum_case_Medium_value);

	zval enum_case_Full_value;
	ZVAL_LONG(&enum_case_Full_value, CAIRO_HINT_STYLE_FULL);
	zend_enum_add_case_cstr(class_entry, "Full", &enum_case_Full_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_HintMetrics(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\HintMetrics", IS_LONG, NULL);

	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, CAIRO_HINT_METRICS_DEFAULT);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);

	zval enum_case_Off_value;
	ZVAL_LONG(&enum_case_Off_value, CAIRO_HINT_METRICS_OFF);
	zend_enum_add_case_cstr(class_entry, "Off", &enum_case_Off_value);

	zval enum_case_On_value;
	ZVAL_LONG(&enum_case_On_value, CAIRO_HINT_METRICS_ON);
	zend_enum_add_case_cstr(class_entry, "On", &enum_case_On_value);

	return class_entry;
}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
static zend_class_entry *register_class_Cairo_ColorMode(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\ColorMode", IS_LONG, NULL);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, CAIRO_COLOR_MODE_DEFAULT);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_NoColor_value;
	ZVAL_LONG(&enum_case_NoColor_value, CAIRO_COLOR_MODE_NO_COLOR);
	zend_enum_add_case_cstr(class_entry, "NoColor", &enum_case_NoColor_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Color_value;
	ZVAL_LONG(&enum_case_Color_value, CAIRO_COLOR_MODE_COLOR);
	zend_enum_add_case_cstr(class_entry, "Color", &enum_case_Color_value);
#endif

	return class_entry;
}
#endif
