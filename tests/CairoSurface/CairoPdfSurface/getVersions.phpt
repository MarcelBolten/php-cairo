--TEST--
Cairo\Surface\Pdf::getVersions() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
var_dump(Cairo\Surface\Pdf::getVersions());

/* Wrong number args */
try {
    Cairo\Surface\Pdf::getVersions('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
array(4) {
  [0]=>
  enum(Cairo\Surface\Pdf\Version::Version_1_4)
  [1]=>
  enum(Cairo\Surface\Pdf\Version::Version_1_5)
  [2]=>
  enum(Cairo\Surface\Pdf\Version::Version_1_6)
  [3]=>
  enum(Cairo\Surface\Pdf\Version::Version_1_7)
}
Cairo\Surface\Pdf::getVersions() expects exactly 0 %s, 1 given
