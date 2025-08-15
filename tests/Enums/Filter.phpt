--TEST--
Cairo\Filter class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\Filter;

$enum = Filter::cases();
var_dump($enum);
--EXPECTF--
array(6) {
  [0]=>
  enum(Cairo\Filter::FAST)
  [1]=>
  enum(Cairo\Filter::GOOD)
  [2]=>
  enum(Cairo\Filter::BEST)
  [3]=>
  enum(Cairo\Filter::NEAREST)
  [4]=>
  enum(Cairo\Filter::BILINEAR)
  [5]=>
  enum(Cairo\Filter::GAUSSIAN)
}
