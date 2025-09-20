--TEST--
Cairo\FontType class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$constants = array(
    'Toy',
    'FT',
    'Win32',
);

$version = \Cairo\version();
if ($version > 10600) {
    $constants[] = 'Quartz';
}
if ($version > 10800) {
    $constants[] = 'User';
}
$error = false;
foreach($constants as $name) {
    if (!defined('Cairo\FontType::' . $name)) {
        $error = true;
        echo 'Missing Constant: Cairo\FontType::' . $name . "\n";
    }
}
if (!$error) {
	echo "No missing constants, checked " . count($constants) . "!\n";
}
--EXPECTF--
No missing constants, checked %d!
