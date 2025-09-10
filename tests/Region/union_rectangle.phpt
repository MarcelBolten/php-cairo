--TEST--
Cairo\Region->unionRectangle() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$region = new Cairo\Region();
var_dump($region);
var_dump($region->getNumRectangles());
var_dump($region->getExtents());

$rectangle1 = new Cairo\Rectangle(10,10,10,10);
var_dump($region->unionRectangle($rectangle1) == \CAIRO\STATUS::Success);
var_dump($region->getNumRectangles());
var_dump($region->getExtents());

$rectangle2 = new Cairo\Rectangle(10,10,20,20);
var_dump($region->unionRectangle($rectangle2) == \CAIRO\STATUS::Success);
var_dump($region->getNumRectangles());
var_dump($region->getExtents());

try {
    $region->unionRectangle(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args */
try {
    $region->unionRectangle($rectangle1, 'foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Region)#%d (0) {
}
int(0)
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
bool(true)
int(1)
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(10)
  ["y"]=>
  float(10)
  ["width"]=>
  float(10)
  ["height"]=>
  float(10)
}
bool(true)
int(1)
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(10)
  ["y"]=>
  float(10)
  ["width"]=>
  float(20)
  ["height"]=>
  float(20)
}
Cairo\Region::unionRectangle(): Argument #1 ($rectangle) must be of type Cairo\Rectangle, int given
Cairo\Region::unionRectangle() expects exactly 1 argument, 2 given
