--TEST--
Cairo\Region->containsRectangle() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$rectangle1 = new Cairo\Rectangle(1,1,100,100);
$rectangle2 = new Cairo\Rectangle(20,20,20,20);
$rectangle3 = new Cairo\Rectangle(20,20,100,100);
$rectangle4 = new Cairo\Rectangle(110,110,20,20);

$region1 = new Cairo\Region();
var_dump($region1);

$region2 = new Cairo\Region($rectangle1);
var_dump($region2);

$contains = $region1->containsRectangle($rectangle1);
var_dump( $contains );
var_dump( $contains == \Cairo\Region\Overlap::Out );

$contains = $region2->containsRectangle($rectangle2);
var_dump( $contains );
var_dump( $contains == \Cairo\Region\Overlap::In );
$contains = $region2->containsRectangle($rectangle3);
var_dump( $contains );
var_dump( $contains == \Cairo\Region\Overlap::Partial );
$contains = $region2->containsRectangle($rectangle4);
var_dump( $contains );
var_dump( $contains == \Cairo\Region\Overlap::Out );


/* Wrong number args */
try {
    $region1->containsRectangle();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $region1->containsRectangle(1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $region1->containsRectangle($rectangle1, 'foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Region)#%d (0) {
}
object(Cairo\Region)#%d (0) {
}
enum(Cairo\Region\Overlap::Out)
bool(true)
enum(Cairo\Region\Overlap::In)
bool(true)
enum(Cairo\Region\Overlap::Partial)
bool(true)
enum(Cairo\Region\Overlap::Out)
bool(true)
Cairo\Region::containsRectangle() expects exactly 1 argument, 0 given
Cairo\Region::containsRectangle(): Argument #1 ($rectangle) must be of type Cairo\Rectangle, int given
Cairo\Region::containsRectangle() expects exactly 1 argument, 2 given
