<?php

use Cairo\Context;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$width = 8;
$height = 8;
$string = '';

$surface = new Image(ImageFormat::ARGB32, $width, $height);
$context = new Context($surface);

$stride = ImageFormat::strideForWidth(ImageFormat::A8, $width);

assert($stride === 8);

$string .= chr(0);
$string .= chr(0);
$string .= chr(255);
$string .= chr(0);
$string .= chr(255);
$string .= chr(0);
$string .= chr(0);
$string .= chr(0);

$string = str_repeat($string, $height);

$mask = Image::createForData($string, ImageFormat::A8, $width, $height);

$context->setSourceRgba(0, 0, 1);
$context->paint();
$context->setSourceRgba(1, 0, 0);
$context->maskSurface($mask, 0, 0);

$surface->writeToPng(dirname(__FILE__).'/a8-mask-php.png');
