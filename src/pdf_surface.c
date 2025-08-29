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

zend_class_entry *ce_cairo_pdfsurface;
zend_class_entry *ce_cairo_pdf_metadata;
zend_class_entry *ce_cairo_pdf_outlineflag;
zend_class_entry *ce_cairo_pdfversion;
zend_class_entry *ce_cairo_pdf_outline;

/* ----------------------------------------------------------------
    \Cairo\Surface\Pdf Class API
------------------------------------------------------------------*/

ZEND_BEGIN_ARG_INFO(CairoPdfSurface___construct_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, file)
    ZEND_ARG_INFO(0, width)
    ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

/* {{{ proto void __construct(string|resource file, float width, float height)
       Creates a PDF surface of the specified size in points to be written to filename. */
PHP_METHOD(CairoPdfSurface, __construct)
{
    zval *stream_zval = NULL;
    stream_closure *closure;
    php_stream *stream = NULL;
    double width, height;
    zend_bool owned_stream = 0;
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


ZEND_BEGIN_ARG_INFO(CairoPdfSurface_versionToString_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Pdf\\Version, 0)
ZEND_END_ARG_INFO()

/* {{{ proto string \Cairo\Surface\Pdf::versionToString(int version)
       Get the string representation of the given version id. This function will return NULL if version isn't valid. */
PHP_METHOD(CairoPdfSurface, versionToString)
{
    zval *version;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(version, ce_cairo_pdfversion)
    ZEND_PARSE_PARAMETERS_END();

    RETURN_STRING(cairo_pdf_version_to_string(Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(version)))));
}
/* }}} */


