--TEST--
Cairo\Pattern\Mesh->moveTo()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Mesh;

$pattern = new Mesh();

$pattern->beginPatch();

// we have to do stuff here
$pattern->moveTo(1, 1.4);
$pattern->lineTo(5, 5);
$pattern->endPatch();
var_dump($pattern);
var_dump($pattern->getPatchCount());

try {
    $pattern->moveTo();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->moveTo(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->moveTo(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->moveTo(array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->moveTo(1, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECT--
object(Cairo\Pattern\Mesh)#1 (0) {
}
int(1)
Cairo\Pattern\Mesh::moveTo() expects exactly 2 arguments, 0 given
Cairo\Pattern\Mesh::moveTo() expects exactly 2 arguments, 1 given
Cairo\Pattern\Mesh::moveTo() expects exactly 2 arguments, 3 given
Cairo\Pattern\Mesh::moveTo(): Argument #1 ($x) must be of type float, array given
Cairo\Pattern\Mesh::moveTo(): Argument #2 ($y) must be of type float, array given
