--TEST--
CairoFtFontFace::setSynthesize()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!class_exists('\Cairo\FontFace\Ft'))
    die('skip - Cairo\FontFace\Ft not available');
--FILE--
<?php
use Cairo\FontFace\Ft;

$fontFile = dirname(__FILE__) . "/Vera.ttf";
$c = new Ft($fontFile);
var_dump($c);

$c->setSynthesize(Ft::SYNTHESIZE_BOLD);
var_dump($c->getSynthesize());

$c->setSynthesize(Ft::SYNTHESIZE_OBLIQUE);
var_dump($c->getSynthesize());

try {
    $c->setSynthesize();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $c->setSynthesize(FT::SYNTHESIZE_BOLD, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $c->setSynthesize(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Ft)#1 (0) {
}
int(1)
int(3)
Cairo\FontFace\Ft::setSynthesize() expects exactly 1 argument, 0 given
Cairo\FontFace\Ft::setSynthesize() expects exactly 1 argument, 2 given
Cairo\FontFace\Ft::setSynthesize(): Argument #1 ($synthFlags) must be of type int, array given
