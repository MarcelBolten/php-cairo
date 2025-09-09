--TEST--
Cairo\Surface\Image->getData() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump(strlen($surface->getData()));

/* Wrong number args */
try {
    $surface->getData('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
int(10000)
Cairo\Surface\Image::getData() expects exactly 0 arguments, 1 given
