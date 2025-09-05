--TEST--
Cairo\FontFace\Toy::getSlant() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
if(!class_exists('Cairo\FontFace\Toy')) die('skip - Cairo\FontFace\Toy not enabled');
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
