--TEST--
CairoFtFontFace::getSynthesize()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!class_exists('\Cairo\FontFace\Ft'))
    die('skip - Cairo\FontFace\Ft not available');
--FILE--
<?php
$fontFile = dirname(__FILE__) . "/Vera.ttf";

$c = new Cairo\FontFace\Ft($fontFile);
var_dump($c);

var_dump($c->getSynthesize());

try {
    $c->getSynthesize('bad param');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Ft)#1 (0) {
}
int(0)
Cairo\FontFace\Ft::getSynthesize() expects exactly 0 arguments, 1 given
