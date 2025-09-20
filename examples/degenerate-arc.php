<?php

use Cairo\Context;
use Cairo\LineCap;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$surface = new Image(ImageFormat::ARGB32, 40, 40);
$context = new Context($surface);

$context->setSourceRgba(1, 1, 1);
$context->paint();
$context->setLineCap(LineCap::Round);
$context->setLineWidth(5);
$context->setSourceRgba(0, 1, 0);

for ($n = 0; $n < 8; $n++)
{
	$theta = $n * 2 * M_PI / 8;
	$context->newSubPath();
	$context->arc(20, 20, 15, $theta, $theta);
	$context->closePath();
}

$context->stroke();
$context->setLineWidth(2);
$context->setSourceRgba(0, 0, 1);

for ($n = 0; $n < 8; $n++)
{
	$theta = $n * 2 * M_PI / 8;
	$context->moveTo(20, 20);
	$context->arc(20, 20, 15, $theta, $theta);
	$context->closePath();
}

$context->stroke();
$context->setSourceRgba(1, 0, 0);
$context->arc(20, 20, 2, 0, 2 * M_PI);
$context->fill();

$surface->writeToPng(dirname(__FILE__).'/degenerate-arc-php.png');
