--TEST--
Cairo\FontOptions->setCustomPaletteColor() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

$options->setCustomPaletteColor(0, 0.5, 0.5, 0.5);
var_dump($options->getCustomPaletteColor(0));

$options->setCustomPaletteColor(1, 0.7, 0.7, 0.7, 0.5);
var_dump($options->getCustomPaletteColor(1));

/* Wrong number arg */
try {
    $options->setCustomPaletteColor();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1 ,1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1, 1, 1, 1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - needs int */
try {
    $options->setCustomPaletteColor(array(), 1, 1, 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1, array(), 1, 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1, 1, array(), 1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1, 1, 1, array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $options->setCustomPaletteColor(1, 1, 1, 1, array());
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
array(4) {
  ["red"]=>
  float(0.7)
  ["green"]=>
  float(0.7)
  ["blue"]=>
  float(0.7)
  ["alpha"]=>
  float(0.5)
}
Cairo\FontOptions::setCustomPaletteColor() expects at least 4 arguments, 0 given
Cairo\FontOptions::setCustomPaletteColor() expects at least 4 arguments, 1 given
Cairo\FontOptions::setCustomPaletteColor() expects at least 4 arguments, 2 given
Cairo\FontOptions::setCustomPaletteColor() expects at least 4 arguments, 3 given
Cairo\FontOptions::setCustomPaletteColor() expects at most 5 arguments, 6 given
Cairo\FontOptions::setCustomPaletteColor(): Argument #1 ($color_id) must be of type int, array given
Cairo\FontOptions::setCustomPaletteColor(): Argument #2 ($red) must be of type float, array given
Cairo\FontOptions::setCustomPaletteColor(): Argument #3 ($green) must be of type float, array given
Cairo\FontOptions::setCustomPaletteColor(): Argument #4 ($blue) must be of type float, array given
Cairo\FontOptions::setCustomPaletteColor(): Argument #5 ($alpha) must be of type float, array given
