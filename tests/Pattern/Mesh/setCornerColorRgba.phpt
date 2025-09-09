--TEST--
Cairo\Pattern\Mesh->setCornerColorRgba()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Pattern\Mesh;

$pattern = new Mesh();

$pattern->beginPatch();

// we have to do stuff here
$pattern->lineTo(5,5);
$pattern->setCornerColorRgba(0, 0.5, 0.5, 0.5, 0.5);
$pattern->endPatch();
var_dump($pattern);
var_dump($pattern->getPatchCount());

try {
    $pattern->setCornerColorRgba();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

$num_args = 5;
for ($i = 0; $i <= $num_args; $i++) {
    $params = range(0, $i);

    if (count($params) === $num_args) {
        continue;
    }

    try {
        $pattern->setCornerColorRgba(...$params);
    } catch (ArgumentCountError $e) {
        echo $e->getMessage(), PHP_EOL;
    }
}

for ($i = 0; $i < $num_args; $i++) {
    $params = array_fill(0, $num_args, 1);
    $params[$i] = array();
    try {
        $pattern->setCornerColorRgba(...$params);
    } catch (TypeError $e) {
        echo $e->getMessage(), PHP_EOL;
    }
}

try {
    $pattern->setCornerColorRgba(-1, 1, 1, 1, 1);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->setCornerColorRgba(4, 1, 1, 1, 1);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECT--
object(Cairo\Pattern\Mesh)#1 (0) {
}
int(1)
Cairo\Pattern\Mesh::setCornerColorRgba() expects exactly 5 arguments, 0 given
Cairo\Pattern\Mesh::setCornerColorRgba() expects exactly 5 arguments, 1 given
Cairo\Pattern\Mesh::setCornerColorRgba() expects exactly 5 arguments, 2 given
Cairo\Pattern\Mesh::setCornerColorRgba() expects exactly 5 arguments, 3 given
Cairo\Pattern\Mesh::setCornerColorRgba() expects exactly 5 arguments, 4 given
Cairo\Pattern\Mesh::setCornerColorRgba() expects exactly 5 arguments, 6 given
Cairo\Pattern\Mesh::setCornerColorRgba(): Argument #1 ($corner_num) must be of type int, array given
Cairo\Pattern\Mesh::setCornerColorRgba(): Argument #2 ($red) must be of type float, array given
Cairo\Pattern\Mesh::setCornerColorRgba(): Argument #3 ($green) must be of type float, array given
Cairo\Pattern\Mesh::setCornerColorRgba(): Argument #4 ($blue) must be of type float, array given
Cairo\Pattern\Mesh::setCornerColorRgba(): Argument #5 ($alpha) must be of type float, array given
Invalid $corner_num. Expected 0, 1, 2, or 3.
Invalid $corner_num. Expected 0, 1, 2, or 3.
