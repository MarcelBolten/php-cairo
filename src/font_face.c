/*
  +----------------------------------------------------------------------+
  | For PHP Version 8                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 2015 Elizabeth M Smith                                 |
  +----------------------------------------------------------------------+
  | http://www.opensource.org/licenses/mit-license.php  MIT License      |
  | Also available in LICENSE                                            |
  +----------------------------------------------------------------------+
  | Authors: Elizabeth M Smith <auroraeosrose@gmail.com>                 |
  |          Swen Zanon <swen.zanon@geoglis.de>                          |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cairo.h>
#include <php.h>
#include <zend_exceptions.h>

#include "php_cairo.h"
#include "php_cairo_internal.h"


zend_class_entry *ce_cairo_fontface;
zend_class_entry *ce_cairo_fonttype;

static zend_object_handlers cairo_font_face_object_handlers;

cairo_font_face_object *cairo_font_face_fetch_object(zend_object *object)
{
    return (cairo_font_face_object *) ((char*)(object) - XtOffsetOf(cairo_font_face_object, std));
}

cairo_font_face_object *cairo_font_face_object_get(zval *zv)
{
    cairo_font_face_object *object = Z_CAIRO_FONT_FACE_P(zv);

    if (object->font_face == NULL) {
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Internal font face object missing in %s, you must call parent::__construct in extended classes.",
            ZSTR_VAL(Z_OBJCE_P(zv)->name));
        return NULL;
    }

    return object;
}


/* ----------------------------------------------------------------
    \Cairo\FontOptions C API
------------------------------------------------------------------*/

/* {{{ */
zend_class_entry * php_cairo_get_fontface_ce()
{
    return ce_cairo_fontface;
}
/* }}} */

/* {{{ */
cairo_font_face_t *cairo_font_face_object_get_font_face(zval *zv)
{
    return cairo_font_face_object_get(zv)->font_face;
}
/* }}} */

/* ----------------------------------------------------------------
    \Cairo\FontOptions Class API
------------------------------------------------------------------*/
/* {{{ proto void \Cairo\FontFace::__contruct()
   \Cairo\FontFace CANNOT be extended in userspace, this will throw an exception on use */
PHP_METHOD(CairoFontFace, __construct)
{
    zend_throw_exception(ce_cairo_exception, "Cairo\\FontFace cannot be constructed", 0);
}
/* }}} */

/* {{{ proto \Cairo\Status \Cairo\FontFace::getStatus()
       Returns the current integer status of the CairoFontFace */
PHP_METHOD(CairoFontFace, getStatus)
{
    cairo_font_face_object *font_face_object;
    zval status_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = cairo_font_face_object_get(getThis());
    if (!font_face_object) {
        RETURN_THROWS();
    }

    status_case = php_enum_from_cairo_c_enum(
        ce_cairo_status,
        cairo_font_face_status(font_face_object->font_face)
    );

    if (Z_TYPE(status_case) == IS_OBJECT) {
        RETURN_ZVAL(&status_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto \Cairo\FontFace \Cairo\FontFace::getType()
       Returns the current integer type of the Cairo\FontFace backend */
PHP_METHOD(CairoFontFace, getType)
{
    cairo_font_face_object *font_face_object;
    zval fonttype_case;

    ZEND_PARSE_PARAMETERS_NONE();

    font_face_object = cairo_font_face_object_get(getThis());
    if (!font_face_object) {
        RETURN_THROWS();
    }

    fonttype_case = php_enum_from_cairo_c_enum(
        ce_cairo_fonttype,
        cairo_font_face_get_type(font_face_object->font_face)
    );

    if (Z_TYPE(fonttype_case) == IS_OBJECT) {
        RETURN_ZVAL(&fonttype_case, 1, 1);
    }
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\FontFace Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_font_face_free_obj(zend_object *object)
{
    cairo_font_face_object *intern = cairo_font_face_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->font_face) {
        cairo_font_face_destroy(intern->font_face);
        intern->font_face = NULL;
    }

    if (intern->closure != NULL) {
        if (intern->closure->owned_stream) {
            php_stream_close(intern->closure->stream);
        }
        efree(intern->closure);
    }

    zend_object_std_dtor(&intern->std);
}

/* {{{ */
static zend_object* cairo_font_face_obj_ctor(zend_class_entry *ce, cairo_font_face_object **intern)
{
    cairo_font_face_object *object = ecalloc(1, sizeof(cairo_font_face_object) + zend_object_properties_size(ce));

    object->font_face = NULL;
    object->closure = NULL;

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &cairo_font_face_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
zend_object* cairo_font_face_create_object(zend_class_entry *ce)
{
    cairo_font_face_object *font_face_obj = NULL;
    zend_object *return_value = cairo_font_face_obj_ctor(ce, &font_face_obj);

    object_properties_init(&font_face_obj->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* cairo_font_face_clone_obj(zend_object *old_object)
{
    cairo_font_face_object *new_font, *old_font;
    old_font = cairo_font_face_fetch_object(old_object);

    zend_object *return_value = cairo_font_face_obj_ctor(old_object->ce, &new_font);
    zend_objects_clone_members(&new_font->std, &old_font->std);

    /* Fonts are created and then never changed, with the exception of
     * the set_user_data stuff. That means we don't have to do any
     * real cloning of the font -- just increase it's ref count and
     * point the new font to the old one. Simples.
     */
    cairo_font_face_reference(old_font->font_face);
    new_font->font_face = old_font->font_face;

    return return_value;
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\FontFace Definition and registration
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO(CairoFontFace_method_no_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ cairo_font_face_methods[] */
static const zend_function_entry cairo_font_face_methods[] = {
    PHP_ME(CairoFontFace, __construct, CairoFontFace_method_no_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(CairoFontFace, getStatus, CairoFontFace_method_no_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoFontFace, getType, CairoFontFace_method_no_args, ZEND_ACC_PUBLIC)
    ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_font_face)
{
    zend_class_entry fontface_ce;

    memcpy(
        &cairo_font_face_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    /* FontFace */
    cairo_font_face_object_handlers.offset = XtOffsetOf(cairo_font_face_object, std);
    cairo_font_face_object_handlers.free_obj = cairo_font_face_free_obj;
    cairo_font_face_object_handlers.clone_obj = cairo_font_face_clone_obj;

    INIT_NS_CLASS_ENTRY(fontface_ce, CAIRO_NAMESPACE, "FontFace", cairo_font_face_methods);
    ce_cairo_fontface = zend_register_internal_class(&fontface_ce);
    ce_cairo_fontface->create_object = cairo_font_face_create_object;
    ce_cairo_fontface->ce_flags |= ZEND_ACC_EXPLICIT_ABSTRACT_CLASS;

    /* FontType */
    CAIRO_REGISTER_ENUM_LONG("FontType", ce_cairo_fonttype);

#define CAIRO_FONTTYPE_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_fonttype, CAIRO_FONT_TYPE)

    CAIRO_FONTTYPE_DECLARE_ENUM_CASE(TOY);
    CAIRO_FONTTYPE_DECLARE_ENUM_CASE(FT);
    CAIRO_FONTTYPE_DECLARE_ENUM_CASE(WIN32);
    CAIRO_FONTTYPE_DECLARE_ENUM_CASE(QUARTZ);
    CAIRO_FONTTYPE_DECLARE_ENUM_CASE(USER);
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    CAIRO_FONTTYPE_DECLARE_ENUM_CASE(DWRITE);
#endif

    return SUCCESS;
}
