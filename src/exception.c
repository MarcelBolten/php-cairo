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

zend_class_entry *ce_cairo_exception;
zend_class_entry *ce_cairo_status;

/* ----------------------------------------------------------------
    Cairo C API
------------------------------------------------------------------*/

bool php_cairo_throw_exception(cairo_status_t status)
{
    char * error_message;

    if (status == CAIRO_STATUS_SUCCESS) {
        return false;
    }

    error_message = estrdup(cairo_status_to_string(status));
    zend_throw_exception(ce_cairo_exception, error_message, status);
    efree(error_message);
    return true;
}

/* ----------------------------------------------------------------
    Cairo\Status Class API
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO(CairoStatus_getMessage_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ proto string CairoStatus->getMessage
       Translates the current enums value to it's cairo status message value */
PHP_METHOD(CairoStatus, getMessage)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING(cairo_status_to_string(
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(getThis())))
    ));
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\Status and Cairo\Exception Definition and registration
------------------------------------------------------------------*/

/* {{{ cairo_status_methods[] */
const zend_function_entry cairo_status_methods[] = {
    PHP_ME(CairoStatus, getMessage, CairoStatus_getMessage_args, ZEND_ACC_PUBLIC)
    ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_exception)
{
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, CAIRO_NAMESPACE, "Exception", NULL);
    ce_cairo_exception = zend_register_internal_class_ex(&ce, zend_exception_get_default());

    ce_cairo_status = zend_register_internal_enum(ZEND_NS_NAME(CAIRO_NAMESPACE, "Status"), IS_LONG, cairo_status_methods);

    #define CAIRO_STATUS_DECLARE_ENUM_CASE(name) \
        CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_status, CAIRO_STATUS)

    CAIRO_STATUS_DECLARE_ENUM_CASE(SUCCESS);
    CAIRO_STATUS_DECLARE_ENUM_CASE(NO_MEMORY);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_RESTORE);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_POP_GROUP);
    CAIRO_STATUS_DECLARE_ENUM_CASE(NO_CURRENT_POINT);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_MATRIX);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_STATUS);
    CAIRO_STATUS_DECLARE_ENUM_CASE(NULL_POINTER);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_STRING);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_PATH_DATA);
    CAIRO_STATUS_DECLARE_ENUM_CASE(READ_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(WRITE_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(SURFACE_FINISHED);
    CAIRO_STATUS_DECLARE_ENUM_CASE(SURFACE_TYPE_MISMATCH);
    CAIRO_STATUS_DECLARE_ENUM_CASE(PATTERN_TYPE_MISMATCH);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_CONTENT);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_FORMAT);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_VISUAL);
    CAIRO_STATUS_DECLARE_ENUM_CASE(FILE_NOT_FOUND);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_DASH);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_DSC_COMMENT);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_INDEX);
    CAIRO_STATUS_DECLARE_ENUM_CASE(CLIP_NOT_REPRESENTABLE);
    CAIRO_STATUS_DECLARE_ENUM_CASE(TEMP_FILE_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_STRIDE);
    CAIRO_STATUS_DECLARE_ENUM_CASE(FONT_TYPE_MISMATCH);
    CAIRO_STATUS_DECLARE_ENUM_CASE(USER_FONT_IMMUTABLE);
    CAIRO_STATUS_DECLARE_ENUM_CASE(USER_FONT_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(NEGATIVE_COUNT);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_CLUSTERS);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_SLANT);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_WEIGHT);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_SIZE);
    CAIRO_STATUS_DECLARE_ENUM_CASE(USER_FONT_NOT_IMPLEMENTED);
    CAIRO_STATUS_DECLARE_ENUM_CASE(DEVICE_TYPE_MISMATCH);
    CAIRO_STATUS_DECLARE_ENUM_CASE(DEVICE_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(INVALID_MESH_CONSTRUCTION);
    CAIRO_STATUS_DECLARE_ENUM_CASE(DEVICE_FINISHED);
    CAIRO_STATUS_DECLARE_ENUM_CASE(LAST_STATUS);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 14, 0)
    CAIRO_STATUS_DECLARE_ENUM_CASE(JBIG2_GLOBAL_MISSING);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    CAIRO_STATUS_DECLARE_ENUM_CASE(WIN32_GDI_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(FREETYPE_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(PNG_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(TAG_ERROR);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    CAIRO_STATUS_DECLARE_ENUM_CASE(DWRITE_ERROR);
    CAIRO_STATUS_DECLARE_ENUM_CASE(SVG_FONT_ERROR);
#endif

    return SUCCESS;
}
/* }}} */
