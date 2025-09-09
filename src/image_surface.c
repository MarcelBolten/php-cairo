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
#include "image_surface_arginfo.h"

zend_class_entry *ce_cairo_imagesurface;
zend_class_entry *ce_cairo_format;

/* ----------------------------------------------------------------
    \Cairo\TextCluster C API
------------------------------------------------------------------*/

zend_class_entry* php_cairo_get_imagesurface_ce()
{
    return ce_cairo_imagesurface;
}


/* ----------------------------------------------------------------
    Cairo\ImageSurface Class API
------------------------------------------------------------------*/

/* {{{ proto void __construct(int format, int width, int height)
       Creates an image surface of the specified format and dimensions.
       Initially the surface contents are set to 0. */
PHP_METHOD(Cairo_Surface_Image, __construct)
{
    zend_long width, height;
    cairo_surface_object *surface_object;
    zval *format_case;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_OBJECT_OF_CLASS(format_case, ce_cairo_format)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = Z_CAIRO_SURFACE_P(getThis());
    if (!surface_object) {
        RETURN_NULL();
    }

    surface_object->surface = cairo_image_surface_create(
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(format_case))),
        width,
        height
    );
    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto \Cairo\Surface\Image Object \Cairo\Surface\Image::createForData(string data, Cairo\Surface\ImageFormat format, int width, int height, int stride)
       Creates an image surface for the provided pixel data. */
PHP_METHOD(Cairo_Surface_Image, createForData)
{
    /* NOTE: we have to keep the data buffer around, so we put it in the cairo_surface_object */
    char *data;
    size_t data_len;
    zend_long format, width, height, stride = -1;
    cairo_surface_object *surface_object;
    zval *format_case;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_STRING(data, data_len)
        Z_PARAM_OBJECT_OF_CLASS(format_case, ce_cairo_format)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();

    format = Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(format_case)));

    if (width < 1 || height < 1) {
        zend_throw_exception(ce_cairo_exception, "Cairo\\Surface\\Image::createForData(): invalid surface dimensions. Arguments #3 ($width) and #4 ($height) must be positive integers.", 0);
        RETURN_THROWS();
    }

    /* Figure out our stride */
    /* This is the way the stride SHOULD be done */
    stride = cairo_format_stride_for_width(format, width);

    if (stride <= 0) {
        zend_throw_exception(ce_cairo_exception, "Could not calculate stride for surface in Cairo\\Surface\\Image::createForData().Argument #3 ($width) might be too large.", 0);
        RETURN_THROWS();
    }

    /* Create the object, stick in the buffer and surface, check our status */
    object_init_ex(return_value, ce_cairo_imagesurface);
    surface_object = Z_CAIRO_SURFACE_P(return_value);
    if (!surface_object) {
        RETURN_NULL();
    }

    /* allocate our internal surface object buffer - has to be left lying around until we destroy the image */
    surface_object->buffer = safe_emalloc(stride * height, sizeof(char), 0);

    if (surface_object->buffer == NULL) {
        zend_throw_exception(ce_cairo_exception, "Cairo\\Surface\\Image::createForData(): Could not allocate memory for buffer", 0);
        RETURN_THROWS();
    }

    /* copy our data into the buffer */
    memcpy(
        surface_object->buffer,
        data,
        data_len
    );

    /* create our surface and check for errors */
    surface_object->surface = cairo_image_surface_create_for_data(
        (unsigned char*)surface_object->buffer,
        format, width, height, stride
    );
    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto string \Cairo\Surface\Image->getData()
       Get the string data of the image surface, for direct inspection or modification */
PHP_METHOD(Cairo_Surface_Image, getData)
{
    cairo_surface_object *surface_object;
    unsigned char *data;
    zend_long height, stride;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }

    data = cairo_image_surface_get_data(surface_object->surface);
    height = cairo_image_surface_get_height(surface_object->surface);
    stride = cairo_image_surface_get_stride(surface_object->surface);

    RETURN_STRINGL(data, height * stride);
}
/* }}} */

/* {{{ proto int \Cairo\Surface\Image->getFormat()
       Get the format of the surface */
PHP_METHOD(Cairo_Surface_Image, getFormat)
{
    cairo_surface_object *surface_object;
    zval format_case;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }

    format_case = php_enum_from_cairo_c_enum(
        ce_cairo_format,
        cairo_image_surface_get_format(surface_object->surface)
    );

    if (Z_TYPE(format_case) == IS_OBJECT) {
        RETURN_ZVAL(&format_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto int \Cairo\Surface\Image->getWidth()
       Get the width of the image surface in pixels. */
PHP_METHOD(Cairo_Surface_Image, getWidth)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }

    RETURN_LONG(cairo_image_surface_get_width(surface_object->surface));
}
/* }}} */

