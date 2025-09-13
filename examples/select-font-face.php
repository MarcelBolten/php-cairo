<?php

use Cairo\Context;
use Cairo\FontSlant;
use Cairo\FontWeight;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;


$textSize = 12;
$surface = new Image(ImageFormat::ARGB32, 192, 16);
$context = new Context($surface);

$context->save();
$context->setSourceRgba(1, 1, 1); /* white */
$context->paint();
$context->restore();

$context->setSourceRgba(0, 0, 0); /* black */
$context->selectFontFace('Bitstream Vera Serif', FontSlant::Normal, FontWeight::Normal);
$context->setFontSize($textSize);

$context->moveTo(0, $textSize);
$context->showText('i-am-serif');

$context->selectFontFace('Bitstream Vera Sans', FontSlant::Normal, FontWeight::Normal);
$context->showText(' i-am-sans');

$context->selectFontFace('Bitstream Vera Sans Mono', FontSlant::Normal, FontWeight::Normal);
$context->showText(' i-am-mono');

$surface->writeToPng(dirname(__FILE__).'/select-font-face-php.png');
