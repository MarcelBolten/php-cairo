--TEST--
Cairo\HintStyle enum
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
--FILE--
<?php
use Cairo\HintStyle;

var_dump(HintStyle::cases());
--EXPECT--
array(5) {
  [0]=>
  enum(Cairo\HintStyle::Default)
  [1]=>
  enum(Cairo\HintStyle::None)
  [2]=>
  enum(Cairo\HintStyle::Slight)
  [3]=>
  enum(Cairo\HintStyle::Medium)
  [4]=>
  enum(Cairo\HintStyle::Full)
}
