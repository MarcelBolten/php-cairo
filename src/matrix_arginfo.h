/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 18d83f5066951849687728e21ffcdf4d73d22c1d */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Matrix___construct, 0, 0, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, xx, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, yx, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, xy, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, yy, IS_DOUBLE, 0, "1.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x0, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y0, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Matrix_initIdentity, 0, 0, Cairo\\Matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Matrix_initTranslate, 0, 2, Cairo\\Matrix, 0)
	ZEND_ARG_TYPE_INFO(0, tx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ty, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Matrix_initScale, 0, 2, Cairo\\Matrix, 0)
	ZEND_ARG_TYPE_INFO(0, sx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, sy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Matrix_initRotate, 0, 1, Cairo\\Matrix, 0)
	ZEND_ARG_TYPE_INFO(0, radians, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Matrix_multiply, 0, 2, Cairo\\Matrix, 0)
	ZEND_ARG_OBJ_INFO(0, m1, Cairo\\Matrix, 0)
	ZEND_ARG_OBJ_INFO(0, m2, Cairo\\Matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Matrix_translate, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, tx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ty, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Matrix_scale, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, sx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, sy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Matrix_rotate, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, radians, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Matrix_invert, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Matrix_transformDistance, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, dx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Matrix_transformPoint, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Matrix, __construct);
ZEND_METHOD(Cairo_Matrix, initIdentity);
ZEND_METHOD(Cairo_Matrix, initTranslate);
ZEND_METHOD(Cairo_Matrix, initScale);
ZEND_METHOD(Cairo_Matrix, initRotate);
ZEND_METHOD(Cairo_Matrix, multiply);
ZEND_METHOD(Cairo_Matrix, translate);
ZEND_METHOD(Cairo_Matrix, scale);
ZEND_METHOD(Cairo_Matrix, rotate);
ZEND_METHOD(Cairo_Matrix, invert);
ZEND_METHOD(Cairo_Matrix, transformDistance);
ZEND_METHOD(Cairo_Matrix, transformPoint);

static const zend_function_entry class_Cairo_Matrix_methods[] = {
	ZEND_ME(Cairo_Matrix, __construct, arginfo_class_Cairo_Matrix___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Matrix, initIdentity, arginfo_class_Cairo_Matrix_initIdentity, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Matrix, initTranslate, arginfo_class_Cairo_Matrix_initTranslate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Matrix, initScale, arginfo_class_Cairo_Matrix_initScale, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Matrix, initRotate, arginfo_class_Cairo_Matrix_initRotate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Matrix, multiply, arginfo_class_Cairo_Matrix_multiply, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Matrix, translate, arginfo_class_Cairo_Matrix_translate, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Matrix, scale, arginfo_class_Cairo_Matrix_scale, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Matrix, rotate, arginfo_class_Cairo_Matrix_rotate, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Matrix, invert, arginfo_class_Cairo_Matrix_invert, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Matrix, transformDistance, arginfo_class_Cairo_Matrix_transformDistance, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Matrix, transformPoint, arginfo_class_Cairo_Matrix_transformPoint, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Matrix(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Matrix", class_Cairo_Matrix_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	zval property_xx_default_value;
	ZVAL_DOUBLE(&property_xx_default_value, 1.0);
	zend_string *property_xx_name = zend_string_init("xx", sizeof("xx") - 1, 1);
	zend_declare_typed_property(class_entry, property_xx_name, &property_xx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_xx_name);

	zval property_yx_default_value;
	ZVAL_DOUBLE(&property_yx_default_value, 0.0);
	zend_string *property_yx_name = zend_string_init("yx", sizeof("yx") - 1, 1);
	zend_declare_typed_property(class_entry, property_yx_name, &property_yx_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_yx_name);

	zval property_xy_default_value;
	ZVAL_DOUBLE(&property_xy_default_value, 0.0);
	zend_string *property_xy_name = zend_string_init("xy", sizeof("xy") - 1, 1);
	zend_declare_typed_property(class_entry, property_xy_name, &property_xy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_xy_name);

	zval property_yy_default_value;
	ZVAL_DOUBLE(&property_yy_default_value, 1.0);
	zend_string *property_yy_name = zend_string_init("yy", sizeof("yy") - 1, 1);
	zend_declare_typed_property(class_entry, property_yy_name, &property_yy_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_yy_name);

	zval property_x0_default_value;
	ZVAL_DOUBLE(&property_x0_default_value, 0.0);
	zend_string *property_x0_name = zend_string_init("x0", sizeof("x0") - 1, 1);
	zend_declare_typed_property(class_entry, property_x0_name, &property_x0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x0_name);

	zval property_y0_default_value;
	ZVAL_DOUBLE(&property_y0_default_value, 0.0);
	zend_string *property_y0_name = zend_string_init("y0", sizeof("y0") - 1, 1);
	zend_declare_typed_property(class_entry, property_y0_name, &property_y0_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y0_name);

	return class_entry;
}
