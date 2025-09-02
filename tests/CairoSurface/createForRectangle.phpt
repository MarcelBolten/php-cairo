--TEST--
Cairo\Surface->createForRectangle() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$surface2 = $surface->createForRectangle(10, 10, 30, 30);
var_dump($surface2);

/* Wrong number args */
try {
    $surface->createForRectangle();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(1, 2);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(1, 2, 3);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(1, 2, 3, 4, 5);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(array(), 2, 3, 4);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(1, array(), 3, 4);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(1, 2, array(), 4);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->createForRectangle(1, 2, 3, array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Surface\SubSurface)#%d (0) {
}
Cairo\Surface::createForRectangle() expects exactly 4 arguments, 0 given
Cairo\Surface::createForRectangle() expects exactly 4 arguments, 1 given
Cairo\Surface::createForRectangle() expects exactly 4 arguments, 2 given
Cairo\Surface::createForRectangle() expects exactly 4 arguments, 3 given
Cairo\Surface::createForRectangle() expects exactly 4 arguments, 5 given
Cairo\Surface::createForRectangle(): Argument #1 ($x) must be of type float, array given
Cairo\Surface::createForRectangle(): Argument #2 ($y) must be of type float, array given
Cairo\Surface::createForRectangle(): Argument #3 ($width) must be of type float, array given
Cairo\Surface::createForRectangle(): Argument #4 ($height) must be of type float, array given
