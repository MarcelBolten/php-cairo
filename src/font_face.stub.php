<?php

/** @generate-class-entries */

namespace Cairo;

abstract class FontFace {

    public function __construct() {}

    public function getStatus(): Status {}

    public function getType(): FontType {}
}

enum FontType: int
{
    /** @cvalue CAIRO_FONT_TYPE_TOY */
    case Toy = UNKNOWN;

    /** @cvalue CAIRO_FONT_TYPE_FT */
    case FT = UNKNOWN;

    /** @cvalue CAIRO_FONT_TYPE_WIN32 */
    case Win32 = UNKNOWN;

    /** @cvalue CAIRO_FONT_TYPE_QUARTZ */
    case Quartz = UNKNOWN;

    /** @cvalue CAIRO_FONT_TYPE_USER */
    case User = UNKNOWN;

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    /** @cvalue CAIRO_FONT_TYPE_DWRITE */
    case DWrite = UNKNOWN;
#endif
}
