--TEST--
Cairo\Pattern\Mesh->getControlPoint()
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
$controlPointNum = 0;
$pattern->setControlPoint($controlPointNum, 5, 5);
$pattern->endPatch();
var_dump($pattern);
var_dump($pattern->getPatchCount());
$point = $pattern->getControlPoint(0, $controlPointNum);
var_dump($point);
assert($point === array("x" => 5.0, "y" => 5.0));

try {
    $pattern->getControlPoint();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(0, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(-1, 0);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(2, 0);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(0, -1);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getControlPoint(0, 4);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

$pattern = new Mesh();

try {
    $pattern->getControlPoint(0, 0);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

$pattern->beginPatch();
$pattern->moveTo(1, 1);
$pattern->setControlPoint(0, 3.141, 5.92);

try {
    $pattern->getControlPoint(0, 0);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

$pattern->endPatch();
assert($pattern->getControlPoint(0, 0) === array("x" => 3.141, "y" => 5.92));
--EXPECT--
object(Cairo\Pattern\Mesh)#1 (0) {
}
int(1)
array(2) {
  ["x"]=>
  float(5)
  ["y"]=>
  float(5)
}
Cairo\Pattern\Mesh::getControlPoint() expects exactly 2 arguments, 0 given
Cairo\Pattern\Mesh::getControlPoint() expects exactly 2 arguments, 1 given
Cairo\Pattern\Mesh::getControlPoint() expects exactly 2 arguments, 3 given
Cairo\Pattern\Mesh::getControlPoint(): Argument #1 ($patch_num) must be of type int, array given
Cairo\Pattern\Mesh::getControlPoint(): Argument #2 ($corner_num) must be of type int, array given
Invalid patch number. Expected 0 to 0.
Invalid patch number. Expected 0 to 0.
Invalid corner number. Expected 0, 1, 2, or 3.
Invalid corner number. Expected 0, 1, 2, or 3.
No patches found or first patch not finished with endPatch().
No patches found or first patch not finished with endPatch().