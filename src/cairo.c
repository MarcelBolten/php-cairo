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
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#    include "config.h"
#endif

#include <php.h>
#include <zend_exceptions.h>
#include <ext/standard/info.h>
#include <cairo.h>

#include "php_cairo.h"
#include "php_cairo_internal.h"
#include "cairo_arginfo.h"

/* ----------------------------------------------------------------
    Cairo Namespace
------------------------------------------------------------------ */

#if defined(CAIRO_HAS_FT_FONT) && defined(HAVE_FREETYPE)
const char* php_cairo_get_ft_error(int error) {

    php_cairo_ft_error *current_error = php_cairo_ft_errors;

    while (current_error->err_msg != NULL) {
        if (current_error->err_code == error) {
            return current_error->err_msg;
        }
        current_error++;
    }
    return NULL;
}
#endif

zval php_enum_from_cairo_c_enum(
    zend_class_entry *enum_ce,
    long c_enum_value
) {
    zval php_enum;
    zval backing_value;
    zval retval;

    ZVAL_LONG(&backing_value, c_enum_value);

    zend_call_method_with_1_params(NULL, enum_ce, NULL, "from", &retval, &backing_value);

    if (Z_TYPE(retval) == IS_OBJECT) {
        ZVAL_COPY(&php_enum, &retval);
    } else {
        ZVAL_NULL(&php_enum);
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Failed to create %s enum from value: %ld",
            ZSTR_VAL(enum_ce->name),
            c_enum_value
        );
    }

    zval_ptr_dtor(&retval);
    return php_enum;
}


/* {{{ proto int \Cairo\version(void)
       Returns an integer version number of the cairo library being used */
PHP_FUNCTION(Cairo_version)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(cairo_version());
}
/* }}} */

/* {{{ proto string \Cairo\version_string(void)
       Returns a string version of the cairo library being used */
PHP_FUNCTION(Cairo_version_string)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING(cairo_version_string());
}
/* }}} */

/* {{{ proto int \Cairo::version(void)
       Returns an integer version number of the cairo library being used */
PHP_METHOD(Cairo_Cairo, version)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_LONG(cairo_version());
}
/* }}} */

/* {{{ proto string \Cairo::versionString(void)
       Returns a string version of the cairo library being used */
PHP_METHOD(Cairo_Cairo, versionString)
{
    ZEND_PARSE_PARAMETERS_NONE();

    RETURN_STRING(cairo_version_string());
}
/* }}} */

/* {{{ proto array \Cairo::availableSurfaces(void)
       Returns an array of available Cairo backend surfaces */
PHP_METHOD(Cairo_Cairo, availableSurfaces)
{
    ZEND_PARSE_PARAMETERS_NONE();

    array_init(return_value);
    add_next_index_string(return_value, "IMAGE");

#ifdef CAIRO_HAS_PNG_FUNCTIONS
    add_next_index_string(return_value, "PNG");
#endif

#ifdef CAIRO_HAS_JPEG_FUNCTIONS
    add_next_index_string(return_value, "JPEG");
#endif

#ifdef CAIRO_HAS_PDF_SURFACE
    add_next_index_string(return_value, "PDF");
#endif

#ifdef CAIRO_HAS_PS_SURFACE
    add_next_index_string(return_value, "PS");
#endif

#ifdef CAIRO_HAS_SVG_SURFACE
    add_next_index_string(return_value, "SVG");
#endif

#ifdef CAIRO_HAS_XLIB_SURFACE
    add_next_index_string(return_value, "XLIB");
#endif

#ifdef CAIRO_HAS_RECORDING_SURFACE
    add_next_index_string(return_value, "RECORDING");
#endif

#ifdef CAIRO_HAS_QUARTZ_SURFACE
    add_next_index_string(return_value, "QUARTZ");
#endif

#ifdef CAIRO_HAS_WIN32_SURFACE
    add_next_index_string(return_value, "WIN32");
#endif
}
/* }}} */

/* {{{ proto array \Cairo::availableFonts(void)
       Returns an array of available Cairo font backends */
PHP_METHOD(Cairo_Cairo, availableFonts)
{
    ZEND_PARSE_PARAMETERS_NONE();

    array_init(return_value);

#if defined(CAIRO_HAS_FT_FONT) && defined(HAVE_FREETYPE)
    add_next_index_string(return_value, "FREETYPE");
#endif
#ifdef CAIRO_HAS_QUARTZ_FONT
    add_next_index_string(return_value, "QUARTZ");
#endif
#ifdef CAIRO_HAS_WIN32_FONT
    add_next_index_string(return_value, "WIN32");
#endif
#ifdef CAIRO_HAS_USER_FONT
    add_next_index_string(return_value, "USER");
#endif
}
/* }}} */


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo)
{
    zend_class_entry ce;
    zend_class_entry *cairo_ce_cairo;

    cairo_ce_cairo = register_class_Cairo_Cairo();

    /* Namespaced version constants */
    register_cairo_symbols(module_number);

    PHP_MINIT(cairo_pattern)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_rectangle)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_matrix)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_exception)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_region)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_font_face)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_font)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_font_options)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_scaled_font)(INIT_FUNC_ARGS_PASSTHRU);
#if defined(CAIRO_HAS_FT_FONT) && defined(HAVE_FREETYPE)
    PHP_MINIT(cairo_ft_font)(INIT_FUNC_ARGS_PASSTHRU);
