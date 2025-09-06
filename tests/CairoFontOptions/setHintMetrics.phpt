--TEST--
Cairo\FontOptions->setHintMetrics() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

$options->setHintMetrics(Cairo\HintMetrics::On);
$options->setHintMetrics();

/* Wrong number args 2 */
try {
    $options->setHintMetrics(Cairo\HintMetrics::On, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - needs int */
try {
    $options->setHintMetrics(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
Cairo\FontOptions::setHintMetrics() expects at most 1 argument, 2 given
Cairo\FontOptions::setHintMetrics(): Argument #1 ($hint_metrics) must be of type Cairo\HintMetrics, array given
