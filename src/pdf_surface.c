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

#if CAIRO_HAS_PDF_SURFACE
#include <cairo-pdf.h>
#include "pdf_surface_arginfo.h"

zend_class_entry *ce_cairo_pdfsurface;
zend_class_entry *ce_cairo_pdf_metadata;
zend_class_entry *ce_cairo_pdf_outlineflag;
zend_class_entry *ce_cairo_pdfversion;
zend_class_entry *ce_cairo_pdf_outline;

/* ----------------------------------------------------------------
    \Cairo\Surface\Pdf Class API
------------------------------------------------------------------*/

/* {{{ proto void __construct(string|resource file, float width, float height)
       Creates a PDF surface of the specified size in points to be written to filename. */
PHP_METHOD(Cairo_Surface_Pdf, __construct)
{
    zval *stream_zval = NULL;
    stream_closure *closure;
    php_stream *stream = NULL;
    double width, height;
    bool owned_stream = false;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_ZVAL(stream_zval)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = Z_CAIRO_SURFACE_P(getThis());
    if (!surface_object) {
        RETURN_NULL();
    }

    /* special case - a NULL file is like an "in memory" PDF */
    if (Z_TYPE_P(stream_zval) == IS_NULL) {
        surface_object->surface = cairo_pdf_surface_create(NULL, width, height);
    }
    /* Otherwise it can be a filename or a PHP stream */
    else {
        if (Z_TYPE_P(stream_zval) == IS_STRING) {
            stream = php_stream_open_wrapper(Z_STRVAL_P(stream_zval), "w+b", REPORT_ERRORS, NULL);
            owned_stream = 1;
        } else if (Z_TYPE_P(stream_zval) == IS_RESOURCE)  {
            php_stream_from_zval(stream, stream_zval);
        } else {
            zend_throw_exception(zend_ce_type_error, "Cairo\\Surface\\Pdf::__construct() expects parameter 1 to be null, a string, or a stream resource", 0);
            RETURN_THROWS();
        }

        /* Pack stream into struct*/
        closure = ecalloc(1, sizeof(stream_closure));
        closure->stream = stream;
        closure->owned_stream = owned_stream;

        surface_object->closure = closure;
        surface_object->surface = cairo_pdf_surface_create_for_stream(php_cairo_write_func, (void *)closure, width, height);
    }

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto string \Cairo\Surface\Pdf::versionToString(int version)
       Get the string representation of the given version id. This function will return NULL if version isn't valid. */
PHP_METHOD(Cairo_Surface_Pdf, versionToString)
{
    zval *version;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(version, ce_cairo_pdfversion)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_STRING(cairo_pdf_version_to_string(Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(version)))));
}
/* }}} */

/* {{{ proto array \Cairo\Surface\Pdf::getVersions()
       Used to retrieve the list of supported versions */
