--TEST--
Cairo\Region->subtract() method
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
var_dump( $region->subtract($region2) == \CAIRO\STATUS::Success );
var_dump( $region->getExtents() );

$rectangle2 = new Cairo\Rectangle(80,10,40,110);
$region3 = new Cairo\Region($rectangle2);
var_dump( $region3->getNumRectangles() );
var_dump( $region2->getExtents() );
var_dump( $region2->subtract($region3) == \CAIRO\STATUS::Success );
var_dump( $region2->getExtents() );
var_dump( $region2->getNumRectangles() );

/* Wrong number args */
try {
    $region->subtract(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $region->subtract($region2, 'foo');
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
  float(0)
  ["y"]=>
  float(0)
  ["width"]=>
  float(0)
  ["height"]=>
  float(0)
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
  float(70)
  ["height"]=>
  float(100)
}
int(1)
Cairo\Region::subtract(): Argument #1 ($region) must be of type Cairo\Region, int given
Cairo\Region::subtract() expects exactly 1 argument, 2 given
