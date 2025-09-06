--TEST--
Cairo\Surface\Image::createFromPng() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!in_array('PNG', Cairo\Cairo::availableSurfaces()))
    die('skip - PNG support not available');
--FILE--
<?php
$surface = Cairo\Surface\Image::createFromPng(dirname(__FILE__) . '/red.png');
var_dump($surface);

$resource = fopen(dirname(__FILE__) . '/red.png', 'rb');
$surface = Cairo\Surface\Image::createFromPng($resource);
var_dump($surface);
fclose($resource);

/* Wrong number args - 1 */
try {
    Cairo\Surface\Image::createFromPng();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args - 2 */
try {
    Cairo\Surface\Image::createFromPng('', 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg */
try {
    Cairo\Surface\Image::createFromPng(array());
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Surface\Image)#%d (0) {
}
Cairo\Surface\Image::createFromPng() expects exactly 1 argument, 0 given
Cairo\Surface\Image::createFromPng() expects exactly 1 argument, 2 given
Cairo\Surface\Image::createFromPng() expects parameter 1 to be a string or a stream resource
