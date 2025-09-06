--TEST--
Cairo\Surface->getDeviceScale() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
if (!method_exists('Cairo\Surface', 'getDeviceScale'))
    die('skip - Cairo\Surface->getDeviceScale not available');
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump($surface->getDeviceScale());
$surface->setDeviceScale(10, 10);
var_dump($surface->getDeviceScale());

/* Wrong number args */
try {
    $surface->getDeviceScale('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
array(2) {
  ["x"]=>
  float(1)
  ["y"]=>
  float(1)
}
array(2) {
  ["x"]=>
  float(10)
  ["y"]=>
  float(10)
}
Cairo\Surface::getDeviceScale() expects exactly 0 arguments, 1 given
