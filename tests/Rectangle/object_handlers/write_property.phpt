--TEST--
Cairo\Rectangle write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
?>
--FILE--
<?php
use Cairo\Rectangle;

$rect = new Rectangle(9, 9, 9, 9);

$rect->x = 1;
$rect->y = 2;
$rect->width = 3;
$rect->height = 4;

var_dump($rect->x);
var_dump($rect->y);
var_dump($rect->width);
var_dump($rect->height);

$rect->banana = 'fruit';
var_dump($rect->banana);

?>
--EXPECT--
int(1)
int(2)
int(3)
int(4)

Deprecated: Creation of dynamic property Cairo\Rectangle::$banana is deprecated in /src/php-cairo/tests/Rectangle/object_handlers/write_property.php on line 16
string(5) "fruit"