--TEST--
Cairo\Glyph read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Glyph;

$glyph = new Glyph(1, 2.3, 4.5);

var_dump($glyph->index);
var_dump($glyph->x);
var_dump($glyph->y);

--EXPECT--
int(1)
float(2.3)
float(4.5)
