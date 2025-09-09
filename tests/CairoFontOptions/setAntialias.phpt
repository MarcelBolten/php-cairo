--TEST--
Cairo\FontOptions->setAntialias() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

$options->setAntialias(\Cairo\Antialias::Subpixel);

/* Wrong number args 0 */
try {
    $options->setAntialias();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args 2 */
try {
    $options->setAntialias(\Cairo\Antialias::Subpixel, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - needs int */
try {
    $options->setAntialias([]);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
Cairo\FontOptions::setAntialias() expects exactly 1 argument, 0 given
Cairo\FontOptions::setAntialias() expects exactly 1 argument, 2 given
Cairo\FontOptions::setAntialias(): Argument #1 ($antialias) must be of type Cairo\Antialias, array given
