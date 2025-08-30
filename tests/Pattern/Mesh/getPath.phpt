--TEST--
Cairo\Pattern\Mesh->lineTo()
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
$pattern->lineTo(1, 5);
$pattern->lineTo(5, 5);
$pattern->lineTo(5, 1);
$pattern->endPatch();
var_dump($pattern);
var_dump($pattern->getPatchCount());
var_dump($pattern->getPath(0));

try {
    $pattern->getPath();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getPath(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getPath(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECT--
object(Cairo\Pattern\Mesh)#1 (0) {
}
int(1)
object(Cairo\Path)#2 (0) {
}
Cairo\Pattern\Mesh::getPath() expects exactly 1 argument, 0 given
Cairo\Pattern\Mesh::getPath() expects exactly 1 argument, 2 given
Cairo\Pattern\Mesh::getPath(): Argument #1 ($patch_num) must be of type int, array given
