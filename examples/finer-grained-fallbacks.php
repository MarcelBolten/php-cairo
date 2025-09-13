<?php

use Cairo\Context;
use Cairo\Operator;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$cisize = 10;
$pad = 2;
$width = $cisize * 6.5 + $pad;
$height = $cisize * 3.5 + $pad;

function drawCircle($context, $cisize, $x, $y)
{
	$context->save();
	$context->translate($x, $y);
	$context->arc(0, 0, $cisize / 2, 0, 2 * M_PI);
	$context->fill();
	$context->restore();
}

function drawCircles($context, $cisize)
{
	drawCircle($context, $cisize, 0, $cisize * -0.1);
	drawCircle($context, $cisize, $cisize * 0.4, $cisize * 0.25);
	drawCircle($context, $cisize, $cisize * 2, 0);
	drawCircle($context, $cisize, $cisize * 4, 0);
	drawCircle($context, $cisize, $cisize * 6, 0);
}

$surface = new Image(ImageFormat::ARGB32, $width, $height);
$context = new Context($surface);

$context->translate($pad, $pad);
$context->setSourceRgba(0, 1, 0);
$context->setOperator(Operator::Over);
drawCircle($context, $cisize, $cisize * 0.5, $cisize * 1.5);
$context->setSourceRgba(1, 0, 0);
$context->setOperator(Operator::Add);
drawCircle($context, $cisize, $cisize * 0.75, $cisize * 1.75);
$context->setSourceRgba(0, 1, 0);
$context->setOperator(Operator::Over);
$context->translate($cisize * 2.5, $cisize * 0.6);
drawCircles($context, $cisize);
$context->setSourceRgba(1, 0, 0);
$context->setOperator(Operator::Add);
$context->translate(0, $cisize * 2);
drawCircles($context, $cisize);

$surface->writeToPng(dirname(__FILE__).'/finer-grained-fallbacks-php.png');
