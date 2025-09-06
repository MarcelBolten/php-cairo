--TEST--
Cairo\Surface->getFallbackResolution() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
if (!method_exists('Cairo\Surface', 'getFallbackResolution'))
    die('skip - Cairo\Surface->getFallbackResolution not available');
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump($surface->getFallbackResolution());

/* Wrong number args */
try {
    $surface->getFallbackResolution('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
array(2) {
  ["x"]=>
  float(%d)
  ["y"]=>
  float(%d)
}
Cairo\Surface::getFallbackResolution() expects exactly 0 arguments, 1 given
