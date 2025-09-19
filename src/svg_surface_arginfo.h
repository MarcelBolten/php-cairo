/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 093b4565777555b0e49d0e72a1f0933ef64bc6fa */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface_Svg___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Svg_restrictToVersion, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Svg\\Version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Svg_versionToString, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Svg\\Version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Svg_getVersions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Svg_setDocumentUnit, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, unit, Cairo\\Surface\\Svg\\\125nit, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_Svg_getDocumentUnit, 0, 0, Cairo\\Surface\\Svg\\\125nit, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(Cairo_Surface_Svg, __construct);
ZEND_METHOD(Cairo_Surface_Svg, restrictToVersion);
ZEND_METHOD(Cairo_Surface_Svg, versionToString);
ZEND_METHOD(Cairo_Surface_Svg, getVersions);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_METHOD(Cairo_Surface_Svg, setDocumentUnit);
ZEND_METHOD(Cairo_Surface_Svg, getDocumentUnit);
#endif

static const zend_function_entry class_Cairo_Surface_Svg_methods[] = {
	ZEND_ME(Cairo_Surface_Svg, __construct, arginfo_class_Cairo_Surface_Svg___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Svg, restrictToVersion, arginfo_class_Cairo_Surface_Svg_restrictToVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Svg, versionToString, arginfo_class_Cairo_Surface_Svg_versionToString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Surface_Svg, getVersions, arginfo_class_Cairo_Surface_Svg_getVersions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	ZEND_ME(Cairo_Surface_Svg, setDocumentUnit, arginfo_class_Cairo_Surface_Svg_setDocumentUnit, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Svg, getDocumentUnit, arginfo_class_Cairo_Surface_Svg_getDocumentUnit, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Surface_Svg(zend_class_entry *class_entry_Cairo_Surface)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Surface", "Svg", class_Cairo_Surface_Svg_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Surface);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Surface_Svg_Version(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Svg\\Version", IS_LONG, NULL);

	zval enum_case_Version_1_1_value;
	ZVAL_LONG(&enum_case_Version_1_1_value, CAIRO_SVG_VERSION_1_1);
	zend_enum_add_case_cstr(class_entry, "Version_1_1", &enum_case_Version_1_1_value);

	zval enum_case_Version_1_2_value;
	ZVAL_LONG(&enum_case_Version_1_2_value, CAIRO_SVG_VERSION_1_2);
	zend_enum_add_case_cstr(class_entry, "Version_1_2", &enum_case_Version_1_2_value);

	return class_entry;
}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
static zend_class_entry *register_class_Cairo_Surface_Svg_Unit(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Svg\\Unit", IS_LONG, NULL);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_User_value;
	ZVAL_LONG(&enum_case_User_value, CAIRO_SVG_UNIT_USER);
	zend_enum_add_case_cstr(class_entry, "User", &enum_case_User_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_EM_value;
	ZVAL_LONG(&enum_case_EM_value, CAIRO_SVG_UNIT_EM);
	zend_enum_add_case_cstr(class_entry, "EM", &enum_case_EM_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_EX_value;
	ZVAL_LONG(&enum_case_EX_value, CAIRO_SVG_UNIT_EX);
	zend_enum_add_case_cstr(class_entry, "EX", &enum_case_EX_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_PX_value;
	ZVAL_LONG(&enum_case_PX_value, CAIRO_SVG_UNIT_PX);
	zend_enum_add_case_cstr(class_entry, "PX", &enum_case_PX_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_IN_value;
	ZVAL_LONG(&enum_case_IN_value, CAIRO_SVG_UNIT_IN);
	zend_enum_add_case_cstr(class_entry, "IN", &enum_case_IN_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_CM_value;
	ZVAL_LONG(&enum_case_CM_value, CAIRO_SVG_UNIT_CM);
	zend_enum_add_case_cstr(class_entry, "CM", &enum_case_CM_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_MM_value;
	ZVAL_LONG(&enum_case_MM_value, CAIRO_SVG_UNIT_MM);
	zend_enum_add_case_cstr(class_entry, "MM", &enum_case_MM_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_PT_value;
	ZVAL_LONG(&enum_case_PT_value, CAIRO_SVG_UNIT_PT);
	zend_enum_add_case_cstr(class_entry, "PT", &enum_case_PT_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_PC_value;
	ZVAL_LONG(&enum_case_PC_value, CAIRO_SVG_UNIT_PC);
	zend_enum_add_case_cstr(class_entry, "PC", &enum_case_PC_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Percent_value;
	ZVAL_LONG(&enum_case_Percent_value, CAIRO_SVG_UNIT_PERCENT);
	zend_enum_add_case_cstr(class_entry, "Percent", &enum_case_Percent_value);
#endif

	return class_entry;
}
#endif
