--TEST--
Cairo\Context->showGlyphs() function
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);
$scaled_font = $context->getScaledFont();

$glyphsArr = $scaled_font->textToGlyphs(10, 10, 'foobar', true);

$context->showGlyphs($glyphsArr['glyphs']);

/* Wrong number args 1 */
try {
    $context->showGlyphs();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showGlyphs(1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type */
try {
    $context->showGlyphs('test');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showGlyphs(array('not', 'Glyphs', 'objects'));
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
Cairo\Context::showGlyphs() expects exactly 1 argument, 0 given
Cairo\Context::showGlyphs() expects exactly 1 argument, 2 given
Cairo\Context::showGlyphs(): Argument #1 ($glyphs) must be of type array, string given
Cairo\Context::showGlyphs(): Argument #1 ($glyphs) must be an array of Cairo\Glyph objects.
