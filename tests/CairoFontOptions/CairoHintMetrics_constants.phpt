--TEST--
Cairo\HintMetrics class constants
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
$constants = [
    'Default',
    'On',
    'Off',
];

foreach($constants as $name) {
    var_dump(defined('\\Cairo\\HintMetrics::' . $name));
}
--EXPECT--
bool(true)
bool(true)
bool(true)
