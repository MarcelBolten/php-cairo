--TEST--
Cairo\Pattern->setFilter() method [using Surface]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$pattern = new Cairo\Pattern\Surface($surface);
var_dump($pattern);

$pattern->setFilter(Cairo\Filter::NEAREST);
$filter = $pattern->getFilter();
var_dump($filter);
var_dump($filter == Cairo\Filter::NEAREST);

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
    $pattern->setFilter([]);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
try {
    $pattern->setFilter($surface);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Pattern\Surface)#%d (0) {
}
enum(Cairo\Filter::NEAREST)
bool(true)
Cairo\Pattern::setFilter() expects exactly 1 argument, 0 given
Cairo\Pattern::setFilter() expects exactly 1 argument, 2 given
Cairo\Pattern::setFilter(): Argument #1 ($filter) must be of type Cairo\Filter, array given
Cairo\Pattern::setFilter(): Argument #1 ($filter) must be of type Cairo\Filter, Cairo\Surface\Image given
