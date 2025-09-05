<?php
if(class_exists('\Cairo\FontFace\Toy')) {
    $fontface = new \Cairo\FontFace\Toy('sans-serif', \Cairo\FontSlant::Normal, \Cairo\FontWeight::Normal);
} else {
    $surface = new Cairo\Surface\Image(Cairo\Surface\ImageFormat::ARGB32, 50, 50);
    $context = new Cairo\Context($surface);
    $context->selectFontFace('sans-serif');
    $fontface = $context->getFontFace();
    unset($surface);
}
