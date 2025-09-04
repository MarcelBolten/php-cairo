--TEST--
Cairo\Surface\Pdf::versionToString() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
if (!in_array('PDF', Cairo::availableSurfaces())) {
    die('skip - PDF surface not available');
}
--FILE--
<?php
echo Cairo\Surface\Pdf::versionToString(Cairo\Surface\Pdf\Version::Version_1_5), PHP_EOL;

/* Wrong number args */
try {
    Cairo\Surface\Pdf::versionToString();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args 2 */
try {
    Cairo\Surface\Pdf::versionToString(1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type */
try {
    Cairo\Surface\Pdf::versionToString([]);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
PDF 1.5
Cairo\Surface\Pdf::versionToString() expects exactly 1 argument, 0 given
Cairo\Surface\Pdf::versionToString() expects exactly 1 argument, 2 given
Cairo\Surface\Pdf::versionToString(): Argument #1 ($version) must be of type Cairo\Surface\Pdf\Version, array given
