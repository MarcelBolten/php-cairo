--TEST--
Cairo\Context->getPathExtents() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!method_exists('Cairo\Context', 'getPathExtents'))
    die('skip - Cairo\Context->getPathExtents extension not available');
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

var_dump($context->getPathExtents());

/* Wrong number args 10*/
try {
    $context->getPathExtents('foobar');
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
Cairo\Context::getPathExtents() expects exactly 0 arguments, 1 given
