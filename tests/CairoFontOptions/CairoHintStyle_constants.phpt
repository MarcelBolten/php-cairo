--TEST--
Cairo\HintStyle class constants
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
$constants = [
    'Default',
    'None',
    'Slight',
    'Medium',
    'Full',
];

foreach ($constants as $name) {
    var_dump(defined('\\Cairo\\HintStyle::' . $name));
}
--EXPECT--
bool(true)
bool(true)
bool(true)
bool(true)
bool(true)
