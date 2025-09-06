--TEST--
Cairo\FontOptions->getAntialias() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

var_dump($options->getAntialias());

/* Wrong number args */
try {
    $options->getAntialias('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\Antialias::Default)
Cairo\FontOptions::getAntialias() expects exactly 0 arguments, 1 given
