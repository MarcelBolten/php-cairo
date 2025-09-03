<?php

/** @generate-class-entries */

namespace Cairo
{
    class ScaledFont
    {
        public function __construct(
            FontFace $font_face,
            Matrix $matrix,
            Matrix $ctm,
            FontOptions $options
        ) {}

        public function getStatus(): Status {}

        /**
         * @return array{ascent: float, descent: float, height: float, max_x_advance: float, max_y_advance: float}
         */
        public function getExtents(): array {}

        /**
         * @return array{x_bearing: float, y_bearing: float, width: float, height: float, x_advance: float, y_advance: float}
         */
        public function getTextExtents(): array {}

        /**
         * @return array{x_bearing: float, y_bearing: float, width: float, height: float, x_advance: float, y_advance: float}
         */
        public function getGlyphExtents(): array {}

        public function getFontFace(): FontFace {}

        public function getFontOptions(): FontOptions {}

        public function getFontMatrix(): Matrix {}

        public function getCtm(): Matrix {}

        public function getScaleMatrix(): Matrix {}

        public function getType(): FontType {}
    }
}
