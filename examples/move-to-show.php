<?php

use Cairo\Context;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$surface = new Image(ImageFormat::RGB24, 2, 2);
$context = new Context($surface);

$c = array(
	chr(0xff) . chr(0xff) . chr(0xff) . chr(0xff),
	chr(0x00) . chr(0x00) . chr(0xff) . chr(0xff),
	chr(0x00) . chr(0xff) . chr(0x00) . chr(0xff),
	chr(0xff) . chr(0x00) . chr(0x00) . chr(0xff)
);

for ($i = 0; $i < 4; $i++) {
	$s = Image::createForData($c[$i], ImageFormat::RGB24, 1, 1);
	$context->setSurface($s, $i % 2, $i / 2);
	$context->paint();
}

$surface->writeToPng(dirname(__FILE__).'/move-to-show-php.png');
