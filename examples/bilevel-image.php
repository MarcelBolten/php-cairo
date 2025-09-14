<?php

use Cairo\Context;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$width = 12;
$height = 4;
$string = '';

$surface = new Image(ImageFormat::ARGB32, $width, $height);
$context = new Context($surface);

$stride = ImageFormat::strideForWidth(ImageFormat::ARGB32, $width);

assert($stride === $width * 4);

$string .= chr(0x00); // blue
$string .= chr(0x00); // green
$string .= chr(0xff); // red
$string .= chr(0xff); // alpha

$string .= chr(0x00);
$string .= chr(0xff);
$string .= chr(0x00);
$string .= chr(0xff);

$string .= chr(0xff);
$string .= chr(0x00);
$string .= chr(0x00);
$string .= chr(0xff);

$string .= chr(0xff);
$string .= chr(0xff);
$string .= chr(0xff);
$string .= chr(0xff);

$string = str_repeat($string, 3 * $height);

$s = Image::createForData($string, ImageFormat::ARGB32, $width, $height);
$context->setSourceRgba(1, 1, 1);
$context->paint();

$context->setSurface($s, 0, 0);
$context->paint();

$surface->writeToPng(dirname(__FILE__).'/bilevel-image-php.png');
