--TEST--
Cairo\HintMetrics enum
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
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
