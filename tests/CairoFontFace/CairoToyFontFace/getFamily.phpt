--TEST--
Cairo\FontFace\Toy::getFamily() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
// Test with all parameters
$c = new Cairo\FontFace\Toy("sans-serif", Cairo\FontSlant::Normal, Cairo\FontWeight::Normal);
var_dump($c->getFamily());
--EXPECTF--
string(10) "sans-serif"
