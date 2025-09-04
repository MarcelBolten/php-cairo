<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo
{
    class Path {}
}

namespace Cairo\Path
{
    enum DataType: int {
        /** @cvalue CAIRO_PATH_MOVE_TO */
        case MoveTo = UNKNOWN;

        /** @cvalue CAIRO_PATH_LINE_TO */
        case LineTo = UNKNOWN;

        /** @cvalue CAIRO_PATH_CURVE_TO */
        case CurveTo = UNKNOWN;

        /** @cvalue CAIRO_PATH_CLOSE_PATH */
        case ClosePath = UNKNOWN;
    }
}