--TEST--
Cairo\Context->getCurrentPoint() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

var_dump($context->getCurrentPoint());

/* Wrong number args - expects 0 */
try {
    $context->getCurrentPoint('foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
array(2) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
}
Cairo\Context::getCurrentPoint() expects exactly 0 arguments, 1 given
