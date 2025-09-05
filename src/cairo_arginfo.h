/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 0a4927cd45645ca13382f9831aeaa255c5131f5f */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Cairo_version, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Cairo_version_sting, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Cairo_version arginfo_Cairo_version

#define arginfo_class_Cairo_Cairo_versionString arginfo_Cairo_version_sting

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Cairo_availableSurfaces, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Cairo_availableFonts arginfo_class_Cairo_Cairo_availableSurfaces

ZEND_FUNCTION(Cairo_version);
ZEND_FUNCTION(Cairo_version_sting);
ZEND_METHOD(Cairo_Cairo, version);
ZEND_METHOD(Cairo_Cairo, versionString);
ZEND_METHOD(Cairo_Cairo, availableSurfaces);
ZEND_METHOD(Cairo_Cairo, availableFonts);

static const zend_function_entry ext_functions[] = {
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version"), zif_Cairo_version, arginfo_Cairo_version, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version"), zif_Cairo_version, arginfo_Cairo_version, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version_sting"), zif_Cairo_version_sting, arginfo_Cairo_version_sting, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version_sting"), zif_Cairo_version_sting, arginfo_Cairo_version_sting, 0)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Cairo_methods[] = {
	ZEND_ME(Cairo_Cairo, version, arginfo_class_Cairo_Cairo_version, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Cairo, versionString, arginfo_class_Cairo_Cairo_versionString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Cairo, availableSurfaces, arginfo_class_Cairo_Cairo_availableSurfaces, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Cairo, availableFonts, arginfo_class_Cairo_Cairo_availableFonts, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Cairo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Cairo", class_Cairo_Cairo_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	zval const_VERSION_value;
	ZVAL_LONG(&const_VERSION_value, CAIRO_VERSION);
	zend_string *const_VERSION_name = zend_string_init_interned("VERSION", sizeof("VERSION") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_VERSION_name, &const_VERSION_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_VERSION_name);

	zval const_VERSION_STRING_value;
	zend_string *const_VERSION_STRING_value_str = zend_string_init(CAIRO_VERSION_STRING, strlen(CAIRO_VERSION_STRING), 1);
	ZVAL_STR(&const_VERSION_STRING_value, const_VERSION_STRING_value_str);
	zend_string *const_VERSION_STRING_name = zend_string_init_interned("VERSION_STRING", sizeof("VERSION_STRING") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_VERSION_STRING_name, &const_VERSION_STRING_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_VERSION_STRING_name);

	return class_entry;
}
