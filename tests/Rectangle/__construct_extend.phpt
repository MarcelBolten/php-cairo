--TEST--
Cairo\Rectangle->__construct() extended
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\Rectangle;
use Cairo\Exception;

class Bad extends Rectangle {
    public function __construct() {
    }
}

$fail = new Bad();

var_dump($fail);
--EXPECTF--
object(Bad)#%d (4) {
  ["x"]=>
  float(0)
  ["y"]=>
  float(0)
  ["width"]=>
  float(0)
  ["height"]=>
  float(0)
}
