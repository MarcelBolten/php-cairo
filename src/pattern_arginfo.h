/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9bb89f595636e48fada2d96fb3253e29047c1538 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Pattern___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_getStatus, 0, 0, Cairo\\Status, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_getType, 0, 0, Cairo\\Pattern\\Type, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_getExtend, 0, 0, Cairo\\Extend, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_setExtend, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, extend, Cairo\\Extend, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_getFilter, 0, 0, Cairo\\Filter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_setFilter, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, filter, Cairo\\Filter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_getMatrix, 0, 0, Cairo\\Matrix, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_setMatrix, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, Cairo\\Matrix, 0)
ZEND_END_ARG_INFO()

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_getDither, 0, 0, Cairo\\Dither, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_setDither, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, dither, Cairo\\Dither, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Pattern_Solid___construct, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, alpha, IS_DOUBLE, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Solid_getRgba, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Gradient_addColorStopRgb, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Gradient_addColorStopRgba, 0, 5, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Gradient_getColorStopRgba, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Gradient_getColorStopCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Pattern_Surface___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, surface, Cairo\\Surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_Surface_getSurface, 0, 0, Cairo\\Surface, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Pattern_Mesh___construct arginfo_class_Cairo_Pattern___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_beginPatch, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Pattern_Mesh_endPatch arginfo_class_Cairo_Pattern_Mesh_beginPatch

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_moveTo, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Pattern_Mesh_lineTo arginfo_class_Cairo_Pattern_Mesh_moveTo

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_curveTo, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y3, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_setControlPoint, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, point_num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_setCornerColorRgb, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, corner_num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_setCornerColorRgba, 0, 5, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, corner_num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Pattern_Mesh_getPatchCount arginfo_class_Cairo_Pattern_Gradient_getColorStopCount

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_getPath, 0, 1, Cairo\\Path, 0)
	ZEND_ARG_TYPE_INFO(0, patch_num, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_getControlPoint, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, patch_num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, point_num, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Pattern_Mesh_getCornerColorRgba, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, patch_num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, corner_num, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Pattern_Gradient_Linear___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, x0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Pattern_Gradient_Linear_getPoints arginfo_class_Cairo_Pattern_Solid_getRgba

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Pattern_Gradient_Radial___construct, 0, 0, 6)
	ZEND_ARG_TYPE_INFO(0, x0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, r0, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, r1, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Pattern_Gradient_Radial_getCircles arginfo_class_Cairo_Pattern_Solid_getRgba

ZEND_METHOD(Cairo_Pattern, __construct);
ZEND_METHOD(Cairo_Pattern, getStatus);
ZEND_METHOD(Cairo_Pattern, getType);
ZEND_METHOD(Cairo_Pattern, getExtend);
ZEND_METHOD(Cairo_Pattern, setExtend);
ZEND_METHOD(Cairo_Pattern, getFilter);
ZEND_METHOD(Cairo_Pattern, setFilter);
ZEND_METHOD(Cairo_Pattern, getMatrix);
ZEND_METHOD(Cairo_Pattern, setMatrix);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_METHOD(Cairo_Pattern, getDither);
ZEND_METHOD(Cairo_Pattern, setDither);
#endif
ZEND_METHOD(Cairo_Pattern_Solid, __construct);
ZEND_METHOD(Cairo_Pattern_Solid, getRgba);
ZEND_METHOD(Cairo_Pattern_Gradient, addColorStopRgb);
ZEND_METHOD(Cairo_Pattern_Gradient, addColorStopRgba);
ZEND_METHOD(Cairo_Pattern_Gradient, getColorStopRgba);
ZEND_METHOD(Cairo_Pattern_Gradient, getColorStopCount);
ZEND_METHOD(Cairo_Pattern_Surface, __construct);
ZEND_METHOD(Cairo_Pattern_Surface, getSurface);
ZEND_METHOD(Cairo_Pattern_Mesh, __construct);
ZEND_METHOD(Cairo_Pattern_Mesh, beginPatch);
ZEND_METHOD(Cairo_Pattern_Mesh, endPatch);
ZEND_METHOD(Cairo_Pattern_Mesh, moveTo);
ZEND_METHOD(Cairo_Pattern_Mesh, lineTo);
ZEND_METHOD(Cairo_Pattern_Mesh, curveTo);
ZEND_METHOD(Cairo_Pattern_Mesh, setControlPoint);
ZEND_METHOD(Cairo_Pattern_Mesh, setCornerColorRgb);
ZEND_METHOD(Cairo_Pattern_Mesh, setCornerColorRgba);
ZEND_METHOD(Cairo_Pattern_Mesh, getPatchCount);
ZEND_METHOD(Cairo_Pattern_Mesh, getPath);
ZEND_METHOD(Cairo_Pattern_Mesh, getControlPoint);
ZEND_METHOD(Cairo_Pattern_Mesh, getCornerColorRgba);
ZEND_METHOD(Cairo_Pattern_Gradient_Linear, __construct);
ZEND_METHOD(Cairo_Pattern_Gradient_Linear, getPoints);
ZEND_METHOD(Cairo_Pattern_Gradient_Radial, __construct);
ZEND_METHOD(Cairo_Pattern_Gradient_Radial, getCircles);

static const zend_function_entry class_Cairo_Pattern_methods[] = {
	ZEND_ME(Cairo_Pattern, __construct, arginfo_class_Cairo_Pattern___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, getStatus, arginfo_class_Cairo_Pattern_getStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, getType, arginfo_class_Cairo_Pattern_getType, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, getExtend, arginfo_class_Cairo_Pattern_getExtend, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, setExtend, arginfo_class_Cairo_Pattern_setExtend, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, getFilter, arginfo_class_Cairo_Pattern_getFilter, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, setFilter, arginfo_class_Cairo_Pattern_setFilter, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, getMatrix, arginfo_class_Cairo_Pattern_getMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, setMatrix, arginfo_class_Cairo_Pattern_setMatrix, ZEND_ACC_PUBLIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	ZEND_ME(Cairo_Pattern, getDither, arginfo_class_Cairo_Pattern_getDither, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern, setDither, arginfo_class_Cairo_Pattern_setDither, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Pattern_Solid_methods[] = {
	ZEND_ME(Cairo_Pattern_Solid, __construct, arginfo_class_Cairo_Pattern_Solid___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Solid, getRgba, arginfo_class_Cairo_Pattern_Solid_getRgba, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Pattern_Gradient_methods[] = {
	ZEND_ME(Cairo_Pattern_Gradient, addColorStopRgb, arginfo_class_Cairo_Pattern_Gradient_addColorStopRgb, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Gradient, addColorStopRgba, arginfo_class_Cairo_Pattern_Gradient_addColorStopRgba, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Gradient, getColorStopRgba, arginfo_class_Cairo_Pattern_Gradient_getColorStopRgba, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Gradient, getColorStopCount, arginfo_class_Cairo_Pattern_Gradient_getColorStopCount, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Pattern_Surface_methods[] = {
	ZEND_ME(Cairo_Pattern_Surface, __construct, arginfo_class_Cairo_Pattern_Surface___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Surface, getSurface, arginfo_class_Cairo_Pattern_Surface_getSurface, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Pattern_Mesh_methods[] = {
	ZEND_ME(Cairo_Pattern_Mesh, __construct, arginfo_class_Cairo_Pattern_Mesh___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, beginPatch, arginfo_class_Cairo_Pattern_Mesh_beginPatch, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, endPatch, arginfo_class_Cairo_Pattern_Mesh_endPatch, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, moveTo, arginfo_class_Cairo_Pattern_Mesh_moveTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, lineTo, arginfo_class_Cairo_Pattern_Mesh_lineTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, curveTo, arginfo_class_Cairo_Pattern_Mesh_curveTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, setControlPoint, arginfo_class_Cairo_Pattern_Mesh_setControlPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, setCornerColorRgb, arginfo_class_Cairo_Pattern_Mesh_setCornerColorRgb, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, setCornerColorRgba, arginfo_class_Cairo_Pattern_Mesh_setCornerColorRgba, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, getPatchCount, arginfo_class_Cairo_Pattern_Mesh_getPatchCount, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, getPath, arginfo_class_Cairo_Pattern_Mesh_getPath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, getControlPoint, arginfo_class_Cairo_Pattern_Mesh_getControlPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Mesh, getCornerColorRgba, arginfo_class_Cairo_Pattern_Mesh_getCornerColorRgba, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Pattern_Gradient_Linear_methods[] = {
	ZEND_ME(Cairo_Pattern_Gradient_Linear, __construct, arginfo_class_Cairo_Pattern_Gradient_Linear___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Gradient_Linear, getPoints, arginfo_class_Cairo_Pattern_Gradient_Linear_getPoints, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Pattern_Gradient_Radial_methods[] = {
	ZEND_ME(Cairo_Pattern_Gradient_Radial, __construct, arginfo_class_Cairo_Pattern_Gradient_Radial___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Pattern_Gradient_Radial, getCircles, arginfo_class_Cairo_Pattern_Gradient_Radial_getCircles, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Pattern(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Pattern", class_Cairo_Pattern_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Extend(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Extend", IS_LONG, NULL);

	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, CAIRO_EXTEND_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);

	zval enum_case_Repeat_value;
	ZVAL_LONG(&enum_case_Repeat_value, CAIRO_EXTEND_REPEAT);
	zend_enum_add_case_cstr(class_entry, "Repeat", &enum_case_Repeat_value);

	zval enum_case_Reflect_value;
	ZVAL_LONG(&enum_case_Reflect_value, CAIRO_EXTEND_REFLECT);
	zend_enum_add_case_cstr(class_entry, "Reflect", &enum_case_Reflect_value);

	zval enum_case_Pad_value;
	ZVAL_LONG(&enum_case_Pad_value, CAIRO_EXTEND_PAD);
	zend_enum_add_case_cstr(class_entry, "Pad", &enum_case_Pad_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Filter(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Filter", IS_LONG, NULL);

	zval enum_case_Fast_value;
	ZVAL_LONG(&enum_case_Fast_value, CAIRO_FILTER_FAST);
	zend_enum_add_case_cstr(class_entry, "Fast", &enum_case_Fast_value);

	zval enum_case_Good_value;
	ZVAL_LONG(&enum_case_Good_value, CAIRO_FILTER_GOOD);
	zend_enum_add_case_cstr(class_entry, "Good", &enum_case_Good_value);

	zval enum_case_Best_value;
	ZVAL_LONG(&enum_case_Best_value, CAIRO_FILTER_BEST);
	zend_enum_add_case_cstr(class_entry, "Best", &enum_case_Best_value);

	zval enum_case_Nearest_value;
	ZVAL_LONG(&enum_case_Nearest_value, CAIRO_FILTER_NEAREST);
	zend_enum_add_case_cstr(class_entry, "Nearest", &enum_case_Nearest_value);

	zval enum_case_Bilinear_value;
	ZVAL_LONG(&enum_case_Bilinear_value, CAIRO_FILTER_BILINEAR);
	zend_enum_add_case_cstr(class_entry, "Bilinear", &enum_case_Bilinear_value);

	zval enum_case_Gaussian_value;
	ZVAL_LONG(&enum_case_Gaussian_value, CAIRO_FILTER_GAUSSIAN);
	zend_enum_add_case_cstr(class_entry, "Gaussian", &enum_case_Gaussian_value);

	return class_entry;
}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
static zend_class_entry *register_class_Cairo_Dither(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Dither", IS_LONG, NULL);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_None_value;
	ZVAL_LONG(&enum_case_None_value, CAIRO_DITHER_NONE);
	zend_enum_add_case_cstr(class_entry, "None", &enum_case_None_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Default_value;
	ZVAL_LONG(&enum_case_Default_value, CAIRO_DITHER_DEFAULT);
	zend_enum_add_case_cstr(class_entry, "Default", &enum_case_Default_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Fast_value;
	ZVAL_LONG(&enum_case_Fast_value, CAIRO_DITHER_FAST);
	zend_enum_add_case_cstr(class_entry, "Fast", &enum_case_Fast_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Good_value;
	ZVAL_LONG(&enum_case_Good_value, CAIRO_DITHER_GOOD);
	zend_enum_add_case_cstr(class_entry, "Good", &enum_case_Good_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Best_value;
	ZVAL_LONG(&enum_case_Best_value, CAIRO_DITHER_BEST);
	zend_enum_add_case_cstr(class_entry, "Best", &enum_case_Best_value);
#endif

	return class_entry;
}
#endif

static zend_class_entry *register_class_Cairo_Pattern_Solid(zend_class_entry *class_entry_Cairo_Pattern)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Pattern", "Solid", class_Cairo_Pattern_Solid_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Pattern, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Pattern);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Pattern_Gradient(zend_class_entry *class_entry_Cairo_Pattern)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Pattern", "Gradient", class_Cairo_Pattern_Gradient_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Pattern, ZEND_ACC_ABSTRACT);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Pattern);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Pattern_Surface(zend_class_entry *class_entry_Cairo_Pattern)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Pattern", "Surface", class_Cairo_Pattern_Surface_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Pattern, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Pattern);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Pattern_Mesh(zend_class_entry *class_entry_Cairo_Pattern)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Pattern", "Mesh", class_Cairo_Pattern_Mesh_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Pattern, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Pattern);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Pattern_Type(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Pattern\\Type", IS_LONG, NULL);

	zval enum_case_Solid_value;
	ZVAL_LONG(&enum_case_Solid_value, CAIRO_PATTERN_TYPE_SOLID);
	zend_enum_add_case_cstr(class_entry, "Solid", &enum_case_Solid_value);

	zval enum_case_Surface_value;
	ZVAL_LONG(&enum_case_Surface_value, CAIRO_PATTERN_TYPE_SURFACE);
	zend_enum_add_case_cstr(class_entry, "Surface", &enum_case_Surface_value);

	zval enum_case_Linear_value;
	ZVAL_LONG(&enum_case_Linear_value, CAIRO_PATTERN_TYPE_LINEAR);
	zend_enum_add_case_cstr(class_entry, "Linear", &enum_case_Linear_value);

	zval enum_case_Radial_value;
	ZVAL_LONG(&enum_case_Radial_value, CAIRO_PATTERN_TYPE_RADIAL);
	zend_enum_add_case_cstr(class_entry, "Radial", &enum_case_Radial_value);

	zval enum_case_Mesh_value;
	ZVAL_LONG(&enum_case_Mesh_value, CAIRO_PATTERN_TYPE_MESH);
	zend_enum_add_case_cstr(class_entry, "Mesh", &enum_case_Mesh_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Pattern_Gradient_Linear(zend_class_entry *class_entry_Cairo_Pattern_Gradient)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Pattern\\Gradient", "Linear", class_Cairo_Pattern_Gradient_Linear_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Pattern_Gradient, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Pattern_Gradient);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Pattern_Gradient_Radial(zend_class_entry *class_entry_Cairo_Pattern_Gradient)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Pattern\\Gradient", "Radial", class_Cairo_Pattern_Gradient_Radial_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Pattern_Gradient, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Pattern_Gradient);
#endif

	return class_entry;
}
