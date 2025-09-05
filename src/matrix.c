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
#include <zend_gc.h>

#include "php_cairo.h"
#include "php_cairo_internal.h"
#include "matrix_arginfo.h"

zend_class_entry *ce_cairo_matrix;
static zend_object_handlers cairo_matrix_object_handlers;

cairo_matrix_object *cairo_matrix_fetch_object(zend_object *object)
{
    return (cairo_matrix_object *) ((char*)(object) - XtOffsetOf(cairo_matrix_object, std));
}

static inline double cairo_matrix_get_property_default(zend_class_entry *ce, char * name) {
    zend_property_info *property_info;
    double value = 0.0;
    zend_string *key = zend_string_init(name, strlen(name), 0);

    property_info = zend_get_property_info(ce, key, 1);
    if (property_info) {
        zval *val = (zval*)((char*)ce->default_properties_table + property_info->offset - OBJ_PROP_TO_OFFSET(0));
        if (val) {
            value = zval_get_double(val);
        }
    }
    zend_string_release(key);
    return value;
}

static inline double cairo_matrix_get_property_value(zend_object *object, char *name) {
    zval *prop, rv;

    prop = zend_read_property(object->ce, object, name, strlen(name), 1, &rv);
    return zval_get_double(prop);
}

cairo_matrix_object *cairo_matrix_object_get(zval *zv)
{
    cairo_matrix_object *object = Z_CAIRO_MATRIX_P(zv);

    if (object->matrix == NULL) {
        zend_throw_exception_ex(ce_cairo_exception, 0,
            "Internal matrix object missing in %s, you must call parent::__construct in extended classes.",
            ZSTR_VAL(Z_OBJCE_P(zv)->name));
        return NULL;
    }

    return object;
}

#define CAIRO_ALLOC_MATRIX(matrix_value) \
    if (!matrix_value) { \
        matrix_value = ecalloc(1, sizeof(cairo_matrix_t)); \
    }

#define CAIRO_VALUE_FROM_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        value = matrix_object->matrix->n; \
        break; \
    }

#define CAIRO_VALUE_TO_STRUCT(n) \
    if (strcmp(member->val, #n) == 0) { \
        matrix_object->matrix->n = zval_get_double(value); \
        break; \
    }

#define CAIRO_ADD_STRUCT_VALUE(n) \
    ZVAL_DOUBLE(&tmp, matrix_object->matrix->n); \
    zend_hash_str_update(props, #n, sizeof(#n)-1, &tmp);

/* ----------------------------------------------------------------
    Cairo\Matrix C API
------------------------------------------------------------------*/

/* {{{ */
cairo_matrix_t *cairo_matrix_object_get_matrix(zval *zv)
{
    cairo_matrix_object *matrix_object = cairo_matrix_object_get(zv);

    return matrix_object->matrix;
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\Matrix Class API
------------------------------------------------------------------*/

/* {{{ proto void __construct([float xx, float yx, float xy, float yy, float x0, float y0])
    CairoMatrix is used throughout cairo to convert between different coordinate
    spaces. A CairoMatrix holds an affine transformation, such as a scale, rotation,
    shear, or a combination of these */
PHP_METHOD(Cairo_Matrix, __construct)
{
    cairo_matrix_object *matrix_object;
    zend_object *object = Z_OBJ_P(getThis());

    /* read defaults from object */
    double xx = cairo_matrix_get_property_value(object, "xx");
    double yx = cairo_matrix_get_property_value(object, "yx");
    double xy = cairo_matrix_get_property_value(object, "xy");
    double yy = cairo_matrix_get_property_value(object, "yy");
    double x0 = cairo_matrix_get_property_value(object, "x0");
    double y0 = cairo_matrix_get_property_value(object, "y0");

    ZEND_PARSE_PARAMETERS_START(0, 6)
        Z_PARAM_OPTIONAL
        Z_PARAM_DOUBLE(xx)
        Z_PARAM_DOUBLE(yx)
        Z_PARAM_DOUBLE(xy)
        Z_PARAM_DOUBLE(yy)
        Z_PARAM_DOUBLE(x0)
        Z_PARAM_DOUBLE(y0)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = cairo_matrix_fetch_object(object);

    cairo_matrix_init(matrix_object->matrix, xx, yx, xy, yy, x0, y0);
}
/* }}} */

/* {{{ proto object \Cairo\Matrix::initIdentity()
       Create initialized matrix to be an identity transformation. */
PHP_METHOD(Cairo_Matrix, initIdentity)
{
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_NONE();

    object_init_ex(return_value, ce_cairo_matrix);
    matrix_object = cairo_matrix_object_get(return_value);
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_init_identity(matrix_object->matrix);
}
/* }}} */

/* {{{ proto object \Cairo\Matrix::initTranslate(float tx, float ty)
       Create initialized matrix to a transformation that translates by
       tx and ty in the X and Y dimensions, respectively. */
PHP_METHOD(Cairo_Matrix, initTranslate)
{
    double tx = 0.0, ty = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(tx)
        Z_PARAM_DOUBLE(ty)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_cairo_matrix);
    matrix_object = cairo_matrix_object_get(return_value);
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_init_translate(matrix_object->matrix, tx, ty);
}
/* }}} */

/* {{{ proto object \Cairo\Matrix::initScale(float sx, float sy)
       Create initialized matrix to a transformation that scales
       by sx and sy in the X and Y dimensions, respectively. */
PHP_METHOD(Cairo_Matrix, initScale)
{
    double sx = 0.0, sy = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(sx)
        Z_PARAM_DOUBLE(sy)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_cairo_matrix);
    matrix_object = cairo_matrix_object_get(return_value);
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_init_scale(matrix_object->matrix, sx, sy);
}
/* }}} */

/* {{{ proto object \Cairo\Matrix::initRotate(float radians)
       Create initialized matrix to a transformation that rotates by radians. */
PHP_METHOD(Cairo_Matrix, initRotate)
{
    double radians = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(radians)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_cairo_matrix);
    matrix_object = cairo_matrix_object_get(return_value);
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_init_rotate(matrix_object->matrix, radians);
}
/* }}} */

