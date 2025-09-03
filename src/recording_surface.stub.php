<?php

/** @generate-class-entries */

namespace Cairo\Surface
{
    class Recording extends \Cairo\Surface
    {
        /**
         * @param Content $content
         * @param null|array{x: float, y: float, width: float, height: float} $extends
         */
        public function __construct(Content $content, null|array $extends = null) {}

        /**
         * @return array{x: float, y: float, width: float, height: float}
         */
        public function inkExtents(): array {}

        public function getExtents(): \Cairo\Rectangle | false {}
    }
}
