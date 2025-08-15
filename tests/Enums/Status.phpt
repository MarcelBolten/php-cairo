--TEST--
Cairo\Status class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\Status;

$enum = Status::SUCCESS;
var_dump($enum);

var_dump($enum->getMessage());

try {
    $enum->getMessage(1);
} catch(TypeError $e) {
    echo $e->getMessage();
}
--EXPECTF--
enum(Cairo\Status::SUCCESS)
string(21) "no error has occurred"
Cairo\Status::getMessage() expects exactly 0 arguments, 1 given
