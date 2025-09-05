/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 73a8fb1f37e5b3c825a531363bc65b6fd0e2f359 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Glyph___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Glyph, __construct);

static const zend_function_entry class_Cairo_Glyph_methods[] = {
	ZEND_ME(Cairo_Glyph, __construct, arginfo_class_Cairo_Glyph___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Glyph(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Glyph", class_Cairo_Glyph_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_FINAL;
#endif

	zval property_index_default_value;
	ZVAL_LONG(&property_index_default_value, 0);
	zend_string *property_index_name = zend_string_init("index", sizeof("index") - 1, 1);
	zend_declare_typed_property(class_entry, property_index_name, &property_index_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_index_name);

	zval property_x_default_value;
	ZVAL_DOUBLE(&property_x_default_value, 0.0);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_DOUBLE(&property_y_default_value, 0.0);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	return class_entry;
}
