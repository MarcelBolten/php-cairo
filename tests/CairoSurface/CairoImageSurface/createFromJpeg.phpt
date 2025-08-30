--TEST--
Cairo\Surface\Image::createFromJpeg() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
if(!in_array('JPEG', Cairo::availableSurfaces())) die('skip - JPEG support not available');
--FILE--
<?php
$surface = Cairo\Surface\Image::createFromJpeg(dirname(__FILE__) . '/red.jpg');
var_dump($surface);

// There is a bug with the stream
echo dirname(__FILE__) . '/red.jpg' . PHP_EOL;
$resource = fopen(dirname(__FILE__) . '/red.jpg', 'rb');
$surface = Cairo\Surface\Image::createFromJpeg($resource);
var_dump($surface);
fclose($resource);

/* Wrong number args - 1 */
try {
    Cairo\Surface\Image::createFromJpeg();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args - 2 */
try {
    Cairo\Surface\Image::createFromJpeg('', 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg */
try {
    Cairo\Surface\Image::createFromJpeg(array());
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Surface\Image)#%d (0) {
}
Cairo\Surface\Image::createFromJpeg() expects exactly 1 argument, 0 given
Cairo\Surface\Image::createFromJpeg() expects exactly 1 argument, 2 given
Cairo\Surface\Image::createFromJpeg() expects parameter 1 to be a string or a stream resource
