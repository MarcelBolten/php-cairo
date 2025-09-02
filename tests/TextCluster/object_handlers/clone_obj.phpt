--TEST--
Cairo\TextCluster clone handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\TextCluster;

$cluster = new TextCluster(1, 2);
$copy = clone $cluster;
$copy->num_bytes = 3;
$copy->num_glyphs = 4;

var_dump($cluster);
var_dump($copy);
--EXPECTF--
object(Cairo\TextCluster)#%d (2) {
  ["num_bytes"]=>
  int(1)
  ["num_glyphs"]=>
  int(2)
}
object(Cairo\TextCluster)#%d (2) {
  ["num_bytes"]=>
  int(3)
  ["num_glyphs"]=>
  int(4)
}
