--TEST--
Cairo\FontOptions->getHintStyle() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

var_dump($options->getHintStyle());

/* Wrong number args */
try {
    $options->getHintStyle('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\HintStyle::Default)
Cairo\FontOptions::getHintStyle() expects exactly 0 arguments, 1 given
