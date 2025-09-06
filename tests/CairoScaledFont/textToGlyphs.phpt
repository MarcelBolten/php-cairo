--TEST--
Cairo\ScaledFont->textToGlyphs() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
include(dirname(__FILE__) . '/create_toyfont.inc');
var_dump($fontface);

$scaled = new Cairo\ScaledFont(
    $fontface,
    new Cairo\Matrix(xx: 5, yy: 5),
    new Cairo\Matrix(),
    new Cairo\FontOptions());
var_dump($scaled);
$string = 'Hello Cairo! 🐘🪲';
$GlyphsArr = $scaled->textToGlyphs(10.1, 10.2, $string, true);
print_r(array_keys($GlyphsArr));
var_dump(count($GlyphsArr['glyphs']));
var_dump(count($GlyphsArr['clusters']));
var_dump($GlyphsArr['glyphs'][0]);
var_dump($GlyphsArr['clusters'][13]);
var_dump($GlyphsArr['cluster_flags']);

$GlyphsArr = $scaled->textToGlyphs(10.1, 10.2, 'a', false);
var_dump($GlyphsArr);

// TODO add test for cluster_flags === CAIRO_TEXT_CLUSTER_FLAG_BACKWARD, aka 1

/* Wrong number args */
try {
    $scaled->textToGlyphs();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $scaled->textToGlyphs(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $scaled->textToGlyphs(1, 0);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $scaled->textToGlyphs(0, 0, 'test', 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg types */
try {
    $scaled->textToGlyphs(array(), 0, 'foo', false);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $scaled->textToGlyphs(0, array(), 'foo', false);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $scaled->textToGlyphs(0, 0, array(), false);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $scaled->textToGlyphs(0, 0, 'foo', array());
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
object(Cairo\ScaledFont)#%d (0) {
}
Array
(
    [0] => glyphs
    [1] => clusters
    [2] => cluster_flags
)
int(15)
int(15)
object(Cairo\Glyph)#%d (3) {
  ["index"]=>
  int(%d)
  ["x"]=>
  float(10.1)
  ["y"]=>
  float(10.2)
}
object(Cairo\TextCluster)#%d (2) {
  ["num_bytes"]=>
  int(4)
  ["num_glyphs"]=>
  int(1)
}
int(0)
array(3) {
  ["glyphs"]=>
  array(1) {
    [0]=>
    object(Cairo\Glyph)#%d (3) {
      ["index"]=>
      int(%d)
      ["x"]=>
      float(10.1)
      ["y"]=>
      float(10.2)
    }
  }
  ["clusters"]=>
  NULL
  ["cluster_flags"]=>
  int(0)
}
Cairo\ScaledFont::textToGlyphs() expects at least 3 arguments, 0 given
Cairo\ScaledFont::textToGlyphs() expects at least 3 arguments, 1 given
Cairo\ScaledFont::textToGlyphs() expects at least 3 arguments, 2 given
Cairo\ScaledFont::textToGlyphs() expects at most 4 arguments, 5 given
Cairo\ScaledFont::textToGlyphs(): Argument #1 ($x) must be of type float, array given
Cairo\ScaledFont::textToGlyphs(): Argument #2 ($y) must be of type float, array given
Cairo\ScaledFont::textToGlyphs(): Argument #3 ($text) must be of type string, array given
Cairo\ScaledFont::textToGlyphs(): Argument #4 ($return_clusters) must be of type bool, array given