/* {{{ proto void CairoMatrix->translate(float tx, float ty)
    Applies a translation to the transformation. The effect of the new transformation
    is to first translate the coordinates by tx and ty, then apply the original
    transformation to the coordinates. */
PHP_METHOD(Cairo_Matrix, translate)
{
    double tx = 0.0, ty = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(tx)
        Z_PARAM_DOUBLE(ty)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = cairo_matrix_object_get(getThis());
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_translate(matrix_object->matrix, tx, ty);
}
/* }}} */

/* {{{ proto void CairoMatrix->scale(float sx, float sy)
       Applies scaling by sx, sy to the transformation in matrix. The effect of
       the new transformation is to first scale the coordinates by sx and sy, then apply
       the original transformation to the coordinates. */
PHP_METHOD(Cairo_Matrix, scale)
{
    double sx = 0.0, sy = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(sx)
        Z_PARAM_DOUBLE(sy)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = cairo_matrix_object_get(getThis());
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_scale(matrix_object->matrix, sx, sy);
}
/* }}} */

/* {{{ proto void CairoMatrix->rotate(float radians)
       Applies rotation by radians to the transformation in matrix. The effect of the new
       transformation is to first rotate the coordinates by radians, then
       apply the original transformation to the coordinates. */
PHP_METHOD(Cairo_Matrix, rotate)
{
    double radians = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_DOUBLE(radians)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = cairo_matrix_object_get(getThis());
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_rotate(matrix_object->matrix, radians);
}
/* }}} */

/* {{{ proto void CairoMatrix->invert()
       Changes matrix to be the inverse of it's original value. Not all transformation
       matrices have inverses; if the matrix collapses points together (it is degenerate),
       then it has no inverse and this function will fail. */
PHP_METHOD(Cairo_Matrix, invert)
{
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_NONE();

    matrix_object = cairo_matrix_object_get(getThis());
    if (!matrix_object) {
        RETURN_THROWS();
    }

    if (php_cairo_throw_exception(cairo_matrix_invert(matrix_object->matrix))) {
        RETURN_THROWS();
    }
}
/* }}} */

/* {{{ proto CairoMatrix \Cairo\Matrix::multiply(Cairo\Matrix matrix1, Cairo\Matrix matrix2)
       Multiplies the affine transformations in two matrices together and returns the result */
