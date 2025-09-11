--TEST--
CairoWin32Fontface::__construct() function
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!class_exists('\Cairo\FontFace\Win32'))
	die('skip - Cairo\FontFace\Win32 class not available');
--FILE--
<?php
var_dump(Cairo\FontFace\Win32\FontWeight::cases());
var_dump(Cairo\FontFace\Win32\FontCharSet::cases());
var_dump(Cairo\FontFace\Win32\FontOutputPrecision::cases());
var_dump(Cairo\FontFace\Win32\FontClipPrecision::cases());
var_dump(Cairo\FontFace\Win32\FontQuality::cases());
var_dump(Cairo\FontFace\Win32\FontPitch::cases());
var_dump(Cairo\FontFace\Win32\FontFamily::cases());
--EXPECTF--
// TODO: copy output from actual run
