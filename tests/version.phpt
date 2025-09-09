--TEST--
Cairo\version()
--SKIPIF--
<?php
include __DIR__ . '/skipif.inc';
--FILE--
<?php
namespace Cairo;
$version = version();
var_dump($version);

try {
    version('foo');
} catch (\ArgumentCountError $e) {
    echo $e->getMessage();
}
--EXPECTF--
int(%d)
Cairo\version() expects exactly 0 arguments, 1 given
