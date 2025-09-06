--TEST--
Cairo\Context->glyphPath() function
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

$glyphsArr = $scaled_font->textToGlyphs(10, 10, 'foo bar', true);

$before = $context->getCurrentPoint();
$context->glyphPath($glyphsArr['glyphs']);
$after = $context->getCurrentPoint();
var_dump($before !== $after);
var_dump($context->getPathExtents());

try {
    $context->glyphPath();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->glyphPath(array(), array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->glyphPath('test');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->glyphPath(array('not', 'a', 'glyph'));
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#1 (0) {
}
object(Cairo\Context)#3 (0) {
}
bool(true)
array(4) {
  ["x1"]=>
  float(%f)
  ["y1"]=>
  float(%f)
  ["x2"]=>
  float(%f)
  ["y2"]=>
  float(%f)
}
Cairo\Context::glyphPath() expects exactly 1 argument, 0 given
Cairo\Context::glyphPath() expects exactly 1 argument, 2 given
Cairo\Context::glyphPath(): Argument #1 ($glyphs) must be of type array, string given
Cairo\Context::glyphPath(): Argument #1 ($glyphs) must be an array of Cairo\Glyph objects.
