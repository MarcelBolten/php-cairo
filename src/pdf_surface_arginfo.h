/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 78fefa818d7bc6a57740a8ae302eed7ce2a6ab72 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface_Pdf___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_restrictToVersion, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Pdf\\Version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_getVersions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_versionToString, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Pdf\\Version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_setSize, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_addOutline, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, link_attribs, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, outline_flag, Cairo\\Surface\\Pdf\\OutlineFlags, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_setMetadata, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, field, Cairo\\Surface\\Pdf\\Metadata, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, value, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_setPageLabel, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_setThumbnailSize, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Pdf_setCustomMetadata, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(Cairo_Surface_Pdf, __construct);
ZEND_METHOD(Cairo_Surface_Pdf, restrictToVersion);
ZEND_METHOD(Cairo_Surface_Pdf, getVersions);
ZEND_METHOD(Cairo_Surface_Pdf, versionToString);
ZEND_METHOD(Cairo_Surface_Pdf, setSize);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
ZEND_METHOD(Cairo_Surface_Pdf, addOutline);
ZEND_METHOD(Cairo_Surface_Pdf, setMetadata);
ZEND_METHOD(Cairo_Surface_Pdf, setPageLabel);
ZEND_METHOD(Cairo_Surface_Pdf, setThumbnailSize);
#endif
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_METHOD(Cairo_Surface_Pdf, setCustomMetadata);
#endif

static const zend_function_entry class_Cairo_Surface_Pdf_methods[] = {
	ZEND_ME(Cairo_Surface_Pdf, __construct, arginfo_class_Cairo_Surface_Pdf___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Pdf, restrictToVersion, arginfo_class_Cairo_Surface_Pdf_restrictToVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Pdf, getVersions, arginfo_class_Cairo_Surface_Pdf_getVersions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Surface_Pdf, versionToString, arginfo_class_Cairo_Surface_Pdf_versionToString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(Cairo_Surface_Pdf, setSize, arginfo_class_Cairo_Surface_Pdf_setSize, ZEND_ACC_PUBLIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	ZEND_ME(Cairo_Surface_Pdf, addOutline, arginfo_class_Cairo_Surface_Pdf_addOutline, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Pdf, setMetadata, arginfo_class_Cairo_Surface_Pdf_setMetadata, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Pdf, setPageLabel, arginfo_class_Cairo_Surface_Pdf_setPageLabel, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Pdf, setThumbnailSize, arginfo_class_Cairo_Surface_Pdf_setThumbnailSize, ZEND_ACC_PUBLIC)
#endif
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	ZEND_ME(Cairo_Surface_Pdf, setCustomMetadata, arginfo_class_Cairo_Surface_Pdf_setCustomMetadata, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Surface_Pdf(zend_class_entry *class_entry_Cairo_Surface)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Surface", "Pdf", class_Cairo_Surface_Pdf_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)

	zval const_OUTLINE_ROOT_value;
	ZVAL_LONG(&const_OUTLINE_ROOT_value, CAIRO_PDF_OUTLINE_ROOT);
	zend_string *const_OUTLINE_ROOT_name = zend_string_init_interned("OUTLINE_ROOT", sizeof("OUTLINE_ROOT") - 1, 1);
	zend_declare_class_constant_ex(class_entry, const_OUTLINE_ROOT_name, &const_OUTLINE_ROOT_value, ZEND_ACC_PUBLIC, NULL);
	zend_string_release(const_OUTLINE_ROOT_name);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Surface_Pdf_Version(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Pdf\\Version", IS_LONG, NULL);

	zval enum_case_Version_1_4_value;
	ZVAL_LONG(&enum_case_Version_1_4_value, CAIRO_PDF_VERSION_1_4);
	zend_enum_add_case_cstr(class_entry, "Version_1_4", &enum_case_Version_1_4_value);

	zval enum_case_Version_1_5_value;
	ZVAL_LONG(&enum_case_Version_1_5_value, CAIRO_PDF_VERSION_1_5);
	zend_enum_add_case_cstr(class_entry, "Version_1_5", &enum_case_Version_1_5_value);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Version_1_6_value;
	ZVAL_LONG(&enum_case_Version_1_6_value, CAIRO_PDF_VERSION_1_6);
	zend_enum_add_case_cstr(class_entry, "Version_1_6", &enum_case_Version_1_6_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	zval enum_case_Version_1_7_value;
	ZVAL_LONG(&enum_case_Version_1_7_value, CAIRO_PDF_VERSION_1_7);
	zend_enum_add_case_cstr(class_entry, "Version_1_7", &enum_case_Version_1_7_value);
#endif

	return class_entry;
}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
static zend_class_entry *register_class_Cairo_Surface_Pdf_OutlineFlags(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Pdf\\OutlineFlags", IS_LONG, NULL);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Open_value;
	ZVAL_LONG(&enum_case_Open_value, CAIRO_PDF_OUTLINE_FLAG_OPEN);
	zend_enum_add_case_cstr(class_entry, "Open", &enum_case_Open_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Bold_value;
	ZVAL_LONG(&enum_case_Bold_value, CAIRO_PDF_OUTLINE_FLAG_BOLD);
	zend_enum_add_case_cstr(class_entry, "Bold", &enum_case_Bold_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Italic_value;
	ZVAL_LONG(&enum_case_Italic_value, CAIRO_PDF_OUTLINE_FLAG_ITALIC);
	zend_enum_add_case_cstr(class_entry, "Italic", &enum_case_Italic_value);
#endif

	return class_entry;
}
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
static zend_class_entry *register_class_Cairo_Surface_Pdf_Metadata(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Surface\\Pdf\\Metadata", IS_LONG, NULL);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Title_value;
	ZVAL_LONG(&enum_case_Title_value, CAIRO_PDF_METADATA_TITLE);
	zend_enum_add_case_cstr(class_entry, "Title", &enum_case_Title_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Author_value;
	ZVAL_LONG(&enum_case_Author_value, CAIRO_PDF_METADATA_AUTHOR);
	zend_enum_add_case_cstr(class_entry, "Author", &enum_case_Author_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Subject_value;
	ZVAL_LONG(&enum_case_Subject_value, CAIRO_PDF_METADATA_SUBJECT);
	zend_enum_add_case_cstr(class_entry, "Subject", &enum_case_Subject_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Keywords_value;
	ZVAL_LONG(&enum_case_Keywords_value, CAIRO_PDF_METADATA_KEYWORDS);
	zend_enum_add_case_cstr(class_entry, "Keywords", &enum_case_Keywords_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_Creator_value;
	ZVAL_LONG(&enum_case_Creator_value, CAIRO_PDF_METADATA_CREATOR);
	zend_enum_add_case_cstr(class_entry, "Creator", &enum_case_Creator_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_CreateDate_value;
	ZVAL_LONG(&enum_case_CreateDate_value, CAIRO_PDF_METADATA_CREATE_DATE);
	zend_enum_add_case_cstr(class_entry, "CreateDate", &enum_case_CreateDate_value);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	zval enum_case_ModDate_value;
	ZVAL_LONG(&enum_case_ModDate_value, CAIRO_PDF_METADATA_MOD_DATE);
	zend_enum_add_case_cstr(class_entry, "ModDate", &enum_case_ModDate_value);
#endif

	return class_entry;
}
#endif
