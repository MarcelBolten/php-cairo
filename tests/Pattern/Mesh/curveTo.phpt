--TEST--
Cairo\Pattern\Mesh->curveTo()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Mesh;

$pattern = new Mesh();

$pattern->beginPatch();

// we have to do stuff here
$pattern->moveTo(0, 0);
$pattern->curveTo(1, 5, 4, 5, 5, 0);
$pattern->endPatch();
var_dump($pattern);
var_dump($pattern->getPatchCount());

try {
    $pattern->curveTo();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(1, 2, 3, 4, 5, 6, 7);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(array(), 2, 3, 4, 5, 6);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(1, array(), 3, 4, 5, 6);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(1, 2, array(), 4, 5, 6);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(1, 2, 3, array(), 5, 6);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(1, 2, 3, 4, array(), 6);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->curveTo(1, 2, 3, 4, 5, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECT--
object(Cairo\Pattern\Mesh)#1 (0) {
}
int(1)
Cairo\Pattern\Mesh::curveTo() expects exactly 6 arguments, 0 given
Cairo\Pattern\Mesh::curveTo() expects exactly 6 arguments, 1 given
Cairo\Pattern\Mesh::curveTo() expects exactly 6 arguments, 7 given
Cairo\Pattern\Mesh::curveTo(): Argument #1 ($x1) must be of type float, array given
Cairo\Pattern\Mesh::curveTo(): Argument #2 ($y1) must be of type float, array given
Cairo\Pattern\Mesh::curveTo(): Argument #3 ($x2) must be of type float, array given
Cairo\Pattern\Mesh::curveTo(): Argument #4 ($y2) must be of type float, array given
Cairo\Pattern\Mesh::curveTo(): Argument #5 ($x3) must be of type float, array given
Cairo\Pattern\Mesh::curveTo(): Argument #6 ($y3) must be of type float, array given
