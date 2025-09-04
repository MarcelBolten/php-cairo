/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 532e2adfa394f0120b711d5a23894740b4bb9c5c */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_FontFace___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontFace_getStatus, 0, 0, Cairo\\Status, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontFace_getType, 0, 0, Cairo\\FontType, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_FontFace, __construct);
ZEND_METHOD(Cairo_FontFace, getStatus);
ZEND_METHOD(Cairo_FontFace, getType);

static const zend_function_entry class_Cairo_FontFace_methods[] = {
	ZEND_ME(Cairo_FontFace, __construct, arginfo_class_Cairo_FontFace___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace, getStatus, arginfo_class_Cairo_FontFace_getStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace, getType, arginfo_class_Cairo_FontFace_getType, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_FontFace(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "FontFace", class_Cairo_FontFace_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontType", IS_LONG, NULL);

	zval enum_case_Toy_value;
	ZVAL_LONG(&enum_case_Toy_value, CAIRO_FONT_TYPE_TOY);
	zend_enum_add_case_cstr(class_entry, "Toy", &enum_case_Toy_value);

	zval enum_case_FT_value;
	ZVAL_LONG(&enum_case_FT_value, CAIRO_FONT_TYPE_FT);
	zend_enum_add_case_cstr(class_entry, "FT", &enum_case_FT_value);

	zval enum_case_Win32_value;
	ZVAL_LONG(&enum_case_Win32_value, CAIRO_FONT_TYPE_WIN32);
	zend_enum_add_case_cstr(class_entry, "Win32", &enum_case_Win32_value);

	zval enum_case_Quartz_value;
	ZVAL_LONG(&enum_case_Quartz_value, CAIRO_FONT_TYPE_QUARTZ);
	zend_enum_add_case_cstr(class_entry, "Quartz", &enum_case_Quartz_value);

	zval enum_case_User_value;
	ZVAL_LONG(&enum_case_User_value, CAIRO_FONT_TYPE_USER);
	zend_enum_add_case_cstr(class_entry, "User", &enum_case_User_value);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_DWrite_value;
	ZVAL_LONG(&enum_case_DWrite_value, CAIRO_FONT_TYPE_DWRITE);
	zend_enum_add_case_cstr(class_entry, "DWrite", &enum_case_DWrite_value);
#endif

	return class_entry;
}
