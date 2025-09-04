<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo;

/**
 * Matrix is used throughout cairo to convert between different coordinate
 * spaces. A Matrix holds an affine transformation, such as a scale, rotation,
 * shear, or a combination of these.
 */
class Matrix
{
    public int $xx;
    public int $yx;
    public int $xy;
    public int $yy;
    public int $x0;
    public int $y0;

    public function __construct(
        float $xx = 1.0,
        float $yx = 0.0,
        float $xy = 0.0,
        float $yy = 1.0,
        float $x0 = 0.0,
        float $y0 = 0.0,
    ) {}

    public static function initIdentity(): Matrix {}

    public static function initTranslate(float $tx, float $ty): Matrix {}

    public static function initScale(float $sx, float $sy): Matrix {}

    public static function initRotate(float $radians): Matrix {}

    public static function multiply(Matrix $a, Matrix $b): Matrix {}

    public function translate(float $tx, float $ty): void {}

    public function scale(float $sx, float $sy): void {}

    public function rotate(float $radians): void {}

    public function invert(): void {}

    /**
     * @return array{"x": float, "y": float}
     * // TODO: return Vector Class
     */
    public function transformDistance(float $dx, float $dy): array {}

    /**
     * @return array{"x": float, "y": float}
     * // TODO: return Point Class
     */
    public function transformPoint(float $x, float $y): array {}
}
