--TEST--
Cairo\Region->getStatus() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$region = new Cairo\Region();
var_dump($region);

$status = $region->getStatus();
var_dump($status);

var_dump($status == Cairo\Status::Success);

/* Wrong number args */
try {
    $region->getStatus('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Region)#%d (0) {
}
enum(Cairo\Status::Success)
bool(true)
Cairo\Region::getStatus() expects exactly 0 arguments, 1 given
