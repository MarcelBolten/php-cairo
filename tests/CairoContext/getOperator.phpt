--TEST--
Cairo\Context->getOperator() function
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$context->setOperator(\Cairo\Operator::CLEAR);
var_dump($context->getOperator());

try {
    $context->getOperator(1);
}
catch (ArgumentCountError $ex) {
    echo $ex->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
enum(Cairo\Operator::CLEAR)
Cairo\Context::getOperator() expects exactly 0 arguments, 1 given
