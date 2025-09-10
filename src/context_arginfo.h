/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 732060a29a00b42f8d33359df4b0d8cec81cdc0e */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Context___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, surface, Cairo\\Surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getStatus, 0, 0, Cairo\\Status, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_save, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_restore arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_pushGroup arginfo_class_Cairo_Context_save

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_pushGroupWithContent, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, content, Cairo\\Surface\\Content, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_popGroup, 0, 0, Cairo\\Pattern, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_popGroupToSource arginfo_class_Cairo_Context_save

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getGroupSurface, 0, 0, Cairo\\Surface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setSourceRgba, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, alpha, IS_DOUBLE, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setSurface, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, surface, Cairo\\Surface, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, x, IS_DOUBLE, 0, "0.0")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, y, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_getSurface arginfo_class_Cairo_Context_getGroupSurface

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setPattern, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pattern, Cairo\\Pattern, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_getPattern arginfo_class_Cairo_Context_popGroup

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setAntialias, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, antialias, Cairo\\Antialias, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getAntialias, 0, 0, Cairo\\Antialias, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setDash, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, dashes, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, offset, IS_DOUBLE, 0, "0.0")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_getDashCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_getDash, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setFillRule, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, fillrule, Cairo\\FillRule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getFillRule, 0, 0, Cairo\\FillRule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setLineCap, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, linecap, Cairo\\LineCap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getLineCap, 0, 0, Cairo\\LineCap, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setLineJoin, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, linejoin, Cairo\\LineJoin, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getLineJoin, 0, 0, Cairo\\LineJoin, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setLineWidth, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_getLineWidth, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setMiterLimit, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, limit, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_getMiterLimit arginfo_class_Cairo_Context_getLineWidth

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setOperator, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, operator, Cairo\\Operator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getOperator, 0, 0, Cairo\\Operator, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setTolerance, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, tolerance, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_getTolerance arginfo_class_Cairo_Context_getLineWidth

#define arginfo_class_Cairo_Context_clip arginfo_class_Cairo_Context_save

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_inClip, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_clipPreserve arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_resetClip arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_getClipExtents arginfo_class_Cairo_Context_getDash

#define arginfo_class_Cairo_Context_getClipRectangleList arginfo_class_Cairo_Context_getDash

#define arginfo_class_Cairo_Context_fill arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_fillPreserve arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_getFillExtents arginfo_class_Cairo_Context_getDash

#define arginfo_class_Cairo_Context_inFill arginfo_class_Cairo_Context_inClip

#define arginfo_class_Cairo_Context_mask arginfo_class_Cairo_Context_setPattern

#define arginfo_class_Cairo_Context_maskSurface arginfo_class_Cairo_Context_setSurface

#define arginfo_class_Cairo_Context_paint arginfo_class_Cairo_Context_save

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_paintWithAlpha, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_stroke arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_strokePreserve arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_getStrokeExtents arginfo_class_Cairo_Context_getDash

#define arginfo_class_Cairo_Context_inStroke arginfo_class_Cairo_Context_inClip

#define arginfo_class_Cairo_Context_copyPage arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_showPage arginfo_class_Cairo_Context_save

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setHairline, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, hairline, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_getHairline, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_translate, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_scale arginfo_class_Cairo_Context_translate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_rotate, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, angle, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_transform, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, matrix, Cairo\\Matrix, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_setMatrix arginfo_class_Cairo_Context_transform

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getMatrix, 0, 0, Cairo\\Matrix, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_identityMatrix arginfo_class_Cairo_Context_save

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_userToDevice, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_userToDeviceDistance arginfo_class_Cairo_Context_userToDevice

#define arginfo_class_Cairo_Context_deviceToUser arginfo_class_Cairo_Context_userToDevice

#define arginfo_class_Cairo_Context_deviceToUserDistance arginfo_class_Cairo_Context_userToDevice

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_copyPath, 0, 0, Cairo\\Path, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_copyPathFlat arginfo_class_Cairo_Context_copyPath

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_appendPath, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, path, Cairo\\Path, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_hasCurrentPoint, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_getCurrentPoint arginfo_class_Cairo_Context_getDash

#define arginfo_class_Cairo_Context_newPath arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_newSubPath arginfo_class_Cairo_Context_save

