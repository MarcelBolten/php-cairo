--TEST--
Cairo\FontOptions->getHintStyle() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
?>
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
?>
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\HintStyle::DEFAULT)
Cairo\FontOptions::getHintStyle() expects exactly 0 arguments, 1 given