PHP_METHOD(Cairo_Matrix, multiply)
{
    zval *matrix1 = NULL, *matrix2 = NULL;
    cairo_matrix_object *matrix_object, *matrix_object1, *matrix_object2;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_OBJECT_OF_CLASS(matrix1, ce_cairo_matrix)
        Z_PARAM_OBJECT_OF_CLASS(matrix2, ce_cairo_matrix)
    ZEND_PARSE_PARAMETERS_END();

    object_init_ex(return_value, ce_cairo_matrix);
    matrix_object = Z_CAIRO_MATRIX_P(return_value);
    CAIRO_ALLOC_MATRIX(matrix_object->matrix);

    matrix_object1 = cairo_matrix_object_get(matrix1);
    matrix_object2 = cairo_matrix_object_get(matrix2);
    if (!matrix_object1 || !matrix_object2) {
        RETURN_THROWS();
    }

    cairo_matrix_multiply(matrix_object->matrix, matrix_object1->matrix, matrix_object2->matrix);
}
/* }}} */

/* {{{ proto array CairoMatrix->transformDistance(float dx, float dy)
       Transforms the distance vector (dx, dy) by matrix. This is similar to transform point
       except that the translation components of the transformation are ignored */
PHP_METHOD(Cairo_Matrix, transformDistance)
{
    double dx = 0.0, dy = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(dx)
        Z_PARAM_DOUBLE(dy)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = cairo_matrix_object_get(getThis());
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_transform_distance(matrix_object->matrix, &dx, &dy);

    array_init(return_value);
    add_assoc_double(return_value, "x", dx);
    add_assoc_double(return_value, "y", dy);
}
/* }}} */

/* {{{ proto array CairoMatrix->transformPoint(float x, float y)
       Transforms the point (x, y) by matrix. */
