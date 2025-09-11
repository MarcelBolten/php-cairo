--TEST--
Cairo\Rectangle create/destroy handlers
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Rectangle;

$rect = new Rectangle();
unset($rect);

class neo extends Rectangle{
    public float $x = 1;
    public float $y = 2;
}

$mr_andersen = new neo();
var_dump($mr_andersen);
--EXPECTF--
object(neo)#%d (4) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(2)
  ["width"]=>
  float(0)
  ["height"]=>
  float(0)
}
