/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8178c479bf725f54a7371a7115694de5eddfee27 */

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
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);

	return class_entry;
}
