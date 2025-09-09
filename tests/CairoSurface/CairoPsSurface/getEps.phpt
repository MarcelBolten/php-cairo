--TEST--
Cairo\Surface\Ps->getEps() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
if (!method_exists('\Cairo\Surface\Ps', 'getEps'))
    die('skip - Cairo\Surface\Ps->getEps not available');
--FILE--
<?php
$surface = new Cairo\Surface\Ps(NULL, 50, 50);
var_dump($surface);

var_dump($surface->getEps());

/* Wrong number args */
try {
    $surface->getEps('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Ps)#%d (0) {
}
bool(false)
Cairo\Surface\Ps::getEps() expects exactly 0 %s, 1 given
