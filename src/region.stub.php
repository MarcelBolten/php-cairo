<?php

/** @generate-class-entries */

namespace Cairo
{
    class Region
    {
        /**
         * @param null|Rectangle|Rectangle[] $rects
         */
        public function __construct(null|Rectangle|array $rectangles = NULL) {}

        public function getStatus(): Status {}

        public function getExtents(): Rectangle {}

        public function getNumRectangles(): int {}

        public function getRectangle(): Rectangle|false {}

        public function isEmpty(): bool {}

        public function containsPoint(int $x, int $y): bool {}

        public function containsRectangle(Rectangle $rectangle): Region\Overlap {}

        public function equal(null|Region $region): bool {}

        public function translate(float $dx, float $dy): void {}

        public function intersect(Region $region): Status {}

        public function intersectRectangle(Rectangle $rectangle): Status {}

        public function subtract(Region $region): Status {}

        public function subtractRectangle(Rectangle $rectangle): Status {}

        public function union(Rectangle $rectangle): Status {}

        public function unionRectangle(Rectangle $rectangle): Status {}

        public function xor(Region $region): Status {}

        public function xorRectangle(Rectangle $rectangle): Status {}
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
        /** @cvalue CAIRO_REGION_OVERLAP_PARTIAL */
        case Partial = UNKNOWN;
    }
}