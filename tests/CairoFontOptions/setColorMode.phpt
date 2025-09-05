--TEST--
Cairo\FontOptions->setColorMode() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

$options->setColorMode(\Cairo\ColorMode::Color);

/* Wrong number args 0 */
try {
    $options->setColorMode();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args 2 */
try {
    $options->setColorMode(\Cairo\ColorMode::NoColor, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - needs Cairo\ColorMode */
try {
    $options->setColorMode(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
Cairo\FontOptions::setColorMode() expects exactly 1 argument, 0 given
Cairo\FontOptions::setColorMode() expects exactly 1 argument, 2 given
Cairo\FontOptions::setColorMode(): Argument #1 ($color_mode) must be of type Cairo\ColorMode, array given
