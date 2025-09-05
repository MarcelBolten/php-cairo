--TEST--
Cairo\ColorMode enum
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
use Cairo\ColorMode;

var_dump(ColorMode::cases());
--EXPECT--
array(3) {
  [0]=>
  enum(Cairo\ColorMode::Default)
  [1]=>
  enum(Cairo\ColorMode::NoColor)
  [2]=>
  enum(Cairo\ColorMode::Color)
}
