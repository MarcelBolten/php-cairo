--TEST--
Cairo\Surface->getContent() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

var_dump($surface->getContent());

/* Wrong number args */
try {
    $surface->getContent('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
enum(Cairo\Surface\Content::ColorAlpha)
Cairo\Surface::getContent() expects exactly 0 arguments, 1 given
