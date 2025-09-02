--TEST--
Cairo\Glyph object write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Glyph;

$glyph = new Glyph(2, 3.4, 4.5);

$glyph->index = 1;
$glyph->x = 6.7;
$glyph->y = 8.9;

var_dump($glyph->index);
var_dump($glyph->x);
var_dump($glyph->y);

--EXPECT--
int(1)
float(6.7)
float(8.9)
