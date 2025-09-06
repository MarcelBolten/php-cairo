--TEST--
Cairo\Pattern\Surface->getFilter()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$pattern = new Cairo\Pattern\Surface($surface);
var_dump($pattern);

$pattern->setFilter(Cairo\Filter::Good);
$filter = $pattern->getFilter();
var_dump($filter);
var_dump($filter == Cairo\Filter::Good);

/* Total number of args needed = 0 */
try {
    $pattern->getFilter(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Pattern\Surface)#%d (0) {
}
enum(Cairo\Filter::Good)
bool(true)
Cairo\Pattern::getFilter() expects exactly 0 arguments, 1 given
