<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo
{
    class Region
    {
        /**
         * @param null|Rectangle|Rectangle[] $rects
         */
        public function __construct(
            null|Rectangle|array $rectangles = NULL
        ) {}

        public function getStatus(): Status {}

        public function getExtents(): Rectangle {}

        public function getNumRectangles(): int {}

        /**
         * Returns the nth rectangle (zero-based) in the region or false if
         * the rectangle does not exist.
         */
        public function getRectangle(
            int $rectId
        ): Rectangle|false {}

        public function isEmpty(): bool {}

        public function containsPoint(
            int $x,
            int $y
        ): bool {}

        public function containsRectangle(
            Rectangle $rectangle
        ): Region\Overlap {}

        public function equal(
            null|Region $region
        ): bool {}

        public function translate(
            int $dx,
            int $dy
        ): void {}

        public function intersect(
            Region $region
        ): Status {}

        public function intersectRectangle(
            Rectangle $rectangle
        ): Status {}

        public function subtract(
            Region $region
        ): Status {}

        public function subtractRectangle(
            Rectangle $rectangle
        ): Status {}

        public function union(
            Region $region
        ): Status {}

        public function unionRectangle(
            Rectangle $rectangle
        ): Status {}

        public function xor(
            Region $region
        ): Status {}

        public function xorRectangle(
            Rectangle $rectangle
        ): Status {}
    }
}

namespace Cairo\Region
{
    enum Overlap: int
    {
        /** @cvalue CAIRO_REGION_OVERLAP_IN */
        case In = UNKNOWN;
        /** @cvalue CAIRO_REGION_OVERLAP_OUT */
        case Out = UNKNOWN;
        /** @cvalue CAIRO_REGION_OVERLAP_PART */
        case Partial = UNKNOWN;
    }
}