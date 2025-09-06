--TEST--
Cairo\FontFace\Toy::getSlant() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
// Test with all parameters
$c = new Cairo\FontFace\Toy("sans-serif", Cairo\FontSlant::Normal, Cairo\FontWeight::Normal);
var_dump($c->getSlant());

$c = new Cairo\FontFace\Toy("sans-serif", Cairo\FontSlant::Italic, Cairo\FontWeight::Normal);
var_dump($c->getSlant());
--EXPECTF--
enum(Cairo\FontSlant::Normal)
enum(Cairo\FontSlant::Italic)
