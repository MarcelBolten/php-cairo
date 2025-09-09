--TEST--
Cairo\Surface\Ps::getLevels() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
if (!method_exists('\Cairo\Surface\Ps', 'getLevels'))
    die('skip - Cairo\Surface\Ps::getLevels not available');
--FILE--
<?php
var_dump(Cairo\Surface\Ps::getLevels());

/* Wrong number args */
try {
    Cairo\Surface\Ps::getLevels('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
array(2) {
  [0]=>
  enum(Cairo\Surface\Ps\Level::Level_2)
  [1]=>
  enum(Cairo\Surface\Ps\Level::Level_3)
}
Cairo\Surface\Ps::getLevels() expects exactly 0 arguments, 1 given
