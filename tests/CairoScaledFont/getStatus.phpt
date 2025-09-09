--TEST--
Cairo\ScaledFont->getStatus() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
include(dirname(__FILE__) . '/create_toyfont.inc');
var_dump($fontface);
$matrix1 = new Cairo\Matrix(1, 0, 1, 1);
$matrix2 = new Cairo\Matrix(2, 0, 2, 2);
$fontoptions = new Cairo\FontOptions();

$scaled = new Cairo\ScaledFont($fontface, $matrix1, $matrix2, $fontoptions);
var_dump($scaled);

$status = $scaled->getStatus();
var_dump($status);

var_dump($status == \Cairo\Status::Success);

/* Wrong number args */
try {
    $scaled->getStatus('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Toy)#%d (0) {
}
object(Cairo\ScaledFont)#%d (0) {
}
enum(Cairo\Status::Success)
bool(true)
Cairo\ScaledFont::getStatus() expects exactly 0 arguments, 1 given
