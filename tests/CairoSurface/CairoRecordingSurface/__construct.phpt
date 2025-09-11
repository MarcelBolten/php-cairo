--TEST--
new Cairo\Surface\Recording [__construct() method ]
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Recording(\Cairo\Surface\Content::ColorAlpha);
var_dump($surface);

$surface2 = new Cairo\Surface\Recording(
    \Cairo\Surface\Content::ColorAlpha,
    new Cairo\Rectangle(0, 0, 400, 400)
);
var_dump($surface2);

/* Wrong number args - 1 */
try {
    new Cairo\Surface\Recording();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args - 3 */
try {
    new Cairo\Surface\Recording(NULL, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 1 */
try {
    new Cairo\Surface\Recording([], 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 2 */
try {
    new Cairo\Surface\Recording(\Cairo\Surface\Content::ColorAlpha, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Recording)#%d (0) {
}
object(Cairo\Surface\Recording)#%d (0) {
}
Cairo\Surface\Recording::__construct() expects at least 1 argument, 0 given
Cairo\Surface\Recording::__construct() expects at most 2 arguments, 3 given
Cairo\Surface\Recording::__construct(): Argument #1 ($content) must be of type Cairo\Surface\Content, array given
Cairo\Surface\Recording::__construct(): Argument #2 ($extents) must be of type ?Cairo\Rectangle, int given
