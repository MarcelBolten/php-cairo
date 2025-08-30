--TEST--
Cairo\FontFace\Toy clone object
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
if(!class_exists('Cairo\FontFace\Toy')) die('skip - Cairo\FontFace\Toy not enabled');
--FILE--
<?php
// Test with all parameters
$c = new Cairo\FontFace\Toy("sans-serif", Cairo\FontSlant::NORMAL, Cairo\FontWeight::NORMAL);
var_dump($c);

$clone = clone $c;
var_dump($clone);
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
object(Cairo\FontFace\Toy)#%d (0) {
}
