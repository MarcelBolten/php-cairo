--TEST--
Cairo\FontOptions->getColorMode() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

var_dump($options->getColorMode());

/* Wrong number args */
try {
    $options->getColorMode('foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\ColorMode::Default)
Cairo\FontOptions::getColorMode() expects exactly 0 arguments, 1 given
