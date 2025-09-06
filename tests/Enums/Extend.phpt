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
  enum(Cairo\Extend::None)
  [1]=>
  enum(Cairo\Extend::Repeat)
  [2]=>
  enum(Cairo\Extend::Reflect)
  [3]=>
  enum(Cairo\Extend::Pad)
}
