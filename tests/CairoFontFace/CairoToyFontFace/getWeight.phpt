--TEST--
Cairo\FontFace\Toy::getWeight() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
// Test with all parameters
$c = new Cairo\FontFace\Toy("sans-serif", Cairo\FontSlant::Normal, Cairo\FontWeight::Normal);
var_dump($c->getWeight());

$c = new Cairo\FontFace\Toy("sans-serif", Cairo\FontSlant::Normal, Cairo\FontWeight::Bold);
var_dump($c->getWeight());
--EXPECTF--
enum(Cairo\FontWeight::Normal)
enum(Cairo\FontWeight::Bold)
