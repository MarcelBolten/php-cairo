--TEST--
Cairo\Matrix read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Matrix;

$matrix = new Matrix(1, 2, 3, 4, 5, 6);

var_dump($matrix->xx);
var_dump($matrix->xy);
var_dump($matrix->x0);
var_dump($matrix->yx);
var_dump($matrix->yy);
var_dump($matrix->y0);

try {
    $matrix->banana = 'fruit';
}
catch (ErrorException $e) {
        if ($e->getSeverity() === E_DEPRECATED) {
            // ignore: Deprecated: Creation of dynamic property Cairo\Matrix::$banana is deprecated
        } else {
            throw $e;
        }
}
try {
    var_dump($matrix->banana);
}
catch (ErrorException $e) {
        if ($e->getSeverity() === E_DEPRECATED) {
            // ignore: Deprecated: Creation of dynamic property Cairo\Matrix::$banana is deprecated
        } else {
            throw $e;
        }
}
--EXPECT--
float(1)
float(3)
float(5)
float(2)
float(4)
float(6)
string(5) "fruit"
