--TEST--
Cairo\FontFace->getType() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
include(dirname(__FILE__) . '/create_toyfont.inc');
var_dump($fontface);

var_dump($fontface->getType());

try {
    $fontface->getType('foo');
} catch (TypeError $e) {
    echo $e->getMessage();
}
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
enum(Cairo\FontType::Toy)
Cairo\FontFace::getType() expects exactly 0 arguments, 1 given
