--TEST--
Cairo\SurfaceType class constants
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
$constants = [
    'Image',
    'PDF',
    'PS',
    'Xlib',
    'Xcb',
    'Glitz',
    'Quartz',
    'Win32',
    'BeOS',
    'DirectFB',
    'SVG',
    'OS2',
    'Win32Printing',
    'QuartzImage',
];

$error = false;
foreach ($constants as $name) {
    $constant = 'Cairo\Surface\Type::' . $name;
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
