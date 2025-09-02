--TEST--
Cairo\Glyph->__construct()
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
use Cairo\TextCluster;
use TypeError as Exception;

$cluster = new TextCluster(1, 2);
var_dump($cluster);

/* Wrong number args - need 2 */
try {
    new TextCluster();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new TextCluster(1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    new TextCluster(1, 1, 1);
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 1 */
try {
    new TextCluster(array(), 1);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 2 */
try {
    new TextCluster(1, array());
} catch (Exception $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\TextCluster)#1 (2) {
  ["num_bytes"]=>
  int(1)
  ["num_glyphs"]=>
  int(2)
}
Cairo\TextCluster::__construct() expects exactly 2 arguments, 0 given
Cairo\TextCluster::__construct() expects exactly 2 arguments, 1 given
Cairo\TextCluster::__construct() expects exactly 2 arguments, 3 given
Cairo\TextCluster::__construct(): Argument #1 ($num_bytes) must be of type int, array given
Cairo\TextCluster::__construct(): Argument #2 ($num_glyphs) must be of type int, array given
