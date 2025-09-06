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
#include "pattern_arginfo.h"

zend_class_entry *ce_cairo_pattern;
zend_class_entry *ce_cairo_pattern_solid;
zend_class_entry *ce_cairo_pattern_gradient;
zend_class_entry *ce_cairo_pattern_gradient_linear;
zend_class_entry *ce_cairo_pattern_gradient_radial;
zend_class_entry *ce_cairo_pattern_surface;
zend_class_entry *ce_cairo_pattern_mesh;
zend_class_entry *ce_cairo_pattern_raster;

zend_class_entry *ce_cairo_pattern_type;
zend_class_entry *ce_cairo_extend;
zend_class_entry *ce_cairo_filter;
zend_class_entry *ce_cairo_dither;

static zend_object_handlers cairo_pattern_object_handlers;

static cairo_user_data_key_t matrix_key;

void cairo_pattern_destroy_func (void *data)
{
    Z_DELREF_P(data);
    efree(data);
}

cairo_pattern_object *cairo_pattern_fetch_object(zend_object *object)
{
    return (cairo_pattern_object *) ((char*)(object) - XtOffsetOf(cairo_pattern_object, std));
}

static inline cairo_pattern_object *cairo_pattern_object_get(zval *zv)
{
    cairo_pattern_object *object = Z_CAIRO_PATTERN_P(zv);
    if (object->pattern == NULL) {
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Internal pattern object missing in %s, you must call parent::__construct in extended classes.",
            ZSTR_VAL(Z_OBJCE_P(zv)->name));
        return NULL;
    }
    return object;
}


/* ----------------------------------------------------------------
    Cairo\Pattern C API
------------------------------------------------------------------*/

zend_class_entry* php_cairo_get_pattern_ce(cairo_pattern_t *pattern)
{
    zend_class_entry *type;
    if (pattern == NULL) {
        return ce_cairo_pattern;
    }

    switch(cairo_pattern_get_type(pattern)) {
        case CAIRO_PATTERN_TYPE_SOLID:
            type = ce_cairo_pattern_solid;
            break;
        case CAIRO_PATTERN_TYPE_SURFACE:
            type = ce_cairo_pattern_surface;
            break;
        case CAIRO_PATTERN_TYPE_LINEAR:
            type = ce_cairo_pattern_gradient_linear;
            break;
        case CAIRO_PATTERN_TYPE_RADIAL:
            type = ce_cairo_pattern_gradient_radial;
            break;
        case CAIRO_PATTERN_TYPE_MESH:
            type = ce_cairo_pattern_mesh;
            break;
        case CAIRO_PATTERN_TYPE_RASTER_SOURCE:
            type = ce_cairo_pattern_raster;
            break;
        default:
            php_error(E_WARNING, "Unsupported Cairo Surface Type");
            return NULL;
    }
    return type;
}


/* ----------------------------------------------------------------
    Cairo\Pattern Class API
------------------------------------------------------------------ */

/* {{{ proto void contruct()
   \Cairo\Pattern CANNOT be extended in userspace, this will throw an exception on use */
PHP_METHOD(Cairo_Pattern, __construct)
{
    ZEND_PARSE_PARAMETERS_NONE();
    zend_throw_exception(ce_cairo_exception, "Cairo\\Pattern cannot be constructed", 0);
}
/* }}} */

/* {{{ proto \Cairo\Status \Cairo\Pattern::getStatus()
   Returns the current integer status of the CairoPattern */
