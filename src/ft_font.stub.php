<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo\FontFace;

class Ft extends \Cairo\FontFace
{
    /**
     * @var int
     * @cvalue CAIRO_FT_SYNTHESIZE_BOLD
     */
    public const SYNTHESIZE_BOLD = UNKNOWN;

    /**
     * @var int
     * @cvalue CAIRO_FT_SYNTHESIZE_OBLIQUE
     */
    public const SYNTHESIZE_OBLIQUE = UNKNOWN;

    /**
     * @param string|resource $stream
     */
    public function __construct(
        $stream,
        int $flags = 0,
    ) {}

    public function getSynthesize(): int {}

    public function setSynthesize(int $synthFlags): void {}

    public function unsetSynthesize(int $synthFlags): void {}
}