PHP_METHOD(Cairo_Matrix, transformPoint)
{
    double x = 0.0, y = 0.0;
    cairo_matrix_object *matrix_object;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_DOUBLE(x)
        Z_PARAM_DOUBLE(y)
    ZEND_PARSE_PARAMETERS_END();

    matrix_object = cairo_matrix_object_get(getThis());
    if (!matrix_object) {
        RETURN_THROWS();
    }

    cairo_matrix_transform_point(matrix_object->matrix, &x, &y);

    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\Matrix Object management
------------------------------------------------------------------*/

/* {{{ */
static void cairo_matrix_free_obj(zend_object *object)
{
    cairo_matrix_object *intern = cairo_matrix_fetch_object(object);

    if (!intern) {
        return;
    }

    if (intern->matrix) {
        efree(intern->matrix);
        intern->matrix = NULL;
    }

    zend_object_std_dtor(&intern->std);
}
/* }}} */

/* {{{ */
static zend_object* cairo_matrix_obj_ctor(zend_class_entry *ce, cairo_matrix_object **intern)
{
    cairo_matrix_object *object = ecalloc(1, sizeof(cairo_matrix_object) + zend_object_properties_size(ce));
    CAIRO_ALLOC_MATRIX(object->matrix);

    zend_object_std_init(&object->std, ce);
    object->std.handlers = &cairo_matrix_object_handlers;
    *intern = object;

    /* We need to read in any default values and set them if applicable
       xx, yx, xy, yy, x0, y0
     */
    if (ce->default_properties_count) {
        object->matrix->xx = cairo_matrix_get_property_default(ce, "xx");
        object->matrix->yx = cairo_matrix_get_property_default(ce, "yx");
        object->matrix->xy = cairo_matrix_get_property_default(ce, "xy");
        object->matrix->yy = cairo_matrix_get_property_default(ce, "yy");
        object->matrix->x0 = cairo_matrix_get_property_default(ce, "x0");
        object->matrix->y0 = cairo_matrix_get_property_default(ce, "y0");
    }

    return &object->std;
}
/* }}} */

/* {{{ */
static zend_object* cairo_matrix_create_object(zend_class_entry *ce)
{
    cairo_matrix_object *intern = NULL;
    zend_object *return_value = cairo_matrix_obj_ctor(ce, &intern);

    object_properties_init(&intern->std, ce);
    return return_value;
}
/* }}} */

/* {{{ */
static zend_object* cairo_matrix_clone_obj(zend_object *zobj)
{
    cairo_matrix_object *new_matrix;
    cairo_matrix_object *old_matrix = cairo_matrix_fetch_object(zobj);
    zend_object *return_value = cairo_matrix_obj_ctor(zobj->ce, &new_matrix);
    CAIRO_ALLOC_MATRIX(new_matrix->matrix);

    cairo_matrix_init(
        new_matrix->matrix,
        old_matrix->matrix->xx,
        old_matrix->matrix->yx,
        old_matrix->matrix->xy,
        old_matrix->matrix->yy,
        old_matrix->matrix->x0,
        old_matrix->matrix->y0
    );

    zend_objects_clone_members(&new_matrix->std, &old_matrix->std);

    return return_value;
}
/* }}} */

/* {{{ */
static zval *cairo_matrix_object_read_property(zend_object *object, zend_string *member, int type, void **cache_slot, zval *rv)
{
    zval *retval;
    double value;
    cairo_matrix_object *matrix_object = cairo_matrix_fetch_object(object);

    if (!matrix_object) {
        return rv;
    }

    do {
        CAIRO_VALUE_FROM_STRUCT(xx);
        CAIRO_VALUE_FROM_STRUCT(yx);
        CAIRO_VALUE_FROM_STRUCT(xy);
        CAIRO_VALUE_FROM_STRUCT(yy);
        CAIRO_VALUE_FROM_STRUCT(x0);
        CAIRO_VALUE_FROM_STRUCT(y0);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->read_property(object, member, type, cache_slot, rv);

        return retval;
    } while(0);

    retval = rv;
    ZVAL_DOUBLE(retval, value);

    return retval;
}
/* }}} */

/* {{{ */
static zval *cairo_matrix_object_write_property(zend_object *object, zend_string *member, zval *value, void **cache_slot)
{
    cairo_matrix_object *matrix_object = cairo_matrix_fetch_object(object);
    zval *retval = NULL;

    if (!matrix_object) {
        return retval;
    }

    do {
        CAIRO_VALUE_TO_STRUCT(xx);
        CAIRO_VALUE_TO_STRUCT(yx);
        CAIRO_VALUE_TO_STRUCT(xy);
        CAIRO_VALUE_TO_STRUCT(yy);
        CAIRO_VALUE_TO_STRUCT(x0);
        CAIRO_VALUE_TO_STRUCT(y0);

        /* not a struct member */
        retval = (zend_get_std_object_handlers())->write_property(object, member, value, cache_slot);
    } while(0);

    return retval;
}
/* }}} */

/* {{{ */
static HashTable *cairo_matrix_object_get_properties(zend_object *object)
{
    HashTable *props;
    // used in CAIRO_ADD_STRUCT_VALUE below
    zval tmp;
    cairo_matrix_object *matrix_object = cairo_matrix_fetch_object(object);

    props = zend_std_get_properties(object);

    if (!matrix_object->matrix) {
        return props;
    }

    /* Don't add struct values when destructor calls get_properties handler */
    if (props && GC_REFCOUNT(props) > 0) {
        CAIRO_ADD_STRUCT_VALUE(xx);
        CAIRO_ADD_STRUCT_VALUE(yx);
        CAIRO_ADD_STRUCT_VALUE(xy);
        CAIRO_ADD_STRUCT_VALUE(yy);
        CAIRO_ADD_STRUCT_VALUE(x0);
        CAIRO_ADD_STRUCT_VALUE(y0);
    }

    return props;
}
/* }}} */

/* ----------------------------------------------------------------
    Cairo\Matrix Definition and registration
------------------------------------------------------------------*/

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(cairo_matrix)
{
    memcpy(
        &cairo_matrix_object_handlers,
        zend_get_std_object_handlers(),
        sizeof(zend_object_handlers)
    );

    cairo_matrix_object_handlers.offset = XtOffsetOf(cairo_matrix_object, std);
    cairo_matrix_object_handlers.free_obj = cairo_matrix_free_obj;
    cairo_matrix_object_handlers.clone_obj = cairo_matrix_clone_obj;
    cairo_matrix_object_handlers.read_property = cairo_matrix_object_read_property;
    cairo_matrix_object_handlers.write_property = cairo_matrix_object_write_property;
    cairo_matrix_object_handlers.get_property_ptr_ptr = NULL;
    cairo_matrix_object_handlers.get_properties = cairo_matrix_object_get_properties;

    ce_cairo_matrix = register_class_Cairo_Matrix();
    ce_cairo_matrix->create_object = cairo_matrix_create_object;

    return SUCCESS;
}
/* }}} */
