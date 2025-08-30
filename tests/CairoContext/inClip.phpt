--TEST--
Cairo\Context->inClip() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);
$context->rectangle(10, 10, 30, 30);
$context->clip();
var_dump($context->getClipExtents());

assert($context->inClip(10  , 10  ) === true);
assert($context->inClip(10  , 39.9) === true);
assert($context->inClip(39.9, 39.9) === true);
assert($context->inClip(39.9, 10  ) === true);

assert($context->inClip( 9.9,  9.9) === false);
assert($context->inClip( 9.9, 25  ) === false);
assert($context->inClip( 9.9, 40  ) === false);
assert($context->inClip(25  , 40  ) === false);
assert($context->inClip(40  , 40  ) === false);
assert($context->inClip(40  , 25  ) === false);
assert($context->inClip(40  ,  9.9) === false);
assert($context->inClip(25  ,  9.9) === false);

try {
    $context->inClip();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->inClip(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->inClip(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->inClip(array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
try {
    $context->inClip(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
array(4) {
  [0]=>
  float(10)
  [1]=>
  float(10)
  [2]=>
  float(40)
  [3]=>
  float(40)
}
Cairo\Context::inClip() expects exactly 2 arguments, 0 given
Cairo\Context::inClip() expects exactly 2 arguments, 1 given
Cairo\Context::inClip() expects exactly 2 arguments, 3 given
Cairo\Context::inClip(): Argument #1 ($x) must be of type float, array given
Cairo\Context::inClip(): Argument #2 ($y) must be of type float, array given