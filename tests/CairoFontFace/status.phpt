--TEST--
Cairo\FontFace->status() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
include(dirname(__FILE__) . '/create_toyfont.inc');
var_dump($fontface);

$status = $fontface->getStatus();
var_dump($status);

var_dump($status == Cairo\Status::Success);

/* Wrong number args */
try {
    $fontface->getStatus('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
enum(Cairo\Status::Success)
bool(true)
Cairo\FontFace::getStatus() expects exactly 0 arguments, 1 given
