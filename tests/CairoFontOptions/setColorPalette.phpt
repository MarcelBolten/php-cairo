--TEST--
Cairo\FontOptions->setColorPalette() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

$options->setColorPalette();
var_dump($options->getColorPalette());

$options->setColorPalette(0);
var_dump($options->getColorPalette());

$options->setColorPalette(99);
var_dump($options->getColorPalette());

/* Wrong number args 2 */
try {
    $options->setColorPalette(0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - needs int */
try {
    $options->setColorPalette(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
int(0)
int(0)
int(99)
Cairo\FontOptions::setColorPalette() expects at most 1 argument, 2 given
Cairo\FontOptions::setColorPalette(): Argument #1 ($palette) must be of type int, array given
