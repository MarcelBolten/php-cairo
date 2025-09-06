--TEST--
Cairo\Surface->markDirty() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$surface->markDirty();

/* Wrong number args */
try {
    $surface->markDirty('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
Cairo\Surface::markDirty() expects exactly 0 %s, 1 given
