--TEST--
new Cairo\Surface\Recording [getExtents() method ]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Recording(\Cairo\Surface\Content::ColorAlpha);
var_dump($surface);
var_dump($surface->getExtents());

$surface2 = new Cairo\Surface\Recording(
  \Cairo\Surface\Content::ColorAlpha,
  new Cairo\Rectangle(0, 0, 400, 400)
);
var_dump($surface2->getExtents());

/* Wrong number args - 1 */
try {
    $surface2->getExtents(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Recording)#%d (0) {
}
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
  ["width"]=>
  float(0)
  ["height"]=>
  float(0)
}
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
  ["width"]=>
  float(400)
  ["height"]=>
  float(400)
}
Cairo\Surface\Recording::getExtents() expects exactly 0 arguments, 1 given
