/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 578f27326cbd6ec3a6c426300ca14cee794a304f */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontFace_Quartz_createForCGFont, 0, 1, Cairo\\FontFace\\Quartz, 0)
	ZEND_ARG_TYPE_INFO(0, font_name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_FontFace_Quartz, createForCGFont);

static const zend_function_entry class_Cairo_FontFace_Quartz_methods[] = {
	ZEND_ME(Cairo_FontFace_Quartz, createForCGFont, arginfo_class_Cairo_FontFace_Quartz_createForCGFont, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_FontFace_Quartz(zend_class_entry *class_entry_Cairo_FontFace)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\FontFace", "Quartz", class_Cairo_FontFace_Quartz_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_FontFace, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_FontFace);
#endif

	return class_entry;
}
