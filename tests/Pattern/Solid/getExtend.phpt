--TEST--
Cairo\Pattern->getExtend() method [using Solid]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Solid;

$pattern = new Solid(1, 1, 1);
$extend = $pattern->getExtend();
var_dump($extend);

/* Total number of args needed = 0 */
try {
    $pattern->getExtend(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECT--
enum(Cairo\Extend::Pad)
Cairo\Pattern::getExtend() expects exactly 0 arguments, 1 given
