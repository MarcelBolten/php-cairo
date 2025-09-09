--TEST--
Cairo\Surface\Svg\Version class constants
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
use Cairo\Surface\Svg\Version as SvgVersion;
use Cairo\Surface\Svg\Unit as SvgUnit;

var_dump(SvgVersion::cases());
var_dump(SvgUnit::cases());

--EXPECTF--
array(2) {
  [0]=>
  enum(Cairo\Surface\Svg\Version::Version_1_1)
  [1]=>
  enum(Cairo\Surface\Svg\Version::Version_1_2)
}
array(10) {
  [0]=>
  enum(Cairo\Surface\Svg\Unit::User)
  [1]=>
  enum(Cairo\Surface\Svg\Unit::EM)
  [2]=>
  enum(Cairo\Surface\Svg\Unit::EX)
  [3]=>
  enum(Cairo\Surface\Svg\Unit::PX)
  [4]=>
  enum(Cairo\Surface\Svg\Unit::IN)
  [5]=>
  enum(Cairo\Surface\Svg\Unit::CM)
  [6]=>
  enum(Cairo\Surface\Svg\Unit::MM)
  [7]=>
  enum(Cairo\Surface\Svg\Unit::PT)
  [8]=>
  enum(Cairo\Surface\Svg\Unit::PC)
  [9]=>
  enum(Cairo\Surface\Svg\Unit::Percent)
}
