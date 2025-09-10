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
#include "surface_arginfo.h"

zend_class_entry *ce_cairo_surface;
zend_class_entry *ce_cairo_content;
zend_class_entry *ce_cairo_surfacetype;


static zend_object_handlers cairo_surface_object_handlers;

cairo_surface_object *cairo_surface_fetch_object(zend_object *object)
{
    return (cairo_surface_object *) ((char*)(object) - XtOffsetOf(cairo_surface_object, std));
}

cairo_surface_object *cairo_surface_object_get(zval *zv)
{
    cairo_surface_object *object = Z_CAIRO_SURFACE_P(zv);

    if (object->surface == NULL) {
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Internal surface object missing in %s, you must call parent::__construct in extended classes.",
            ZSTR_VAL(Z_OBJCE_P(zv)->name));
        return NULL;
    }

    return object;
}

/* ----------------------------------------------------------------
    Cairo\Pattern Class API
------------------------------------------------------------------ */

/* {{{ proto void contruct()
       CairoSurface CANNOT be extended in userspace, this will throw an exception on use */
PHP_METHOD(Cairo_Surface, __construct) {
    ZEND_PARSE_PARAMETERS_NONE();
    zend_throw_exception(ce_cairo_exception, "Cairo\\Surface cannot be constructed", 0);
}
/* }}} */

/* {{{ proto CairoSurface object \Cairo\Surface::createSimilar(\Cairo\Content content, double width, double height)
       Create a new surface that is as compatible as possible with an existing surface. */
PHP_METHOD(Cairo_Surface, createSimilar)
{
    cairo_surface_object *surface_object, *new_surface_object;
    cairo_surface_t *new_surface;
    zval *content;
    double width, height;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS(content, ce_cairo_content)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    new_surface = cairo_surface_create_similar(
        surface_object->surface,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(content))),
        width,
        height
    );

    /* we can't always rely on the same type of surface being returned, so we use php_cairo_get_surface_ce */
    object_init_ex(return_value, php_cairo_get_surface_ce(new_surface));
    new_surface_object = Z_CAIRO_SURFACE_P(return_value);
    if (!new_surface_object) {
        RETURN_NULL();
    }

    new_surface_object->surface = new_surface;
}
/* }}} */

/* {{{ proto CairoSurface object \Cairo\Surface::createSimilarImage(\Cairo\Format format, double width, double height)
       Create a new image surface that is as compatible as possible for uploading to and the use in conjunction with an existing surface.
       Unlike cairo_surface_create_similar() the new image surface won't inherit the device scale from other. */
PHP_METHOD(Cairo_Surface, createSimilarImage)
{
    cairo_surface_object *surface_object, *new_surface_object;
    cairo_surface_t *new_surface;
    double width, height;
    zval *format;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS(format, ce_cairo_format)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    new_surface = cairo_surface_create_similar_image(
        surface_object->surface,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(format))),
        width,
        height
    );

    /* --> because of used method php_cairo_get_surface_ce() should always give 'ce_cairo_imagesurface' */
    object_init_ex(return_value, php_cairo_get_surface_ce(new_surface));
    new_surface_object = Z_CAIRO_SURFACE_P(return_value);
    if (!new_surface_object) {
        RETURN_NULL();
    }

    new_surface_object->surface = new_surface;
}
/* }}} */

/* {{{ proto CairoSurface object \Cairo\Surface::createForRectangle(double x, double y, double width, double height)
       create a new surface that is a rectangle within the target surface. */
PHP_METHOD(Cairo_Surface, createForRectangle)
{
    zval *surface_zval = NULL;
    cairo_surface_object *surface_object, *new_surface_object;
    cairo_surface_t *new_surface;
    double x, y, width, height;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_zval = getThis();
    surface_object = cairo_surface_object_get(surface_zval);
    if (!surface_object) {
        RETURN_THROWS();
    }

    new_surface = cairo_surface_create_for_rectangle(surface_object->surface, x, y, width, height);

    object_init_ex(return_value, php_cairo_get_subsurface_ce());
    new_surface_object = Z_CAIRO_SURFACE_P(return_value);
    // Store reference to the parent object
    ZVAL_COPY(&new_surface_object->parent_zval, surface_zval);
    new_surface_object->surface = new_surface;
}
/* }}} */


/* {{{ proto \Cairo\Status \Cairo\Surface::getStatus()
       Checks whether an error has previously occurred for this surface. */
