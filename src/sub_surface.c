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
#include "sub_surface_arginfo.h"


zend_class_entry *ce_cairo_subsurface;


/* ----------------------------------------------------------------
    \Cairo\TextCluster C API
------------------------------------------------------------------*/

zend_class_entry* php_cairo_get_subsurface_ce()
{
    return ce_cairo_subsurface;
}


/* ----------------------------------------------------------------
    \Cairo\TextCluster Class API
------------------------------------------------------------------*/

/* {{{ proto CairoSubSurface __construct(int content, array extents)
       Returns new CairoSubSurface */
PHP_METHOD(Cairo_Surface_SubSurface, __construct)
{
    zend_throw_exception(ce_cairo_exception, "Cairo\\Surface\\SubSurface cannot be constructed", 0);
}
/* }}} */


/* ----------------------------------------------------------------
    Cairo\Surface\Sub Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_sub_surface)
{
    ce_cairo_subsurface = register_class_Cairo_Surface_SubSurface(ce_cairo_surface);

    return SUCCESS;
}
