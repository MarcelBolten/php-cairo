--TEST--
Cairo\Rectangle write_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
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
--EXPECT--
float(1)
float(2)
float(3)
float(4)

