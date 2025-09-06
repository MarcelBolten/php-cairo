--TEST--
Cairo\Context->closePath() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$context->closePath();

/* Wrong number args - expects 0 */
try {
    $context->closePath('foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
Cairo\Context::closePath() expects exactly 0 arguments, 1 given
