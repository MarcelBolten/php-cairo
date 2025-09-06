--TEST--
Cairo\FontWeight class constants
--SKIPIF--
<?php
include __DIR__ . '/../skipif.inc';
--FILE--
<?php
$constants = array(
	'Normal',
	'Bold',
	);

$error = false;
foreach($constants as $name) {
	if (!defined('Cairo\FontWeight::' . $name)) {
		$error = true;
		echo 'Missing Constant: Cairo\FontWeight::' . $name . "\n";
	}
}

if (!$error) {
	echo "No missing constants, checked " . sizeof($constants) . "!\n";
}
--EXPECT--
No missing constants, checked 2!
