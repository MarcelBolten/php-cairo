/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8b8aa50a3abad8885501238335f0b07a9e40e9dd */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Region___construct, 0, 0, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, rectangles, Cairo\\Rectangle, MAY_BE_NULL|MAY_BE_ARRAY, "NULL")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Region_getStatus, 0, 0, Cairo\\Status, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Region_getExtents, 0, 0, Cairo\\Rectangle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Region_getNumRectangles, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_class_Cairo_Region_getRectangle, 0, 0, Cairo\\Rectangle, MAY_BE_FALSE)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Region_isEmpty, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Region_containsPoint, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Region_containsRectangle, 0, 1, Cairo\\Region\\Overlap, 0)
	ZEND_ARG_OBJ_INFO(0, rectangle, Cairo\\Rectangle, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Region_equal, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, region, Cairo\\Region, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Region_translate, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, dx, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, dy, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Region_intersect, 0, 1, Cairo\\Status, 0)
	ZEND_ARG_OBJ_INFO(0, region, Cairo\\Region, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Region_intersectRectangle, 0, 1, Cairo\\Status, 0)
	ZEND_ARG_OBJ_INFO(0, rectangle, Cairo\\Rectangle, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Region_subtract arginfo_class_Cairo_Region_intersect

#define arginfo_class_Cairo_Region_subtractRectangle arginfo_class_Cairo_Region_intersectRectangle

#define arginfo_class_Cairo_Region_union arginfo_class_Cairo_Region_intersectRectangle

#define arginfo_class_Cairo_Region_unionRectangle arginfo_class_Cairo_Region_intersectRectangle

#define arginfo_class_Cairo_Region_xor arginfo_class_Cairo_Region_intersect

#define arginfo_class_Cairo_Region_xorRectangle arginfo_class_Cairo_Region_intersectRectangle

ZEND_METHOD(Cairo_Region, __construct);
ZEND_METHOD(Cairo_Region, getStatus);
ZEND_METHOD(Cairo_Region, getExtents);
ZEND_METHOD(Cairo_Region, getNumRectangles);
ZEND_METHOD(Cairo_Region, getRectangle);
ZEND_METHOD(Cairo_Region, isEmpty);
ZEND_METHOD(Cairo_Region, containsPoint);
ZEND_METHOD(Cairo_Region, containsRectangle);
ZEND_METHOD(Cairo_Region, equal);
ZEND_METHOD(Cairo_Region, translate);
ZEND_METHOD(Cairo_Region, intersect);
ZEND_METHOD(Cairo_Region, intersectRectangle);
ZEND_METHOD(Cairo_Region, subtract);
ZEND_METHOD(Cairo_Region, subtractRectangle);
ZEND_METHOD(Cairo_Region, union);
ZEND_METHOD(Cairo_Region, unionRectangle);
ZEND_METHOD(Cairo_Region, xor);
ZEND_METHOD(Cairo_Region, xorRectangle);

static const zend_function_entry class_Cairo_Region_methods[] = {
	ZEND_ME(Cairo_Region, __construct, arginfo_class_Cairo_Region___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, getStatus, arginfo_class_Cairo_Region_getStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, getExtents, arginfo_class_Cairo_Region_getExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, getNumRectangles, arginfo_class_Cairo_Region_getNumRectangles, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, getRectangle, arginfo_class_Cairo_Region_getRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, isEmpty, arginfo_class_Cairo_Region_isEmpty, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, containsPoint, arginfo_class_Cairo_Region_containsPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, containsRectangle, arginfo_class_Cairo_Region_containsRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, equal, arginfo_class_Cairo_Region_equal, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, translate, arginfo_class_Cairo_Region_translate, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, intersect, arginfo_class_Cairo_Region_intersect, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, intersectRectangle, arginfo_class_Cairo_Region_intersectRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, subtract, arginfo_class_Cairo_Region_subtract, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, subtractRectangle, arginfo_class_Cairo_Region_subtractRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, union, arginfo_class_Cairo_Region_union, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, unionRectangle, arginfo_class_Cairo_Region_unionRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, xor, arginfo_class_Cairo_Region_xor, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Region, xorRectangle, arginfo_class_Cairo_Region_xorRectangle, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Region(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Region", class_Cairo_Region_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Region_Overlap(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Region\\Overlap", IS_LONG, NULL);

	zval enum_case_In_value;
	ZVAL_LONG(&enum_case_In_value, CAIRO_REGION_OVERLAP_IN);
	zend_enum_add_case_cstr(class_entry, "In", &enum_case_In_value);

	zval enum_case_Out_value;
	ZVAL_LONG(&enum_case_Out_value, CAIRO_REGION_OVERLAP_OUT);
	zend_enum_add_case_cstr(class_entry, "Out", &enum_case_Out_value);

	zval enum_case_Partial_value;
	ZVAL_LONG(&enum_case_Partial_value, CAIRO_REGION_OVERLAP_PARTIAL);
	zend_enum_add_case_cstr(class_entry, "Partial", &enum_case_Partial_value);

	return class_entry;
}
