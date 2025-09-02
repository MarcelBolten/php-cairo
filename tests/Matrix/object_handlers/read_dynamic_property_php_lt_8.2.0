--TEST--
Cairo\Matrix read_property handler - Dynamic Properties (PHP < 8.2)
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (version_compare(PHP_VERSION, '8.2.0', '>=')) {
    die('skip Test requires PHP < 8.2 for dynamic properties support');
}
--FILE--
<?php
use Cairo\Matrix;

$matrix = new Matrix(1, 2, 3, 4, 5, 6);

// Test standard matrix properties
var_dump($matrix->xx);
var_dump($matrix->xy);
var_dump($matrix->x0);
var_dump($matrix->yx);
var_dump($matrix->yy);
var_dump($matrix->y0);

// Test dynamic property access (should work in PHP < 8.2)
$matrix->customProperty = 'test';
var_dump($matrix->customProperty);
--EXPECT--
float(1)
float(3)
float(5)
float(2)
float(4)
float(6)
string(4) "test"
