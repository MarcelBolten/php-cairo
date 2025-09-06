--TEST--
Cairo\Surface\Svg::getVersions() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
var_dump(Cairo\Surface\Svg::getVersions());

/* Wrong number args */
try {
    Cairo\Surface\Svg::getVersions('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
array(2) {
  [0]=>
  enum(Cairo\Surface\Svg\Version::Version_1_1)
  [1]=>
  enum(Cairo\Surface\Svg\Version::Version_1_2)
}
Cairo\Surface\Svg::getVersions() expects exactly 0 arguments, 1 given
