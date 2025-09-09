--TEST--
Cairo\Matrix read_property handler - Deprecation Warning (PHP >= 8.2)
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (version_compare(PHP_VERSION, '8.2.0', '<'))
    die('skip Test requires PHP >= 8.2 for dynamic properties deprecation');
--FILE--
<?php
use Cairo\Matrix;

$matrix = new Matrix(1, 2, 3, 4, 5, 6);

// Test dynamic property access (should show deprecation warning in PHP >= 8.2)
$matrix->customProperty = 'test';
var_dump($matrix->customProperty);
--EXPECTF--

Deprecated: Creation of dynamic property Cairo\Matrix::$customProperty is deprecated in %s on line %d
string(4) "test"
