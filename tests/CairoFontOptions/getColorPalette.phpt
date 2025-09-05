--TEST--
Cairo\FontOptions->getColorPalette() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

var_dump($options->getColorPalette());

/* Wrong number args */
try {
    $options->getColorPalette('foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
int(%d)
Cairo\FontOptions::getColorPalette() expects exactly 0 arguments, 1 given