#define arginfo_class_Cairo_Context_closePath arginfo_class_Cairo_Context_save

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_arc, 0, 5, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, radius, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, angle1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, angle2, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_arcNegative arginfo_class_Cairo_Context_arc

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_curveTo, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y2, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, x3, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y3, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_lineTo arginfo_class_Cairo_Context_translate

#define arginfo_class_Cairo_Context_moveTo arginfo_class_Cairo_Context_translate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_rectangle, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_glyphPath, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, glyphs, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_textPath, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_relCurveTo arginfo_class_Cairo_Context_curveTo

#define arginfo_class_Cairo_Context_relLineTo arginfo_class_Cairo_Context_translate

#define arginfo_class_Cairo_Context_relMoveTo arginfo_class_Cairo_Context_translate

#define arginfo_class_Cairo_Context_getPathExtents arginfo_class_Cairo_Context_getDash

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_selectFontFace, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, family, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, slant, Cairo\\FontSlant, 0, "Cairo\\FontSlant::Normal")
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, weight, Cairo\\FontWeight, 0, "Cairo\\FontWeight::Normal")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setFontSize, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_setFontMatrix arginfo_class_Cairo_Context_transform

#define arginfo_class_Cairo_Context_getFontMatrix arginfo_class_Cairo_Context_getMatrix

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setFontOptions, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, options, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getFontOptions, 0, 0, Cairo\\FontOptions, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setFontFace, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, font_face, Cairo\\FontFace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getFontFace, 0, 0, Cairo\\FontFace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_setScaledFont, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, scaled_font, Cairo\\ScaledFont, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_Cairo_Context_getScaledFont, 0, 0, Cairo\\ScaledFont, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_showText arginfo_class_Cairo_Context_textPath

