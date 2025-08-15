--TEST--
Cairo\Surface\Svg::getVersions() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
if(!in_array('SVG', Cairo::availableSurfaces())) die('skip - SVG surface not available');
?>
--FILE--
<?php
var_dump(Cairo\Surface\Svg::getVersions());

/* Wrong number args */
try {
    Cairo\Surface\Svg::getVersions('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
array(2) {
  [0]=>
  enum(Cairo\Surface\Svg\Version::VERSION_1_1)
  [1]=>
  enum(Cairo\Surface\Svg\Version::VERSION_1_2)
}
Cairo\Surface\Svg::getVersions() expects exactly 0 %s, 1 given