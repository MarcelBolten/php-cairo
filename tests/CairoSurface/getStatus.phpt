--TEST--
Cairo\Surface->getStatus() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$status = $surface->getStatus();

var_dump($status);
var_dump($status == \Cairo\Status::Success);

/* Wrong number args */
try {
    $surface->getStatus('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
enum(Cairo\Status::Success)
bool(true)
Cairo\Surface::getStatus() expects exactly 0 arguments, 1 given
