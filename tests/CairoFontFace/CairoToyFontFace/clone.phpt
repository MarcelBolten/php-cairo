--TEST--
Cairo\FontFace\Toy clone object
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
// Test with all parameters
$c = new Cairo\FontFace\Toy("sans-serif", Cairo\FontSlant::Normal, Cairo\FontWeight::Normal);
var_dump($c);

$clone = clone $c;
var_dump($clone);
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
object(Cairo\FontFace\Toy)#%d (0) {
}
