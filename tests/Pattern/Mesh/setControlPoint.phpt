--TEST--
Cairo\Pattern\Mesh->setControlPoint()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Mesh;

$pattern = new Mesh();

$pattern->beginPatch();

// we have to do stuff here
$pattern->moveTo(1, 1);
$pattern->setControlPoint(0, 5, 5);
$pattern->endPatch();
var_dump($pattern);
var_dump($pattern->getPatchCount());

try {
    $pattern->setControlPoint();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setControlPoint(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setControlPoint(1, 2, 3, 4);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setControlPoint(array(), 1, 3);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setControlPoint(1, array(), 3);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setControlPoint(1, 2, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setControlPoint(-1, 2, 2);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setControlPoint(4, 2, 2);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECT--
object(Cairo\Pattern\Mesh)#1 (0) {
}
int(1)
Cairo\Pattern\Mesh::setControlPoint() expects exactly 3 arguments, 0 given
Cairo\Pattern\Mesh::setControlPoint() expects exactly 3 arguments, 1 given
Cairo\Pattern\Mesh::setControlPoint() expects exactly 3 arguments, 4 given
Cairo\Pattern\Mesh::setControlPoint(): Argument #1 ($corner_num) must be of type int, array given
Cairo\Pattern\Mesh::setControlPoint(): Argument #2 ($x) must be of type float, array given
Cairo\Pattern\Mesh::setControlPoint(): Argument #3 ($y) must be of type float, array given
Invalid point number. Expected 0, 1, 2, or 3.
Invalid point number. Expected 0, 1, 2, or 3.