--TEST--
Cairo\Surface\Svg::getDocumentUnit() method
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
if (!method_exists('\Cairo\Surface\Svg', 'getDocumentUnit'))
    die('skip - Cairo\Surface\Svg->getDocumentUnit not available');
--FILE--
<?php
$surface = new Cairo\Surface\Svg(NULL, 50, 50);
var_dump($surface->getDocumentUnit());


/* Wrong number args */
try {
    $surface->getDocumentUnit('foo');
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
enum(Cairo\Surface\Svg\Unit::User)
Cairo\Surface\Svg::getDocumentUnit() expects exactly 0 arguments, 1 given
