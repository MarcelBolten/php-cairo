--TEST--
Cairo\Pattern->setFilter() method [using Solid]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Solid;

$pattern = new Solid(1, 1, 1);

$pattern->setFilter(Cairo\Filter::Good);
$filter = $pattern->getFilter();
var_dump($filter == Cairo\Filter::Good);

/* Total number of args needed = 1 */
try {
    $pattern->setFilter();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
try {
    $pattern->setFilter(1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* arg must be int or castable to int */
try {
    $pattern->setFilter(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
bool(true)
Cairo\Pattern::setFilter() expects exactly 1 argument, 0 given
Cairo\Pattern::setFilter() expects exactly 1 argument, 2 given
Cairo\Pattern::setFilter(): Argument #1 ($filter) must be of type Cairo\Filter, array given
