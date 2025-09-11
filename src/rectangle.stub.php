<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo;

// Todo: Make properties read-only in PHP 8.1+
// Todo: Make class final
class Rectangle
{
    public float $x = 0;

    public float $y = 0;

    public float $width = 0;

    public float $height = 0;

    public function __construct(
        float $x = 0,
        float $y = 0,
        float $width = 0,
        float $height = 0,
    ) {}
}
