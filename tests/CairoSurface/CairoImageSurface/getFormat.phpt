--TEST--
Cairo\Surface\Image->getFormat() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump($surface->getFormat());

/* Wrong number args */
try {
    $surface->getFormat('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
enum(Cairo\Surface\ImageFormat::ARGB32)
Cairo\Surface\Image::getFormat() expects exactly 0 arguments, 1 given
