/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a81cf5d25decb87d776263e53d7af470bbee55e7 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_createSimilar, 0, 3, Cairo\\Surface, 0)
	ZEND_ARG_OBJ_INFO(0, content, Cairo\\Surface\\Content, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_createSimilarImage, 0, 3, Cairo\\Surface, 0)
	ZEND_ARG_OBJ_INFO(0, format, Cairo\\Surface\\ImageFormat, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_createForRectangle, 0, 4, Cairo\\Surface, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_getStatus, 0, 0, Cairo\\Status, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_finish, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Surface_flush arginfo_class_Cairo_Surface_finish

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_getFontOptions, 0, 0, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_getContent, 0, 0, Cairo\\Surface\\Content, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Surface_markDirty arginfo_class_Cairo_Surface_finish

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_markDirtyRectangle, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_setDeviceOffset, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_getDeviceOffset, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Surface_setDeviceScale arginfo_class_Cairo_Surface_setDeviceOffset

#define arginfo_class_Cairo_Surface_getDeviceScale arginfo_class_Cairo_Surface_getDeviceOffset

#define arginfo_class_Cairo_Surface_setFallbackResolution arginfo_class_Cairo_Surface_setDeviceOffset

#define arginfo_class_Cairo_Surface_getFallbackResolution arginfo_class_Cairo_Surface_getDeviceOffset

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_getType, 0, 0, Cairo\\Surface\\Type, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Surface_showPage arginfo_class_Cairo_Surface_finish

#define arginfo_class_Cairo_Surface_copyPage arginfo_class_Cairo_Surface_finish

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_hasShowTextGlyphs, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Surface_mapToImage, 0, 0, Cairo\\Surface, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, rectangle, Cairo\\Rectangle, 1, "NULL")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_unmapImage, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, surface, Cairo\\Surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_writeToPng, 0, 1, IS_VOID, 0)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_writeToJpeg, 0, 1, IS_VOID, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, quality, IS_LONG, 0, "90")
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Surface, __construct);
ZEND_METHOD(Cairo_Surface, createSimilar);
ZEND_METHOD(Cairo_Surface, createSimilarImage);
ZEND_METHOD(Cairo_Surface, createForRectangle);
ZEND_METHOD(Cairo_Surface, getStatus);
ZEND_METHOD(Cairo_Surface, finish);
ZEND_METHOD(Cairo_Surface, flush);
ZEND_METHOD(Cairo_Surface, getFontOptions);
ZEND_METHOD(Cairo_Surface, getContent);
ZEND_METHOD(Cairo_Surface, markDirty);
ZEND_METHOD(Cairo_Surface, markDirtyRectangle);
ZEND_METHOD(Cairo_Surface, setDeviceOffset);
ZEND_METHOD(Cairo_Surface, getDeviceOffset);
ZEND_METHOD(Cairo_Surface, setDeviceScale);
ZEND_METHOD(Cairo_Surface, getDeviceScale);
ZEND_METHOD(Cairo_Surface, setFallbackResolution);
ZEND_METHOD(Cairo_Surface, getFallbackResolution);
ZEND_METHOD(Cairo_Surface, getType);
ZEND_METHOD(Cairo_Surface, showPage);
ZEND_METHOD(Cairo_Surface, copyPage);
ZEND_METHOD(Cairo_Surface, hasShowTextGlyphs);
ZEND_METHOD(Cairo_Surface, mapToImage);
ZEND_METHOD(Cairo_Surface, unmapImage);
ZEND_METHOD(Cairo_Surface, writeToPng);
ZEND_METHOD(Cairo_Surface, writeToJpeg);

