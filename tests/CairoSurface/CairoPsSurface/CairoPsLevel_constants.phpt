--TEST--
Cairo\Surface\Ps\Level class constants
--SKIPIF--
<?php
include __DIR__ . '/../../skipif.inc';
include __DIR__ . '/skipif.inc';
--FILE--
<?php
$constants = array(
	'Level_2',
	'Level_3',
);

$error = false;
foreach($constants as $name) {
	$constant = 'Cairo\Surface\Ps\Level::' . $name;
	if (!defined($constant)) {
		$error = true;
		echo 'Missing Constant: ' . $constant . "\n";
	}
}
if (!$error) {
	echo "No missing constants, checked " . sizeof($constants) . "!\n";
}
echo "Done\n";
--EXPECTF--
No missing constants, checked %d!
Done
