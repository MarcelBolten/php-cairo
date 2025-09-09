--TEST--
Cairo\FontOptions->hash() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

var_dump($options->hash());

/* Wrong number args */
try {
    $options->hash('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
int(0)
Cairo\FontOptions::hash() expects exactly 0 arguments, 1 given
