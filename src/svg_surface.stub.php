<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo\Surface
{
    class Svg extends \Cairo\Surface
    {
        /**
         * @param null|string|resource $file
         */
        public function __construct(
            $file,
            float $width,
            float $height
        ) {}

        public function restrictToVersion(
            Svg\Version $version
        ): void {}

        public static function versionToString(
            Svg\Version $version
        ): string {}

        /**
         * @return Svg\Version[]
         */
        public static function getVersions(): array {}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
        public function setDocumentUnit(
            Svg\Unit $unit
        ): void {}

        public function getDocumentUnit(): Svg\Unit {}
#endif
    }
}

namespace Cairo\Surface\Svg
{
    enum Version: int
    {
        /** @cvalue CAIRO_SVG_VERSION_1_1 */
        case Version_1_1 = UNKNOWN;

        /** @cvalue CAIRO_SVG_VERSION_1_2 */
        case Version_1_2 = UNKNOWN;
    }

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    enum Unit: int
    {
        /** @cvalue CAIRO_SVG_UNIT_USER */
        case User = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_EM */
        case EM = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_EX */
        case EX = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_PX */
        case PX = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_IN */
        case IN = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_CM */
        case CM = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_MM */
        case MM = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_PT */
        case PT = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_PC */
        case PC = UNKNOWN;

        /** @cvalue CAIRO_SVG_UNIT_PERCENT */
        case Percent = UNKNOWN;
    }
#endif
}
