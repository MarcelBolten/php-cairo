--TEST--
Cairo\Region->intersect() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$region = new Cairo\Region();
var_dump($region);
var_dump( $region->getExtents() );

$rectangle = new Cairo\Rectangle(1,1,100,100);
$region2 = new Cairo\Region($rectangle);
var_dump( $region2->getNumRectangles() );
$region->intersect($region2);
var_dump( $region->getExtents() );

$rectangle2 = new Cairo\Rectangle(20,20,100,100);
$region3 = new Cairo\Region($rectangle2);
var_dump( $region3->getNumRectangles() );
var_dump( $region2->getExtents() );
$region2->intersect($region3);
var_dump( $region2->getExtents() );
var_dump( $region2->getNumRectangles() );

/* Wrong number args */
try {
    $region->intersect(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $region->intersect($region2, 'foo');
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
  float(1)
  ["y"]=>
  float(1)
  ["width"]=>
  float(100)
  ["height"]=>
  float(100)
}
object(Cairo\Rectangle)#%d (4) {
  ["x"]=>
  float(20)
  ["y"]=>
  float(20)
  ["width"]=>
  float(81)
  ["height"]=>
  float(81)
}
int(1)
Cairo\Region::intersect(): Argument #1 ($region) must be of type Cairo\Region, int given
Cairo\Region::intersect() expects exactly 1 argument, 2 given
