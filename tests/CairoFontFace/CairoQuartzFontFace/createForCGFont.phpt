--TEST--
Cairo\FontFace\Quartz::createForCGFont()
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
if (!class_exists('\Cairo\FontFace\Quartz'))
    die('skip - Cairo\FontFace\Quartz class not available');
--FILE--
<?php
use Cairo\FontFace\Quartz;

var_dump(Quartz::createForCGFont('Helvetica'));
var_dump(Quartz::createForCGFont('Times-Roman'));

$courier = Quartz::createForCGFont('Courier');
var_dump($courier);
var_dump($courier->getType());

try {
    Quartz::createForCGFont('non existing font');
} catch (\Exception|\Error $e) {
    echo $e->getMessage() . PHP_EOL;
}

try {
    Quartz::createForCGFont();
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    Quartz::createForCGFont('test', '2nd param');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    Quartz::createForCGFont(array());
} catch (\TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontFace\Quartz)#%d (0) {
}
object(Cairo\FontFace\Quartz)#%d (0) {
}
object(Cairo\FontFace\Quartz)#%d (0) {
}
enum(Cairo\FontType::Quartz)
Cairo\FontFace\Quartz::createForCGFont(): Unable to create font face for 'non existing font'
Cairo\FontFace\Quartz::createForCGFont() expects exactly 1 argument, 0 given
Cairo\FontFace\Quartz::createForCGFont() expects exactly 1 argument, 2 given
Cairo\FontFace\Quartz::createForCGFont(): Argument #1 ($font_name) must be of type string, array given
