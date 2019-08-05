/* demo1 extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_demo1.h"
#include "zend_exceptions.h"


/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif
/*以下函数见 zend_API.h**/
PHP_FUNCTION(hello_bool)
{
	ZVAL_BOOL(return_value,1);
}


PHP_FUNCTION(hello_long)
{
	RETVAL_LONG(12);
	return;
}

PHP_FUNCTION(hello_double)
{
	RETURN_DOUBLE(1.2);
}

PHP_FUNCTION(hello_string)
{
	RETURN_STRING("hello,json");
}

PHP_FUNCTION(hello_null)
{
	RETURN_NULL();
}

PHP_FUNCTION(hello_arr)
{
	zval arr;
	array_init(&arr);
	add_next_index_long(&arr,11);
	add_next_index_null(&arr);
	add_next_index_string(&arr,"hello");
	add_next_index_bool(&arr,0);
	add_index_double(&arr,4,4);
	add_assoc_string(&arr,"lgid","11564");
	array_init(return_value);
	add_assoc_zval(return_value,"data",&arr);	
}


PHP_FUNCTION(hello_exception)/**抛出异常,异常类型见zend_exceptions.h，用户空间可以捕获**/
{
	zend_throw_exception_ex(zend_ce_error_exception, 5, "Class not exists");//zend_ce_error_exception在zend_exceptions.h中已定义

}

PHP_FUNCTION(hello_name)
{
	char *var = "Json";
	size_t var_len = sizeof(var) - 1;
	zend_string *str;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	str = strpprintf(0, "Hello %s", var);

	RETURN_STR(str);
}


/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(demo1)
{
#if defined(ZTS) && defined(COMPILE_DL_DEMO1)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(demo1)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "demo1 support", "enabled");
	php_info_print_table_end();
}


PHP_MINIT_FUNCTION(demo1)
{
	/**注册常量 zend_constants.h**/
	REGISTER_NULL_CONSTANT("CONSTANT_NULL",CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("CONSTANT_LONG",322,CONST_CS | CONST_PERSISTENT);
	REGISTER_BOOL_CONSTANT("CONSTANT_BOOL",1,CONST_CS | CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("CONSTANT_DOUBLE",1,CONST_CS | CONST_PERSISTENT);
	REGISTER_STRING_CONSTANT("CONSTANT_STRING","hello,everyone",CONST_CS | CONST_PERSISTENT);
	return SUCCESS;
}
/* }}} */


ZEND_BEGIN_ARG_INFO(arginfo_demo1_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ demo1_functions[]
 */
static const zend_function_entry demo1_functions[] = {
	PHP_FE(hello_null,		NULL)
	PHP_FE(hello_string,		NULL)
	PHP_FE(hello_double,		NULL)
	PHP_FE(hello_long,		NULL)
	PHP_FE(hello_bool,		NULL)
	PHP_FE(hello_arr,		NULL)
	PHP_FE(hello_name,		NULL)
	PHP_FE(hello_exception,		NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ demo1_module_entry
 */
zend_module_entry demo1_module_entry = {
	STANDARD_MODULE_HEADER,
	"demo1",					/* Extension name */
	demo1_functions,			/* zend_function_entry */
	PHP_MINIT(demo1),							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(demo1),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(demo1),			/* PHP_MINFO - Module info */
	PHP_DEMO1_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_DEMO1
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(demo1)
#endif