PHP_METHOD(Cairo_Pattern, getStatus)
{
    cairo_pattern_object *pattern_object;
    zval status_case;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    status_case = php_enum_from_cairo_c_enum(
        ce_cairo_status,
        cairo_pattern_status(pattern_object->pattern)
    );

    if (Z_TYPE(status_case) == IS_OBJECT) {
        RETURN_ZVAL(&status_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Pattern::getType()
   This function returns the Cairo\Pattern\Type of a pattern */
PHP_METHOD(Cairo_Pattern, getType)
{
    cairo_pattern_object *pattern_object;
    zval pattern_case;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    pattern_case = php_enum_from_cairo_c_enum(
        ce_cairo_pattern_type,
        cairo_pattern_get_type(pattern_object->pattern)
    );

    if (Z_TYPE(pattern_case) == IS_OBJECT) {
        RETURN_ZVAL(&pattern_case, 1, 1);
    }
}

/* }}} */

/* {{{ proto int \Cairo\Pattern::getExtend()
       Gets the current extend mode for a pattern */
PHP_METHOD(Cairo_Pattern, getExtend)
{
    cairo_pattern_object *pattern_object;
    zval extend_case;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    extend_case = php_enum_from_cairo_c_enum(
        ce_cairo_extend,
        cairo_pattern_get_extend(pattern_object->pattern)
    );

    if (Z_TYPE(extend_case) == IS_OBJECT) {
        RETURN_ZVAL(&extend_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Pattern::setExtend(object)
       Sets the mode to be used for drawing outside the area of a pattern */
PHP_METHOD(Cairo_Pattern, setExtend)
{
    cairo_pattern_object *pattern_object;
    zval *extend_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(extend_case, ce_cairo_extend)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_pattern_set_extend(
        pattern_object->pattern,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(extend_case)))
    );

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto int \Cairo\Pattern::getFilter()
       Gets the current filter mode for a pattern */
PHP_METHOD(Cairo_Pattern, getFilter)
{
    cairo_pattern_object *pattern_object;
    zval filter_case;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    filter_case = php_enum_from_cairo_c_enum(
        ce_cairo_filter,
        cairo_pattern_get_filter(pattern_object->pattern)
    );

    if (Z_TYPE(filter_case) == IS_OBJECT) {
        RETURN_ZVAL(&filter_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Pattern::setFilter(Cairo\Filter filter)
       Sets the filter to be used for resizing when using this pattern */
PHP_METHOD(Cairo_Pattern, setFilter)
{
    cairo_pattern_object *pattern_object;
    zval *filter_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(filter_case, ce_cairo_filter)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_pattern_set_filter(
        pattern_object->pattern,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(filter_case)))
    );
    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}

/* }}} */

/* {{{ proto object \Cairo\Pattern::getMatrix()
   Returns the pattern's transformation matrix */
PHP_METHOD(Cairo_Pattern, getMatrix)
{
    cairo_pattern_object *pattern_object;
    zval *matrix = NULL;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    matrix = cairo_pattern_get_user_data(pattern_object->pattern, &matrix_key);
    if (matrix) {
        RETURN_COPY(matrix);
    }

    zval *matrix_store = emalloc(sizeof(zval));
    cairo_status_t status;

    object_init_ex(return_value, ce_cairo_matrix);
    cairo_pattern_get_matrix(pattern_object->pattern, cairo_matrix_object_get_matrix(return_value));
    ZVAL_COPY(matrix_store, return_value);
    status = cairo_pattern_set_user_data(
        pattern_object->pattern,
        &matrix_key,
        (void *)matrix_store, cairo_pattern_destroy_func
    );

    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Pattern::setMatrix(\Cairo\Matrix object)
   Sets the pattern's transformation matrix using the created matrix object.
   This matrix is a transformation from user space to pattern space. */
PHP_METHOD(Cairo_Pattern, setMatrix)
{
    zval *matrix_zval;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(matrix_zval, ce_cairo_matrix)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_pattern_set_matrix(pattern_object->pattern, cairo_matrix_object_get_matrix(matrix_zval));

    zval *matrix_store = emalloc(sizeof(zval));
    cairo_status_t status;

    ZVAL_COPY(matrix_store, matrix_zval);

    status = cairo_pattern_set_user_data(pattern_object->pattern, &matrix_key,
        (void *)matrix_store, cairo_pattern_destroy_func
    );

    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }
}
/* }}} */

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
/* {{{ proto object \Cairo\Pattern::getDither()
       Returns the pattern's dithering mode */
PHP_METHOD(Cairo_Pattern, getDither)
{
    cairo_pattern_object *pattern_object;
    zval dither_case;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    dither_case = php_enum_from_cairo_c_enum(
        ce_cairo_dither,
        cairo_pattern_get_dither(pattern_object->pattern)
    );

    if (Z_TYPE(dither_case) == IS_OBJECT) {
        RETURN_ZVAL(&dither_case, 1, 1);
    }
}
/* }}} */

/* {{{ proto void \Cairo\Pattern::setDither(Cairo\Dither dither)
       Sets the dithering mode to be used for this pattern */
PHP_METHOD(Cairo_Pattern, setDither)
{
    cairo_pattern_object *pattern_object;
    zval *dither_case;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(dither_case, ce_cairo_dither)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_pattern_set_dither(
        pattern_object->pattern,
        Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(dither_case)))
    );

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */
#endif


/* ----------------------------------------------------------------
    \Cairo\Pattern\Solid Class API
------------------------------------------------------------------ */

/* {{{ proto void contruct(float red, float green, float blue[, float alpha])
    Returns new \Cairo\Pattern\Solid using rgb and optionally alpha */
PHP_METHOD(Cairo_Pattern_Solid, __construct)
{
    double red = 0.0, green = 0.0, blue = 0.0;
    double alpha;
    bool alpha_is_null = true;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_START(3, 4)
        Z_PARAM_DOUBLE(red)
        Z_PARAM_DOUBLE(green)
        Z_PARAM_DOUBLE(blue)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE_OR_NULL(alpha, alpha_is_null)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = Z_CAIRO_PATTERN_P(getThis());
    if (!pattern_object) {
        RETURN_NULL();
    }

    if (alpha_is_null) {
        pattern_object->pattern = cairo_pattern_create_rgb(red, green, blue);
    } else {
        pattern_object->pattern = cairo_pattern_create_rgba(red, green, blue, alpha);
    }

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Pattern\Solid::getRgba()
   This function returns an array with four elements,
   the float values of red, green, blue, and alpha from the solid pattern */
PHP_METHOD(Cairo_Pattern_Solid, getRgba)
{
    cairo_pattern_object *pattern_object;
    double red, green, blue, alpha;
        cairo_status_t status;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    status = cairo_pattern_get_rgba(pattern_object->pattern, &red, &green, &blue, &alpha);
    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "red", red);
    add_assoc_double(return_value, "green", green);
    add_assoc_double(return_value, "blue", blue);
    add_assoc_double(return_value, "alpha", alpha);
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern\Gradient Class API
------------------------------------------------------------------ */

/* {{{ proto void \Cairo\Pattern\Gradient::addColorStopRgb(float offset, float red, float green, float blue)
   Adds an opaque color stop to a gradient pattern.
   The offset specifies the location along the gradient's control vector. */
PHP_METHOD(Cairo_Pattern_Gradient, addColorStopRgb)
{
    double offset = 0.0, red = 0.0, green = 0.0, blue = 0.0;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_DOUBLE(offset)
        Z_PARAM_DOUBLE(red)
        Z_PARAM_DOUBLE(green)
        Z_PARAM_DOUBLE(blue)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_pattern_add_color_stop_rgb(pattern_object->pattern, offset, red, green, blue);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void \Cairo\Pattern\Gradient::addColorStopRgba(float offset, float red, float green, float blue, float alpha)
   Adds a transparent color stop to a gradient pattern.
   The offset specifies the location along the gradient's control vector. */
PHP_METHOD(Cairo_Pattern_Gradient, addColorStopRgba)
{
    double offset = 0.0, red = 0.0, green = 0.0, blue = 0.0, alpha = 0.0;
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_START(5, 5)
        Z_PARAM_DOUBLE(offset)
        Z_PARAM_DOUBLE(red)
        Z_PARAM_DOUBLE(green)
        Z_PARAM_DOUBLE(blue)
        Z_PARAM_DOUBLE(alpha)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_pattern_add_color_stop_rgba(pattern_object->pattern, offset, red, green, blue, alpha);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Pattern\Gradient::getColorStopRgba()
   Gets the color and offset information at the given index for a gradient pattern */
PHP_METHOD(Cairo_Pattern_Gradient, getColorStopRgba)
{
    zend_long index;
    double offset, red, green, blue, alpha;
    cairo_pattern_object *pattern_object;
    cairo_status_t status;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    status = cairo_pattern_get_color_stop_rgba(pattern_object->pattern, index, &offset, &red, &green, &blue, &alpha);
    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "offset", offset);
    add_assoc_double(return_value, "red", red);
    add_assoc_double(return_value, "green", green);
    add_assoc_double(return_value, "blue", blue);
    add_assoc_double(return_value, "alpha", alpha);
}
/* }}} */

/* {{{ proto int \Cairo\Pattern\Gradient::getColorStopCount()
   Gets the number of color stops specified in the given gradient pattern */
PHP_METHOD(Cairo_Pattern_Gradient, getColorStopCount)
{
    int count;
    cairo_pattern_object *pattern_object;
    cairo_status_t status;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    status = cairo_pattern_get_color_stop_count(pattern_object->pattern, &count);
    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }

    RETURN_LONG(count);
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern\Gradient\Radial Class API
------------------------------------------------------------------ */

/* {{{ proto void construct(float x0, float y0, float r0, float x1, float y1, float r1)
  Create a new Gradient along the line defined by (x0, y0) and (x1, y1).
  Before using the gradient pattern, a number of color stops should be defined. */
PHP_METHOD(Cairo_Pattern_Gradient_Radial, __construct)
{
    cairo_pattern_object *pattern_object;
    double x0 = 0.0, y0 = 0.0, r0 = 0.0, x1 = 0.0, y1 = 0.0, r1 = 0.0;

    ZEND_PARSE_PARAMETERS_START(6, 6)
        Z_PARAM_DOUBLE(x0)
        Z_PARAM_DOUBLE(y0)
        Z_PARAM_DOUBLE(r0)
        Z_PARAM_DOUBLE(x1)
        Z_PARAM_DOUBLE(y1)
        Z_PARAM_DOUBLE(r1)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = Z_CAIRO_PATTERN_P(getThis());
    if (!pattern_object) {
        RETURN_NULL();
    }
    pattern_object->pattern = cairo_pattern_create_radial(x0, y0, r0, x1, y1, r1);
    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto array \Cairo\Pattern\Gradient\Radial::getCircles()
   Gets the gradient endpoint circles for a radial gradient
   each specified as a center coordinate and a radius.*/
PHP_METHOD(Cairo_Pattern_Gradient_Radial, getCircles)
{
    cairo_pattern_object *pattern_object;
    double x0 = 0.0, y0 = 0.0, r0 = 0.0, x1 = 0.0, y1 = 0.0, r1 = 0.0;
    cairo_status_t status;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    status = cairo_pattern_get_radial_circles(pattern_object->pattern, &x0, &y0, &r0, &x1, &y1, &r1);

    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x0", x0);
    add_assoc_double(return_value, "y0", y0);
    add_assoc_double(return_value, "r0", r0);
    add_assoc_double(return_value, "x1", x1);
    add_assoc_double(return_value, "y1", y1);
    add_assoc_double(return_value, "r1", r1);
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern\Gradient\Linear Class API
------------------------------------------------------------------ */

/* {{{ proto void construct(float x0, float y0, float x1, float y1)
  Create a new CairoLinearGradient along the line defined by (x0, y0) and (x1, y1).
  Before using the gradient pattern, a number of color stops should be defined. */
PHP_METHOD(Cairo_Pattern_Gradient_Linear, __construct)
{
    cairo_pattern_object *pattern_object;
    double x0 = 0.0, y0 = 0.0, x1 = 0.0, y1 = 0.0;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_DOUBLE(x0)
        Z_PARAM_DOUBLE(y0)
        Z_PARAM_DOUBLE(x1)
        Z_PARAM_DOUBLE(y1)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = Z_CAIRO_PATTERN_P(getThis());
    if (!pattern_object) {
        RETURN_NULL();
    }

    pattern_object->pattern = cairo_pattern_create_linear(x0, y0, x1, y1);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto void cairo_pattern_get_linear_points(CairoLinearGradient object)
   proto void \Cairo\Pattern\Gradient\Linear::getPoints()
   Gets the gradient endpoints for a linear gradient. */
PHP_METHOD(Cairo_Pattern_Gradient_Linear, getPoints)
{
    cairo_pattern_object *pattern_object;
    double x0, y0, x1, y1;
    cairo_status_t status;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    status = cairo_pattern_get_linear_points(pattern_object->pattern, &x0, &y0, &x1, &y1);

    if (php_cairo_throw_exception(status)) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x0", x0);
    add_assoc_double(return_value, "y0", y0);
    add_assoc_double(return_value, "x1", x1);
    add_assoc_double(return_value, "y1", y1);
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern\Surface Class API
------------------------------------------------------------------ */

/* {{{ proto void contruct([object surface])
    Returns new \Cairo\Pattern\Surface using supplied surface */
PHP_METHOD(Cairo_Pattern_Surface, __construct)
{
    cairo_pattern_object *pattern_object;
    cairo_surface_object *surface_object;
    zval *surface_zval;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_OBJECT_OF_CLASS(surface_zval, ce_cairo_surface)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = Z_CAIRO_PATTERN_P(getThis());
    if (!pattern_object) {
        RETURN_NULL();
    }

    surface_object = cairo_surface_object_get(surface_zval);
    if (!surface_object) {
        RETURN_THROWS();
    }

    pattern_object->pattern = cairo_pattern_create_for_surface(surface_object->surface);
    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }

    /* we need to be able to get these zvals out later, so store it*/
    ZVAL_COPY(&pattern_object->surface, surface_zval);
}
/* }}} */

/* {{{ proto CairoSurface object \Cairo\Pattern\Surface::getSurface()
   This function returns the surface object */
PHP_METHOD(Cairo_Pattern_Surface, getSurface)
{
    cairo_pattern_object *pattern_object;
    cairo_surface_object *surface_object;
    cairo_surface_t *surface;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_pattern_get_surface(pattern_object->pattern, &surface))) {
        RETURN_THROWS();
    }

    /* If we have a surface, grab that zval to use */
    CAIRO_RETURN_IF_REF(pattern_object->surface);

    /* Otherwise we spawn a new object */
    /* we can't always rely on the same type of surface being returned, so we use php_cairo_get_surface_ce */
    object_init_ex(return_value, php_cairo_get_surface_ce(surface));

    // cairo_surface_create_object(php_cairo_get_surface_ce(surface));
    surface_object = Z_CAIRO_SURFACE_P(return_value);

    /* if there IS a value in surface, destroy it cause we're getting a new one */
    if (surface_object->surface != NULL) {
        cairo_surface_destroy(surface_object->surface);
    }

    surface_object->surface = surface;
    cairo_surface_reference(surface_object->surface);
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern\Mesh Class API
------------------------------------------------------------------ */

/* {{{ proto void contruct()
    Returns new \Cairo\Pattern\Mesh */
PHP_METHOD(Cairo_Pattern_Mesh, __construct)
{
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = Z_CAIRO_PATTERN_P(getThis());
    if (!pattern_object) {
        RETURN_NULL();
    }

    pattern_object->pattern = cairo_pattern_create_mesh();

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::beginPatch()
  begin a patch in a mesh pattern */
PHP_METHOD(Cairo_Pattern_Mesh, beginPatch)
{
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_mesh_pattern_begin_patch(pattern_object->pattern);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::endPatch()
  end a patch in a mesh pattern*/
PHP_METHOD(Cairo_Pattern_Mesh, endPatch)
{
    cairo_pattern_object *pattern_object;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_mesh_pattern_end_patch(pattern_object->pattern);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::moveTo(float x, float y)
  move to a new starting point position in the patch */
PHP_METHOD(Cairo_Pattern_Mesh, moveTo)
{
    cairo_pattern_object *pattern_object;
    double x, y;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_mesh_pattern_move_to(pattern_object->pattern, x, y);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::lineTo(float x, float y)
   add a line from the current point to position in the patch */
PHP_METHOD(Cairo_Pattern_Mesh, lineTo)
{
    cairo_pattern_object *pattern_object;
    double x, y;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_mesh_pattern_line_to(pattern_object->pattern, x, y);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::curveTo(float x1, float y1, float x2,
 *           float y2, float x3, float y3)
   cubic bezier spline added to current path */
PHP_METHOD(Cairo_Pattern_Mesh, curveTo)
{
    cairo_pattern_object *pattern_object;
    double x1, y1, x2, y2, x3, y3;

    ZEND_PARSE_PARAMETERS_START(6, 6)
        Z_PARAM_DOUBLE(x1)
        Z_PARAM_DOUBLE(y1)
        Z_PARAM_DOUBLE(x2)
        Z_PARAM_DOUBLE(y2)
        Z_PARAM_DOUBLE(x3)
        Z_PARAM_DOUBLE(y3)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_mesh_pattern_curve_to(pattern_object->pattern, x1, y1, x2, y2, x3, y3);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::setControlPoint(int point_num,
            float x, float y)
        Set an internal control point of the current patch. */
PHP_METHOD(Cairo_Pattern_Mesh, setControlPoint)
{
    cairo_pattern_object *pattern_object;
    zend_long point_num;
    double x, y;

    ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_LONG(point_num)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    if (point_num < 0 || point_num > 3) {
        zend_throw_error(ce_cairo_exception, "Invalid $point_num. Expected 0, 1, 2, or 3.");
        RETURN_THROWS();
    }

    cairo_mesh_pattern_set_control_point(pattern_object->pattern, point_num, x, y);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

// TODO: combine setCornerColorRgb and setCornerColorRgba to setCornerColor
// default value for alpha = 1.0

/* {{{  proto void \Cairo\Pattern\Mesh::setCornerColorRgb(int corner_num,
            float red, float blue, float green)
        Sets the color of a corner of the current patch in a mesh pattern. */
PHP_METHOD(Cairo_Pattern_Mesh, setCornerColorRgb)
{
    cairo_pattern_object *pattern_object;
    zend_long corner_num;
    double red, green, blue;

    ZEND_PARSE_PARAMETERS_START(4, 4)
        Z_PARAM_LONG(corner_num)
        Z_PARAM_DOUBLE(red)
        Z_PARAM_DOUBLE(green)
        Z_PARAM_DOUBLE(blue)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    if (corner_num < 0 || corner_num > 3) {
        zend_throw_error(ce_cairo_exception, "Invalid $corner_num. Expected 0, 1, 2, or 3.");
        RETURN_THROWS();
    }

    cairo_mesh_pattern_set_corner_color_rgb(pattern_object->pattern, corner_num, red, green, blue);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::setCornerColorRgba(int corner_num,
            float red, float blue, float green, float alpha)
        Sets the color of a corner of the current patch in a mesh pattern. */
PHP_METHOD(Cairo_Pattern_Mesh, setCornerColorRgba)
{
    cairo_pattern_object *pattern_object;
    zend_long corner_num;
    double red, green, blue, alpha;

    ZEND_PARSE_PARAMETERS_START(5, 5)
        Z_PARAM_LONG(corner_num)
        Z_PARAM_DOUBLE(red)
        Z_PARAM_DOUBLE(green)
        Z_PARAM_DOUBLE(blue)
        Z_PARAM_DOUBLE(alpha)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    if (corner_num < 0 || corner_num > 3) {
        zend_throw_error(ce_cairo_exception, "Invalid $corner_num. Expected 0, 1, 2, or 3.");
        RETURN_THROWS();
    }

    cairo_mesh_pattern_set_corner_color_rgba(pattern_object->pattern, corner_num, red, green, blue, alpha);

    if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::getPatchCount()
        Gets the number of patches specified in the given mesh pattern. */
PHP_METHOD(Cairo_Pattern_Mesh, getPatchCount)
{
    cairo_pattern_object *pattern_object;
    unsigned int count;

    ZEND_PARSE_PARAMETERS_NONE();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_mesh_pattern_get_patch_count(pattern_object->pattern, &count))) {
        RETURN_THROWS();
    }

    RETURN_LONG(count);
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::getPath()
        Gets path defining the patch patch_num for a mesh pattern. */
PHP_METHOD(Cairo_Pattern_Mesh, getPath)
{
    cairo_pattern_object *pattern_object;
    cairo_path_object *path_object;
    cairo_path_t *path;
    zend_long patch_num;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(patch_num)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    path = cairo_mesh_pattern_get_path(pattern_object->pattern, patch_num);

    object_init_ex(return_value, ce_cairo_path);

    path_object = Z_CAIRO_PATH_P(return_value);
    if (!path_object) {
        RETURN_NULL();
    }

    path_object->path = path;
}
/* }}} */

/* {{{  proto array \Cairo\Pattern\Mesh::getControlPoint()
        Gets the control point point_num of patch patch_num for a mesh pattern. */
PHP_METHOD(Cairo_Pattern_Mesh, getControlPoint)
{
    cairo_pattern_object *pattern_object;
    zend_long patch_num, point_num;
    double x, y;
    unsigned int count, max_patch_id;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(patch_num)
        Z_PARAM_LONG(point_num)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_mesh_pattern_get_patch_count(pattern_object->pattern, &count);
    max_patch_id = count - 1;
    if (count == 0) {
        zend_throw_error(ce_cairo_exception, "No patches found or first patch not finished with endPatch().");
        RETURN_THROWS();
    } else if (patch_num < 0 || (unsigned int)patch_num > max_patch_id) {
        zend_throw_error(ce_cairo_exception, "Invalid $patch_num. Expected 0 to %d.", max_patch_id);
        RETURN_THROWS();
    }

    if (point_num < 0 || point_num > 3) {
        zend_throw_error(ce_cairo_exception, "Invalid $point_num. Expected 0, 1, 2, or 3.");
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_mesh_pattern_get_control_point(
        pattern_object->pattern, patch_num, point_num, &x, &y))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* {{{  proto void \Cairo\Pattern\Mesh::getCornerColorRgba()
        Gets the color information in corner of path for a mesh pattern */
PHP_METHOD(Cairo_Pattern_Mesh, getCornerColorRgba)
{
    cairo_pattern_object *pattern_object;
    zend_long patch_num, corner_num;
    double red, green, blue, alpha;
    unsigned int count, max_patch_id;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_LONG(patch_num)
        Z_PARAM_LONG(corner_num)
    ZEND_PARSE_PARAMETERS_END();

    pattern_object = cairo_pattern_object_get(getThis());
    if (!pattern_object) {
        RETURN_THROWS();
    }

    cairo_mesh_pattern_get_patch_count(pattern_object->pattern, &count);
    max_patch_id = count - 1;
    if (count == 0) {
        zend_throw_error(ce_cairo_exception, "No patches found or first patch not finished with endPatch().");
        RETURN_THROWS();
    } else if (patch_num < 0 || (unsigned int)patch_num > max_patch_id) {
        zend_throw_error(ce_cairo_exception, "Invalid $patch_num. Expected 0 to %d.", max_patch_id);
        RETURN_THROWS();
    }

    if (corner_num < 0 || corner_num > 3) {
        zend_throw_error(ce_cairo_exception, "Invalid $corner_num. Expected 0, 1, 2, or 3.");
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_mesh_pattern_get_corner_color_rgba(
        pattern_object->pattern, patch_num, corner_num, &red, &green, &blue, &alpha))) {
        RETURN_THROWS();
    }

    array_init(return_value);
    add_assoc_double(return_value, "red", red);
    add_assoc_double(return_value, "green", green);
    add_assoc_double(return_value, "blue", blue);
    add_assoc_double(return_value, "alpha", alpha);
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern\RasterSource Class API
------------------------------------------------------------------ */

/* {{{ proto void construct(enum \Cairo\Surface\Content, int width, int height)
       Returns new \Cairo\Pattern\RasterSource using supplied surface */
// PHP_METHOD(CairoPatternRasterSource, __construct)
// {
//     cairo_pattern_object *pattern_object;
//     zend_long width, height;
//     zval *content;

//     ZEND_PARSE_PARAMETERS_START(3, 3)
//         Z_PARAM_OBJECT_OF_CLASS(content, ce_cairo_content)
//         Z_PARAM_LONG(width)
//         Z_PARAM_LONG(height)
//     ZEND_PARSE_PARAMETERS_END();

//     pattern_object = Z_CAIRO_PATTERN_P(getThis());
//     if (!pattern_object) {
//         RETURN_NULL();
//     }

//     // TODO: create callbacks in C that feed to php methods as callbacks
//     // register them all, and do the create
//     // also figure out callback data - varargs?
//     if (php_cairo_throw_exception(cairo_pattern_status(pattern_object->pattern))) {
//         RETURN_THROWS();
//     }
// }
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_pattern_free_obj(zend_object *object)
{
    cairo_pattern_object *intern = cairo_pattern_fetch_object(object);

    if (!intern) {
        return;
    }

    zval_ptr_dtor(&intern->surface);

    if (intern->pattern) {
        cairo_pattern_destroy(intern->pattern);
        intern->pattern = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* cairo_pattern_obj_ctor(zend_class_entry *ce, cairo_pattern_object **intern)
{
    cairo_pattern_object *object = ecalloc(1, sizeof(cairo_pattern_object) + zend_object_properties_size(ce));

    ZVAL_UNDEF(&object->surface);
    object->pattern = NULL;

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &cairo_pattern_object_handlers;
    *intern = object;

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* cairo_pattern_create_object(zend_class_entry *ce)
{
    cairo_pattern_object *pattern = NULL;
    zend_object *return_value = cairo_pattern_obj_ctor(ce, &pattern);

    object_properties_init(&pattern->std, ce);
    return return_value;
}
/* }}} */


/* ----------------------------------------------------------------
    \Cairo\Pattern Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_pattern)
{
    memcpy(
        &cairo_pattern_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    // Pattern
    cairo_pattern_object_handlers.offset = XtOffsetOf(cairo_pattern_object, std);
    cairo_pattern_object_handlers.free_obj = cairo_pattern_free_obj;

    ce_cairo_pattern = register_class_Cairo_Pattern();
    ce_cairo_pattern->create_object = cairo_pattern_create_object;

    // Pattern\Solid
    ce_cairo_pattern_solid = register_class_Cairo_Pattern_Solid(ce_cairo_pattern);

    // Pattern\Gradient
    ce_cairo_pattern_gradient = register_class_Cairo_Pattern_Gradient(ce_cairo_pattern);

    // Pattern\Gradient\Radial
    ce_cairo_pattern_gradient_radial = register_class_Cairo_Pattern_Gradient_Radial(ce_cairo_pattern_gradient);

    // Pattern\Gradient\Linear
    ce_cairo_pattern_gradient_linear = register_class_Cairo_Pattern_Gradient_Linear(ce_cairo_pattern_gradient);

    // Pattern\Surface
    ce_cairo_pattern_surface = register_class_Cairo_Pattern_Surface(ce_cairo_pattern);

    // Pattern\Mesh
    ce_cairo_pattern_mesh = register_class_Cairo_Pattern_Mesh(ce_cairo_pattern);

    // Pattern\RasterSource
    // not implemented yet
    // ce_cairo_pattern_raster = register_class_Cairo_Pattern_RasterSource(ce_cairo_pattern);

    // Pattern\Type
    ce_cairo_pattern_type = register_class_Cairo_Pattern_Type();

    // Extend
    ce_cairo_extend = register_class_Cairo_Extend();

    // Filter
    ce_cairo_filter = register_class_Cairo_Filter();

    // Dither
    ce_cairo_dither = register_class_Cairo_Dither();

    return SUCCESS;
}
