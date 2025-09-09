--TEST--
Cairo\FontOptions->getSubpixelOrder() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

var_dump($options->getSubpixelOrder());

/* Wrong number args */
try {
    $options->getSubpixelOrder('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\SubPixelOrder::Default)
Cairo\FontOptions::getSubpixelOrder() expects exactly 0 arguments, 1 given
