/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 3817974b6275425adaecdb5c6ff0766921be8ba8 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_FontFace_Ft___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, stream)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, flags, IS_LONG, 0, "0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontFace_Ft_getSynthesize, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontFace_Ft_setSynthesize, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, synthFlags, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_FontFace_Ft_unsetSynthesize arginfo_class_Cairo_FontFace_Ft_setSynthesize

ZEND_METHOD(Cairo_FontFace_Ft, __construct);
ZEND_METHOD(Cairo_FontFace_Ft, getSynthesize);
ZEND_METHOD(Cairo_FontFace_Ft, setSynthesize);
ZEND_METHOD(Cairo_FontFace_Ft, unsetSynthesize);

static const zend_function_entry class_Cairo_FontFace_Ft_methods[] = {
	ZEND_ME(Cairo_FontFace_Ft, __construct, arginfo_class_Cairo_FontFace_Ft___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace_Ft, getSynthesize, arginfo_class_Cairo_FontFace_Ft_getSynthesize, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace_Ft, setSynthesize, arginfo_class_Cairo_FontFace_Ft_setSynthesize, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace_Ft, unsetSynthesize, arginfo_class_Cairo_FontFace_Ft_unsetSynthesize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_FontFace_Ft(zend_class_entry *class_entry_Cairo_FontFace)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\FontFace", "Ft", class_Cairo_FontFace_Ft_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_FontFace, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_FontFace);
#endif

	zval const_SYNTHESIZE_BOLD_value;
	ZVAL_LONG(&const_SYNTHESIZE_BOLD_value, CAIRO_FT_SYNTHESIZE_BOLD);
	zend_string *const_SYNTHESIZE_BOLD_name = zend_string_init_interned("SYNTHESIZE_BOLD", sizeof("SYNTHESIZE_BOLD") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SYNTHESIZE_BOLD_name, &const_SYNTHESIZE_BOLD_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SYNTHESIZE_BOLD_name);

	zval const_SYNTHESIZE_OBLIQUE_value;
	ZVAL_LONG(&const_SYNTHESIZE_OBLIQUE_value, CAIRO_FT_SYNTHESIZE_OBLIQUE);
	zend_string *const_SYNTHESIZE_OBLIQUE_name = zend_string_init_interned("SYNTHESIZE_OBLIQUE", sizeof("SYNTHESIZE_OBLIQUE") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_SYNTHESIZE_OBLIQUE_name, &const_SYNTHESIZE_OBLIQUE_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_SYNTHESIZE_OBLIQUE_name);

	return class_entry;
}
