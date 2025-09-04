--TEST--
Cairo\Surface\Pdf->setCustomMetadata() method
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
use Cairo\Exception;

$surface = new Cairo\Surface\Pdf(NULL, 50, 50);
var_dump($surface);

$surface->setCustomMetadata("ISBN", "978-0123456789");

/* Wrong number args 0 */
try {
    $surface->setCustomMetadata();
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong number args 3 */
try {
    $surface->setCustomMetadata("foo", "bar", "baz");
} catch (ArgumentCountError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 1 */
try {
    $surface->setCustomMetadata([], "bla");
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

/* Wrong arg type 2 */
try {
    $surface->setCustomMetadata("foo", []);
} catch (TypeError $e) {
    echo $e->getMessage(), PHP_EOL;
}

try {
    $surface->setCustomMetadata("Title", "A title");
} catch (ValueError $e) {
    echo $e->getMessage(), PHP_EOL;
}
--EXPECTF--
object(Cairo\Surface\Pdf)#%d (0) {
}
Cairo\Surface\Pdf::setCustomMetadata() expects exactly 2 arguments, 0 given
Cairo\Surface\Pdf::setCustomMetadata() expects exactly 2 arguments, 3 given
Cairo\Surface\Pdf::setCustomMetadata(): Argument #1 ($field) must be of type string, array given
Cairo\Surface\Pdf::setCustomMetadata(): Argument #2 ($value) must be of type string, array given
Cairo\Surface\Pdf::setCustomMetadata(): Argument #1 ($field) may be any string except for the following names reserved by PDF: Title, Author, Subject, Keywords, Creator, Producer, CreationDate, ModDate, Trapped.
