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
    public int $x = 0;

    public int $y = 0;

    public int $width = 0;

    public int $height = 0;

    public function __construct(
        int $x = 0,
        int $y = 0,
        int $width = 0,
        int $height = 0,
    ) {}
}
