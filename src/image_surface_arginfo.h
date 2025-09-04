/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 2fa9fa43d013095c282e54cf4871bee6dc0d017d */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface_Image___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, format, Cairo\\Surface\\ImageFormat, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_Image_createForData, 0, 4, Cairo\\Surface\\Image, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, format, Cairo\\Surface\\ImageFormat, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Image_getData, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_Image_getFormat, 0, 0, Cairo\\Surface\\ImageFormat, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Image_getWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Surface_Image_getHeight arginfo_class_Cairo_Surface_Image_getWidth

#define arginfo_class_Cairo_Surface_Image_getStride arginfo_class_Cairo_Surface_Image_getWidth

#if defined(CAIRO_HAS_PNG_FUNCTIONS)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_Image_createFromPng, 0, 1, Cairo\\Surface\\Image, 0)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()
#endif

#if defined(CAIRO_HAS_JPEG_FUNCTIONS)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_Image_createFromJpeg, 0, 1, Cairo\\Surface\\Image, 0)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_ImageFormat_strideForWidth, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, format, Cairo\\Surface\\ImageFormat, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Surface_Image, __construct);
ZEND_METHOD(Cairo_Surface_Image, createForData);
ZEND_METHOD(Cairo_Surface_Image, getData);
ZEND_METHOD(Cairo_Surface_Image, getFormat);
ZEND_METHOD(Cairo_Surface_Image, getWidth);
ZEND_METHOD(Cairo_Surface_Image, getHeight);
ZEND_METHOD(Cairo_Surface_Image, getStride);
#if defined(CAIRO_HAS_PNG_FUNCTIONS)
ZEND_METHOD(Cairo_Surface_Image, createFromPng);
#endif
#if defined(CAIRO_HAS_JPEG_FUNCTIONS)
ZEND_METHOD(Cairo_Surface_Image, createFromJpeg);
#endif
ZEND_METHOD(Cairo_Surface_ImageFormat, strideForWidth);

#if defined(CAIRO_HAS_JPEG_FUNCTIONS)
static const zend_function_entry class_Cairo_Surface_Image_methods[] = {
	ZEND_ME(Cairo_Surface_Image, __construct, arginfo_class_Cairo_Surface_Image___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Image, createForData, arginfo_class_Cairo_Surface_Image_createForData, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Surface_Image, getData, arginfo_class_Cairo_Surface_Image_getData, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Image, getFormat, arginfo_class_Cairo_Surface_Image_getFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Image, getWidth, arginfo_class_Cairo_Surface_Image_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Image, getHeight, arginfo_class_Cairo_Surface_Image_getHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Image, getStride, arginfo_class_Cairo_Surface_Image_getStride, ZEND_ACC_PUBLIC)
#if defined(CAIRO_HAS_PNG_FUNCTIONS)
	ZEND_ME(Cairo_Surface_Image, createFromPng, arginfo_class_Cairo_Surface_Image_createFromPng, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	ZEND_ME(Cairo_Surface_Image, createFromJpeg, arginfo_class_Cairo_Surface_Image_createFromJpeg, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};
#endif

static const zend_function_entry class_Cairo_Surface_ImageFormat_methods[] = {
	ZEND_ME(Cairo_Surface_ImageFormat, strideForWidth, arginfo_class_Cairo_Surface_ImageFormat_strideForWidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

#if defined(CAIRO_HAS_JPEG_FUNCTIONS)
static zend_class_entry *register_class_Cairo_Surface_Image(zend_class_entry *class_entry_Cairo_Surface)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Surface", "Image", class_Cairo_Surface_Image_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Surface);
#endif

	return class_entry;
}
#endif

static zend_class_entry *register_class_Cairo_Surface_ImageFormat(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\ImageFormat", IS_LONG, class_Cairo_Surface_ImageFormat_methods);

	zval enum_case_ARGB32_value;
	ZVAL_LONG(&enum_case_ARGB32_value, CAIRO_FORMAT_ARGB32);
	zend_enum_add_case_cstr(class_entry, "ARGB32", &enum_case_ARGB32_value);

	zval enum_case_RGB24_value;
	ZVAL_LONG(&enum_case_RGB24_value, CAIRO_FORMAT_RGB24);
	zend_enum_add_case_cstr(class_entry, "RGB24", &enum_case_RGB24_value);

	zval enum_case_A8_value;
	ZVAL_LONG(&enum_case_A8_value, CAIRO_FORMAT_A8);
	zend_enum_add_case_cstr(class_entry, "A8", &enum_case_A8_value);

	zval enum_case_A1_value;
	ZVAL_LONG(&enum_case_A1_value, CAIRO_FORMAT_A1);
	zend_enum_add_case_cstr(class_entry, "A1", &enum_case_A1_value);

	zval enum_case_RGB16_565_value;
	ZVAL_LONG(&enum_case_RGB16_565_value, CAIRO_FORMAT_RGB16_565);
	zend_enum_add_case_cstr(class_entry, "RGB16_565", &enum_case_RGB16_565_value);

	zval enum_case_RGB30_value;
	ZVAL_LONG(&enum_case_RGB30_value, CAIRO_FORMAT_RGB30);
	zend_enum_add_case_cstr(class_entry, "RGB30", &enum_case_RGB30_value);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 17, 2)
	zval enum_case_RGBA128F_value;
	ZVAL_LONG(&enum_case_RGBA128F_value, CAIRO_FORMAT_RGBA128F);
	zend_enum_add_case_cstr(class_entry, "RGBA128F", &enum_case_RGBA128F_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 17, 2)
	zval enum_case_RGB96F_value;
	ZVAL_LONG(&enum_case_RGB96F_value, CAIRO_FORMAT_RGB96F);
	zend_enum_add_case_cstr(class_entry, "RGB96F", &enum_case_RGB96F_value);
#endif

	return class_entry;
}
