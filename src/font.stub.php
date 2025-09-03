<?php

/** @generate-class-entries */

namespace Cairo\FontFace
{
    class Toy extends FontFace
    {
        public function __construct(
            string $family,
            \Cairo\FontSlant $slant = \Cairo\FontSlant::Normal,
            \Cairo\FontWeight $weight = \Cairo\FontWeight::Normal,
        ) {}

        public function getFamily(): string {}

        public function getSlant(): \Cairo\FontSlant {}

        public function getWeight(): \Cairo\FontWeight {}
    }
}

namespace Cairo
{
    enum FontSlant: int
    {
        /** @cvalue CAIRO_FONT_SLANT_NORMAL */
        case Normal = UNKNOWN;

        /** @cvalue CAIRO_FONT_SLANT_ITALIC */
        case Italic = UNKNOWN;

        /** @cvalue CAIRO_FONT_SLANT_OBLIQUE */
        case Oblique = UNKNOWN;
    }

    enum FontWeight: int
    {
        // workaround as cases cannot be assigned a value via @cvalue directly for now
        /** @cvalue CAIRO_FONT_WEIGHT_NORMAL */
        case Normal = UNKNOWN;

        /** @cvalue CAIRO_FONT_WEIGHT_BOLD */
        case Bold = UNKNOWN;
    }
}
