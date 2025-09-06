--TEST--
Cairo\Context->setOperator() method
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


/* wrong params */
try {
	$context->setOperator();
	trigger_error('Cairo\Context->setOperator() expects 1 param');
}
catch (TypeError $ex) {
	echo $ex->getMessage(), PHP_EOL;
}
try {
	$context->setOperator(\Cairo\Operator::CLEAR, 1);
	trigger_error('Cairo\Context->setOperator() expects 1 param');
}
catch (TypeError $ex) {
	echo $ex->getMessage(), PHP_EOL;
}

/* wrong type */
try {
	$context->setOperator(array());
	trigger_error('Cairo\Context->setOperator() expects 1 param');
}
catch (TypeError $ex) {
	echo $ex->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
enum(Cairo\Operator::CLEAR)
Cairo\Context::setOperator() expects exactly 1 argument, 0 given
Cairo\Context::setOperator() expects exactly 1 argument, 2 given
Cairo\Context::setOperator(): Argument #1 ($operator) must be of type Cairo\Operator, array given
