--TEST--
Cairo\ColorMode enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
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