#endif
#if defined(CAIRO_HAS_QUARTZ_FONT)
    PHP_MINIT(cairo_quartz_font)(INIT_FUNC_ARGS_PASSTHRU);
#endif
#if defined(CAIRO_HAS_WIN32_FONT) && defined(HAVE_WIN32_FONT)
    PHP_MINIT(cairo_win32_font)(INIT_FUNC_ARGS_PASSTHRU);
#endif
    PHP_MINIT(cairo_surface)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_image_surface)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_sub_surface)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_recording_surface)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_pdf_surface)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_svg_surface)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_ps_surface)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_path)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_context)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_glyph)(INIT_FUNC_ARGS_PASSTHRU);
    PHP_MINIT(cairo_text_cluster)(INIT_FUNC_ARGS_PASSTHRU);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(cairo)
{
#if 0 && defined(ZEND_DEBUG) && ZEND_DEBUG == 1
     cairo_debug_reset_static_data();
    // ^^^ when running some tests with pango, this causes a crash
    // This is what happens:
    // Assertion failed: hash_table->live_entries == 0 (../src/cairo-hash.c: _cairo_hash_table_destroy: 217)
    // bt
    // #0  __restore_sigs (set=set@entry=0x7ffe66bfa860) at ./arch/x86_64/syscall_arch.h:40
    // #1  0x00007688c4091e1b in raise (sig=sig@entry=6) at src/signal/raise.c:11
    // #2  0x00007688c40759ad in abort () at src/exit/abort.c:11
    // #3  0x00007688c4075a59 in __assert_fail (expr=<optimized out>, file=<optimized out>, line=<optimized out>, func=<optimized out>) at src/exit/assert.c:7
    // #4  0x00007688c2c2cb50 in _cairo_hash_table_destroy (hash_table=<optimized out>) at ../src/cairo-hash.c:214
    // #5  _cairo_hash_table_destroy (hash_table=<optimized out>) at ../src/cairo-hash.c:214
    // #6  0x00007688c2c26a19 in _cairo_scaled_font_map_destroy () at ../src/cairo-scaled-font.c:451
    // #7  cairo_debug_reset_static_data () at ../src/cairo-debug.c:67
    // #8  0x00007688c2d24bbf in zm_shutdown_cairo (type=1, module_number=36) at /src/php-cairo/src/cairo.c:210
    // cairo-scaled-font.c:451 _cairo_hash_table_destroy (font_map->hash_table);
    // cairo-hash.c:217 assert (hash_table->live_entries == 0);
    // So this means there are still references to scaled fonts somewhere.
    // But where? I have no idea.
#endif

    return SUCCESS;
}

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(cairo)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "Cairo Graphics Library Bindings", "enabled");
    php_info_print_table_header(1,
#ifdef COMPILE_DL_CAIRO
        "compiled as dynamic module"
#else
        "compiled as static module"
#endif
    );
    php_info_print_table_row(2, "Cairo Library Version", CAIRO_VERSION_STRING);
    php_info_print_table_row(2, "Extension Version", PHP_CAIRO_VERSION);
    php_info_print_table_row(1, "Surface Backends Available");
    php_info_print_table_row(2, "Image Surface", "enabled");
    php_info_print_table_row(2, "PNG Support",
#ifdef CAIRO_HAS_PNG_FUNCTIONS
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "JPEG Support",
#ifdef CAIRO_HAS_JPEG_FUNCTIONS
        "enabled"
#else
        "disabled"
#endif
        );
    php_info_print_table_row(2, "PDF Surface",
#ifdef CAIRO_HAS_PDF_SURFACE
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "PS Surface",
#ifdef CAIRO_HAS_PS_SURFACE
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "Xlib (X11, X.org) Surface",
#ifdef CAIRO_HAS_XLIB_SURFACE
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "Quartz (MacOSX) Surface",
#ifdef CAIRO_HAS_QUARTZ_SURFACE
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "SVG Surface",
#ifdef CAIRO_HAS_SVG_SURFACE
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "Win32 Surface",
#ifdef CAIRO_HAS_WIN32_SURFACE
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "Recording Surface",
#ifdef CAIRO_HAS_RECORDING_SURFACE
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(1, "Font Backends Available");
    php_info_print_table_row(2, "Freetype Fonts",
#if defined(CAIRO_HAS_FT_FONT) && defined(HAVE_FREETYPE)
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "Quartz Fonts",
#ifdef CAIRO_HAS_QUARTZ_FONT
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "Win32 Fonts",
#ifdef CAIRO_HAS_WIN32_FONT
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_row(2, "User Fonts",
#ifdef CAIRO_HAS_USER_FONT
        "enabled"
#else
        "disabled"
#endif
    );
    php_info_print_table_end();
}
/* }}} */

/* {{{ cairo_module_entry */
zend_module_entry cairo_module_entry = {
    STANDARD_MODULE_HEADER_EX,
    NULL,
    NULL,
    "cairo",
    ext_functions,
    PHP_MINIT(cairo),
    PHP_MSHUTDOWN(cairo),
    NULL,
    NULL,
    PHP_MINFO(cairo),
    PHP_CAIRO_VERSION,
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CAIRO
    ZEND_GET_MODULE(cairo)
#endif
