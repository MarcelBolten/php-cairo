<?php

use Cairo\Antialias;
use Cairo\Context;
use Cairo\Filter;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$points = 10;
$step = 1.0 / $points;
$pad = 1;
$width = ($pad + ($points * 2) + $pad);
$height = $width;

$surface = new Image(ImageFormat::ARGB32, $width, $height);
$context = new Context($surface);
$context->setSourceRgba(1, 1, 1);
$context->paint();
$context->setSourceRgba(0, 0, 0);
// $context->translate($pad, $pad);
$context->setAntialias(Antialias::None);

$s = new Image(ImageFormat::ARGB32, 1, 1);
$c = new Context($s);
$c->setSourceRgba(0, 0, 0);
$c->paint();

for ($x = 0; $x < $points; $x++) {
	for ($y = 0; $y < $points; $y++) {
		$tx = round((2 + $step) * $x + $pad);
		$ty = round((2 + $step) * $y + $pad);

		$context->setSurface($s, $tx, $ty);
		$source = $context->getPattern();
		$source->setFilter(Filter::Nearest);
		$context->paint();
	}
}

$surface->writeToPng(dirname(__FILE__).'/a1-image-sample-php.png');
