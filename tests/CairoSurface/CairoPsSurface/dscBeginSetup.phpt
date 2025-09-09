--TEST--
Cairo\Surface\Ps->dscBeginSetup() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Ps(NULL, 50, 50);
var_dump($surface);

$surface->dscBeginSetup();

/* Wrong number args */
try {
    $surface->dscBeginSetup('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Ps)#%d (0) {
}
Cairo\Surface\Ps::dscBeginSetup() expects exactly 0 %s, 1 given
