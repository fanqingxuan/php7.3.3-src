--TEST--
Check if demo1 is loaded
--SKIPIF--
<?php
if (!extension_loaded('demo1')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "demo1" is available';
?>
--EXPECT--
The extension "demo1" is available
