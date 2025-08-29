<?php

use Cairo\Context;
use Cairo\Surface\Pdf;

function drawPattern($surface, $size)
{
	$halfSize = $size / 2;
	$context = new Context($surface);
	// white
	$context->setSourceRgb(1, 1, 1);
	$context->rectangle(0, 0, $halfSize, $halfSize);
	$context->fill();
	// red
	$context->setSourceRgb(1, 0, 0);
	$context->rectangle($halfSize, 0, $halfSize, $halfSize);
	$context->fill();
	// green
	$context->setSourceRgb(0, 1, 0);
	$context->rectangle(0, $halfSize, $halfSize, $halfSize);
	$context->fill();
	// blue
	$context->setSourceRgb(0, 0, 1);
	$context->rectangle($halfSize, $halfSize, $halfSize, $halfSize);
	$context->fill();
}

$size = 90;
$surface = new Pdf('pdf-surface-source.pdf', $size, $size);
$surface->setFallbackResolution(72, 72);
$context = new Context($surface);
$context->setSourceRgb(0, 0, 0);
$context->paint();

$surfaceSize = $size - 30;
$s = new Pdf('temp.pdf', $surfaceSize, $surfaceSize);
drawPattern($s, $surfaceSize);
$s->writeToPng(dirname(__FILE__).'/temp.png');
$context->setSurface($s, 15.0, 15.0);
$context->paint();

$surface->writeToPng(dirname(__FILE__).'/pdf-surface-source-php.png');
