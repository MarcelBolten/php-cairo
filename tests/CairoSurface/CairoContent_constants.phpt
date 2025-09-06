--TEST--
Cairo\Surface\Content class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$constants = [
    'Color',
    'Alpha',
    'ColorAlpha',
];

$error = false;
foreach ($constants as $name) {
    $constant = 'Cairo\Surface\Content::' . $name;
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
