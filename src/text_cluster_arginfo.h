/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 5e3a7d915ab336d07b7e07d552703ae738c34c09 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_TextCluster___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, num_bytes, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_glyphs, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_TextCluster, __construct);

static const zend_function_entry class_Cairo_TextCluster_methods[] = {
	ZEND_ME(Cairo_TextCluster, __construct, arginfo_class_Cairo_TextCluster___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_TextCluster(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "TextCluster", class_Cairo_TextCluster_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_num_bytes_default_value;
	ZVAL_LONG(&property_num_bytes_default_value, 0);
	zend_string *property_num_bytes_name = zend_string_init("num_bytes", sizeof("num_bytes") - 1, 1);
	zend_declare_typed_property(class_entry, property_num_bytes_name, &property_num_bytes_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_num_bytes_name);

	zval property_num_glyphs_default_value;
	ZVAL_LONG(&property_num_glyphs_default_value, 0);
	zend_string *property_num_glyphs_name = zend_string_init("num_glyphs", sizeof("num_glyphs") - 1, 1);
	zend_declare_typed_property(class_entry, property_num_glyphs_name, &property_num_glyphs_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_num_glyphs_name);

	return class_entry;
}
