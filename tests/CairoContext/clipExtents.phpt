--TEST--
Cairo\Context->getClipExtents() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

var_dump($context->getClipExtents());
try {
    $context->getClipExtents('foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage();
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
  float(50)
  ["y2"]=>
  float(50)
}
Cairo\Context::getClipExtents() expects exactly 0 arguments, 1 given
