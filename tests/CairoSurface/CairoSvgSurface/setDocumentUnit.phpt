--TEST--
Cairo\Surface\Svg::setDocumentUnit() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
if (!in_array('SVG', Cairo::availableSurfaces())) {
    die('skip - SVG surface not available');
}
if (!method_exists('Cairo\Surface\Svg', 'getDocumentUnit')) {
    die('skip - Cairo\Surface\Svg->setDocumentUnit not available');
}
?>
--FILE--
<?php
$surface = new Cairo\Surface\Svg(NULL, 50, 50);

$surface->setDocumentUnit(Cairo\Surface\Svg\Unit::MM);
var_dump($surface->getDocumentUnit());


/* Wrong arg value */
try {
    $surface->setDocumentUnit(99);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type */
try {
    $surface->setDocumentUnit('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args */
try {
    $surface->setDocumentUnit('foo', 'bar');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECTF--
enum(Cairo\Surface\Svg\Unit::MM)
Cairo\Surface\Svg::setDocumentUnit(): Argument #1 ($unit) must be of type Cairo\Surface\Svg\Unit, int given
Cairo\Surface\Svg::setDocumentUnit(): Argument #1 ($unit) must be of type Cairo\Surface\Svg\Unit, string given
Cairo\Surface\Svg::setDocumentUnit() expects exactly 1 argument, 2 given