<?php

/** @generate-class-entries */

namespace Cairo\Surface {

    class Image extends \Cairo\Surface
    {
        public function __construct(
            ImageFormat $format,
            int $width,
            int $height,
        ) {}

        public static function createForData(
            string $data,
            ImageFormat $format,
            int $width,
            int $height,
        ): Image {}

        public function getData(): string {}

        public function getFormat(): ImageFormat {}

        public function getWidth(): int {}

        public function getHeight(): int {}

        public function getStride(): int {}

        /** @param string|resource $file */
        public function createFromPng($file): Image {}

        /** @param string|resource $file */
        public function createFromJpeg($file): Image {}
    }

    enum ImageFormat: int
    {
        /** @cvalue CAIRO_FORMAT_ARGB32 */
        case ARGB32 = UNKNOWN;

        /** @cvalue CAIRO_FORMAT_RGB24 */
        case RGB24 = UNKNOWN;

        /** @cvalue CAIRO_FORMAT_A8 */
        case A8 = UNKNOWN;

        /** @cvalue CAIRO_FORMAT_A1 */
        case A1 = UNKNOWN;

        /** @cvalue CAIRO_FORMAT_RGB16_565 */
        case RGB16_565 = UNKNOWN;

        /** @cvalue CAIRO_FORMAT_RGB30 */
        case RGB30 = UNKNOWN;

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 17, 2)
        /** @cvalue CAIRO_FORMAT_RGBA128F */
        case RGBA128F = UNKNOWN;

        /** @cvalue CAIRO_FORMAT_RGB96F */
        case RGB96F = UNKNOWN;
#endif

        public static function strideForWidth(ImageFormat $format, int $width): int {}
    }
}
