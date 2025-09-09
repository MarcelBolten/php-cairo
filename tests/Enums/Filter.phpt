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
  enum(Cairo\Filter::Fast)
  [1]=>
  enum(Cairo\Filter::Good)
  [2]=>
  enum(Cairo\Filter::Best)
  [3]=>
  enum(Cairo\Filter::Nearest)
  [4]=>
  enum(Cairo\Filter::Bilinear)
  [5]=>
  enum(Cairo\Filter::Gaussian)
}
