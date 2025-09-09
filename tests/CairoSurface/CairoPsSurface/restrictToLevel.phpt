--TEST--
Cairo\Surface\Ps->restrictToLevel() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
if (!method_exists('\Cairo\Surface\Ps', 'restrictToLevel'))
    die('skip - Cairo\Surface\Ps->restrictToLevel not available');
--FILE--
<?php
$surface = new Cairo\Surface\Ps(NULL, 50, 50);
var_dump($surface);

// explicitly provide value
$surface->restrictToLevel(Cairo\Surface\Ps\Level::Level_3);

// set default value
$surface->restrictToLevel();

/* Wrong number args 2 */
try {
    $surface->restrictToLevel(Cairo\Surface\Ps\Level::Level_2, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type */
try {
    $surface->restrictToLevel(array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Ps)#%d (0) {
}
Cairo\Surface\Ps::restrictToLevel() expects at most 1 argument, 2 given
Cairo\Surface\Ps::restrictToLevel(): Argument #1 ($level) must be of type Cairo\Surface\Ps\Level, array given
