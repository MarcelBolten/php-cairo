--TEST--
Cairo\Context->getAntialias() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

var_dump($context->getAntialias());

/* Wrong number args */
try {
    $context->getAntialias('foobar');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
enum(Cairo\Antialias::Default)
Cairo\Context::getAntialias() expects exactly 0 arguments, 1 given
