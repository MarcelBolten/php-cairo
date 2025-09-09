/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8570f608b0754bdf2919275180bf9d3bc17f5333 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_ScaledFont___construct, 0, 0, 4)
	ZEND_ARG_OBJ_INFO(0, font_face, Cairo\\FontFace, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, Cairo\\Matrix, 0)
	ZEND_ARG_OBJ_INFO(0, ctm, Cairo\\Matrix, 0)
	ZEND_ARG_OBJ_INFO(0, options, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_ScaledFont_getStatus, 0, 0, Cairo\\Status, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_ScaledFont_getExtents, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_ScaledFont_getTextExtents, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_ScaledFont_getGlyphExtents, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, glyph, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_ScaledFont_getFontFace, 0, 0, Cairo\\FontFace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_ScaledFont_getFontOptions, 0, 0, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_ScaledFont_getFontMatrix, 0, 0, Cairo\\Matrix, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_ScaledFont_getCtm arginfo_class_Cairo_ScaledFont_getFontMatrix

#define arginfo_class_Cairo_ScaledFont_getScaleMatrix arginfo_class_Cairo_ScaledFont_getFontMatrix

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_ScaledFont_getType, 0, 0, Cairo\\FontType, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_ScaledFont_textToGlyphs, 0, 3, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, return_clusters, _IS_BOOL, 0, "false")
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_ScaledFont, __construct);
ZEND_METHOD(Cairo_ScaledFont, getStatus);
ZEND_METHOD(Cairo_ScaledFont, getExtents);
ZEND_METHOD(Cairo_ScaledFont, getTextExtents);
ZEND_METHOD(Cairo_ScaledFont, getGlyphExtents);
ZEND_METHOD(Cairo_ScaledFont, getFontFace);
ZEND_METHOD(Cairo_ScaledFont, getFontOptions);
ZEND_METHOD(Cairo_ScaledFont, getFontMatrix);
ZEND_METHOD(Cairo_ScaledFont, getCtm);
ZEND_METHOD(Cairo_ScaledFont, getScaleMatrix);
ZEND_METHOD(Cairo_ScaledFont, getType);
ZEND_METHOD(Cairo_ScaledFont, textToGlyphs);

static const zend_function_entry class_Cairo_ScaledFont_methods[] = {
	ZEND_ME(Cairo_ScaledFont, __construct, arginfo_class_Cairo_ScaledFont___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getStatus, arginfo_class_Cairo_ScaledFont_getStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getExtents, arginfo_class_Cairo_ScaledFont_getExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getTextExtents, arginfo_class_Cairo_ScaledFont_getTextExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getGlyphExtents, arginfo_class_Cairo_ScaledFont_getGlyphExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getFontFace, arginfo_class_Cairo_ScaledFont_getFontFace, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getFontOptions, arginfo_class_Cairo_ScaledFont_getFontOptions, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getFontMatrix, arginfo_class_Cairo_ScaledFont_getFontMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getCtm, arginfo_class_Cairo_ScaledFont_getCtm, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getScaleMatrix, arginfo_class_Cairo_ScaledFont_getScaleMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, getType, arginfo_class_Cairo_ScaledFont_getType, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_ScaledFont, textToGlyphs, arginfo_class_Cairo_ScaledFont_textToGlyphs, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_ScaledFont(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "ScaledFont", class_Cairo_ScaledFont_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}
