/* demo1 extension for PHP */

#ifndef PHP_DEMO1_H
# define PHP_DEMO1_H

extern zend_module_entry demo1_module_entry;
# define phpext_demo1_ptr &demo1_module_entry

# define PHP_DEMO1_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_DEMO1)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_DEMO1_H */

