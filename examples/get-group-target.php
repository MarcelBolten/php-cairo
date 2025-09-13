<?php

use Cairo\Context;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$surface = new Image(ImageFormat::ARGB32, 8, 8);
$context = new Context($surface);
$context->save();
$context->setSourceRgba(0, 0, 1);
$context->paint();

$context->rectangle(2, 2, 4, 4);
$context->clip();
$context->setSourceRgba(1, 0, 0);
$context->paint();
$context->restore();
$context->pushGroup();

$s = $context->getGroupSurface();

$context->setSourceRgba(0, 1, 0);
$context->fill();
$off = $s->getDeviceOffset();
$te = $off['x'];

echo $te . PHP_EOL;

$context->rectangle(2, 2, 4, 4);
$context->fill();
$context->popGroupToSource();
$context->paint();

$surface->writeToPng(dirname(__FILE__).'/get-group-target-php.png');
