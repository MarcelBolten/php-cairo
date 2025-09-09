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
array(5) {
  [0]=>
  enum(Cairo\Pattern\Type::Solid)
  [1]=>
  enum(Cairo\Pattern\Type::Surface)
  [2]=>
  enum(Cairo\Pattern\Type::Linear)
  [3]=>
  enum(Cairo\Pattern\Type::Radial)
  [4]=>
  enum(Cairo\Pattern\Type::Mesh)
}