ZEND_BEGIN_ARG_INFO(CairoPdfSurface_getVersions_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ proto array \Cairo\Surface\Pdf::getVersions()
       Used to retrieve the list of supported versions */
PHP_METHOD(CairoPdfSurface, getVersions)
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


ZEND_BEGIN_ARG_INFO(CairoPdfSurface_setSize_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, width)
    ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\Surface\Pdf::setSize(double width, double height)
       Changes the size of a PDF surface for the current (and subsequent) pages.
       This should be called before any drawing takes place on the surface */
PHP_METHOD(CairoPdfSurface, setSize)
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


ZEND_BEGIN_ARG_INFO(CairoPdfSurface_restrictToVersion_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_OBJ_INFO(0, version, Cairo\\Surface\\Pdf\\Version, 0)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\Surface\Pdf::restrictToVersion(int version)
       Restricts the generated PDF file to version. */
PHP_METHOD(CairoPdfSurface, restrictToVersion)
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


ZEND_BEGIN_ARG_INFO(CairoPdfSurface_addOutline_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, parent_id)
    ZEND_ARG_INFO(0, name)
    ZEND_ARG_INFO(0, link_attribs)
    ZEND_ARG_OBJ_INFO(0, outline_flag, Cairo\\Surface\\Pdf\\OutlineFlags, 0)
ZEND_END_ARG_INFO()

/* {{{ proto int \Cairo\Surface\Pdf::addOutline(int parent_id, string name, string link_attr, int outline_flag])
       Add an item to the document outline hierarchy with a name that links to the location specified by link_attribs.
       Link attributes have the same keys and values as the Link Tag, excluding the "rect" attribute.
       The item will be a child of the item with id parent_id.
       Use CAIRO_PDF_OUTLINE_ROOT as the parent id of top level items.
       Returns the id for the added item. */
PHP_METHOD(CairoPdfSurface, addOutline)
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


ZEND_BEGIN_ARG_INFO_EX(CairoPdfSurface_setMetadata_args, ZEND_SEND_BY_VAL, 0, 1)
    ZEND_ARG_OBJ_INFO(0, metadata_constant, Cairo\\Surface\\Pdf\\Metadata, 0)
    ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, metadata, IS_STRING, 0, "\"\"")
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\Surface\Pdf::setMetadata(int metadata_constant [, string metadata])
       Set document metadata.
       The values for the CAIRO_PDF_METADATA_CREATE_DATE and CAIRO_PDF_METADATA_MOD_DATE fields must be in ISO-8601 format: YYYY-MM-DDThh:mm:ss.
       An optional timezone of the form "[+/-]hh:mm" or "Z" for UTC time can be appended.
       All other metadata values can be any UTF-8 string. */
PHP_METHOD(CairoPdfSurface, setMetadata)
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


ZEND_BEGIN_ARG_INFO(CairoPdfSurface_setPageLabel_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\Surface\Pdf::setPageLabel(string label)
       Set page label for the current page. */
PHP_METHOD(CairoPdfSurface, setPageLabel)
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


ZEND_BEGIN_ARG_INFO(CairoPdfSurface_setThumbnailSize_args, ZEND_SEND_BY_VAL)
    ZEND_ARG_INFO(0, width)
    ZEND_ARG_INFO(0, height)
ZEND_END_ARG_INFO()

/* {{{ proto void \Cairo\Surface\Pdf::setThumbnailSize(double width, double height)
       Set the thumbnail image size for the current and all subsequent pages.
       Setting a width or height of 0 disables thumbnails for the current and subsequent pages. */
PHP_METHOD(CairoPdfSurface, setThumbnailSize)
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

    cairo_pdf_surface_set_thumbnail_size(surface_object->surface, width, height);
    if (php_cairo_throw_exception(cairo_surface_status(surface_object->surface))) {
        RETURN_THROWS();
    }
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Surface\Pdf Definition and registration
------------------------------------------------------------------*/

/* {{{ cairo_pdf_surface_methods[] */
const zend_function_entry cairo_pdf_surface_methods[] = {
    PHP_ME(CairoPdfSurface, __construct, CairoPdfSurface___construct_args, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(CairoPdfSurface, restrictToVersion, CairoPdfSurface_restrictToVersion_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoPdfSurface, getVersions, CairoPdfSurface_getVersions_args, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(CairoPdfSurface, versionToString, CairoPdfSurface_versionToString_args, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(CairoPdfSurface, setSize, CairoPdfSurface_setSize_args, ZEND_ACC_PUBLIC)
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    PHP_ME(CairoPdfSurface, addOutline, CairoPdfSurface_addOutline_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoPdfSurface, setMetadata, CairoPdfSurface_setMetadata_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoPdfSurface, setPageLabel, CairoPdfSurface_setPageLabel_args, ZEND_ACC_PUBLIC)
    PHP_ME(CairoPdfSurface, setThumbnailSize, CairoPdfSurface_setThumbnailSize_args, ZEND_ACC_PUBLIC)
#endif
    ZEND_FE_END
};
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_pdf_surface)
{
    zend_class_entry pdf_ce;

    INIT_NS_CLASS_ENTRY(pdf_ce,
        ZEND_NS_NAME(CAIRO_NAMESPACE, "Surface"), "Pdf",
        cairo_pdf_surface_methods);
    ce_cairo_pdfsurface = zend_register_internal_class_ex(&pdf_ce, ce_cairo_surface);
    ce_cairo_pdfsurface->create_object = cairo_surface_create_object;

    /* PDF-Versions */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Surface", ZEND_NS_NAME("Pdf", "Version")), ce_cairo_pdfversion);

#define CAIRO_PDF_VERSIONS_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_pdfversion, CAIRO_PDF)

    CAIRO_PDF_VERSIONS_DECLARE_ENUM_CASE(VERSION_1_4);
    CAIRO_PDF_VERSIONS_DECLARE_ENUM_CASE(VERSION_1_5);

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    CAIRO_PDF_VERSIONS_DECLARE_ENUM_CASE(VERSION_1_6);
    CAIRO_PDF_VERSIONS_DECLARE_ENUM_CASE(VERSION_1_7);
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    /* Outline: OUTLINE_ROOT as a constant of the Pdf class */
    zend_declare_class_constant_long(
        ce_cairo_pdfsurface,
        "OUTLINE_ROOT", sizeof("OUTLINE_ROOT")-1,
        CAIRO_PDF_OUTLINE_ROOT
    );

    /* Outline-Flags */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Surface", ZEND_NS_NAME("Pdf", "OutlineFlags")), ce_cairo_pdf_outlineflag);

#define CAIRO_PDF_OUTLINEFLAGS_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_pdf_outlineflag, CAIRO_PDF_OUTLINE_FLAG)

    CAIRO_PDF_OUTLINEFLAGS_DECLARE_ENUM_CASE(OPEN);
    CAIRO_PDF_OUTLINEFLAGS_DECLARE_ENUM_CASE(BOLD);
    CAIRO_PDF_OUTLINEFLAGS_DECLARE_ENUM_CASE(ITALIC);

    /* Metadata */
    CAIRO_REGISTER_ENUM_LONG(ZEND_NS_NAME("Surface", ZEND_NS_NAME("Pdf", "Metadata")), ce_cairo_pdf_metadata);

#define CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(name) \
    CAIRO_GENERIC_LONG_ENUM_CASE(name, ce_cairo_pdf_metadata, CAIRO_PDF_METADATA)

    CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(TITLE);
    CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(AUTHOR);
    CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(SUBJECT);
    CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(KEYWORDS);
    CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(CREATOR);
    CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(CREATE_DATE);
    CAIRO_PDF_METADATA_DECLARE_ENUM_CASE(MOD_DATE);
#endif

    return SUCCESS;
}

#endif
