<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo\Surface
{
    class Ps Extends \Cairo\Surface
    {
        /**
         * @param null|string|resource $file
         */
        public function __construct(
            $file,
            float $width,
            float $height
        ) {}

        public function setSize(
            float $width,
            float $height
        ): void {}

        public function restrictToLevel(
            Ps\Level $level = Ps\Level::Level_2
        ): void {}

        public static function getLevels(): array {}

        public static function levelToString(
            Ps\Level $level
        ): string {}

        public function setEps(
            bool $eps
        ): void {}

        public function getEps(): bool {}

        public function dscBeginSetup(): void {}

        public function dscBeginPageSetup(): void {}

        public function dscComment(
            string $comment
        ): void {}
    }
}

namespace Cairo\Surface\Ps
{
    enum Level: int
    {
        /** @cvalue CAIRO_PS_LEVEL_2 */
        case Level_2 = UNKNOWN;

        /** @cvalue CAIRO_PS_LEVEL_3 */
        case Level_3 = UNKNOWN;
    }
}