static const zend_function_entry class_Cairo_Surface_methods[] = {
	ZEND_ME(Cairo_Surface, __construct, arginfo_class_Cairo_Surface___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, createSimilar, arginfo_class_Cairo_Surface_createSimilar, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, createSimilarImage, arginfo_class_Cairo_Surface_createSimilarImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, createForRectangle, arginfo_class_Cairo_Surface_createForRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, getStatus, arginfo_class_Cairo_Surface_getStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, finish, arginfo_class_Cairo_Surface_finish, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, flush, arginfo_class_Cairo_Surface_flush, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, getFontOptions, arginfo_class_Cairo_Surface_getFontOptions, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, getContent, arginfo_class_Cairo_Surface_getContent, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, markDirty, arginfo_class_Cairo_Surface_markDirty, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, markDirtyRectangle, arginfo_class_Cairo_Surface_markDirtyRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, setDeviceOffset, arginfo_class_Cairo_Surface_setDeviceOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, getDeviceOffset, arginfo_class_Cairo_Surface_getDeviceOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, setDeviceScale, arginfo_class_Cairo_Surface_setDeviceScale, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, getDeviceScale, arginfo_class_Cairo_Surface_getDeviceScale, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, setFallbackResolution, arginfo_class_Cairo_Surface_setFallbackResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, getFallbackResolution, arginfo_class_Cairo_Surface_getFallbackResolution, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, getType, arginfo_class_Cairo_Surface_getType, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, showPage, arginfo_class_Cairo_Surface_showPage, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, copyPage, arginfo_class_Cairo_Surface_copyPage, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, hasShowTextGlyphs, arginfo_class_Cairo_Surface_hasShowTextGlyphs, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, mapToImage, arginfo_class_Cairo_Surface_mapToImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, unmapImage, arginfo_class_Cairo_Surface_unmapImage, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, writeToPng, arginfo_class_Cairo_Surface_writeToPng, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface, writeToJpeg, arginfo_class_Cairo_Surface_writeToJpeg, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Surface(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Surface", class_Cairo_Surface_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Surface_Content(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Content", IS_LONG, NULL);

	zval enum_case_Color_value;
	ZVAL_LONG(&enum_case_Color_value, CAIRO_CONTENT_COLOR);
	zend_enum_add_case_cstr(class_entry, "Color", &enum_case_Color_value);

	zval enum_case_Alpha_value;
	ZVAL_LONG(&enum_case_Alpha_value, CAIRO_CONTENT_ALPHA);
	zend_enum_add_case_cstr(class_entry, "Alpha", &enum_case_Alpha_value);

	zval enum_case_ColorAlpha_value;
	ZVAL_LONG(&enum_case_ColorAlpha_value, CAIRO_CONTENT_COLOR_ALPHA);
	zend_enum_add_case_cstr(class_entry, "ColorAlpha", &enum_case_ColorAlpha_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Surface_Type(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Type", IS_LONG, NULL);

	zval enum_case_Image_value;
	ZVAL_LONG(&enum_case_Image_value, CAIRO_SURFACE_TYPE_IMAGE);
	zend_enum_add_case_cstr(class_entry, "Image", &enum_case_Image_value);

	zval enum_case_PDF_value;
	ZVAL_LONG(&enum_case_PDF_value, CAIRO_SURFACE_TYPE_PDF);
	zend_enum_add_case_cstr(class_entry, "PDF", &enum_case_PDF_value);

	zval enum_case_PS_value;
	ZVAL_LONG(&enum_case_PS_value, CAIRO_SURFACE_TYPE_PS);
	zend_enum_add_case_cstr(class_entry, "PS", &enum_case_PS_value);

	zval enum_case_Xlib_value;
	ZVAL_LONG(&enum_case_Xlib_value, CAIRO_SURFACE_TYPE_XLIB);
	zend_enum_add_case_cstr(class_entry, "Xlib", &enum_case_Xlib_value);

	zval enum_case_Xcb_value;
	ZVAL_LONG(&enum_case_Xcb_value, CAIRO_SURFACE_TYPE_XCB);
	zend_enum_add_case_cstr(class_entry, "Xcb", &enum_case_Xcb_value);

	zval enum_case_Glitz_value;
	ZVAL_LONG(&enum_case_Glitz_value, CAIRO_SURFACE_TYPE_GLITZ);
	zend_enum_add_case_cstr(class_entry, "Glitz", &enum_case_Glitz_value);

	zval enum_case_Quartz_value;
	ZVAL_LONG(&enum_case_Quartz_value, CAIRO_SURFACE_TYPE_QUARTZ);
	zend_enum_add_case_cstr(class_entry, "Quartz", &enum_case_Quartz_value);

	zval enum_case_Win32_value;
	ZVAL_LONG(&enum_case_Win32_value, CAIRO_SURFACE_TYPE_WIN32);
	zend_enum_add_case_cstr(class_entry, "Win32", &enum_case_Win32_value);

	zval enum_case_BeOS_value;
	ZVAL_LONG(&enum_case_BeOS_value, CAIRO_SURFACE_TYPE_BEOS);
	zend_enum_add_case_cstr(class_entry, "BeOS", &enum_case_BeOS_value);

	zval enum_case_DirectFB_value;
	ZVAL_LONG(&enum_case_DirectFB_value, CAIRO_SURFACE_TYPE_DIRECTFB);
	zend_enum_add_case_cstr(class_entry, "DirectFB", &enum_case_DirectFB_value);

	zval enum_case_SVG_value;
	ZVAL_LONG(&enum_case_SVG_value, CAIRO_SURFACE_TYPE_SVG);
	zend_enum_add_case_cstr(class_entry, "SVG", &enum_case_SVG_value);

	zval enum_case_OS2_value;
	ZVAL_LONG(&enum_case_OS2_value, CAIRO_SURFACE_TYPE_OS2);
	zend_enum_add_case_cstr(class_entry, "OS2", &enum_case_OS2_value);

	zval enum_case_Win32Printing_value;
	ZVAL_LONG(&enum_case_Win32Printing_value, CAIRO_SURFACE_TYPE_WIN32_PRINTING);
	zend_enum_add_case_cstr(class_entry, "Win32Printing", &enum_case_Win32Printing_value);

	zval enum_case_QuartzImage_value;
	ZVAL_LONG(&enum_case_QuartzImage_value, CAIRO_SURFACE_TYPE_QUARTZ_IMAGE);
	zend_enum_add_case_cstr(class_entry, "QuartzImage", &enum_case_QuartzImage_value);

	zval enum_case_Script_value;
	ZVAL_LONG(&enum_case_Script_value, CAIRO_SURFACE_TYPE_SCRIPT);
	zend_enum_add_case_cstr(class_entry, "Script", &enum_case_Script_value);

	zval enum_case_QT_value;
	ZVAL_LONG(&enum_case_QT_value, CAIRO_SURFACE_TYPE_QT);
	zend_enum_add_case_cstr(class_entry, "QT", &enum_case_QT_value);

	zval enum_case_Recording_value;
	ZVAL_LONG(&enum_case_Recording_value, CAIRO_SURFACE_TYPE_RECORDING);
	zend_enum_add_case_cstr(class_entry, "Recording", &enum_case_Recording_value);

	zval enum_case_VG_value;
	ZVAL_LONG(&enum_case_VG_value, CAIRO_SURFACE_TYPE_VG);
	zend_enum_add_case_cstr(class_entry, "VG", &enum_case_VG_value);

	zval enum_case_GL_value;
	ZVAL_LONG(&enum_case_GL_value, CAIRO_SURFACE_TYPE_GL);
	zend_enum_add_case_cstr(class_entry, "GL", &enum_case_GL_value);

	zval enum_case_DRM_value;
	ZVAL_LONG(&enum_case_DRM_value, CAIRO_SURFACE_TYPE_DRM);
	zend_enum_add_case_cstr(class_entry, "DRM", &enum_case_DRM_value);

	zval enum_case_Tee_value;
	ZVAL_LONG(&enum_case_Tee_value, CAIRO_SURFACE_TYPE_TEE);
	zend_enum_add_case_cstr(class_entry, "Tee", &enum_case_Tee_value);

	zval enum_case_XML_value;
	ZVAL_LONG(&enum_case_XML_value, CAIRO_SURFACE_TYPE_XML);
	zend_enum_add_case_cstr(class_entry, "XML", &enum_case_XML_value);

	zval enum_case_Skia_value;
	ZVAL_LONG(&enum_case_Skia_value, CAIRO_SURFACE_TYPE_SKIA);
	zend_enum_add_case_cstr(class_entry, "Skia", &enum_case_Skia_value);

	zval enum_case_Subsurface_value;
	ZVAL_LONG(&enum_case_Subsurface_value, CAIRO_SURFACE_TYPE_SUBSURFACE);
	zend_enum_add_case_cstr(class_entry, "Subsurface", &enum_case_Subsurface_value);

	zval enum_case_COGL_value;
	ZVAL_LONG(&enum_case_COGL_value, CAIRO_SURFACE_TYPE_COGL);
	zend_enum_add_case_cstr(class_entry, "COGL", &enum_case_COGL_value);

	return class_entry;
}
