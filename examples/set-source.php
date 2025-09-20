<?php

use Cairo\Context;
use Cairo\Extend;
use Cairo\Pattern\Surface as PatternSurface;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$surface = new Image(ImageFormat::ARGB32, 5, 5);
$context = new Context($surface);

$color = chr(0x4c) . chr(0x33) . chr(0x19) . chr(0x80);

$s = Image::createForData($color, ImageFormat::ARGB32, 1, 1);

$pat = new PatternSurface($s);
$pat->setExtend(Extend::Repeat);

for ($i = 0; $i < 5; $i++) {
	switch ($i) {
		case 0:
			$context->setSourceRgba(.6, .7, .8);
			break;
		case 1:
			$context->setSourceRgba(.2, .4, .6, .5);
			break;
		case 2:
			$context->setSourceRgba(.2, .4, .6, .5);
			break;
		default:
			$context->setPattern($pat);
	}

	$context->rectangle($i, 0, 1, 5);
	$context->fill();
}

$surface->writeToPng(dirname(__FILE__).'/set-source-php.png');
