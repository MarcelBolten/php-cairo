<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo\Surface;

class Recording extends \Cairo\Surface
{
    public function __construct(
        Content $content,
        null|\Cairo\Rectangle $extents = null
    ) {}

    public function inkExtents(): \Cairo\Rectangle {}

    public function getExtents(): \Cairo\Rectangle|false {}
}
