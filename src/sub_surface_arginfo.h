/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 2ee4272d6125fe28a502546c62a81bb7999580d3 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface_SubSurface___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Surface_SubSurface, __construct);

static const zend_function_entry class_Cairo_Surface_SubSurface_methods[] = {
	ZEND_ME(Cairo_Surface_SubSurface, __construct, arginfo_class_Cairo_Surface_SubSurface___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Surface_SubSurface(zend_class_entry *class_entry_Cairo_Surface)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Surface", "SubSurface", class_Cairo_Surface_SubSurface_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Surface);
#endif

	return class_entry;
}
