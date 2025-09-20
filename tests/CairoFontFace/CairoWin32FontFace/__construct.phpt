--TEST--
Cairo\FontFace\Win32::__construct() function
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!class_exists('\Cairo\FontFace\Win32'))
	die('skip - Cairo\FontFace\Win32 class not available');
--FILE--
<?php
$f_opts = array(
    'lfFaceName' => 'Impact',
	// lfHeight=0: The font mapper uses a default height value when it searches for a match.
	'lfHeight' => 0,
	// lfWidth=0: The aspect ratio of the device is matched against the digitization aspect ratio of the available fonts to find the closest match, determined by the absolute value of the difference
    'lfWidth' => 0,
    'lfEscapement' => 0,
    'lfOrientation' => 0,
    'lfWeight' => Cairo\FontFace\Win32\FontWeight::Bold->value,
    'lfItalic' => false,
    'lfUnderline' => false,
    'lfStrikeOut' => false,
    'lfCharSet' => Cairo\FontFace\Win32\FontCharSet::Default->value,
    'lfOutPrecision' => Cairo\FontFace\Win32\FontOutputPrecision::Default->value,
    'lfClipPrecision' => Cairo\FontFace\Win32\FontClipPrecision::Default->value,
    'lfQuality' => Cairo\FontFace\Win32\FontQuality::Default->value,
    'lfPitchAndFamily' => Cairo\FontFace\Win32\FontPitch::Default->value | Cairo\FontFace\Win32\FontFamily::Dontcare->value
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
Cairo\FontFace\Win32::__construct(): Argument #1 ($font_options) must be of type ?array, string given
Cairo\FontFace\Win32::__construct() expects at most 1 argument, 2 given
