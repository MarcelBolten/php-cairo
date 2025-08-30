--TEST--
Cairo\ScaledFont->getGlyphExtents() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
die('skip - Cairo glyph support not complete');
--FILE--
<?php
include(dirname(__FILE__) . '/create_toyfont.inc');
var_dump($fontface);
$matrix1 = new Cairo\Matrix(1, 0, 1, 1);
$matrix2 = new Cairo\Matrix(2, 0, 2, 2);
$fontoptions = new Cairo\FontOptions();

$scaled = new Cairo\ScaledFont($fontface, $matrix1, $matrix2, $fontoptions);
var_dump($scaled);
--EXPECTF--
