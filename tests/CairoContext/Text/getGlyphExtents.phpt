--TEST--
Cairo\Context->getGlyphExtents() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);
$scaled_font = $context->getScaledFont();

$string = 'foobar';
$glyphsArr = $scaled_font->textToGlyphs(10, 10, $string, false);

var_dump($context->getGlyphExtents($glyphsArr['glyphs']));

/* Wrong number args 1 */
try {
    $context->getGlyphExtents();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args 1 */
try {
    $context->getGlyphExtents(array(), 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type */
try {
    $context->getGlyphExtents('text');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->getGlyphExtents(array('not', 'glyphs'));
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
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
Cairo\Context::getGlyphExtents() expects exactly 1 argument, 0 given
Cairo\Context::getGlyphExtents() expects exactly 1 argument, 2 given
Cairo\Context::getGlyphExtents(): Argument #1 ($glyphs) must be of type array, string given
Cairo\Context::getGlyphExtents(): Argument #1 ($glyphs) must be an array of Cairo\Glyph objects.
