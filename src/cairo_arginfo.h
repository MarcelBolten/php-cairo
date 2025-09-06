/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9159abebed4ae5a59101c2e885a0ac0fdfb77e0d */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Cairo_version, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Cairo_version_string, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Cairo_version arginfo_Cairo_version

#define arginfo_class_Cairo_Cairo_versionString arginfo_Cairo_version_string

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Cairo_availableSurfaces, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Cairo_availableFonts arginfo_class_Cairo_Cairo_availableSurfaces

ZEND_FUNCTION(Cairo_version);
ZEND_FUNCTION(Cairo_version_string);
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
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version_string"), zif_Cairo_version_string, arginfo_Cairo_version_string, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version_string"), zif_Cairo_version_string, arginfo_Cairo_version_string, 0)
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

static void register_cairo_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("Cairo\\VERSION", CAIRO_VERSION, CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("Cairo\\VERSION_STRING", CAIRO_VERSION_STRING, CONST_PERSISTENT);
}

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

	return class_entry;
}
