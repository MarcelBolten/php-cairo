--TEST--
Cairo\TextCluster read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\TextCluster;

$cluster = new TextCluster(1, 2);

var_dump($cluster->num_bytes);
var_dump($cluster->num_glyphs);

--EXPECT--
int(1)
int(2)
