--TEST--
Cairo\FontOptions->getAntialias() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
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
enum(Cairo\Antialias::DEFAULT)
Cairo\FontOptions::getAntialias() expects exactly 0 arguments, 1 given
