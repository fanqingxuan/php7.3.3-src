--TEST--
demo1_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('demo1')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = demo1_test1();

var_dump($ret);
?>
--EXPECT--
The extension demo1 is loaded and working!
NULL
