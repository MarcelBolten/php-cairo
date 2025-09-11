--TEST--
CairoWin32Fontface::__construct() function
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!class_exists('\Cairo\FontFace\Win32'))
	die('skip - Cairo\FontFace\Win32 class not available');
--FILE--
<?php
$f_opts = array (
    'lfWeight' => Cairo\FontFace\Win32\FontWeight::BOLD->value,
    'lfFaceName' => 'Impact'
);

// Test with no params
$f = new Cairo\FontFace\Win32();
var_dump($f);

// Test with all params
$f = new Cairo\FontFace\Win32($f_opts);
var_dump($f);

// Test with incorrect param
try {
	$f = new Cairo\FontFace\Win32('not an array');
} catch (TypeError $e) {
	echo $e->getMessage(), PHP_EOL;
}

// Test with too many params
try {
	$f = new Cairo\FontFace\Win32($f_opts, '2nd param');
} catch (ArgumentCountError $e) {
	echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Win32)#%d (0) {
}
object(Cairo\FontFace\Win32)#%d (0) {
}
Cairo\FontFace\Win32::__construct() expects parameter 1 to be array, string given
Cairo\FontFace\Win32::__construct() expects at least 1 argument, 2 given
