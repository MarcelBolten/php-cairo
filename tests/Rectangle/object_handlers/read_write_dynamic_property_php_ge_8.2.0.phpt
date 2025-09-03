--TEST--
Cairo\Rectangle read_property handler - Deprecation Warning (PHP >= 8.2)
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (version_compare(PHP_VERSION, '8.2.0', '<')) {
    die('skip Test requires PHP >= 8.2 for dynamic properties deprecation');
}
--FILE--
<?php
use Cairo\Rectangle;

$rect = new Rectangle(1, 2, 3, 4);

// Test dynamic property access (should show deprecation warning in PHP >= 8.2)
$rect->customProperty = 'test';
var_dump($rect->customProperty);
--EXPECTF--

Deprecated: Creation of dynamic property Cairo\Rectangle::$customProperty is deprecated in %s on line %d
string(4) "test"
