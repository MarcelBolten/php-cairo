--TEST--
cairo extension class listing
--SKIPIF--
<?php
include __DIR__ . '/skipif.inc';
if (strtolower(PHP_OS_FAMILY) !== 'windows') {
    die('skip - This test is for Windows only');
}
--FILE--
<?php
$ext = new ReflectionExtension('cairo');
var_dump($ext->getClassNames());
--EXPECT--
array(64) {
  [0]=>
  string(11) "Cairo\Cairo"
  [1]=>
  string(13) "Cairo\Pattern"
  [2]=>
  string(19) "Cairo\Pattern\Solid"
  [3]=>
  string(22) "Cairo\Pattern\Gradient"
  [4]=>
  string(29) "Cairo\Pattern\Gradient\Radial"
  [5]=>
  string(29) "Cairo\Pattern\Gradient\Linear"
  [6]=>
  string(21) "Cairo\Pattern\Surface"
  [7]=>
  string(18) "Cairo\Pattern\Mesh"
  [8]=>
  string(18) "Cairo\Pattern\Type"
  [9]=>
  string(12) "Cairo\Extend"
  [10]=>
  string(12) "Cairo\Filter"
  [11]=>
  string(12) "Cairo\Dither"
  [12]=>
  string(15) "Cairo\Rectangle"
  [13]=>
  string(12) "Cairo\Matrix"
  [14]=>
  string(15) "Cairo\Exception"
  [15]=>
  string(12) "Cairo\Status"
  [16]=>
  string(12) "Cairo\Region"
  [17]=>
  string(20) "Cairo\Region\Overlap"
  [18]=>
  string(14) "Cairo\FontFace"
  [19]=>
  string(14) "Cairo\FontType"
  [20]=>
  string(18) "Cairo\FontFace\Toy"
  [21]=>
  string(15) "Cairo\FontSlant"
  [22]=>
  string(16) "Cairo\FontWeight"
  [23]=>
  string(17) "Cairo\FontOptions"
  [24]=>
  string(15) "Cairo\Antialias"
  [25]=>
  string(19) "Cairo\SubPixelOrder"
  [26]=>
  string(15) "Cairo\HintStyle"
  [27]=>
  string(17) "Cairo\HintMetrics"
  [28]=>
  string(15) "Cairo\ColorMode"
  [29]=>
  string(16) "Cairo\ScaledFont"
  [30]=>
  string(17) "Cairo\FontFace\Ft"
  [31]=>
  string(20) "Cairo\FontFace\Win32"
  [32]=>
  string(31) "Cairo\FontFace\Win32\FontWeight"
  [33]=>
  string(32) "Cairo\FontFace\Win32\FontCharset"
  [34]=>
  string(40) "Cairo\FontFace\Win32\FontOutputPrecision"
  [35]=>
  string(38) "Cairo\FontFace\Win32\FontClipPrecision"
  [36]=>
  string(32) "Cairo\FontFace\Win32\FontQuality"
  [37]=>
  string(30) "Cairo\FontFace\Win32\FontPitch"
  [38]=>
  string(31) "Cairo\FontFace\Win32\FontFamily"
  [39]=>
  string(13) "Cairo\Surface"
  [40]=>
  string(21) "Cairo\Surface\Content"
  [41]=>
  string(18) "Cairo\Surface\Type"
  [42]=>
  string(19) "Cairo\Surface\Image"
  [43]=>
  string(25) "Cairo\Surface\ImageFormat"
  [44]=>
  string(24) "Cairo\Surface\SubSurface"
  [45]=>
  string(23) "Cairo\Surface\Recording"
  [46]=>
  string(17) "Cairo\Surface\Pdf"
  [47]=>
  string(25) "Cairo\Surface\Pdf\Version"
  [48]=>
  string(30) "Cairo\Surface\Pdf\OutlineFlags"
  [49]=>
  string(26) "Cairo\Surface\Pdf\Metadata"
  [50]=>
  string(17) "Cairo\Surface\Svg"
  [51]=>
  string(25) "Cairo\Surface\Svg\Version"
  [52]=>
  string(22) "Cairo\Surface\Svg\Unit"
  [53]=>
  string(16) "Cairo\Surface\Ps"
  [54]=>
  string(22) "Cairo\Surface\Ps\Level"
  [55]=>
  string(10) "Cairo\Path"
  [56]=>
  string(19) "Cairo\Path\DataType"
  [57]=>
  string(13) "Cairo\Context"
  [58]=>
  string(14) "Cairo\FillRule"
  [59]=>
  string(13) "Cairo\LineCap"
  [60]=>
  string(14) "Cairo\LineJoin"
  [61]=>
  string(14) "Cairo\Operator"
  [62]=>
  string(11) "Cairo\Glyph"
  [63]=>
  string(17) "Cairo\TextCluster"
}
