--TEST--
Cairo::versionString() method
--SKIPIF--
<?php
if(!extension_loaded('cairo')) die('skip - Cairo extension not available');
--FILE--
<?php
namespace Cairo;
$version = version_string();
var_dump($version);

$version = Cairo::versionString();
var_dump($version);

/* Wrong number args */
try {
    version_string('foo');
    //trigger_error('Cairo::versionString should take no arguments');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args */
try {
    Cairo::versionString('foo');
    //trigger_error('Cairo::versionString should take no arguments');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
string(%d) %s
string(%d) %s
Cairo\version_string() expects exactly 0 arguments, 1 given
Cairo\Cairo::versionString() expects exactly 0 arguments, 1 given
