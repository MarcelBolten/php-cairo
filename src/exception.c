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
#include "exception_arginfo.h"

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

/* {{{ proto string CairoStatus->getMessage
       Translates the current enums value to it's cairo status message value */
PHP_METHOD(Cairo_Status, getMessage)
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

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_exception)
{
    ce_cairo_exception = register_class_Cairo_Exception(zend_ce_exception);

    ce_cairo_status = register_class_Cairo_Status();

    return SUCCESS;
}
/* }}} */