/* {{{ proto int \Cairo\Surface\Image->getHeight()
       Get the height of the image surface in pixels. */
PHP_METHOD(Cairo_Surface_Image, getHeight)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }

    RETURN_LONG(cairo_image_surface_get_height(surface_object->surface));
}
/* }}} */

/* {{{ proto int \Cairo\Surface\Image->getStride()
       Get the stride of the image surface in bytes */
PHP_METHOD(Cairo_Surface_Image, getStride)
{
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_NONE();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }

    RETURN_LONG(cairo_image_surface_get_stride(surface_object->surface));
}
/* }}} */

#ifdef CAIRO_HAS_PNG_FUNCTIONS
/* {{{ proto \Cairo\Surface\Image object \Cairo\Surface\Image::createFromPng(file|resource file)
       Creates a new image surface and initializes the contents to the given PNG file. */
PHP_METHOD(Cairo_Surface_Image, createFromPng)
{
    cairo_surface_object *surface_object;
    zval *stream_zval = NULL;
    stream_closure *closure;
    bool owned_stream = false;
    php_stream *stream = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(stream_zval)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_cairo_imagesurface);
    surface_object = Z_CAIRO_SURFACE_P(return_value);

    if (Z_TYPE_P(stream_zval) == IS_STRING) {
        surface_object->surface = cairo_image_surface_create_from_png(Z_STRVAL_P(stream_zval));
    } else if (Z_TYPE_P(stream_zval) == IS_RESOURCE)  {
        php_stream_from_zval(stream, stream_zval);

        if (!stream) {
            RETURN_NULL();
        }

        // Pack stream into struct
        closure = ecalloc(1, sizeof(stream_closure));
        closure->stream = stream;
        closure->owned_stream = owned_stream;

        surface_object->closure = closure;
        surface_object->surface = cairo_image_surface_create_from_png_stream((cairo_read_func_t) php_cairo_read_func, (void *)closure);
    } else {
        zend_throw_exception(ce_cairo_exception, "Cairo\\Surface\\Image::createFromPng() expects parameter 1 to be a string or a stream resource", 0);
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */
#endif


#ifdef CAIRO_HAS_JPEG_FUNCTIONS
/* {{{ proto \Cairo\Surface\Image object \Cairo\Surface\Image::createFromJpeg(file|resource file)
       Creates a new image surface and initializes the contents to the given JPEG file. */
PHP_METHOD(Cairo_Surface_Image, createFromJpeg)
{
    cairo_surface_object *surface_object;
    zval *stream_zval = NULL;
    stream_closure *closure;
    bool owned_stream = false;
    php_stream *stream = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(stream_zval)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_cairo_imagesurface);
    surface_object = Z_CAIRO_SURFACE_P(return_value);

    if (Z_TYPE_P(stream_zval) == IS_STRING) {
        surface_object->surface = cairo_image_surface_create_from_jpeg(Z_STRVAL_P(stream_zval));
    } else if (Z_TYPE_P(stream_zval) == IS_RESOURCE) {
        php_stream_from_zval(stream, stream_zval);

        if (!stream) {
            RETURN_NULL();
        }

        // Pack stream into struct
        closure = ecalloc(1, sizeof(stream_closure));
        closure->stream = stream;
        closure->owned_stream = owned_stream;

        surface_object->closure = closure;
        surface_object->surface = cairo_image_surface_create_from_jpeg_stream(
            (cairo_read_func_t) php_cairo_read_func,
            (void *)closure
        );
    } else {
        zend_throw_exception(ce_cairo_exception, "Cairo\\Surface\\Image::createFromJpeg() Argument #1 ($file) must be of type string or a stream resource", 0);
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */
#endif

/* {{{ proto int CairoFormat::strideForWidth(long format, long width)
        This function provides a stride value that will respect all alignment
        requirements of the accelerated image-rendering code within cairo. */
PHP_METHOD(Cairo_Surface_ImageFormat, strideForWidth)
{
    long width;
    zval *format;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(format, ce_cairo_format)
        Z_PARAM_LONG(width)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_LONG(cairo_format_stride_for_width(
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(format))),
        width
    ));
}
/* }}} */


/* ----------------------------------------------------------------
    Cairo\FontOptions Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_image_surface)
{
    ce_cairo_imagesurface = register_class_Cairo_Surface_Image(ce_cairo_surface);

    ce_cairo_format = register_class_Cairo_Surface_ImageFormat();

    return SUCCESS;
}
/* }}} */
