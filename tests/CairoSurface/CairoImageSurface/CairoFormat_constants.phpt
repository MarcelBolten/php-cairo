--TEST--
Cairo\Surface\ImageFormat class constants
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$constants = [
    'ARGB32',
    'RGB24',
    'A8',
    'A1',
];

$error = false;
foreach ($constants as $name) {
    $constant = 'Cairo\Surface\ImageFormat::' . $name;
    if (!defined($constant)) {
        $error = true;
        echo 'Missing Constant: ' . $constant . "\n";
    }
}
if (!$error) {
    echo "No missing constants, checked " . sizeof($constants) . "!\n";
}
echo "Done\n";
--EXPECTF--
No missing constants, checked %d!
Done
