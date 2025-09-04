<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo
{
    abstract class Pattern
    {
        public function __construct() {}

        public function getType(): Pattern\Type {}

        public function getStatus(): Status {}

        public function getMatrix(): Matrix {}

        public function setMatrix(Matrix $matrix): void {}

        public function getExtend(): Extend {}

        public function setExtend(Extend $extend): void {}

        public function getFilter(): Filter {}

        public function setFilter(Filter $filter): void {}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
        public function getDither(): Dither {}

        public function setDither(Dither $dither): void {}
#endif
    }

    enum Extend: int
    {
        /** @value CAIRO_EXTEND_NONE */
        case None = UNKNOWN;

        /** @value CAIRO_EXTEND_REPEAT */
        case Repeat = UNKNOWN;

        /** @value CAIRO_EXTEND_REFLECT */
        case Reflect = UNKNOWN;

        /** @value CAIRO_EXTEND_PAD */
        case Pad = UNKNOWN;
    }

    enum Filter: int
    {
        /** @value CAIRO_FILTER_FAST */
        case Fast = UNKNOWN;

        /** @value CAIRO_FILTER_GOOD */
        case Good = UNKNOWN;

        /** @value CAIRO_FILTER_BEST */
        case Best = UNKNOWN;

        /** @value CAIRO_FILTER_NEAREST */
        case Nearest = UNKNOWN;

        /** @value CAIRO_FILTER_BILINEAR */
        case Bilinear = UNKNOWN;

        /** @value CAIRO_FILTER_GAUSSIAN */
        case Gaussian = UNKNOWN;
    }

    enum Dither: int
    {
        /** @value CAIRO_DITHER_NONE */
        case None = UNKNOWN;

        /** @value CAIRO_DITHER_DEFAULT */
        case Default = UNKNOWN;

        /** @value CAIRO_DITHER_FAST */
        case Fast = UNKNOWN;

        /** @value CAIRO_DITHER_GOOD */
        case Good = UNKNOWN;

        /** @value CAIRO_DITHER_BEST */
        case Best = UNKNOWN;
    }
}

namespace Cairo\Pattern
{
    class Solid extends \Cairo\Pattern
    {
        public function __construct(float $red, float $green, float $blue, float $alpha = 0) {}

        /**
         * @return array{red: float, green: float, blue: float, alpha: float}
         */
        public function getRgba(): array {}
    }

    abstract class Gradient extends \Cairo\Pattern
    {
        public function getColorStopCount(): int {}

        /**
         * @return array{red: float, green: float, blue: float, alpha: float}
         */
        public function getColorStopRgba(int $index): array {}

        public function addColorStopRgb(float $offset, float $red, float $green, float $blue): void {}

        public function addColorStopRgba(float $offset, float $red, float $green, float $blue, float $alpha): void {}
    }

    class Surface extends \Cairo\Pattern
    {
        public function __construct(\Cairo\Surface $surface) {}

        public function getSurface(): \Cairo\Surface {}
    }

    class Mesh extends \Cairo\Pattern
    {
        public function __construct() {}

        public function beginPatch(): void {}

        public function endPatch(): void {}

        public function moveTo(float $x, float $y): void {}

        public function lineTo(float $x, float $y): void {}

        public function curveTo(float $x1, float $y1, float $x2, float $y2, float $x3, float $y3): void {}

        public function setControlPoint(int $corner_num, float $x, float $y): void {}

        public function setCornerColorRgb(int $corner_num, float $red, float $green, float $blue): void {}

        public function setCornerColorRgba(int $corner_num, float $red, float $green, float $blue, float $alpha): void {}

        public function getPatchCount(): int {}

        public function getPath(int $patch_num): \Cairo\Path {}

        /**
         * @return array{x: float, y: float}
         */
        public function getControlPoint(int $patch_num, int $point_num): array {}

        /**
         * @return array{red: float, green: float, blue: float, alpha: float}
         */
        public function getCornerColorRgba(int $patch_num, int $corner_num): array {}
    }

    // Not implemented
    // abstract class RasterSource extends Pattern
    // {
    //     public abstract function __construct(
    //         \Cairo\Content $target,
    //         int $width,
    //         int $height
    //     ) {}

    //     public abstract function acquire(): void {}
    //     public abstract function release(): void {}
    //     public abstract function snapshot(): void {}
    //     public abstract function copy(): void {}
    //     public abstract function finish(): void {}
    // }

    enum Type: int
    {
        /**@cvlaue CAIRO_PATTERN_TYPE_SOLID */
        case Solid = UNKNOWN;

        /**@cvlaue CAIRO_PATTERN_TYPE_SURFACE */
        case Surface = UNKNOWN;

        /**@cvlaue CAIRO_PATTERN_TYPE_LINEAR */
        case Linear = UNKNOWN;

        /**@cvlaue CAIRO_PATTERN_TYPE_RADIAL */
        case Radial = UNKNOWN;

        /**@cvlaue CAIRO_PATTERN_TYPE_MESH */
        case Mesh = UNKNOWN;

        /**@cvlaue CAIRO_PATTERN_TYPE_RASTER_SOURCE */
        case RasterSource = UNKNOWN;
    }
}

namespace Cairo\Pattern\Gradient
{
    class Linear extends \Cairo\Pattern\Gradient
    {
        public function __construct(
            float $x0,
            float $y0,
            float $x1,
            float $y1,
        ) {}

        /**
         * @return array{x0: float, y0: float, x1: float, y1: float}
         */
        public function getPoints(): array {}
    }

    class Radial extends \Cairo\Pattern\Gradient
    {
        public function __construct(
            float $x0,
            float $y0,
            float $r0,
            float $x1,
            float $y1,
            float $r1,
        ) {}

        /**
         * @return array{x0: float, y0: float, r0: float, x1: float, y1: float, r1: float}
         */
        public function getCircles(): array {}
    }
}
