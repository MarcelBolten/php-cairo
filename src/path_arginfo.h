/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4e6a25245929e0135e6d77ac86ab9b266cdbd392 */

static zend_class_entry *register_class_Cairo_Path(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Path", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Path_DataType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Path\\DataType", IS_LONG, NULL);

	zval enum_case_MoveTo_value;
	ZVAL_LONG(&enum_case_MoveTo_value, CAIRO_PATH_MOVE_TO);
	zend_enum_add_case_cstr(class_entry, "MoveTo", &enum_case_MoveTo_value);

	zval enum_case_LineTo_value;
	ZVAL_LONG(&enum_case_LineTo_value, CAIRO_PATH_LINE_TO);
	zend_enum_add_case_cstr(class_entry, "LineTo", &enum_case_LineTo_value);

	zval enum_case_CurveTo_value;
	ZVAL_LONG(&enum_case_CurveTo_value, CAIRO_PATH_CURVE_TO);
	zend_enum_add_case_cstr(class_entry, "CurveTo", &enum_case_CurveTo_value);

	zval enum_case_ClosePath_value;
	ZVAL_LONG(&enum_case_ClosePath_value, CAIRO_PATH_CLOSE_PATH);
	zend_enum_add_case_cstr(class_entry, "ClosePath", &enum_case_ClosePath_value);

	return class_entry;
}
