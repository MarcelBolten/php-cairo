/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 08b17ccf0a73de0bf9be15a73042d77b55607e52 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_Cairo_Surface_Recording___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, content, Cairo\\Surface\\Content, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, extents, IS_ARRAY, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_Cairo_Surface_Recording_inkExtents, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_TYPE_MASK_EX(arginfo_class_Cairo_Surface_Recording_getExtents, 0, 0, Cairo\\Rectangle, MAY_BE_FALSE)
ZEND_END_ARG_INFO()

ZEND_METHOD(Cairo_Surface_Recording, __construct);
ZEND_METHOD(Cairo_Surface_Recording, inkExtents);
ZEND_METHOD(Cairo_Surface_Recording, getExtents);

static const zend_function_entry class_Cairo_Surface_Recording_methods[] = {
	ZEND_ME(Cairo_Surface_Recording, __construct, arginfo_class_Cairo_Surface_Recording___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Recording, inkExtents, arginfo_class_Cairo_Surface_Recording_inkExtents, ZEND_ACC_PUBLIC)
	ZEND_ME(Cairo_Surface_Recording, getExtents, arginfo_class_Cairo_Surface_Recording_getExtents, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_Cairo_Surface_Recording(zend_class_entry *class_entry_Cairo_Surface)
{
	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "Cairo\\Surface", "Recording", class_Cairo_Surface_Recording_methods);
#if (PHP_VERSION_ID >= 80400)
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_Cairo_Surface, 0);
#else
	class_entry = zend_register_internal_class_ex(&ce, class_entry_Cairo_Surface);
#endif

	return class_entry;
}
