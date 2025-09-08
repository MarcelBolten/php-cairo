--TEST--
Cairo\TextCluster read_property handler - Dynamic Properties (PHP < 8.2)
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (version_compare(PHP_VERSION, '8.2.0', '>='))
    die('skip Test requires PHP < 8.2 for dynamic properties support');
--FILE--
<?php
use Cairo\TextCluster;

$rect = new TextCluster(1, 1);

// Test dynamic property access (should work in PHP < 8.2)
$rect->customProperty = 'test';
var_dump($rect->customProperty);
--EXPECT--
string(4) "test"
