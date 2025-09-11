--TEST--
Cairo\Region->xor() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$region = new Cairo\Region();
var_dump($region);
var_dump( $region->getExtents() );

$rectangle = new Cairo\Rectangle(10,10,100,100);
$region2 = new Cairo\Region($rectangle);
var_dump( $region2->getNumRectangles() );
var_dump( $region->xor($region2) == \CAIRO\STATUS::Success );
var_dump( $region->getExtents() );

$rectangle2 = new Cairo\Rectangle(80,10,40,110);
$region3 = new Cairo\Region($rectangle2);
var_dump( $region3->getNumRectangles() );
var_dump( $region2->getExtents() );
var_dump( $region2->xor($region3) == \CAIRO\STATUS::Success );
var_dump( $region2->getExtents() );
var_dump( $region2->getNumRectangles() );

/* Wrong number args */
try {
    $region->xor(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $region->xor($region2, 'foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Region)#%d (0) {
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
int(1)
bool(true)
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(10)
  ["y"]=>
  float(10)
  ["width"]=>
  float(100)
  ["height"]=>
  float(100)
}
int(1)
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(10)
  ["y"]=>
  float(10)
  ["width"]=>
  float(100)
  ["height"]=>
  float(100)
}
bool(true)
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(10)
  ["y"]=>
  float(10)
  ["width"]=>
  float(110)
  ["height"]=>
  float(110)
}
int(3)
Cairo\Region::xor(): Argument #1 ($region) must be of type Cairo\Region, int given
Cairo\Region::xor() expects exactly 1 argument, 2 given
