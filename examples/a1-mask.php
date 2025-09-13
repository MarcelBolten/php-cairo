<?php

use Cairo\Context;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$width = 10;
$height = 8;
$string = '';

$surface = new Image(ImageFormat::ARGB32, $width, $height);
$context = new Context($surface);

$s = new Image(ImageFormat::A1, $width, $height);
$stride = $s->getStride();

echo 'Stride: ' . $stride . PHP_EOL;

for ($i = 0; $i < $height; $i++)
{
	$string .= chr(0x14);
	$string .= chr(0xAA);
}

echo $string . PHP_EOL;

$s->createForData($string, ImageFormat::A1, $width, $height);

$context->setSourceRgba(0, 0, 1);
$context->paint();
$context->setSourceRgba(1, 0, 0);
$context->maskSurface($s, 0, 0);

$surface->writeToPng(dirname(__FILE__).'/a1-mask-php.png');
