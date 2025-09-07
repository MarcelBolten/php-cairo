--TEST--
Cairo\Context->setLineJoin() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$context->setLineJoin(Cairo\LineJoin::Bevel);
var_dump($context->getLineJoin());

/* Wrong number args - 1 */
try {
    $context->setLineJoin();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args - 2 */
try {
    $context->setLineJoin(1, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong args */
try {
    $context->setLineJoin(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
enum(Cairo\LineJoin::Bevel)
Cairo\Context::setLineJoin() expects exactly 1 argument, 0 given
Cairo\Context::setLineJoin() expects exactly 1 argument, 2 given
Cairo\Context::setLineJoin(): Argument #1 ($linejoin) must be of type Cairo\LineJoin, array given
