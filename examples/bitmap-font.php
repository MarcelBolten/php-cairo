<?php

use Cairo\Context;
use Cairo\FontOptions;
use Cairo\HintMetrics;
use Cairo\HintStyle;
use Cairo\Surface\Image;
use Cairo\Surface\ImageFormat;

$width = 247;
$height = 26;

$surface = new Image(ImageFormat::ARGB32, $width, $height);
$context = new Context($surface);
$context->selectFontFace('6x13.pcf');
$context->setFontSize(11.5);

$fo = new FontOptions();
$fo->setHintMetrics(HintMetrics::On);

$context->setFontOptions($fo);
$fe = $context->getFontExtents();
$context->moveTo(1, $fe['ascent'] - 1);
$context->setSourceRgba(0, 0, 1);
$fo->setHintStyle(HintStyle::None);
$context->setFontOptions($fo);
$context->showText('the ');
$fo->setHintStyle(HintStyle::Slight);
$context->setFontOptions($fo);
$context->showText('quick ');
$fo->setHintStyle(HintStyle::Medium);
$context->setFontOptions($fo);
$context->showText('brown');
$fo->setHintStyle(HintStyle::Full);
$context->setFontOptions($fo);
$context->showText(' fox');

$context->textPath(' jumps over a lazy dog');
$context->fill();

$context->translate($width, $height);
$context->rotate(M_PI);

$context->moveTo(1, $fe['height'] - $fe['descent'] - 1);
$fo->setHintMetrics(HintMetrics::Off);
$fo->setHintStyle(HintStyle::None);
$context->setFontOptions($fo);
$context->showText('the ');
$fo->setHintStyle(HintStyle::Slight);
$context->setFontOptions($fo);
$context->showText('quick');
$fo->setHintStyle(HintStyle::Medium);
$context->setFontOptions($fo);
$context->showText(' brown');
$fo->setHintStyle(HintStyle::Full);
$context->setFontOptions($fo);
$context->showText(' fox');

$context->textPath(' jumps over');
$context->textPath(' a lazy dog');
$context->fill();
$surface->writeToPng(dirname(__FILE__).'/bitmap-font-php.png');
