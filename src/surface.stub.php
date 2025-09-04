<?php

/** @generate-class-entries */

namespace Cairo
{
    abstract class Surface
    {
        /**
         * @throws \Cairo\Exception
         */
        public function __construct() {}

        public function createSimilar(
            Surface\Content $content,
            float $width,
            float $height
        ): Surface {}

        public function createSimilarImage(
            Surface\ImageFormat $format,
            float $width,
            float $height
        ): Surface {}

        public function createForRectangle(
            float $x,
            float $y,
            float $width,
            float $height
        ): Surface {}

        public function getStatus(): Status {}

        public function finish(): void {}

        public function flush(): void {}

        public function getFontOptions(): FontOptions {}

        public function getContent(): Surface\Content {}

        public function markDirty(): void {}

        public function markDirtyRectangle(
            int $x,
            int $y,
            int $width,
            int $height
        ): void {}

        public function setDeviceOffset(
            float $x,
            float $y
        ): void {}

        /**
         * @return array{x: float, y: float}
         */
        public function getDeviceOffset(): array {}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 14, 0)
        public function setDeviceScale(
            float $x,
            float $y
        ): void {}

        /**
         * @return array{x: float, y: float}
         */
        public function getDeviceScale(): array {}
#endif

        public function setFallbackResolution(
            float $x,
            float $y
        ): void {}

        /**
         * @return array{x: float, y: float}
         */
        public function getFallbackResolution(): array {}

        public function getType(): Surface\Type {}

        public function showPage(): void {}

        public function copyPage(): void {}

        public function hasShowTextGlyphs(): bool {}

        public function mapToImage(
            null|Rectangle $rectangle = NULL
        ): Surface\Image {}

        /**
         * $surface must be a surface created by mapToImage() or the behavior is undefined.
         */
        public function unmapImage(
            Surface\Image $surface
        ): void {}

#ifdef CAIRO_HAS_PNG_FUNCTIONS
        /**
         * @param string|resource $file
         */
        public function writeToPng(
            $file
        ): void {}
#endif

#ifdef CAIRO_HAS_JPEG_FUNCTIONS
        /**
         * @param string|resource $file
         */
        public function writeToJpeg(
            $file,
            int $quality = 90
        ): void {}
#endif
    }
}

namespace Cairo\Surface
{
    enum Content: int
    {
        /** @cvalue CAIRO_CONTENT_COLOR */
        case Color = UNKNOWN;

        /** @cvalue CAIRO_CONTENT_ALPHA */
        case Alpha = UNKNOWN;

        /** @cvalue CAIRO_CONTENT_COLOR_ALPHA */
        case ColorAlpha = UNKNOWN;
    }

    enum Type: int
    {
        /** @cvalue CAIRO_SURFACE_TYPE_IMAGE */
        case Image = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_PDF */
        case PDF = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_PS */
        case PS = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_XLIB */
        case Xlib = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_XCB */
        case Xcb = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_GLITZ
         */
        case Glitz = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_QUARTZ */
        case Quartz = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_WIN32 */
        case Win32 = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_BEOS
         */
        case BeOS = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_DIRECTFB
         */
        case DirectFB = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_SVG */
        case SVG = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_OS2
         */
        case OS2 = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_WIN32_PRINTING */
        case Win32Printing = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_QUARTZ_IMAGE */
        case QuartzImage = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_SCRIPT */
        case Script = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_QT
         */
        case QT = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_RECORDING */
        case Recording = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_VG
         */
        case VG = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_GL
         */
        case GL = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_DRM
         */
        case DRM = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_TEE */
        case Tee = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_XML */
        case XML = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_SKIA
         */
        case Skia = UNKNOWN;

        /** @cvalue CAIRO_SURFACE_TYPE_SUBSURFACE */
        case Subsurface = UNKNOWN;

        /**
         * @deprecated as of version 1.18
         * @cvalue CAIRO_SURFACE_TYPE_COGL
         */
        case COGL = UNKNOWN;
    }
}
