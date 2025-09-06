--TEST--
Cairo\ScaledFont->getExtents() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
include(dirname(__FILE__) . '/create_toyfont.inc');
var_dump($fontface);
$matrix1 = new Cairo\Matrix(1, 0, 1, 1);
$matrix2 = new Cairo\Matrix(2, 0, 2, 2);
$fontoptions = new Cairo\FontOptions();

$scaled = new Cairo\ScaledFont($fontface, $matrix1, $matrix2, $fontoptions);
var_dump($scaled);
var_dump($scaled->getExtents());

/* Wrong number args */
try {
    var_dump($scaled->getExtents(1));
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
object(Cairo\ScaledFont)#%d (0) {
}
array(5) {
  ["ascent"]=>
  float(%f)
  ["descent"]=>
  float(%f)
  ["height"]=>
  float(%f)
  ["max_x_advance"]=>
  float(%f)
  ["max_y_advance"]=>
  float(%f)
}
Cairo\ScaledFont::getExtents() expects exactly 0 arguments, 1 given
