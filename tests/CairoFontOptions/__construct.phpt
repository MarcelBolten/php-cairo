--TEST--
new Cairo\FontOptions [ __construct() method ]
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$options = new Cairo\FontOptions();
var_dump($options);

/* Wrong number args */
try {
    new Cairo\FontOptions('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\FontOptions)#%d (0) {
}
Cairo\FontOptions::__construct() expects exactly 0 %s, 1 given
