<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo;

abstract class Cairo
{
    /**
     * @var int
     * @cvalue CAIRO_VERSION */
    public const VERSION = UNKNOWN;

    /**
     * @var string
     * @cvalue CAIRO_VERSION_STRING */
    public const VERSION_STRING = UNKNOWN;

    public static function version(): int {}

    public static function versionString(): string {}

    public static function availableSurfaces(): array {}

    public static function availableFonts(): array {}
}

function version(): int {}

function version_sting(): string {}
