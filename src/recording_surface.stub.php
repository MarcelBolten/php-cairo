<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo\Surface
{
    class Recording extends \Cairo\Surface
    {
        /**
         * @param Content $content
         * @param null|array{x: float, y: float, width: float, height: float} $extends
         */
        public function __construct(
            Content $content,
            null|array $extents = null
        ) {}

        /**
         * @return array{x: float, y: float, width: float, height: float}
         */
        public function inkExtents(): array {}

        public function getExtents(): \Cairo\Rectangle|false {}
    }
}
