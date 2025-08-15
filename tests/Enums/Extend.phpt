--TEST--
Cairo\Extend class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\Extend;

var_dump(Extend::cases());
--EXPECTF--
array(4) {
  [0]=>
  enum(Cairo\Extend::NONE)
  [1]=>
  enum(Cairo\Extend::REPEAT)
  [2]=>
  enum(Cairo\Extend::REFLECT)
  [3]=>
  enum(Cairo\Extend::PAD)
}
