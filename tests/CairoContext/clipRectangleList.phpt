--TEST--
Cairo\Context->clipRectangleList() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

var_dump($context->clipRectangleList());

try {
    $context->clipRectangleList('foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage();
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
array(1) {
  [0]=>
  array(4) {
    ["x"]=>
    float(0)
    ["y"]=>
    float(0)
    ["width"]=>
    float(50)
    ["height"]=>
    float(50)
  }
}
Cairo\Context::clipRectangleList() expects exactly 0 arguments, 1 given
