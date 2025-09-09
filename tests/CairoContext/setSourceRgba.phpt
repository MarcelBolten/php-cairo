--TEST--
Cairo\Context->setSourceRgba() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$context->setSourceRgba(0.1, 0.1, 0.1);
var_dump($context->getPattern()->getRgba());
$context->setSourceRgba(0.3, 0.3, 0.3, null);
var_dump($context->getPattern()->getRgba());
$context->setSourceRgba(0.5, 0.5, 0.5, 0.5);
var_dump($context->getPattern()->getRgba());

/* Wrong number of args: 0 */
try {
    $context->setSourceRgba();
}
catch(ArgumentCountError $ex) {
    echo $ex->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba(1);
}
catch(ArgumentCountError $ex) {
    echo $ex->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba(1, 1);
}
catch(ArgumentCountError $ex) {
    echo $ex->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba(1, 1, 1, 1, 1);
}
catch(ArgumentCountError $ex) {
    echo $ex->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba("1", "1", "1", "0");
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba("1.0", "1.0", "1.0", "0.0");
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba(array(), 1, 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba(1, array(), 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba(1, 1, array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->setSourceRgba(1, 1, 1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
array(4) {
  ["red"]=>
  float(0.1)
  ["green"]=>
  float(0.1)
  ["blue"]=>
  float(0.1)
  ["alpha"]=>
  float(1)
}
array(4) {
  ["red"]=>
  float(0.3)
  ["green"]=>
  float(0.3)
  ["blue"]=>
  float(0.3)
  ["alpha"]=>
  float(1)
}
array(4) {
  ["red"]=>
  float(0.5)
  ["green"]=>
  float(0.5)
  ["blue"]=>
  float(0.5)
  ["alpha"]=>
  float(0.5)
}
Cairo\Context::setSourceRgba() expects at least 3 arguments, 0 given
Cairo\Context::setSourceRgba() expects at least 3 arguments, 1 given
Cairo\Context::setSourceRgba() expects at least 3 arguments, 2 given
Cairo\Context::setSourceRgba() expects at most 4 arguments, 5 given
Cairo\Context::setSourceRgba(): Argument #1 ($red) must be of type float, array given
Cairo\Context::setSourceRgba(): Argument #2 ($green) must be of type float, array given
Cairo\Context::setSourceRgba(): Argument #3 ($blue) must be of type float, array given
Cairo\Context::setSourceRgba(): Argument #4 ($alpha) must be of type ?float, array given
