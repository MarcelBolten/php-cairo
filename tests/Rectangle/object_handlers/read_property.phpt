--TEST--
Cairo\Rectangle read_property handler
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
--FILE--
<?php
use Cairo\Rectangle;

$rect = new Rectangle(1, 2, 3, 4);

var_dump($rect->x);
var_dump($rect->y);
var_dump($rect->width);
var_dump($rect->height);
--EXPECT--
float(1)
float(2)
float(3)
float(4)
