<?php

use Cairo\Context;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$redmask = 0x5;
$greenmask = 0x50;

$surface = new Image(ImageFormat::ARGB32, 20, 20);
$context = new Context($surface);
$context->setSourceRgba(0, 0, 1);
$context->paint();

$s = new Image(ImageFormat::A1, 6400, 20);
$height = $s->getHeight();
$width = $s->getWidth();

$data = '';
for ($y = 0; $y < $height; $y++) {
	for ($x = 0; $x < ($width + 7) / 8; $x++) {
		$data .= chr(5);
	}
}

$s = Image::createForData($data, ImageFormat::A1, $width, $height);
$context->setSourceRgba(1, 0, 0);
$context->maskSurface($s);
$context->fill();

$s = new Image(ImageFormat::A1, 20, 6400);
$height = $s->getHeight();
$width = $s->getWidth();

$data = '';
for ($y = 0; $y < $height; $y++) {
	for ($x = 0; $x < ($width + 7) / 8; $x++) {
		$data = $data.chr(80);
	}
}

$s = Image::createForData($data, ImageFormat::A1, $width, $height);
$context->setSourceRgba(0, 1, 0);
$context->maskSurface($s, 0, 0);

$surface->writeToPng(dirname(__FILE__).'/large-source-php.png');
