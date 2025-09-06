--TEST--
Cairo\Context->copyPage() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$context->copyPage();
try {
    $context->copyPage('foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage();
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
Cairo\Context::copyPage() expects exactly 0 arguments, 1 given
