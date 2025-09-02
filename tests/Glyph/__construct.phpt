--TEST--
Cairo\Glyph->__construct()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\Glyph;
use TypeError as Exception;

$glyph = new Glyph(1, 3.1415, 2.7182);
var_dump($glyph);

/* Wrong number args - need 1, 2, or 3 */
try {
    new Glyph();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new Glyph(1, 1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 1 */
try {
    new Glyph(array(), 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 2 */
try {
    new Glyph(1, array(), 1);
} catch (Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 3 */
try {
    new Glyph(1, 1, array());
} catch (Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Glyph)#1 (3) {
  ["index"]=>
  int(1)
  ["x"]=>
  float(3.1415)
  ["y"]=>
  float(2.7182)
}
Cairo\Glyph::__construct() expects at least 1 argument, 0 given
Cairo\Glyph::__construct() expects at most 3 arguments, 4 given
Cairo\Glyph::__construct(): Argument #1 ($index) must be of type int, array given
Cairo\Glyph::__construct(): Argument #2 ($x) must be of type float, array given
Cairo\Glyph::__construct(): Argument #3 ($y) must be of type float, array given
