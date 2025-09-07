--TEST--
Cairo\Context->setHairline() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$context->setHairline(true);
var_dump($context->getHairline());

/* Wrong number args */
try {
    $context->setHairline();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->setHairline(true, false);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->setHairline(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
bool(true)
Cairo\Context::setHairline() expects exactly 1 argument, 0 given
Cairo\Context::setHairline() expects exactly 1 argument, 2 given
Cairo\Context::setHairline(): Argument #1 ($hairline) must be of type bool, array given