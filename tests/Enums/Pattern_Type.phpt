--TEST--
Cairo\Pattern\Type class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Type;

$enum = Type::cases();
var_dump($enum);
--EXPECTF--
array(6) {
  [0]=>
  enum(Cairo\Pattern\Type::SOLID)
  [1]=>
  enum(Cairo\Pattern\Type::SURFACE)
  [2]=>
  enum(Cairo\Pattern\Type::LINEAR)
  [3]=>
  enum(Cairo\Pattern\Type::RADIAL)
  [4]=>
  enum(Cairo\Pattern\Type::MESH)
  [5]=>
  enum(Cairo\Pattern\Type::RASTER_SOURCE)
}
