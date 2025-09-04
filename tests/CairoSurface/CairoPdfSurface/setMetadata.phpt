--TEST--
Cairo\Surface\Pdf->setMetadata() method
--SKIPIF--
<?php
if (!extension_loaded('cairo')) {
    die('skip - Cairo extension not available');
}
if (!in_array('PDF', Cairo::availableSurfaces())) {
    die('skip - PDF surface not available');
}
--FILE--
<?php
$surface = new Cairo\Surface\Pdf(NULL, 50, 50);
var_dump($surface);

$surface->setMetadata(\Cairo\Surface\Pdf\Metadata::Title, "blubber");
$surface->setMetadata(\Cairo\Surface\Pdf\Metadata::CreateDate, date("Y-m-d\TH:i:s"));
$surface->setMetadata(\Cairo\Surface\Pdf\Metadata::Author);

/* Wrong number args 0 */
try {
    $surface->setMetadata();
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args 3 */
try {
    $surface->setMetadata(\Cairo\Surface\Pdf\Metadata::Title, "bla", "bla");
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 1 */
try {
    $surface->setMetadata([], "bla");
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 2 */
try {
    $surface->setMetadata(\Cairo\Surface\Pdf\Metadata::Title, []);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Pdf)#%d (0) {
}
Cairo\Surface\Pdf::setMetadata() expects at least 1 argument, 0 given
Cairo\Surface\Pdf::setMetadata() expects at most 2 arguments, 3 given
Cairo\Surface\Pdf::setMetadata(): Argument #1 ($field) must be of type Cairo\Surface\Pdf\Metadata, array given
Cairo\Surface\Pdf::setMetadata(): Argument #2 ($value) must be of type string, array given
