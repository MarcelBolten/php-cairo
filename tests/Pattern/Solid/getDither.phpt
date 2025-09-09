--TEST--
Cairo\Pattern->getDither() method [using Solid]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Solid;

$pattern = new Solid(1, 1, 1);
$dither = $pattern->getDither();
var_dump($dither);

/* Total number of args needed = 0 */
try {
    $pattern->getDither(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECT--
enum(Cairo\Dither::Default)
Cairo\Pattern::getDither() expects exactly 0 arguments, 1 given
