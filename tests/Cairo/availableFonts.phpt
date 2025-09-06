--TEST--
Cairo::availableFonts() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
namespace Cairo;
$fonts = Cairo::availableFonts();
var_dump(is_array($fonts));
var_dump($fonts[0]);

/* Wrong number args */
try {
    Cairo::availableFonts('foo');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
bool(true)
string(%d) %s
Cairo\Cairo::availableFonts() expects exactly 0 arguments, 1 given
