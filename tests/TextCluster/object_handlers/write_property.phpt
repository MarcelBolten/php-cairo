--TEST--
Cairo\TextCluster object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\TextCluster;

$glyph = new TextCluster(1, 1);

$glyph->num_bytes = 2;
$glyph->num_glyphs = 3;

var_dump($glyph->num_bytes);
var_dump($glyph->num_glyphs);

--EXPECT--
int(2)
int(3)
