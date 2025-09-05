--TEST--
Cairo\Context->selectFontFace() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
$surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
var_dump($surface);

$context = new Cairo\Context($surface);
var_dump($context);

$context->selectFontFace('sans-serif');
$fontface = $context->getFontFace();
var_dump($fontface);

// test with named parameters
try {
    $context->selectFontFace(
        family: 'sans-serif',
        weight: Cairo\FontWeight::Normal
    );
} catch (Exception | Error $e) {
    var_dump($e);
}


/* Wrong number args */
try {
    $context->selectFontFace();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args - too many */
try {
    $context->selectFontFace('sans-serif', Cairo\FontSlant::Normal, Cairo\FontWeight::Normal, 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - string */
try {
    $context->selectFontFace([]);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - int */
try {
    $context->selectFontFace('sans-serif', []);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type - int */
try {
    $context->selectFontFace('sans-serif', Cairo\FontSlant::Normal, []);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Image)#%d (0) {
}
object(Cairo\Context)#%d (0) {
}
object(Cairo\FontFace\Toy)#%d (0) {
}
Cairo\Context::selectFontFace() expects at least 1 argument, 0 given
Cairo\Context::selectFontFace() expects at most 3 arguments, 4 given
Cairo\Context::selectFontFace(): Argument #1 ($family) must be of type string, array given
Cairo\Context::selectFontFace(): Argument #2 ($slant) must be of type Cairo\FontSlant, array given
Cairo\Context::selectFontFace(): Argument #3 ($weight) must be of type Cairo\FontWeight, array given
