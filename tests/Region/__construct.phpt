--TEST--
Cairo\Region->__construct()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$region = new Cairo\Region();
var_dump($region);

$rectangle = new Cairo\Rectangle(0, 0, 100, 100);
$region2 = new Cairo\Region($rectangle);
var_dump($region2);

$region3 = new Cairo\Region([]);
var_dump($region3);

/* Wrong number args 2*/
try {
    new Cairo\Region([], []);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg-types */
try {
    new Cairo\Region([1]);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg-types */
try {
    new Cairo\Region('surface');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Region)#%d (0) {
}
object(Cairo\Region)#%d (0) {
}
object(Cairo\Region)#%d (0) {
}
Cairo\Region::__construct() expects at most 1 argument, 2 given
Cairo\Region::__construct(): Argument #1 ($rectangle) must be empty, a Cairo\Rectangle object, or an array of Cairo\Rectangle objects.
Cairo\Region::__construct(): Argument #1 ($rectangle) must be empty, a Cairo\Rectangle object, or an array of Cairo\Rectangle objects.
