--TEST--
Cairo\Surface\Image->getHeight() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump($surface->getHeight());

/* Wrong number args */
try {
    $surface->getHeight('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
int(50)
Cairo\Surface\Image::getHeight() expects exactly 0 arguments, 1 given
