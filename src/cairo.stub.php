<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo;

/**
 * @var int
 * @cvalue CAIRO_VERSION */
const VERSION = UNKNOWN;

/**
 * @var string
 * @cvalue CAIRO_VERSION_STRING */
const VERSION_STRING = UNKNOWN;

abstract class Cairo
{
    public static function version(): int {}

    public static function versionString(): string {}

    public static function availableSurfaces(): array {}

    public static function availableFonts(): array {}
}

function version(): int {}

function version_string(): string {}
