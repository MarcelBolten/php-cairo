/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: dac4e3e8bbc3b2275081f9561626a90981ebba53 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface_Ps___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_setSize, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_restrictToLevel, 0, 0, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, level, Cairo\\Surface\\Ps\\Level, 0, "Cairo\\Surface\\Ps\\Level::Level_2")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_getLevels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_levelToString, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, level, Cairo\\Surface\\Ps\\Level, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_setEps, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, eps, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_getEps, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_dscBeginSetup, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Surface_Ps_dscBeginPageSetup arginfo_class_Cairo_Surface_Ps_dscBeginSetup

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Ps_dscComment, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, comment, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Surface_Ps, __construct);
ZEND_METHOD(Cairo_Surface_Ps, setSize);
ZEND_METHOD(Cairo_Surface_Ps, restrictToLevel);
ZEND_METHOD(Cairo_Surface_Ps, getLevels);
ZEND_METHOD(Cairo_Surface_Ps, levelToString);
ZEND_METHOD(Cairo_Surface_Ps, setEps);
ZEND_METHOD(Cairo_Surface_Ps, getEps);
ZEND_METHOD(Cairo_Surface_Ps, dscBeginSetup);
ZEND_METHOD(Cairo_Surface_Ps, dscBeginPageSetup);
ZEND_METHOD(Cairo_Surface_Ps, dscComment);

static const zend_function_entry class_Cairo_Surface_Ps_methods[] = {
	ZEND_ME(Cairo_Surface_Ps, __construct, arginfo_class_Cairo_Surface_Ps___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Ps, setSize, arginfo_class_Cairo_Surface_Ps_setSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Ps, restrictToLevel, arginfo_class_Cairo_Surface_Ps_restrictToLevel, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Ps, getLevels, arginfo_class_Cairo_Surface_Ps_getLevels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Surface_Ps, levelToString, arginfo_class_Cairo_Surface_Ps_levelToString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Surface_Ps, setEps, arginfo_class_Cairo_Surface_Ps_setEps, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Ps, getEps, arginfo_class_Cairo_Surface_Ps_getEps, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Ps, dscBeginSetup, arginfo_class_Cairo_Surface_Ps_dscBeginSetup, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Ps, dscBeginPageSetup, arginfo_class_Cairo_Surface_Ps_dscBeginPageSetup, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Ps, dscComment, arginfo_class_Cairo_Surface_Ps_dscComment, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Surface_Ps(zend_class_entry *class_entry_Cairo_Surface)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Surface", "Ps", class_Cairo_Surface_Ps_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Surface);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Surface_Ps_Level(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Ps\\Level", IS_LONG, NULL);

	zval enum_case_Level_2_value;
	ZVAL_LONG(&enum_case_Level_2_value, CAIRO_PS_LEVEL_2);
	zend_enum_add_case_cstr(class_entry, "Level_2", &enum_case_Level_2_value);

	zval enum_case_Level_3_value;
	ZVAL_LONG(&enum_case_Level_3_value, CAIRO_PS_LEVEL_3);
	zend_enum_add_case_cstr(class_entry, "Level_3", &enum_case_Level_3_value);

	return class_entry;
}
