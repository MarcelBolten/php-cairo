--TEST--
Cairo::version() method
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
namespace Cairo;
$version = version();
var_dump($version);

$version = Cairo::version();
var_dump($version);

/* Wrong number args */
try {
    version('foo');
    //trigger_error('Cairo\version should take no arguments');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args */
try {
    Cairo::version('foo');
    //trigger_error('Cairo::version should take no arguments');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
int(%d)
int(%d)
Cairo\version() expects exactly 0 arguments, 1 given
Cairo\Cairo::version() expects exactly 0 arguments, 1 given
