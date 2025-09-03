/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 40cbf033164459fb6f2fb2c1b3e2de0a8bbd0618 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface_SVG___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_SVG_restrictToVersion, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\SVG\\Version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_SVG_versionToString, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\SVG\\Version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_SVG_getVersions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_SVG_setDocumentUnit, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, unit, Cairo\\Surface\\Svg\\\125nit, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_SVG_getDocumentUnit, 0, 0, Cairo\\Surface\\Svg\\\125nit, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(Cairo_Surface_SVG, __construct);
ZEND_METHOD(Cairo_Surface_SVG, restrictToVersion);
ZEND_METHOD(Cairo_Surface_SVG, versionToString);
ZEND_METHOD(Cairo_Surface_SVG, getVersions);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_METHOD(Cairo_Surface_SVG, setDocumentUnit);
ZEND_METHOD(Cairo_Surface_SVG, getDocumentUnit);
#endif

static const zend_function_entry class_Cairo_Surface_SVG_methods[] = {
	ZEND_ME(Cairo_Surface_SVG, __construct, arginfo_class_Cairo_Surface_SVG___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_SVG, restrictToVersion, arginfo_class_Cairo_Surface_SVG_restrictToVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_SVG, versionToString, arginfo_class_Cairo_Surface_SVG_versionToString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Surface_SVG, getVersions, arginfo_class_Cairo_Surface_SVG_getVersions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	ZEND_ME(Cairo_Surface_SVG, setDocumentUnit, arginfo_class_Cairo_Surface_SVG_setDocumentUnit, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_SVG, getDocumentUnit, arginfo_class_Cairo_Surface_SVG_getDocumentUnit, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Surface_SVG(zend_class_entry *class_entry_Cairo_Surface)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Surface", "SVG", class_Cairo_Surface_SVG_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Surface_SVG_Version(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\SVG\\Version", IS_LONG, NULL);

	zval enum_case_Version_1_1_value;
	ZVAL_LONG(&enum_case_Version_1_1_value, CAIRO_SVG_VERSION_1_1);
	zend_enum_add_case_cstr(class_entry, "Version_1_1", &enum_case_Version_1_1_value);

	zval enum_case_Version_1_2_value;
	ZVAL_LONG(&enum_case_Version_1_2_value, CAIRO_SVG_VERSION_1_2);
	zend_enum_add_case_cstr(class_entry, "Version_1_2", &enum_case_Version_1_2_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Surface_SVG_Unit(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\SVG\\Unit", IS_LONG, NULL);

	zval enum_case_User_value;
	ZVAL_LONG(&enum_case_User_value, CAIRO_SVG_UNIT_USER);
	zend_enum_add_case_cstr(class_entry, "User", &enum_case_User_value);

	zval enum_case_EM_value;
	ZVAL_LONG(&enum_case_EM_value, CAIRO_SVG_UNIT_EM);
	zend_enum_add_case_cstr(class_entry, "EM", &enum_case_EM_value);

	zval enum_case_EX_value;
	ZVAL_LONG(&enum_case_EX_value, CAIRO_SVG_UNIT_EX);
	zend_enum_add_case_cstr(class_entry, "EX", &enum_case_EX_value);

	zval enum_case_PX_value;
	ZVAL_LONG(&enum_case_PX_value, CAIRO_SVG_UNIT_PX);
	zend_enum_add_case_cstr(class_entry, "PX", &enum_case_PX_value);

	zval enum_case_IN_value;
	ZVAL_LONG(&enum_case_IN_value, CAIRO_SVG_UNIT_IN);
	zend_enum_add_case_cstr(class_entry, "IN", &enum_case_IN_value);

	zval enum_case_CM_value;
	ZVAL_LONG(&enum_case_CM_value, CAIRO_SVG_UNIT_CM);
	zend_enum_add_case_cstr(class_entry, "CM", &enum_case_CM_value);

	zval enum_case_MM_value;
	ZVAL_LONG(&enum_case_MM_value, CAIRO_SVG_UNIT_MM);
	zend_enum_add_case_cstr(class_entry, "MM", &enum_case_MM_value);

	zval enum_case_PT_value;
	ZVAL_LONG(&enum_case_PT_value, CAIRO_SVG_UNIT_PT);
	zend_enum_add_case_cstr(class_entry, "PT", &enum_case_PT_value);

	zval enum_case_PC_value;
	ZVAL_LONG(&enum_case_PC_value, CAIRO_SVG_UNIT_PC);
	zend_enum_add_case_cstr(class_entry, "PC", &enum_case_PC_value);

	zval enum_case_Percent_value;
	ZVAL_LONG(&enum_case_Percent_value, CAIRO_SVG_UNIT_PERCENT);
	zend_enum_add_case_cstr(class_entry, "Percent", &enum_case_Percent_value);

	return class_entry;
}
