--TEST--
Cairo::available_surfaces() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
namespace Cairo;
$surfaces = Cairo::availableSurfaces();
var_dump(is_array($surfaces));
var_dump($surfaces[0]);

/* Wrong number args */
try {
    Cairo::availableSurfaces('foo');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
bool(true)
string(5) "IMAGE"
Cairo\Cairo::availableSurfaces() expects exactly 0 arguments, 1 given
