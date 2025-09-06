--TEST--
Cairo\FontSlant class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$constants = [
    'Normal',
    'Italic',
    'Oblique',
];

$error = false;
foreach ($constants as $name) {
    if (!defined('Cairo\FontSlant::' . $name)) {
        $error = true;
        echo 'Missing Constant: Cairo\FontSlant::' . $name . "\n";
    }
}
if (!$error) {
    echo "No missing constants, checked " . sizeof($constants) . "!\n";
}
--EXPECT--
No missing constants, checked 3!
