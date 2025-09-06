--TEST--
Cairo\Context->getTarget() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$surface2 = $context->getSurface();
var_dump($surface2);
var_dump($surface2 === $surface);
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
object(Cairo\Surface\Image)#%d (0) {
}
bool(true)
