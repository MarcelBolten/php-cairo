--TEST--
Cairo\Surface\Image->getWidth() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump($surface->getWidth());

/* Wrong number args */
try {
    $surface->getWidth('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
int(50)
Cairo\Surface\Image::getWidth() expects exactly 0 arguments, 1 given
