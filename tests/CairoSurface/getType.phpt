--TEST--
Cairo\Surface->getType() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump($surface->getType());

/* Wrong number args */
try {
    $surface->getType('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
enum(Cairo\Surface\Type::Image)
Cairo\Surface::getType() expects exactly 0 arguments, 1 given
