--TEST--
Cairo\Context->showTextGlyphs() function
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
$glyphsArr = $scaled_font->textToGlyphs(10, 10, $string, true);
$context->showTextGlyphs($string, ...$glyphsArr);

/* Wrong number args 1 */
try {
    $context->showTextGlyphs();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('text');
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('text', array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('text', array(), array());
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('text', array(), array(), 0, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type */
try {
    $context->showTextGlyphs(array(), array(), array(), 0);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('test', 123, array(), 0);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('test', array(), 123, 0);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('test', array(), array(), array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('test', array('not', 'Glyphs', 'objects'), array(), 0);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $context->showTextGlyphs('test', array(), array('not', 'Clusters', 'objects'), 0);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
Cairo\Context::showTextGlyphs() expects exactly 4 arguments, 0 given
Cairo\Context::showTextGlyphs() expects exactly 4 arguments, 1 given
Cairo\Context::showTextGlyphs() expects exactly 4 arguments, 2 given
Cairo\Context::showTextGlyphs() expects exactly 4 arguments, 3 given
Cairo\Context::showTextGlyphs() expects exactly 4 arguments, 5 given
Cairo\Context::showTextGlyphs(): Argument #1 ($text) must be of type string, array given
Cairo\Context::showTextGlyphs(): Argument #2 ($glyphs) must be of type array, int given
Cairo\Context::showTextGlyphs(): Argument #3 ($clusters) must be of type array, int given
Cairo\Context::showTextGlyphs(): Argument #4 ($cluster_flags) must be of type int, array given
Cairo\Context::showTextGlyphs(): Argument #1 ($glyphs) must be an array of Cairo\Glyph objects.
Cairo\Context::showTextGlyphs(): Argument #2 ($clusters) must be an array of Cairo\TextCluster objects.
