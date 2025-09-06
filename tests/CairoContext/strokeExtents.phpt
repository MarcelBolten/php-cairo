--TEST--
Cairo\Context->strokeExtents() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

var_dump($context->strokeExtents());

/* Wrong number args */
try {
    $context->strokeExtents('foobar');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
array(4) {
  ["x1"]=>
  float(0)
  ["y1"]=>
  float(0)
  ["x2"]=>
  float(0)
  ["y2"]=>
  float(0)
}
Cairo\Context::strokeExtents() expects exactly 0 %s, 1 given
