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

try {
    $rect->banana = 'fruit';
}
catch (ErrorException $e) {
        if ($e->getSeverity() === E_DEPRECATED) {
            // ignore: Deprecated: Creation of dynamic property Cairo\Rectangle::$banana is deprecated
        } else {
            throw $e;
        }
}
try {
    var_dump($rect->banana);
}
catch (ErrorException $e) {
        if ($e->getSeverity() === E_DEPRECATED) {
            // ignore: Deprecated: Creation of dynamic property Cairo\Rectangle::$banana is deprecated
        } else {
            throw $e;
        }
}
--EXPECT--
int(1)
int(2)
int(3)
int(4)
string(5) "fruit"
