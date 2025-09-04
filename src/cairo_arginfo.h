/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 7433662f54ebc00aa22068c4f7c821fc006c5f41 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Cairo_version, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_Cairo_version_sting, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Cairo_version arginfo_Cairo_version

#define arginfo_class_Cairo_Cairo_versionString arginfo_Cairo_version_sting

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Cairo_availableSurfaces, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Cairo_availableFonts arginfo_class_Cairo_Cairo_availableSurfaces

#define arginfo_class_Cairo_Status_getMessage arginfo_Cairo_version_sting

ZEND_FUNCTION(Cairo_version);
ZEND_FUNCTION(Cairo_version_sting);
ZEND_METHOD(Cairo_Cairo, version);
ZEND_METHOD(Cairo_Cairo, versionString);
ZEND_METHOD(Cairo_Cairo, availableSurfaces);
ZEND_METHOD(Cairo_Cairo, availableFonts);
ZEND_METHOD(Cairo_Status, getMessage);

static const zend_function_entry ext_functions[] = {
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version"), zif_Cairo_version, arginfo_Cairo_version, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version"), zif_Cairo_version, arginfo_Cairo_version, 0)
#endif
#if (PHP_VERSION_ID >= 80400)
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version_sting"), zif_Cairo_version_sting, arginfo_Cairo_version_sting, 0, NULL, NULL)
#else
	ZEND_RAW_FENTRY(ZEND_NS_NAME("Cairo", "version_sting"), zif_Cairo_version_sting, arginfo_Cairo_version_sting, 0)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Cairo_methods[] = {
	ZEND_ME(Cairo_Cairo, version, arginfo_class_Cairo_Cairo_version, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Cairo, versionString, arginfo_class_Cairo_Cairo_versionString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Cairo, availableSurfaces, arginfo_class_Cairo_Cairo_availableSurfaces, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Cairo, availableFonts, arginfo_class_Cairo_Cairo_availableFonts, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_Cairo_Status_methods[] = {
	ZEND_ME(Cairo_Status, getMessage, arginfo_class_Cairo_Status_getMessage, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Cairo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Cairo", class_Cairo_Cairo_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_ABSTRACT);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
	class_entry->ce_flags |= ZEND_ACC_ABSTRACT;
#endif

	zval const_VERSION_value;
	ZVAL_LONG(&const_VERSION_value, CAIRO_VERSION);
	zend_string *const_VERSION_name = zend_string_init_interned("VERSION", sizeof("VERSION") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_VERSION_name, &const_VERSION_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_VERSION_name);

	zval const_VERSION_STRING_value;
	zend_string *const_VERSION_STRING_value_str = zend_string_init(CAIRO_VERSION_STRING, strlen(CAIRO_VERSION_STRING), 1);
	ZVAL_STR(&const_VERSION_STRING_value, const_VERSION_STRING_value_str);
	zend_string *const_VERSION_STRING_name = zend_string_init_interned("VERSION_STRING", sizeof("VERSION_STRING") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_VERSION_STRING_name, &const_VERSION_STRING_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_VERSION_STRING_name);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Exception(zend_class_entry *class_entry_Exception)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Exception", NULL);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Exception, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Exception);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Status(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Status", IS_LONG, class_Cairo_Status_methods);

	zval enum_case_Success_value;
	ZVAL_LONG(&enum_case_Success_value, CAIRO_STATUS_SUCCESS);
	zend_enum_add_case_cstr(class_entry, "Success", &enum_case_Success_value);

	zval enum_case_NoMemory_value;
	ZVAL_LONG(&enum_case_NoMemory_value, CAIRO_STATUS_NO_MEMORY);
	zend_enum_add_case_cstr(class_entry, "NoMemory", &enum_case_NoMemory_value);

	zval enum_case_InvalidRestore_value;
	ZVAL_LONG(&enum_case_InvalidRestore_value, CAIRO_STATUS_INVALID_RESTORE);
	zend_enum_add_case_cstr(class_entry, "InvalidRestore", &enum_case_InvalidRestore_value);

	zval enum_case_InvalidPopGroup_value;
	ZVAL_LONG(&enum_case_InvalidPopGroup_value, CAIRO_STATUS_INVALID_POP_GROUP);
	zend_enum_add_case_cstr(class_entry, "InvalidPopGroup", &enum_case_InvalidPopGroup_value);

	zval enum_case_NoCurrentPoint_value;
	ZVAL_LONG(&enum_case_NoCurrentPoint_value, CAIRO_STATUS_NO_CURRENT_POINT);
	zend_enum_add_case_cstr(class_entry, "NoCurrentPoint", &enum_case_NoCurrentPoint_value);

	zval enum_case_InvalidMatrix_value;
	ZVAL_LONG(&enum_case_InvalidMatrix_value, CAIRO_STATUS_INVALID_MATRIX);
	zend_enum_add_case_cstr(class_entry, "InvalidMatrix", &enum_case_InvalidMatrix_value);

	zval enum_case_InvalidStatus_value;
	ZVAL_LONG(&enum_case_InvalidStatus_value, CAIRO_STATUS_INVALID_STATUS);
	zend_enum_add_case_cstr(class_entry, "InvalidStatus", &enum_case_InvalidStatus_value);

	zval enum_case_NullPointer_value;
	ZVAL_LONG(&enum_case_NullPointer_value, CAIRO_STATUS_NULL_POINTER);
	zend_enum_add_case_cstr(class_entry, "NullPointer", &enum_case_NullPointer_value);

	zval enum_case_InvalidString_value;
	ZVAL_LONG(&enum_case_InvalidString_value, CAIRO_STATUS_INVALID_STRING);
	zend_enum_add_case_cstr(class_entry, "InvalidString", &enum_case_InvalidString_value);

	zval enum_case_InvalidPathData_value;
	ZVAL_LONG(&enum_case_InvalidPathData_value, CAIRO_STATUS_INVALID_PATH_DATA);
	zend_enum_add_case_cstr(class_entry, "InvalidPathData", &enum_case_InvalidPathData_value);

	zval enum_case_ReadError_value;
	ZVAL_LONG(&enum_case_ReadError_value, CAIRO_STATUS_READ_ERROR);
	zend_enum_add_case_cstr(class_entry, "ReadError", &enum_case_ReadError_value);

	zval enum_case_WriteError_value;
	ZVAL_LONG(&enum_case_WriteError_value, CAIRO_STATUS_WRITE_ERROR);
	zend_enum_add_case_cstr(class_entry, "WriteError", &enum_case_WriteError_value);

	zval enum_case_SurfaceFinished_value;
	ZVAL_LONG(&enum_case_SurfaceFinished_value, CAIRO_STATUS_SURFACE_FINISHED);
	zend_enum_add_case_cstr(class_entry, "SurfaceFinished", &enum_case_SurfaceFinished_value);

	zval enum_case_SurfaceTypeMismatch_value;
	ZVAL_LONG(&enum_case_SurfaceTypeMismatch_value, CAIRO_STATUS_SURFACE_TYPE_MISMATCH);
	zend_enum_add_case_cstr(class_entry, "SurfaceTypeMismatch", &enum_case_SurfaceTypeMismatch_value);

	zval enum_case_PatternTypeMismatch_value;
	ZVAL_LONG(&enum_case_PatternTypeMismatch_value, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	zend_enum_add_case_cstr(class_entry, "PatternTypeMismatch", &enum_case_PatternTypeMismatch_value);

	zval enum_case_InvalidContent_value;
	ZVAL_LONG(&enum_case_InvalidContent_value, CAIRO_STATUS_INVALID_CONTENT);
	zend_enum_add_case_cstr(class_entry, "InvalidContent", &enum_case_InvalidContent_value);

	zval enum_case_InvalidFormat_value;
	ZVAL_LONG(&enum_case_InvalidFormat_value, CAIRO_STATUS_INVALID_FORMAT);
	zend_enum_add_case_cstr(class_entry, "InvalidFormat", &enum_case_InvalidFormat_value);

	zval enum_case_InvalidVisual_value;
	ZVAL_LONG(&enum_case_InvalidVisual_value, CAIRO_STATUS_INVALID_VISUAL);
	zend_enum_add_case_cstr(class_entry, "InvalidVisual", &enum_case_InvalidVisual_value);

	zval enum_case_FileNotFound_value;
	ZVAL_LONG(&enum_case_FileNotFound_value, CAIRO_STATUS_FILE_NOT_FOUND);
	zend_enum_add_case_cstr(class_entry, "FileNotFound", &enum_case_FileNotFound_value);

	zval enum_case_InvalidDash_value;
	ZVAL_LONG(&enum_case_InvalidDash_value, CAIRO_STATUS_INVALID_DASH);
	zend_enum_add_case_cstr(class_entry, "InvalidDash", &enum_case_InvalidDash_value);

	zval enum_case_InvalidDscComment_value;
	ZVAL_LONG(&enum_case_InvalidDscComment_value, CAIRO_STATUS_INVALID_DSC_COMMENT);
	zend_enum_add_case_cstr(class_entry, "InvalidDscComment", &enum_case_InvalidDscComment_value);

	zval enum_case_InvalidIndex_value;
	ZVAL_LONG(&enum_case_InvalidIndex_value, CAIRO_STATUS_INVALID_INDEX);
	zend_enum_add_case_cstr(class_entry, "InvalidIndex", &enum_case_InvalidIndex_value);

	zval enum_case_ClipNotRepresentable_value;
	ZVAL_LONG(&enum_case_ClipNotRepresentable_value, CAIRO_STATUS_CLIP_NOT_REPRESENTABLE);
	zend_enum_add_case_cstr(class_entry, "ClipNotRepresentable", &enum_case_ClipNotRepresentable_value);

	zval enum_case_TempFileError_value;
	ZVAL_LONG(&enum_case_TempFileError_value, CAIRO_STATUS_TEMP_FILE_ERROR);
	zend_enum_add_case_cstr(class_entry, "TempFileError", &enum_case_TempFileError_value);

	zval enum_case_InvalidStride_value;
	ZVAL_LONG(&enum_case_InvalidStride_value, CAIRO_STATUS_INVALID_STRIDE);
	zend_enum_add_case_cstr(class_entry, "InvalidStride", &enum_case_InvalidStride_value);

	zval enum_case_FontTypeMismatch_value;
	ZVAL_LONG(&enum_case_FontTypeMismatch_value, CAIRO_STATUS_FONT_TYPE_MISMATCH);
	zend_enum_add_case_cstr(class_entry, "FontTypeMismatch", &enum_case_FontTypeMismatch_value);

	zval enum_case_UserFontImmutable_value;
	ZVAL_LONG(&enum_case_UserFontImmutable_value, CAIRO_STATUS_USER_FONT_IMMUTABLE);
	zend_enum_add_case_cstr(class_entry, "UserFontImmutable", &enum_case_UserFontImmutable_value);

	zval enum_case_UserFontError_value;
	ZVAL_LONG(&enum_case_UserFontError_value, CAIRO_STATUS_USER_FONT_ERROR);
	zend_enum_add_case_cstr(class_entry, "UserFontError", &enum_case_UserFontError_value);

	zval enum_case_NegativeCount_value;
	ZVAL_LONG(&enum_case_NegativeCount_value, CAIRO_STATUS_NEGATIVE_COUNT);
	zend_enum_add_case_cstr(class_entry, "NegativeCount", &enum_case_NegativeCount_value);

	zval enum_case_InvalidClusters_value;
	ZVAL_LONG(&enum_case_InvalidClusters_value, CAIRO_STATUS_INVALID_CLUSTERS);
	zend_enum_add_case_cstr(class_entry, "InvalidClusters", &enum_case_InvalidClusters_value);

	zval enum_case_InvalidSlant_value;
	ZVAL_LONG(&enum_case_InvalidSlant_value, CAIRO_STATUS_INVALID_SLANT);
	zend_enum_add_case_cstr(class_entry, "InvalidSlant", &enum_case_InvalidSlant_value);

	zval enum_case_InvalidWeight_value;
	ZVAL_LONG(&enum_case_InvalidWeight_value, CAIRO_STATUS_INVALID_WEIGHT);
	zend_enum_add_case_cstr(class_entry, "InvalidWeight", &enum_case_InvalidWeight_value);

	zval enum_case_InvalidSize_value;
	ZVAL_LONG(&enum_case_InvalidSize_value, CAIRO_STATUS_INVALID_SIZE);
	zend_enum_add_case_cstr(class_entry, "InvalidSize", &enum_case_InvalidSize_value);

	zval enum_case_UserFontNotImplemented_value;
	ZVAL_LONG(&enum_case_UserFontNotImplemented_value, CAIRO_STATUS_USER_FONT_NOT_IMPLEMENTED);
	zend_enum_add_case_cstr(class_entry, "UserFontNotImplemented", &enum_case_UserFontNotImplemented_value);

	zval enum_case_DeviceTypeMismatch_value;
	ZVAL_LONG(&enum_case_DeviceTypeMismatch_value, CAIRO_STATUS_DEVICE_TYPE_MISMATCH);
	zend_enum_add_case_cstr(class_entry, "DeviceTypeMismatch", &enum_case_DeviceTypeMismatch_value);

	zval enum_case_DeviceError_value;
	ZVAL_LONG(&enum_case_DeviceError_value, CAIRO_STATUS_DEVICE_ERROR);
	zend_enum_add_case_cstr(class_entry, "DeviceError", &enum_case_DeviceError_value);

	zval enum_case_InvalidMeshConstruction_value;
	ZVAL_LONG(&enum_case_InvalidMeshConstruction_value, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	zend_enum_add_case_cstr(class_entry, "InvalidMeshConstruction", &enum_case_InvalidMeshConstruction_value);

	zval enum_case_DeviceFinished_value;
	ZVAL_LONG(&enum_case_DeviceFinished_value, CAIRO_STATUS_DEVICE_FINISHED);
	zend_enum_add_case_cstr(class_entry, "DeviceFinished", &enum_case_DeviceFinished_value);

	zval enum_case_LastStatus_value;
	ZVAL_LONG(&enum_case_LastStatus_value, CAIRO_STATUS_LAST_STATUS);
	zend_enum_add_case_cstr(class_entry, "LastStatus", &enum_case_LastStatus_value);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 14, 0)
	zval enum_case_JBIG2GlobalMissing_value;
	ZVAL_LONG(&enum_case_JBIG2GlobalMissing_value, CAIRO_STATUS_JBIG2_GLOBAL_MISSING);
	zend_enum_add_case_cstr(class_entry, "JBIG2GlobalMissing", &enum_case_JBIG2GlobalMissing_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Win32GDIError_value;
	ZVAL_LONG(&enum_case_Win32GDIError_value, CAIRO_STATUS_WIN32_GDI_ERROR);
	zend_enum_add_case_cstr(class_entry, "Win32GDIError", &enum_case_Win32GDIError_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_FreetypeError_value;
	ZVAL_LONG(&enum_case_FreetypeError_value, CAIRO_STATUS_FREETYPE_ERROR);
	zend_enum_add_case_cstr(class_entry, "FreetypeError", &enum_case_FreetypeError_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_PNGError_value;
	ZVAL_LONG(&enum_case_PNGError_value, CAIRO_STATUS_PNG_ERROR);
	zend_enum_add_case_cstr(class_entry, "PNGError", &enum_case_PNGError_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_TagError_value;
	ZVAL_LONG(&enum_case_TagError_value, CAIRO_STATUS_TAG_ERROR);
	zend_enum_add_case_cstr(class_entry, "TagError", &enum_case_TagError_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_DWriterError_value;
	ZVAL_LONG(&enum_case_DWriterError_value, CAIRO_STATUS_DWRITE_ERROR);
	zend_enum_add_case_cstr(class_entry, "DWriterError", &enum_case_DWriterError_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_SVGFontError_value;
	ZVAL_LONG(&enum_case_SVGFontError_value, CAIRO_STATUS_SVG_FONT_ERROR);
	zend_enum_add_case_cstr(class_entry, "SVGFontError", &enum_case_SVGFontError_value);
#endif

	return class_entry;
}
