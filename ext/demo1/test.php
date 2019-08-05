<?php
var_dump(hello_null(),hello_bool(),hello_long(),hello_string(),hello_arr(),hello_double(),"\r\n");

var_dump("<pre>",CONSTANT_NULL,CONSTANT_STRING,CONSTANT_LONG,CONSTANT_BOOL,CONSTANT_DOUBLE);

var_dump(hello_name(),hello_name("杰哥"));

try {
var_dump("Exception:",hello_exception()); 
} catch(Exception $e) {
}
?>
