--TEST--
Cairo\Surface\Pdf->restrictToVersion() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Pdf(NULL, 50, 50);
var_dump($surface);

$surface->restrictToVersion(Cairo\Surface\Pdf\Version::Version_1_5);

/* Wrong number args */
try {
    $surface->restrictToVersion();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args 2 */
try {
    $surface->restrictToVersion(1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type */
try {
    $surface->restrictToVersion(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Pdf)#%d (0) {
}
Cairo\Surface\Pdf::restrictToVersion() expects exactly 1 argument, 0 given
Cairo\Surface\Pdf::restrictToVersion() expects exactly 1 argument, 2 given
Cairo\Surface\Pdf::restrictToVersion(): Argument #1 ($version) must be of type Cairo\Surface\Pdf\Version, array given
