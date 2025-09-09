--TEST--
new Cairo\Surface\Recording [inkExtents() method ]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Recording(\Cairo\Surface\Content::ColorAlpha);
var_dump($surface);
var_dump($surface->inkExtents());

$extents = ['x' => 0, 'y' => 0, 'width' => 400, 'height' => 400];
$surface2 = new Cairo\Surface\Recording(\Cairo\Surface\Content::ColorAlpha, $extents);
var_dump($surface2->inkExtents());

/* Wrong number args - 1 */
try {
    $surface2->inkExtents(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Recording)#%d (0) {
}
array(4) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
  ["width"]=>
  float(0)
  ["height"]=>
  float(0)
}
array(4) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
  ["width"]=>
  float(0)
  ["height"]=>
  float(0)
}
Cairo\Surface\Recording::inkExtents() expects exactly 0 arguments, 1 given
