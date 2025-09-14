<?php

use Cairo\Context;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$width = 10;
$height = 8;
$string = '';

$surface = new Image(ImageFormat::ARGB32, $width, $height);
$context = new Context($surface);

$stride = ImageFormat::strideForWidth(ImageFormat::A1, $width);
assert($stride === 4);

$string .= chr(0x14); // 00101000 opaque pixels: 3, 5
$string .= chr(0x02); // 01000000 opaque pixels: 10
$string .= chr(0x00); // padding byte for 4-byte alignment
$string .= chr(0x00); // padding byte for 4-byte alignment

$string = str_repeat($string, $height);

$mask = Image::createForData($string, ImageFormat::A1, $width, $height);

$context->setSourceRgba(0, 0, 1);
$context->paint();
$context->setSourceRgba(1, 0, 0);
$context->maskSurface($mask, 0, 0);

$surface->writeToPng(dirname(__FILE__).'/a1-mask-php.png');
