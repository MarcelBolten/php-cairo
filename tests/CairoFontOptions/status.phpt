--TEST--
Cairo\FontOptions->status() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
?>
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

$status = $options->getStatus();
var_dump($status);
var_dump($status == Cairo\Status::SUCCESS);

/* Wrong number args */
try {
    $options->getStatus('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
enum(Cairo\Status::SUCCESS)
bool(true)
Cairo\FontOptions::getStatus() expects exactly 0 arguments, 1 given