#define arginfo_class_Cairo_Context_showGlyphs arginfo_class_Cairo_Context_glyphPath

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_showTextGlyphs, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, glyphs, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, clusters, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, cluster_flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_Cairo_Context_getFontExtents arginfo_class_Cairo_Context_getDash

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_getTextExtents, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Context_getGlyphExtents, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, glyphs, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Context, __construct);
ZEND_METHOD(Cairo_Context, getStatus);
ZEND_METHOD(Cairo_Context, save);
ZEND_METHOD(Cairo_Context, restore);
ZEND_METHOD(Cairo_Context, pushGroup);
ZEND_METHOD(Cairo_Context, pushGroupWithContent);
ZEND_METHOD(Cairo_Context, popGroup);
ZEND_METHOD(Cairo_Context, popGroupToSource);
ZEND_METHOD(Cairo_Context, getGroupSurface);
ZEND_METHOD(Cairo_Context, setSourceRgba);
ZEND_METHOD(Cairo_Context, setSurface);
ZEND_METHOD(Cairo_Context, getSurface);
ZEND_METHOD(Cairo_Context, setPattern);
ZEND_METHOD(Cairo_Context, getPattern);
ZEND_METHOD(Cairo_Context, setAntialias);
ZEND_METHOD(Cairo_Context, getAntialias);
ZEND_METHOD(Cairo_Context, setDash);
ZEND_METHOD(Cairo_Context, getDashCount);
ZEND_METHOD(Cairo_Context, getDash);
ZEND_METHOD(Cairo_Context, setFillRule);
ZEND_METHOD(Cairo_Context, getFillRule);
ZEND_METHOD(Cairo_Context, setLineCap);
ZEND_METHOD(Cairo_Context, getLineCap);
ZEND_METHOD(Cairo_Context, setLineJoin);
ZEND_METHOD(Cairo_Context, getLineJoin);
ZEND_METHOD(Cairo_Context, setLineWidth);
ZEND_METHOD(Cairo_Context, getLineWidth);
ZEND_METHOD(Cairo_Context, setMiterLimit);
ZEND_METHOD(Cairo_Context, getMiterLimit);
ZEND_METHOD(Cairo_Context, setOperator);
ZEND_METHOD(Cairo_Context, getOperator);
ZEND_METHOD(Cairo_Context, setTolerance);
ZEND_METHOD(Cairo_Context, getTolerance);
ZEND_METHOD(Cairo_Context, clip);
ZEND_METHOD(Cairo_Context, inClip);
ZEND_METHOD(Cairo_Context, clipPreserve);
ZEND_METHOD(Cairo_Context, resetClip);
ZEND_METHOD(Cairo_Context, getClipExtents);
ZEND_METHOD(Cairo_Context, getClipRectangleList);
ZEND_METHOD(Cairo_Context, fill);
ZEND_METHOD(Cairo_Context, fillPreserve);
ZEND_METHOD(Cairo_Context, getFillExtents);
ZEND_METHOD(Cairo_Context, inFill);
ZEND_METHOD(Cairo_Context, mask);
ZEND_METHOD(Cairo_Context, maskSurface);
ZEND_METHOD(Cairo_Context, paint);
ZEND_METHOD(Cairo_Context, paintWithAlpha);
ZEND_METHOD(Cairo_Context, stroke);
ZEND_METHOD(Cairo_Context, strokePreserve);
ZEND_METHOD(Cairo_Context, getStrokeExtents);
ZEND_METHOD(Cairo_Context, inStroke);
ZEND_METHOD(Cairo_Context, copyPage);
ZEND_METHOD(Cairo_Context, showPage);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
ZEND_METHOD(Cairo_Context, setHairline);
ZEND_METHOD(Cairo_Context, getHairline);
#endif
ZEND_METHOD(Cairo_Context, translate);
ZEND_METHOD(Cairo_Context, scale);
ZEND_METHOD(Cairo_Context, rotate);
ZEND_METHOD(Cairo_Context, transform);
ZEND_METHOD(Cairo_Context, setMatrix);
ZEND_METHOD(Cairo_Context, getMatrix);
ZEND_METHOD(Cairo_Context, identityMatrix);
ZEND_METHOD(Cairo_Context, userToDevice);
ZEND_METHOD(Cairo_Context, userToDeviceDistance);
ZEND_METHOD(Cairo_Context, deviceToUser);
ZEND_METHOD(Cairo_Context, deviceToUserDistance);
ZEND_METHOD(Cairo_Context, copyPath);
ZEND_METHOD(Cairo_Context, copyPathFlat);
ZEND_METHOD(Cairo_Context, appendPath);
ZEND_METHOD(Cairo_Context, hasCurrentPoint);
ZEND_METHOD(Cairo_Context, getCurrentPoint);
ZEND_METHOD(Cairo_Context, newPath);
ZEND_METHOD(Cairo_Context, newSubPath);
ZEND_METHOD(Cairo_Context, closePath);
ZEND_METHOD(Cairo_Context, arc);
ZEND_METHOD(Cairo_Context, arcNegative);
ZEND_METHOD(Cairo_Context, curveTo);
ZEND_METHOD(Cairo_Context, lineTo);
ZEND_METHOD(Cairo_Context, moveTo);
ZEND_METHOD(Cairo_Context, rectangle);
ZEND_METHOD(Cairo_Context, glyphPath);
ZEND_METHOD(Cairo_Context, textPath);
ZEND_METHOD(Cairo_Context, relCurveTo);
ZEND_METHOD(Cairo_Context, relLineTo);
ZEND_METHOD(Cairo_Context, relMoveTo);
ZEND_METHOD(Cairo_Context, getPathExtents);
ZEND_METHOD(Cairo_Context, selectFontFace);
ZEND_METHOD(Cairo_Context, setFontSize);
ZEND_METHOD(Cairo_Context, setFontMatrix);
ZEND_METHOD(Cairo_Context, getFontMatrix);
ZEND_METHOD(Cairo_Context, setFontOptions);
ZEND_METHOD(Cairo_Context, getFontOptions);
ZEND_METHOD(Cairo_Context, setFontFace);
ZEND_METHOD(Cairo_Context, getFontFace);
ZEND_METHOD(Cairo_Context, setScaledFont);
ZEND_METHOD(Cairo_Context, getScaledFont);
ZEND_METHOD(Cairo_Context, showText);
ZEND_METHOD(Cairo_Context, showGlyphs);
ZEND_METHOD(Cairo_Context, showTextGlyphs);
ZEND_METHOD(Cairo_Context, getFontExtents);
ZEND_METHOD(Cairo_Context, getTextExtents);
ZEND_METHOD(Cairo_Context, getGlyphExtents);

