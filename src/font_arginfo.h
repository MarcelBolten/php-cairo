/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9b0d91d7edba9ad153d838310a4147d1e46788fa */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_FontFace_Toy___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, slant, Cairo\\FontSlant, 0, "Cairo\\FontSlant::Normal")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, weight, Cairo\\FontWeight, 0, "Cairo\\FontWeight::Normal")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_FontFace_Toy_getFamily, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontFace_Toy_getSlant, 0, 0, Cairo\\FontSlant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_FontFace_Toy_getWeight, 0, 0, Cairo\\FontWeight, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_FontFace_Toy, __construct);
ZEND_METHOD(Cairo_FontFace_Toy, getFamily);
ZEND_METHOD(Cairo_FontFace_Toy, getSlant);
ZEND_METHOD(Cairo_FontFace_Toy, getWeight);

static const zend_function_entry class_Cairo_FontFace_Toy_methods[] = {
	ZEND_ME(Cairo_FontFace_Toy, __construct, arginfo_class_Cairo_FontFace_Toy___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace_Toy, getFamily, arginfo_class_Cairo_FontFace_Toy_getFamily, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace_Toy, getSlant, arginfo_class_Cairo_FontFace_Toy_getSlant, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_FontFace_Toy, getWeight, arginfo_class_Cairo_FontFace_Toy_getWeight, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_FontFace_Toy(zend_class_entry *class_entry_Cairo_FontFace_FontFace)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\FontFace", "Toy", class_Cairo_FontFace_Toy_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_FontFace_FontFace, 0);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontSlant(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontSlant", IS_LONG, NULL);

	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, CAIRO_FONT_SLANT_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);

	zval enum_case_Italic_value;
	ZVAL_LONG(&enum_case_Italic_value, CAIRO_FONT_SLANT_ITALIC);
	zend_enum_add_case_cstr(class_entry, "Italic", &enum_case_Italic_value);

	zval enum_case_Oblique_value;
	ZVAL_LONG(&enum_case_Oblique_value, CAIRO_FONT_SLANT_OBLIQUE);
	zend_enum_add_case_cstr(class_entry, "Oblique", &enum_case_Oblique_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FontWeight(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FontWeight", IS_LONG, NULL);

	zval enum_case_Normal_value;
	ZVAL_LONG(&enum_case_Normal_value, CAIRO_FONT_WEIGHT_NORMAL);
	zend_enum_add_case_cstr(class_entry, "Normal", &enum_case_Normal_value);

	zval enum_case_Bold_value;
	ZVAL_LONG(&enum_case_Bold_value, CAIRO_FONT_WEIGHT_BOLD);
	zend_enum_add_case_cstr(class_entry, "Bold", &enum_case_Bold_value);

	return class_entry;
}
