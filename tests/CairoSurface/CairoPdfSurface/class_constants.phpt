--TEST--
Cairo\Pdf class constants
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php

if (\Cairo\VERSION >= 11600) {
    $constants = [
        '\Cairo\Surface\Pdf::OUTLINE_ROOT',

        '\Cairo\Surface\Pdf\OutlineFlags::Open',
        '\Cairo\Surface\Pdf\OutlineFlags::Bold',
        '\Cairo\Surface\Pdf\OutlineFlags::Italic',

        '\Cairo\Surface\Pdf\Metadata::Title',
        '\Cairo\Surface\Pdf\Metadata::Author',
        '\Cairo\Surface\Pdf\Metadata::Subject',
        '\Cairo\Surface\Pdf\Metadata::Keywords',
        '\Cairo\Surface\Pdf\Metadata::Creator',
        '\Cairo\Surface\Pdf\Metadata::CreateDate',
        '\Cairo\Surface\Pdf\Metadata::ModDate',

        '\Cairo\Surface\Pdf\Version::Version_1_4',
        '\Cairo\Surface\Pdf\Version::Version_1_5',
        '\Cairo\Surface\Pdf\Version::Version_1_6',
        '\Cairo\Surface\Pdf\Version::Version_1_7'
    ];
} else {
    $constants = [];
}

$error = false;
foreach ($constants as $constant) {
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
