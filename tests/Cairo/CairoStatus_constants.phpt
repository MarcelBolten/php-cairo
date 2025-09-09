--TEST--
CairoStatus class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$constants = array(
    'Success',
    'NoMemory',
    'InvalidRestore',
    'InvalidPopGroup',
    'NoCurrentPoint',
    'InvalidMatrix',
    'InvalidStatus',
    'NullPointer',
    'InvalidString',
    'InvalidPathData',
    'ReadError',
    'WriteError',
    'SurfaceFinished',
    'SurfaceTypeMismatch',
    'PatternTypeMismatch',
    'InvalidContent',
    'InvalidFormat',
    'InvalidVisual',
    'FileNotFound',
    'InvalidDash',
    'InvalidDscComment',
    'InvalidIndex',
    'ClipNotRepresentable'
);
if (\Cairo\VERSION >= 10600) {
    $constants_16 = array(
        'TempFileError',
        'InvalidStride'
    );
    $constants = array_merge($constants, $constants_16);
}
if (\Cairo\VERSION >= 10800)
{
    $constants_18 = array(
        'FontTypeMismatch',
        'UserFontImmutable',
        'UserFontError',
        'NegativeCount',
        'InvalidClusters',
        'InvalidSlant',
        'InvalidWeight'
    );
    $constants = array_merge($constants, $constants_18);
}

$error = false;
foreach ($constants as $name) {
    $constant = '\Cairo\Status::' . $name;
    if (!defined($constant)) {
        $error = true;
        echo 'Missing Constant: ' . $constant . "\n";
    }
}
if (!$error) {
    echo "No missing constants, checked " . count($constants) . "!\n";
}
--EXPECTF--
No missing constants, checked %d!
