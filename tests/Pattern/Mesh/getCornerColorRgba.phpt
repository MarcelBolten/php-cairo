--TEST--
Cairo\Pattern\Mesh->getCornerColorRgba()
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
for ($i = 0; $i < 4; $i++) {
    $color = $i / 3;
    $pattern->setCornerColorRgba($i, $color, $color, $color, 1);
}
$pattern->endPatch();

var_dump($pattern);
var_dump($pattern->getPatchCount());

for ($i = 0; $i < 4; $i++) {
    var_dump($pattern->getCornerColorRgba(0, $i));
}

try {
    $pattern->getCornerColorRgba();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getCornerColorRgba(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getCornerColorRgba(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

$num_args = 2;
for ($i = 0; $i < $num_args; $i++) {
    $params = array_fill(0, $num_args, 1);
    $params[$i] = array();
    try {
        $pattern->getCornerColorRgba(...$params);
    } catch (TypeError $e) {
        echo $e->getMessage(), PHP_EOL;
    }
}

try {
    $pattern->getCornerColorRgba(-1, 1);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getCornerColorRgba(4, 1);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getCornerColorRgba(0, -1);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $pattern->getCornerColorRgba(0, 4);
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Pattern\Mesh)#%d (0) {
}
int(1)
array(4) {
  ["red"]=>
  float(0)
  ["green"]=>
  float(0)
  ["blue"]=>
  float(0)
  ["alpha"]=>
  float(1)
}
array(4) {
  ["red"]=>
  float(%f)
  ["green"]=>
  float(%f)
  ["blue"]=>
  float(%f)
  ["alpha"]=>
  float(1)
}
array(4) {
  ["red"]=>
  float(%f)
  ["green"]=>
  float(%f)
  ["blue"]=>
  float(%f)
  ["alpha"]=>
  float(1)
}
array(4) {
  ["red"]=>
  float(1)
  ["green"]=>
  float(1)
  ["blue"]=>
  float(1)
  ["alpha"]=>
  float(1)
}
Cairo\Pattern\Mesh::getCornerColorRgba() expects exactly 2 arguments, 0 given
Cairo\Pattern\Mesh::getCornerColorRgba() expects exactly 2 arguments, 1 given
Cairo\Pattern\Mesh::getCornerColorRgba() expects exactly 2 arguments, 3 given
Cairo\Pattern\Mesh::getCornerColorRgba(): Argument #1 ($patch_num) must be of type int, array given
Cairo\Pattern\Mesh::getCornerColorRgba(): Argument #2 ($corner_num) must be of type int, array given
Invalid patch number. Expected 0 to 0.
Invalid patch number. Expected 0 to 0.
Invalid corner number. Expected 0, 1, 2, or 3.
Invalid corner number. Expected 0, 1, 2, or 3.
