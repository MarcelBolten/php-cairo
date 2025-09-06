--TEST--
Cairo\FontOptions->getHintMetrics() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

var_dump($options->getHintMetrics());

/* Wrong number args */
try {
    $options->getHintMetrics('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\HintMetrics::Default)
Cairo\FontOptions::getHintMetrics() expects exactly 0 arguments, 1 given
