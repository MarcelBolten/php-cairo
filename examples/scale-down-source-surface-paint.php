<?php

use Cairo\Context;
use Cairo\Filter;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$surface = new Image(ImageFormat::ARGB32, 6, 6);
$context = new Context($surface);

$data = '';

for ($i = 0; $i < 2; $i++)
{
	$data .= chr(0xff);
	$data .= chr(0xff);
	$data .= chr(0xff);
	$data .= chr(0xff);

	$data .= chr(0xff);
	$data .= chr(0xff);
	$data .= chr(0xff);
	$data .= chr(0xff);

	$data .= chr(0x00);
	$data .= chr(0x00);
	$data .= chr(0xff);
	$data .= chr(0xff);

	$data .= chr(0x00);
	$data .= chr(0x00);
	$data .= chr(0xff);
	$data .= chr(0xff);
}

for ($i = 0; $i < 2; $i++)
{
	$data .= chr(0x00);
	$data .= chr(0xff);
	$data .= chr(0x00);
	$data .= chr(0xff);

	$data .= chr(0x00);
	$data .= chr(0xff);
	$data .= chr(0x00);
	$data .= chr(0xff);

	$data .= chr(0xff);
	$data .= chr(0x00);
	$data .= chr(0x00);
	$data .= chr(0xff);

	$data .= chr(0xff);
	$data .= chr(0x00);
	$data .= chr(0x00);
	$data .= chr(0xff);
}

$context->setSourceRgba(0, 0, 0);
$context->paint();

$s = new Image(ImageFormat::ARGB32, 100, 100);
$s->createForData($data, ImageFormat::RGB24, 4, 4);
$context->scale(0.5, 0.5);
$context->setSurface($s, 4, 4);
$pat = $context->getPattern();
$pat->setFilter(Filter::Nearest);
$context->paint();

$surface->writeToPng(dirname(__FILE__).'/scale-down-source-surface-paint-php.png');
