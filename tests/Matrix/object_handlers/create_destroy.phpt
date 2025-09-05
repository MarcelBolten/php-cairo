--TEST--
Cairo\Matrix create/destroy handlers
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Matrix;

$matrix = new Matrix();
unset($matrix);

class neo extends Matrix{
    public float $xx = 8;
    public float $xy = 5;
}

$mr_andersen = new neo();
var_dump($mr_andersen);
--EXPECTF--
object(neo)#%d (6) {
  ["xx"]=>
  float(8)
  ["yx"]=>
  float(0)
  ["xy"]=>
  float(5)
  ["yy"]=>
  float(1)
  ["x0"]=>
  float(0)
  ["y0"]=>
  float(0)
}
