--TEST--
Cairo\HintMetrics enum
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
use Cairo\HintMetrics;

var_dump(HintMetrics::cases());
--EXPECT--
array(3) {
  [0]=>
  enum(Cairo\HintMetrics::Default)
  [1]=>
  enum(Cairo\HintMetrics::Off)
  [2]=>
  enum(Cairo\HintMetrics::On)
}
