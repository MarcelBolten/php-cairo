--TEST--
Cairo\Context->setAntialias() method
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

$context->setAntialias(Cairo\Antialias::GRAY);
var_dump($context->getAntialias());

/* Wrong number args - 1 */
try {
    $context->setAntialias();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args - 1 */
try {
    $context->setAntialias(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong args */
try {
    $context->setAntialias(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
enum(Cairo\Antialias::GRAY)
Cairo\Context::setAntialias() expects exactly 1 argument, 0 given
Cairo\Context::setAntialias() expects exactly 1 argument, 2 given
Cairo\Context::setAntialias(): Argument #1 ($antialias) must be of type Cairo\Antialias, array given
