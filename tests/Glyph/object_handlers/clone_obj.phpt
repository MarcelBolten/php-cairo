--TEST--
Cairo\Glyph clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Glyph;

$glyph = new Glyph(1, 1, 1);
$copy = clone $glyph;
$copy->index = 9;

var_dump($glyph);
var_dump($copy);
--EXPECTF--
object(Cairo\Glyph)#%d (3) {
  ["index"]=>
  int(1)
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
object(Cairo\Glyph)#%d (3) {
  ["index"]=>
  int(9)
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}