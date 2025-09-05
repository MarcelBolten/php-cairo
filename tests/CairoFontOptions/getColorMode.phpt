--TEST--
Cairo\FontOptions->getColorMode() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
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