PHP_METHOD(Cairo_Surface, getStatus)
{
    cairo_surface_object *surface_object;
    zval status_case;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    status_case = php_enum_from_cairo_c_enum(
        ce_cairo_status,
        cairo_surface_status(surface_object->surface)
    );

    if (Z_TYPE(status_case) == IS_OBJECT) {
        RETURN_ZVAL(&status_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Surface::finish()
       This function finishes the surface and drops all references to external resources. For example,
       for the Xlib backend it means that cairo will no longer access the drawable, which can be freed. */
PHP_METHOD(Cairo_Surface, finish)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_finish(surface_object->surface);
}
/* }}} */

/* {{{ proto void \Cairo\Surface::flush()
       Do any pending drawing for the surface and also restore any temporary modification's cairo has made
       to the surface's state. This function must be called before switching from drawing on the surface
       with cairo to drawing on it directly with native APIs. */
PHP_METHOD(Cairo_Surface, flush)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_flush(surface_object->surface);
}
/* }}} */

/* {{{ proto CairoFontOptions object \Cairo\Surface::getFontOptions()
       Retrieves the default font rendering options for the surface. */
PHP_METHOD(Cairo_Surface, getFontOptions)
{
    cairo_surface_object *surface_object;
    cairo_font_options_object *font_object;
    cairo_font_options_t *options = cairo_font_options_create();

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    object_init_ex(return_value, php_cairo_get_fontoptions_ce());
    font_object = Z_CAIRO_FONT_OPTIONS_P(return_value);

    cairo_surface_get_font_options(surface_object->surface, options);
    font_object->font_options = options;
}
/* }}} */

/* {{{ proto \Cairo\Content \Cairo\Surface::getContent()
       This function returns the content type of surface which indicates whether the surface contains color and/or alpha information. */
PHP_METHOD(Cairo_Surface, getContent)
{
    cairo_surface_object *surface_object;
    zval content_case;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    content_case = php_enum_from_cairo_c_enum(
        ce_cairo_content,
        cairo_surface_get_content(surface_object->surface)
    );

    if (Z_TYPE(content_case) == IS_OBJECT) {
        RETURN_ZVAL(&content_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Surface::markDirty()
       Tells cairo that drawing has been done to surface using means other than cairo, and that cairo should reread any cached areas. */
PHP_METHOD(Cairo_Surface, markDirty)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_mark_dirty(surface_object->surface);
}
/* }}} */

/* {{{ proto void \Cairo\Surface::markDirtyRectangle(float x, float y, float width, float height)
       Drawing has been done only to the specified rectangle, so that cairo can retain cached contents for other parts of the surface.
       Any cached clip set on the surface will be reset by this function, to make sure that future cairo calls have the clip set that they expect.*/
PHP_METHOD(Cairo_Surface, markDirtyRectangle)
{
    cairo_surface_object *surface_object;
    long x = 0, y = 0, width = 0, height = 0;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(x)
        Z_PARAM_LONG(y)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_mark_dirty_rectangle(surface_object->surface, x, y, width, height);
}
/* }}} */

/* {{{ proto void \Cairo\Surface::setDeviceOffset(float x, float y)
       Sets an offset that is added to the device coordinates determined by the CTM when drawing to surface. */
PHP_METHOD(Cairo_Surface, setDeviceOffset)
{
    cairo_surface_object *surface_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_set_device_offset(surface_object->surface, x, y);
}
/* }}} */

/* {{{ proto array \Cairo\Surface::getDeviceOffset()
       This function returns the previous device offset */
PHP_METHOD(Cairo_Surface, getDeviceOffset)
{
    cairo_surface_object *surface_object;
    double x, y;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_get_device_offset(surface_object->surface, &x, &y);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ proto void \Cairo\Surface::setDeviceScale(float x, float y)
       Sets a scale that is multiplied to the device coordinates determined by the CTM when drawing to surface.
       One common use for this is to render to very high resolution display devices at a scale factor,
       so that code that assumes 1 pixel will be a certain size will still work.
       Setting a transformation via cairo_translate() isn't sufficient to do this,
       since functions like cairo_device_to_user() will expose the hidden scale. */
PHP_METHOD(Cairo_Surface, setDeviceScale)
{
    cairo_surface_object *surface_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_set_device_scale(surface_object->surface, x, y);
}
/* }}} */

/* {{{ proto array \Cairo\Surface::getDeviceScale()
       This function returns the previous set device scale. */
PHP_METHOD(Cairo_Surface, getDeviceScale)
{
    cairo_surface_object *surface_object;
    double x, y;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_get_device_scale(surface_object->surface, &x, &y);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ proto void \Cairo\Surface::setFallbackResolution(float x, float y)
      Set the horizontal and vertical resolution for image fallbacks.
      When certain operations aren't supported natively by a backend, cairo will fallback by
      rendering operations to an image and then overlaying that image onto the output. */
PHP_METHOD(Cairo_Surface, setFallbackResolution)
{
    cairo_surface_object *surface_object;
    double x = 0.0, y = 0.0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_set_fallback_resolution(surface_object->surface, x, y);
}
/* }}} */

/* {{{ proto array \Cairo\Surface::getFallbackResolution()
       This function returns the previous fallback resolution */
PHP_METHOD(Cairo_Surface, getFallbackResolution)
{
    cairo_surface_object *surface_object;
    double x, y;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_get_fallback_resolution(surface_object->surface, &x, &y);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{ proto \Cairo\Surface\Type \Cairo\Surface::getType()
       This function returns the type of the backend used to create a surface. */
PHP_METHOD(Cairo_Surface, getType)
{
    cairo_surface_object *surface_object;
    zval surface_case;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    surface_case = php_enum_from_cairo_c_enum(
        ce_cairo_surfacetype,
        cairo_surface_get_type(surface_object->surface)
    );

    if (Z_TYPE(surface_case) == IS_OBJECT) {
        RETURN_ZVAL(&surface_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Surface::showPage()
       Emits and clears the current page for backends that support multiple pages.
       Same as CairoContext->showPage(); */
PHP_METHOD(Cairo_Surface, showPage)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_show_page(surface_object->surface);
}
/* }}} */

/* {{{ proto void \Cairo\Surface::copyPage()
       Emits the current page for backends that support multiple pages,
       but doesn't clear it, so that the contents of the current page will be retained for the next page.
       Same as CairoContext->copyPage(); */
PHP_METHOD(Cairo_Surface, copyPage)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_copy_page(surface_object->surface);
}
/* }}} */

/* {{{ proto bool \Cairo\Surface::hasShowTextGlyphs()
       Returns whether the surface supports sophisticated cairo_show_text_glyphs() operations
       Users can use this function to avoid computing UTF-8 text and cluster mapping if the target surface does not use it. */
PHP_METHOD(Cairo_Surface, hasShowTextGlyphs)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    RETURN_BOOL(cairo_surface_has_show_text_glyphs(surface_object->surface));
}
/* }}} */

/* {{{ proto CairoSurface object \Cairo\Surface::mapToImage([\Cairo\Rectangle rectangle])
       .... */
PHP_METHOD(Cairo_Surface, mapToImage)
{
    cairo_surface_object *surface_object, *new_surface_object;
    cairo_surface_t *new_surface;
    zval *rectangle_zval = NULL;
    cairo_rectangle_object *rectangle_object;
    cairo_rectangle_int_t int_rect;

    ZEND_PARSE_PARAMETERS_START(0, 1)
        Z_PARAM_OPTIONAL
        Z_PARAM_OBJECT_OF_CLASS(rectangle_zval, ce_cairo_rectangle)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (rectangle_zval != NULL && Z_TYPE_P(rectangle_zval) == IS_OBJECT) {
        rectangle_object = Z_CAIRO_RECTANGLE_P(rectangle_zval);
        int_rect = cairo_expand_to_rectangle_int(rectangle_object->rect);
        new_surface = cairo_surface_map_to_image(surface_object->surface, &int_rect);
        cairo_surface_reference(new_surface);
    } else {
        new_surface = cairo_surface_map_to_image(surface_object->surface, NULL);
    }

    object_init_ex(return_value, php_cairo_get_imagesurface_ce());
    new_surface_object = Z_CAIRO_SURFACE_P(return_value);
    if (!new_surface_object) {
        RETURN_NULL();
    }

    new_surface_object->surface = new_surface;
    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto CairoSurface object \Cairo\Surface::unmapImage([\Cairo\Sourface\Image image_surface])
       .... */
PHP_METHOD(Cairo_Surface, unmapImage)
{
    cairo_surface_object *surface_object, *image_surface_object;
    zval *image_surface_zval;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(image_surface_zval, ce_cairo_imagesurface)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    image_surface_object = cairo_surface_object_get(image_surface_zval);
    if (!image_surface_object) {
        RETURN_THROWS();
    }

    cairo_surface_unmap_image(surface_object->surface, image_surface_object->surface);

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */


#ifdef CAIRO_HAS_PNG_FUNCTIONS
/* {{{ proto void \Cairo\Surface::writeToPng(file|resource file)
       Writes the contents of surface to a new file filename or PHP stream as a PNG image.
       Unlike some other stream supporting functions, you may NOT pass a null filename */
PHP_METHOD(Cairo_Surface, writeToPng)
{
    cairo_surface_object *surface_object;
    zval *stream_zval = NULL;
    stream_closure *closure;
    php_stream *stream = NULL;
    bool owned_stream = false;
    cairo_status_t status;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(stream_zval)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (Z_TYPE_P(stream_zval) == IS_STRING && Z_STRLEN_P(stream_zval) > 0) {
        stream = php_stream_open_wrapper(Z_STRVAL_P(stream_zval), "w+b", REPORT_ERRORS, NULL);
        owned_stream = 1;
    } else if (Z_TYPE_P(stream_zval) == IS_RESOURCE)  {
        php_stream_from_zval(stream, stream_zval);
    } else {
        zend_throw_exception(ce_cairo_exception, "Cairo\\Surface::writeToPng() expects parameter 1 to be a (not empty) string or a stream resource", 0);
        RETURN_THROWS();
    }

    /* Pack stream into struct */
    closure = ecalloc(1, sizeof(stream_closure));
    closure->stream = stream;
    closure->owned_stream = owned_stream;

    status = cairo_surface_write_to_png_stream(surface_object->surface, php_cairo_write_func, (void *)closure);
    if (owned_stream) {
        php_stream_close(stream);
    }
    efree(closure);

    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }
}
/* }}} */
#endif


#ifdef CAIRO_HAS_JPEG_FUNCTIONS
/* {{{ proto void \Cairo\Surface::writeToJpeg(file|resource file)
       Writes the contents of surface to a new file filename or PHP stream as a JPEG image.
       Unlike some other stream supporting functions, you may NOT pass a null filename */
PHP_METHOD(Cairo_Surface, writeToJpeg)
{
    cairo_surface_object *surface_object;
    zval *stream_zval = NULL;
    stream_closure *closure;
    php_stream *stream = NULL;
    bool owned_stream = false;
    cairo_status_t status;
    double quality = 90;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_ZVAL(stream_zval)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(quality)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (Z_TYPE_P(stream_zval) == IS_STRING && Z_STRLEN_P(stream_zval) > 0) {
        stream = php_stream_open_wrapper(Z_STRVAL_P(stream_zval), "w+b", REPORT_ERRORS, NULL);
        owned_stream = 1;
    } else if (Z_TYPE_P(stream_zval) == IS_RESOURCE)  {
        php_stream_from_zval(stream, stream_zval);
    } else {
        zend_throw_exception(ce_cairo_exception, "Cairo\\Surface::writeToJpeg() expects parameter 1 to be a (not empty) string or a stream resource", 0);
        RETURN_THROWS();
    }

    /* Pack stream into struct */
    closure = ecalloc(1, sizeof(stream_closure));
    closure->stream = stream;
    closure->owned_stream = owned_stream;

    status = cairo_image_surface_write_to_jpeg_stream(
        surface_object->surface,
        php_cairo_write_func,
        (void *)closure,
        quality
    );
    if (owned_stream) {
        php_stream_close(stream);
    }
    efree(closure);

    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }
}
/* }}} */
#endif


/* ----------------------------------------------------------------
    Cairo\Surface Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_surface_free_obj(zend_object *object)
{
    cairo_surface_object *intern = cairo_surface_fetch_object(object);

    if (!intern) {
        return;
    }

    /* buffer for the create_from_data image stuff */
    if (intern->buffer) {
        efree(intern->buffer);
        intern->buffer = NULL;
    }

    if (intern->surface) {
        cairo_surface_finish(intern->surface);
        cairo_surface_destroy(intern->surface);
        intern->surface = NULL;
    }

    /* closure free up time */
    if (intern->closure) {
        if (intern->closure->owned_stream == 1) {
            php_stream_close(intern->closure->stream);
        }
        efree(intern->closure);
        intern->closure = NULL;
    }

    zval_ptr_dtor(&intern->parent_zval);

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* cairo_surface_obj_ctor(zend_class_entry *ce, cairo_surface_object **intern)
{
    cairo_surface_object *object = ecalloc(1, sizeof(cairo_surface_object) + zend_object_properties_size(ce));

    object->surface = NULL;
    object->buffer = NULL;
    object->closure = NULL;
    ZVAL_UNDEF(&object->parent_zval);

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &cairo_surface_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
zend_object* cairo_surface_create_object(zend_class_entry *ce)
{
    cairo_surface_object *surface = NULL;
    zend_object *return_value = cairo_surface_obj_ctor(ce, &surface);

    object_properties_init(&surface->std, ce);
    return return_value;
}
/* }}} */


/* ----------------------------------------------------------------
    Cairo\Surface C API
------------------------------------------------------------------*/

/* Helper methods for stream surface read/writes */
cairo_status_t php_cairo_write_func(void *closure, const unsigned char *data, unsigned int length)
{
    size_t written;
    stream_closure *cast_closure;

    cast_closure = (stream_closure *)closure;

    written = php_stream_write(cast_closure->stream, data, length);
    if (written == length) {
        return CAIRO_STATUS_SUCCESS;
    }

    return CAIRO_STATUS_WRITE_ERROR;
}

cairo_status_t php_cairo_read_func(void *closure, const unsigned char *data, unsigned int length)
{
    unsigned int read;
    stream_closure *cast_closure;

    cast_closure = (stream_closure *)closure;

    read = php_stream_read(cast_closure->stream, (char *)data, length);
    if (read == length) {
        return CAIRO_STATUS_SUCCESS;
    }

    return CAIRO_STATUS_READ_ERROR;
}

zend_class_entry* php_cairo_get_surface_ce(cairo_surface_t *surface)
{
    zend_class_entry *type;

    if (surface == NULL) {
        return ce_cairo_surface;
    }

    switch (cairo_surface_get_type(surface)) {
        case CAIRO_SURFACE_TYPE_IMAGE:
            type = ce_cairo_imagesurface;
            break;

#ifdef CAIRO_HAS_PDF_SURFACE
        case CAIRO_SURFACE_TYPE_PDF:
            type = ce_cairo_pdfsurface;
            break;
#endif
#ifdef CAIRO_HAS_SVG_SURFACE
        case CAIRO_SURFACE_TYPE_SVG:
            type = ce_cairo_svgsurface;
            break;
#endif

#ifdef CAIRO_HAS_PS_SURFACE
        case CAIRO_SURFACE_TYPE_PS:
            type = ce_cairo_pssurface;
            break;
#endif

#ifdef CAIRO_HAS_RECORDING_SURFACE
        case CAIRO_SURFACE_TYPE_RECORDING:
            type = ce_cairo_recordingsurface;
            break;
#endif
/*
#ifdef CAIRO_HAS_WIN32_SURFACE
        case CAIRO_SURFACE_TYPE_WIN32:
            type = get_CairoWin32Surface_ce_ptr();
            break;
#endif
#ifdef CAIRO_HAS_XLIB_SURFACE
        case CAIRO_SURFACE_TYPE_XLIB:
            type = get_CairoXlibSurface_ce_ptr();
            break;
#endif
#ifdef CAIRO_HAS_QUARTZ_SURFACE
        case CAIRO_SURFACE_TYPE_QUARTZ:
            type = get_CairoQuartzSurface_ce_ptr();
            break;
#endif */

        case CAIRO_SURFACE_TYPE_SUBSURFACE:
            type = ce_cairo_subsurface;
            break;

        default:
            php_error(E_WARNING, "Unsupported Cairo Surface Type");
            return NULL;
    }
    return type;
}

/* ----------------------------------------------------------------
    Cairo\Surface Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_surface)
{
    memcpy(
        &cairo_surface_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(cairo_surface_object_handlers)
    );

    /* Surface */
    cairo_surface_object_handlers.offset = XtOffsetOf(cairo_surface_object, std);
    cairo_surface_object_handlers.free_obj = cairo_surface_free_obj;

    ce_cairo_surface = register_class_Cairo_Surface();
    ce_cairo_surface->create_object = cairo_surface_create_object;

    /* CairoContent */
    ce_cairo_content = register_class_Cairo_Surface_Content();

    /* SurfaceType */
    ce_cairo_surfacetype = register_class_Cairo_Surface_Type();

    return SUCCESS;
}
