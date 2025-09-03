/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: e4b916dcec93f79cc698710a978a48d0ada31b69 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_FontFace_Ft___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_FontFace_Ft, __construct);

static const zend_function_entry class_Cairo_FontFace_Ft_methods[] = {
	ZEND_ME(Cairo_FontFace_Ft, __construct, arginfo_class_Cairo_FontFace_Ft___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_FontFace_Ft(zend_class_entry *class_entry_Cairo_FontFace)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\FontFace", "Ft", class_Cairo_FontFace_Ft_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_FontFace, 0);

	return class_entry;
}
