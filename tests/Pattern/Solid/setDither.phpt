--TEST--
Cairo\Pattern->setDither() method [using Solid]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Solid;

$pattern = new Solid(1, 1, 1);

$pattern->setDither(Cairo\Dither::Good);
$dither = $pattern->getDither();
var_dump($dither == Cairo\Dither::Good);

/* Total number of args needed = 1 */
try {
    $pattern->setDither();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
try {
    $pattern->setDither(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* arg must be int or castable to int */
try {
    $pattern->setDither(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
bool(true)
Cairo\Pattern::setDither() expects exactly 1 argument, 0 given
Cairo\Pattern::setDither() expects exactly 1 argument, 2 given
Cairo\Pattern::setDither(): Argument #1 ($dither) must be of type Cairo\Dither, array given