PHP_METHOD(Cairo_Surface_Pdf, getVersions)
{
    const cairo_pdf_version_t *versions = 0;
    int version_count = 0, i = 0;
    zval pdf_version_case;

    ZEND_PARSE_PARAMETERS_NONE();

    cairo_pdf_get_versions(&versions, &version_count);
    array_init(return_value);

    for (i = 0; i < version_count; i++) {
        pdf_version_case = php_enum_from_cairo_c_enum(ce_cairo_pdfversion, versions[i]);
        add_next_index_zval(return_value, &pdf_version_case);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Surface\Pdf::setSize(double width, double height)
       Changes the size of a PDF surface for the current (and subsequent) pages.
       This should be called before any drawing takes place on the surface */
PHP_METHOD(Cairo_Surface_Pdf, setSize)
{
    double width = 0.0, height = 0.0;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(width)
        Z_PARAM_DOUBLE(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_pdf_surface_set_size(surface_object->surface, width, height);
    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Surface\Pdf::restrictToVersion(int version)
       Restricts the generated PDF file to version. */
PHP_METHOD(Cairo_Surface_Pdf, restrictToVersion)
{
    cairo_surface_object *surface_object;
    zval *version;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(version, ce_cairo_pdfversion);
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_pdf_surface_restrict_to_version(
        surface_object->surface,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(version)))
    );
    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */


/* {{{ proto int \Cairo\Surface\Pdf::addOutline(int parent_id, string name, string link_attr, int outline_flag])
       Add an item to the document outline hierarchy with a name that links to the location specified by link_attribs.
       Link attributes have the same keys and values as the Link Tag, excluding the "rect" attribute.
       The item will be a child of the item with id parent_id.
       Use CAIRO_PDF_OUTLINE_ROOT as the parent id of top level items.
       Returns the id for the added item. */
PHP_METHOD(Cairo_Surface_Pdf, addOutline)
{
    cairo_surface_object *surface_object;
    zend_long parent_id;
    zval *outline_flag;
    char *name, *linkAttribs;
    size_t name_len, linkAttribs_len;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(parent_id);
        Z_PARAM_STRING(name, name_len)
        Z_PARAM_STRING(linkAttribs, linkAttribs_len)
        Z_PARAM_OBJECT_OF_CLASS(outline_flag, ce_cairo_pdf_outlineflag);
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    RETVAL_LONG(cairo_pdf_surface_add_outline(
        surface_object->surface,
        parent_id,
        (const char *)name,
        (const char *)linkAttribs,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(outline_flag)))
    ));

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */


/* {{{ proto void \Cairo\Surface\Pdf::setMetadata(int metadata_constant [, string metadata])
       Set document metadata.
       The values for the CAIRO_PDF_METADATA_CREATE_DATE and CAIRO_PDF_METADATA_MOD_DATE fields must be in ISO-8601 format: YYYY-MM-DDThh:mm:ss.
       An optional timezone of the form "[+/-]hh:mm" or "Z" for UTC time can be appended.
       All other metadata values can be any UTF-8 string. */
PHP_METHOD(Cairo_Surface_Pdf, setMetadata)
{
    cairo_surface_object *surface_object;
    zval *metadata_const;
    char *metadata = "";
    size_t metadata_len;

    ZEND_PARSE_PARAMETERS_START(1, 2)
        Z_PARAM_OBJECT_OF_CLASS(metadata_const, ce_cairo_pdf_metadata);
        Z_PARAM_OPTIONAL;
        Z_PARAM_STRING(metadata, metadata_len)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_pdf_surface_set_metadata(
        surface_object->surface,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(metadata_const))),
        (const char *)metadata
    );

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */


/* {{{ proto void \Cairo\Surface\Pdf::setPageLabel(string label)
       Set page label for the current page. */
PHP_METHOD(Cairo_Surface_Pdf, setPageLabel)
{
    char *label;
    size_t label_len;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(label, label_len)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_pdf_surface_set_page_label(surface_object->surface, (const char *)label);

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */


/* {{{ proto void \Cairo\Surface\Pdf::setThumbnailSize(double width, double height)
       Set the thumbnail image size for the current and all subsequent pages.
       Setting a width or height of 0 disables thumbnails for the current and subsequent pages. */
PHP_METHOD(Cairo_Surface_Pdf, setThumbnailSize)
{
    long width = 0, height = 0;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(width)
        Z_PARAM_LONG(height)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    cairo_pdf_surface_set_thumbnail_size(surface_object->surface, width, height);
    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */


#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
/* {{{ proto void \Cairo\Surface\Pdf::setCustomMetadata(string field, string value)
       Set custom metadata for the PDF document.
       field may be any string except for the following names reserved by PDF:
       "Title", "Author", "Subject", "Keywords", "Creator", "Producer", "CreationDate", "ModDate", "Trapped" .*/
PHP_METHOD(Cairo_Surface_Pdf, setCustomMetadata)
{
    char *field, *value;
    size_t field_len, value_len;
    cairo_surface_object *surface_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STRING(field, field_len)
        Z_PARAM_STRING(value, value_len)
    ZEND_PARSE_PARAMETERS_END();

    surface_object = cairo_surface_object_get(getThis());
    if (!surface_object) {
        RETURN_THROWS();
    }

    if (strcasecmp(field, "Title") == 0
        || strcasecmp(field, "Author") == 0
        || strcasecmp(field, "Subject") == 0
        || strcasecmp(field, "Keywords") == 0
        || strcasecmp(field, "Creator") == 0
        || strcasecmp(field, "Producer") == 0
        || strcasecmp(field, "CreationDate") == 0
        || strcasecmp(field, "ModDate") == 0
        || strcasecmp(field, "Trapped") == 0
    ) {
        zend_throw_exception_ex(zend_ce_value_error, 0,
            "Cairo\\Surface\\Pdf::setCustomMetadata(): "
            "Argument #1 ($field) may be any string except for the following names reserved by PDF: "
            "Title, Author, Subject, Keywords, Creator, Producer, CreationDate, ModDate, Trapped."
        );
        RETURN_THROWS();
    }

    cairo_pdf_surface_set_custom_metadata(
        surface_object->surface,
        (const char *)field,
        (const char *)value
    );

    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */
#endif

/* ----------------------------------------------------------------
    \Cairo\Surface\Pdf Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_pdf_surface)
{
    ce_cairo_pdfsurface = register_class_Cairo_Surface_Pdf(ce_cairo_surface);

    /* PDF-Versions */
    ce_cairo_pdfversion = register_class_Cairo_Surface_Pdf_Version();

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    /* Outline-Flags */
    ce_cairo_pdf_outlineflag = register_class_Cairo_Surface_Pdf_OutlineFlags();

    /* Metadata */
    ce_cairo_pdf_metadata = register_class_Cairo_Surface_Pdf_Metadata();
#endif

    return SUCCESS;
}

#endif
