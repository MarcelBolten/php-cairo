--TEST--
Cairo\ScaledFont->getGlyphExtents() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
include(dirname(__FILE__) . '/create_toyfont.inc');
var_dump($fontface);

$scaled = new Cairo\ScaledFont(
  $fontface,
  new Cairo\Matrix(1, 0, 1, 1),
  new Cairo\Matrix(2, 0, 2, 2),
  new Cairo\FontOptions()
);
var_dump($scaled);

var_dump($scaled->getGlyphExtents($scaled->textToGlyphs(0, 0, 'W')['glyphs']));
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
object(Cairo\ScaledFont)#%d (0) {
}
array(6) {
  ["x_bearing"]=>
  float(%f)
  ["y_bearing"]=>
  float(%f)
  ["width"]=>
  float(%f)
  ["height"]=>
  float(%f)
  ["x_advance"]=>
  float(%f)
  ["y_advance"]=>
  float(%f)
}
