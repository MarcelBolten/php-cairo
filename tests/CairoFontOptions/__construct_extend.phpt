--TEST--
Cairo\FontOptions->__construct() extended
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\FontOptions;
use Cairo\Exception;

class Bad extends FontOptions {
    public function __construct() {}
}

$fail = new Bad();
var_dump($fail);

try {
    var_dump($fail->getStatus());
} catch (Cairo\Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Bad)#1 (0) {
}
Internal font options object missing in Bad, you must call parent::__construct in extended classes.
