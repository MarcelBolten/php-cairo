--TEST--
Cairo\FontOptions->getCustomPaletteColor() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php

use Cairo\Exception;

$options = new Cairo\FontOptions();
var_dump($options);

$options->setCustomPaletteColor(3, 0.5, 0.5, 0.5);

var_dump($options->getCustomPaletteColor(3));

try {
    $options->getCustomPaletteColor(99);
} catch (Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args */
try {
    $options->getCustomPaletteColor();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->getCustomPaletteColor(0, 'foo');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->getCustomPaletteColor(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
array(4) {
  ["red"]=>
  float(0.5)
  ["green"]=>
  float(0.5)
  ["blue"]=>
  float(0.5)
  ["alpha"]=>
  float(1)
}
invalid index passed to getter
Cairo\FontOptions::getCustomPaletteColor() expects exactly 1 argument, 0 given
Cairo\FontOptions::getCustomPaletteColor() expects exactly 1 argument, 2 given
Cairo\FontOptions::getCustomPaletteColor(): Argument #1 ($color_id) must be of type int, array given
