--TEST--
Cairo\Context->getStatus() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
?>
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$status = $context->getStatus();
var_dump($status);

var_dump($status == Cairo\Status::SUCCESS);

/* Wrong number args */
try {
    $context->getStatus('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
enum(Cairo\Status::SUCCESS)
bool(true)
Cairo\Context::getStatus() expects exactly 0 arguments, 1 given