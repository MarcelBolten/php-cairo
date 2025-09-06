--TEST--
Cairo\version_string()
--SKIPIF--
<?php
include __DIR__ . '/skipif.inc';
--FILE--
<?php
namespace Cairo;
$version = version_string();
var_dump($version);

try {
    version_string('foo');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage() . PHP_EOL;
}
--EXPECTF--
string(%d) "%d.%d.%d"
Cairo\version_string() expects exactly 0 arguments, 1 given
