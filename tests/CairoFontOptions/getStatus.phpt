--TEST--
Cairo\FontOptions->getStatus() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

$status = $options->getStatus();
var_dump($status);
var_dump($status == Cairo\Status::Success);

/* Wrong number args */
try {
    $options->getStatus('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\Status::Success)
bool(true)
Cairo\FontOptions::getStatus() expects exactly 0 arguments, 1 given