static const zend_function_entry class_Cairo_Context_methods[] = {
	ZEND_ME(Cairo_Context, __construct, arginfo_class_Cairo_Context___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getStatus, arginfo_class_Cairo_Context_getStatus, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, save, arginfo_class_Cairo_Context_save, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, restore, arginfo_class_Cairo_Context_restore, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, pushGroup, arginfo_class_Cairo_Context_pushGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, pushGroupWithContent, arginfo_class_Cairo_Context_pushGroupWithContent, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, popGroup, arginfo_class_Cairo_Context_popGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, popGroupToSource, arginfo_class_Cairo_Context_popGroupToSource, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getGroupSurface, arginfo_class_Cairo_Context_getGroupSurface, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setSourceRgba, arginfo_class_Cairo_Context_setSourceRgba, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setSurface, arginfo_class_Cairo_Context_setSurface, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getSurface, arginfo_class_Cairo_Context_getSurface, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setPattern, arginfo_class_Cairo_Context_setPattern, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getPattern, arginfo_class_Cairo_Context_getPattern, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setAntialias, arginfo_class_Cairo_Context_setAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getAntialias, arginfo_class_Cairo_Context_getAntialias, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setDash, arginfo_class_Cairo_Context_setDash, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getDashCount, arginfo_class_Cairo_Context_getDashCount, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getDash, arginfo_class_Cairo_Context_getDash, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setFillRule, arginfo_class_Cairo_Context_setFillRule, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getFillRule, arginfo_class_Cairo_Context_getFillRule, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setLineCap, arginfo_class_Cairo_Context_setLineCap, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getLineCap, arginfo_class_Cairo_Context_getLineCap, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setLineJoin, arginfo_class_Cairo_Context_setLineJoin, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getLineJoin, arginfo_class_Cairo_Context_getLineJoin, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setLineWidth, arginfo_class_Cairo_Context_setLineWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getLineWidth, arginfo_class_Cairo_Context_getLineWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setMiterLimit, arginfo_class_Cairo_Context_setMiterLimit, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getMiterLimit, arginfo_class_Cairo_Context_getMiterLimit, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setOperator, arginfo_class_Cairo_Context_setOperator, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getOperator, arginfo_class_Cairo_Context_getOperator, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setTolerance, arginfo_class_Cairo_Context_setTolerance, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getTolerance, arginfo_class_Cairo_Context_getTolerance, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, clip, arginfo_class_Cairo_Context_clip, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, inClip, arginfo_class_Cairo_Context_inClip, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, clipPreserve, arginfo_class_Cairo_Context_clipPreserve, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, resetClip, arginfo_class_Cairo_Context_resetClip, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getClipExtents, arginfo_class_Cairo_Context_getClipExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getClipRectangleList, arginfo_class_Cairo_Context_getClipRectangleList, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, fill, arginfo_class_Cairo_Context_fill, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, fillPreserve, arginfo_class_Cairo_Context_fillPreserve, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getFillExtents, arginfo_class_Cairo_Context_getFillExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, inFill, arginfo_class_Cairo_Context_inFill, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, mask, arginfo_class_Cairo_Context_mask, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, maskSurface, arginfo_class_Cairo_Context_maskSurface, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, paint, arginfo_class_Cairo_Context_paint, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, paintWithAlpha, arginfo_class_Cairo_Context_paintWithAlpha, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, stroke, arginfo_class_Cairo_Context_stroke, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, strokePreserve, arginfo_class_Cairo_Context_strokePreserve, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getStrokeExtents, arginfo_class_Cairo_Context_getStrokeExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, inStroke, arginfo_class_Cairo_Context_inStroke, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, copyPage, arginfo_class_Cairo_Context_copyPage, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, showPage, arginfo_class_Cairo_Context_showPage, ZEND_ACC_PUBLIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	ZEND_ME(Cairo_Context, setHairline, arginfo_class_Cairo_Context_setHairline, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getHairline, arginfo_class_Cairo_Context_getHairline, ZEND_ACC_PUBLIC)
#endif
	ZEND_ME(Cairo_Context, translate, arginfo_class_Cairo_Context_translate, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, scale, arginfo_class_Cairo_Context_scale, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, rotate, arginfo_class_Cairo_Context_rotate, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, transform, arginfo_class_Cairo_Context_transform, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setMatrix, arginfo_class_Cairo_Context_setMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getMatrix, arginfo_class_Cairo_Context_getMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, identityMatrix, arginfo_class_Cairo_Context_identityMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, userToDevice, arginfo_class_Cairo_Context_userToDevice, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, userToDeviceDistance, arginfo_class_Cairo_Context_userToDeviceDistance, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, deviceToUser, arginfo_class_Cairo_Context_deviceToUser, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, deviceToUserDistance, arginfo_class_Cairo_Context_deviceToUserDistance, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, copyPath, arginfo_class_Cairo_Context_copyPath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, copyPathFlat, arginfo_class_Cairo_Context_copyPathFlat, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, appendPath, arginfo_class_Cairo_Context_appendPath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, hasCurrentPoint, arginfo_class_Cairo_Context_hasCurrentPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getCurrentPoint, arginfo_class_Cairo_Context_getCurrentPoint, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, newPath, arginfo_class_Cairo_Context_newPath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, newSubPath, arginfo_class_Cairo_Context_newSubPath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, closePath, arginfo_class_Cairo_Context_closePath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, arc, arginfo_class_Cairo_Context_arc, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, arcNegative, arginfo_class_Cairo_Context_arcNegative, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, curveTo, arginfo_class_Cairo_Context_curveTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, lineTo, arginfo_class_Cairo_Context_lineTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, moveTo, arginfo_class_Cairo_Context_moveTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, rectangle, arginfo_class_Cairo_Context_rectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, glyphPath, arginfo_class_Cairo_Context_glyphPath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, textPath, arginfo_class_Cairo_Context_textPath, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, relCurveTo, arginfo_class_Cairo_Context_relCurveTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, relLineTo, arginfo_class_Cairo_Context_relLineTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, relMoveTo, arginfo_class_Cairo_Context_relMoveTo, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getPathExtents, arginfo_class_Cairo_Context_getPathExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, selectFontFace, arginfo_class_Cairo_Context_selectFontFace, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setFontSize, arginfo_class_Cairo_Context_setFontSize, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setFontMatrix, arginfo_class_Cairo_Context_setFontMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getFontMatrix, arginfo_class_Cairo_Context_getFontMatrix, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setFontOptions, arginfo_class_Cairo_Context_setFontOptions, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getFontOptions, arginfo_class_Cairo_Context_getFontOptions, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setFontFace, arginfo_class_Cairo_Context_setFontFace, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getFontFace, arginfo_class_Cairo_Context_getFontFace, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, setScaledFont, arginfo_class_Cairo_Context_setScaledFont, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getScaledFont, arginfo_class_Cairo_Context_getScaledFont, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, showText, arginfo_class_Cairo_Context_showText, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, showGlyphs, arginfo_class_Cairo_Context_showGlyphs, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, showTextGlyphs, arginfo_class_Cairo_Context_showTextGlyphs, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getFontExtents, arginfo_class_Cairo_Context_getFontExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getTextExtents, arginfo_class_Cairo_Context_getTextExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Context, getGlyphExtents, arginfo_class_Cairo_Context_getGlyphExtents, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Context(void)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo", "Context", class_Cairo_Context_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, NULL);
#endif

	return class_entry;
}

static zend_class_entry *register_class_Cairo_FillRule(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\FillRule", IS_LONG, NULL);

	zval enum_case_Winding_value;
	ZVAL_LONG(&enum_case_Winding_value, CAIRO_FILL_RULE_WINDING);
	zend_enum_add_case_cstr(class_entry, "Winding", &enum_case_Winding_value);

	zval enum_case_EvenOdd_value;
	ZVAL_LONG(&enum_case_EvenOdd_value, CAIRO_FILL_RULE_EVEN_ODD);
	zend_enum_add_case_cstr(class_entry, "EvenOdd", &enum_case_EvenOdd_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_LineCap(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\LineCap", IS_LONG, NULL);

	zval enum_case_Butt_value;
	ZVAL_LONG(&enum_case_Butt_value, CAIRO_LINE_CAP_BUTT);
	zend_enum_add_case_cstr(class_entry, "Butt", &enum_case_Butt_value);

	zval enum_case_Round_value;
	ZVAL_LONG(&enum_case_Round_value, CAIRO_LINE_CAP_ROUND);
	zend_enum_add_case_cstr(class_entry, "Round", &enum_case_Round_value);

	zval enum_case_Square_value;
	ZVAL_LONG(&enum_case_Square_value, CAIRO_LINE_CAP_SQUARE);
	zend_enum_add_case_cstr(class_entry, "Square", &enum_case_Square_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_LineJoin(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\LineJoin", IS_LONG, NULL);

	zval enum_case_Miter_value;
	ZVAL_LONG(&enum_case_Miter_value, CAIRO_LINE_JOIN_MITER);
	zend_enum_add_case_cstr(class_entry, "Miter", &enum_case_Miter_value);

	zval enum_case_Round_value;
	ZVAL_LONG(&enum_case_Round_value, CAIRO_LINE_JOIN_ROUND);
	zend_enum_add_case_cstr(class_entry, "Round", &enum_case_Round_value);

	zval enum_case_Bevel_value;
	ZVAL_LONG(&enum_case_Bevel_value, CAIRO_LINE_JOIN_BEVEL);
	zend_enum_add_case_cstr(class_entry, "Bevel", &enum_case_Bevel_value);

	return class_entry;
}

static zend_class_entry *register_class_Cairo_Operator(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("Cairo\\Operator", IS_LONG, NULL);

	zval enum_case_Clear_value;
	ZVAL_LONG(&enum_case_Clear_value, CAIRO_OPERATOR_CLEAR);
	zend_enum_add_case_cstr(class_entry, "Clear", &enum_case_Clear_value);

	zval enum_case_Source_value;
	ZVAL_LONG(&enum_case_Source_value, CAIRO_OPERATOR_SOURCE);
	zend_enum_add_case_cstr(class_entry, "Source", &enum_case_Source_value);

	zval enum_case_Over_value;
	ZVAL_LONG(&enum_case_Over_value, CAIRO_OPERATOR_OVER);
	zend_enum_add_case_cstr(class_entry, "Over", &enum_case_Over_value);

	zval enum_case_In_value;
	ZVAL_LONG(&enum_case_In_value, CAIRO_OPERATOR_IN);
	zend_enum_add_case_cstr(class_entry, "In", &enum_case_In_value);

	zval enum_case_Out_value;
	ZVAL_LONG(&enum_case_Out_value, CAIRO_OPERATOR_OUT);
	zend_enum_add_case_cstr(class_entry, "Out", &enum_case_Out_value);

	zval enum_case_Atop_value;
	ZVAL_LONG(&enum_case_Atop_value, CAIRO_OPERATOR_ATOP);
	zend_enum_add_case_cstr(class_entry, "Atop", &enum_case_Atop_value);

	zval enum_case_Dest_value;
	ZVAL_LONG(&enum_case_Dest_value, CAIRO_OPERATOR_DEST);
	zend_enum_add_case_cstr(class_entry, "Dest", &enum_case_Dest_value);

	zval enum_case_DestOver_value;
	ZVAL_LONG(&enum_case_DestOver_value, CAIRO_OPERATOR_DEST_OVER);
	zend_enum_add_case_cstr(class_entry, "DestOver", &enum_case_DestOver_value);

	zval enum_case_DestIn_value;
	ZVAL_LONG(&enum_case_DestIn_value, CAIRO_OPERATOR_DEST_IN);
	zend_enum_add_case_cstr(class_entry, "DestIn", &enum_case_DestIn_value);

	zval enum_case_DestOut_value;
	ZVAL_LONG(&enum_case_DestOut_value, CAIRO_OPERATOR_DEST_OUT);
	zend_enum_add_case_cstr(class_entry, "DestOut", &enum_case_DestOut_value);

	zval enum_case_DestAtop_value;
	ZVAL_LONG(&enum_case_DestAtop_value, CAIRO_OPERATOR_DEST_ATOP);
	zend_enum_add_case_cstr(class_entry, "DestAtop", &enum_case_DestAtop_value);

	zval enum_case_Xor_value;
	ZVAL_LONG(&enum_case_Xor_value, CAIRO_OPERATOR_XOR);
	zend_enum_add_case_cstr(class_entry, "Xor", &enum_case_Xor_value);

	zval enum_case_Add_value;
	ZVAL_LONG(&enum_case_Add_value, CAIRO_OPERATOR_ADD);
	zend_enum_add_case_cstr(class_entry, "Add", &enum_case_Add_value);

	zval enum_case_Saturate_value;
	ZVAL_LONG(&enum_case_Saturate_value, CAIRO_OPERATOR_SATURATE);
	zend_enum_add_case_cstr(class_entry, "Saturate", &enum_case_Saturate_value);

	zval enum_case_Multiply_value;
	ZVAL_LONG(&enum_case_Multiply_value, CAIRO_OPERATOR_MULTIPLY);
	zend_enum_add_case_cstr(class_entry, "Multiply", &enum_case_Multiply_value);

	zval enum_case_Screen_value;
	ZVAL_LONG(&enum_case_Screen_value, CAIRO_OPERATOR_SCREEN);
	zend_enum_add_case_cstr(class_entry, "Screen", &enum_case_Screen_value);

	zval enum_case_Overlay_value;
	ZVAL_LONG(&enum_case_Overlay_value, CAIRO_OPERATOR_OVERLAY);
	zend_enum_add_case_cstr(class_entry, "Overlay", &enum_case_Overlay_value);

	zval enum_case_Darken_value;
	ZVAL_LONG(&enum_case_Darken_value, CAIRO_OPERATOR_DARKEN);
	zend_enum_add_case_cstr(class_entry, "Darken", &enum_case_Darken_value);

	zval enum_case_Lighten_value;
	ZVAL_LONG(&enum_case_Lighten_value, CAIRO_OPERATOR_LIGHTEN);
	zend_enum_add_case_cstr(class_entry, "Lighten", &enum_case_Lighten_value);

	zval enum_case_ColorDodge_value;
	ZVAL_LONG(&enum_case_ColorDodge_value, CAIRO_OPERATOR_COLOR_DODGE);
	zend_enum_add_case_cstr(class_entry, "ColorDodge", &enum_case_ColorDodge_value);

	zval enum_case_ColorBurn_value;
	ZVAL_LONG(&enum_case_ColorBurn_value, CAIRO_OPERATOR_COLOR_BURN);
	zend_enum_add_case_cstr(class_entry, "ColorBurn", &enum_case_ColorBurn_value);

	zval enum_case_HardLight_value;
	ZVAL_LONG(&enum_case_HardLight_value, CAIRO_OPERATOR_HARD_LIGHT);
	zend_enum_add_case_cstr(class_entry, "HardLight", &enum_case_HardLight_value);

	zval enum_case_SoftLight_value;
	ZVAL_LONG(&enum_case_SoftLight_value, CAIRO_OPERATOR_SOFT_LIGHT);
	zend_enum_add_case_cstr(class_entry, "SoftLight", &enum_case_SoftLight_value);

	zval enum_case_Difference_value;
	ZVAL_LONG(&enum_case_Difference_value, CAIRO_OPERATOR_DIFFERENCE);
	zend_enum_add_case_cstr(class_entry, "Difference", &enum_case_Difference_value);

	zval enum_case_Exclusion_value;
	ZVAL_LONG(&enum_case_Exclusion_value, CAIRO_OPERATOR_EXCLUSION);
	zend_enum_add_case_cstr(class_entry, "Exclusion", &enum_case_Exclusion_value);

	zval enum_case_HslHue_value;
	ZVAL_LONG(&enum_case_HslHue_value, CAIRO_OPERATOR_HSL_HUE);
	zend_enum_add_case_cstr(class_entry, "HslHue", &enum_case_HslHue_value);

	zval enum_case_HslSaturation_value;
	ZVAL_LONG(&enum_case_HslSaturation_value, CAIRO_OPERATOR_HSL_SATURATION);
	zend_enum_add_case_cstr(class_entry, "HslSaturation", &enum_case_HslSaturation_value);

	zval enum_case_HslColor_value;
	ZVAL_LONG(&enum_case_HslColor_value, CAIRO_OPERATOR_HSL_COLOR);
	zend_enum_add_case_cstr(class_entry, "HslColor", &enum_case_HslColor_value);

	zval enum_case_HslLuminosity_value;
	ZVAL_LONG(&enum_case_HslLuminosity_value, CAIRO_OPERATOR_HSL_LUMINOSITY);
	zend_enum_add_case_cstr(class_entry, "HslLuminosity", &enum_case_HslLuminosity_value);

	return class_entry;
}
