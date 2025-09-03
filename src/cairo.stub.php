<?php

/** @generate-class-entries */

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

class Exception extends \Exception {}

function version(): int {}

function version_sting(): string {}

enum Status: int
{
    /** @cvalue CAIRO_STATUS_SUCCESS */
    case Success = UNKNOWN;

    /** @cvalue CAIRO_STATUS_NO_MEMORY */
    case NoMemory = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_RESTORE */
    case InvalidRestore = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_POP_GROUP */
    case InvalidPopGroup = UNKNOWN;

    /** @cvalue CAIRO_STATUS_NO_CURRENT_POINT */
    case NoCurrentPoint = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_MATRIX */
    case InvalidMatrix = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_STATUS */
    case InvalidStatus = UNKNOWN;

    /** @cvalue CAIRO_STATUS_NULL_POINTER */
    case NullPointer = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_STRING */
    case InvalidString = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_PATH_DATA */
    case InvalidPathData = UNKNOWN;

    /** @cvalue CAIRO_STATUS_READ_ERROR */
    case ReadError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_WRITE_ERROR */
    case WriteError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_SURFACE_FINISHED */
    case SurfaceFinished = UNKNOWN;

    /** @cvalue CAIRO_STATUS_SURFACE_TYPE_MISMATCH */
    case SurfaceTypeMismatch = UNKNOWN;

    /** @cvalue CAIRO_STATUS_PATTERN_TYPE_MISMATCH */
    case PatternTypeMismatch = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_CONTENT */
    case InvalidContent = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_FORMAT */
    case InvalidFormat = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_VISUAL */
    case InvalidVisual = UNKNOWN;

    /** @cvalue CAIRO_STATUS_FILE_NOT_FOUND */
    case FileNotFound = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_DASH */
    case InvalidDash = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_DSC_COMMENT */
    case InvalidDscComment = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_INDEX */
    case InvalidIndex = UNKNOWN;

    /** @cvalue CAIRO_STATUS_CLIP_NOT_REPRESENTABLE */
    case ClipNotRepresentable = UNKNOWN;

    /** @cvalue CAIRO_STATUS_TEMP_FILE_ERROR */
    case TempFileError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_STRIDE */
    case InvalidStride = UNKNOWN;

    /** @cvalue CAIRO_STATUS_FONT_TYPE_MISMATCH */
    case FontTypeMismatch = UNKNOWN;

    /** @cvalue CAIRO_STATUS_USER_FONT_IMMUTABLE */
    case UserFontImmutable = UNKNOWN;

    /** @cvalue CAIRO_STATUS_USER_FONT_ERROR */
    case UserFontError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_NEGATIVE_COUNT */
    case NegativeCount = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_CLUSTERS */
    case InvalidClusters = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_SLANT */
    case InvalidSlant = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_WEIGHT */
    case InvalidWeight = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_SIZE */
    case InvalidSize = UNKNOWN;

    /** @cvalue CAIRO_STATUS_USER_FONT_NOT_IMPLEMENTED */
    case UserFontNotImplemented = UNKNOWN;

    /** @cvalue CAIRO_STATUS_DEVICE_TYPE_MISMATCH */
    case DeviceTypeMismatch = UNKNOWN;

    /** @cvalue CAIRO_STATUS_DEVICE_ERROR */
    case DeviceError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_INVALID_MESH_CONSTRUCTION */
    case InvalidMeshConstruction = UNKNOWN;

    /** @cvalue CAIRO_STATUS_DEVICE_FINISHED */
    case DeviceFinished = UNKNOWN;

    /** @cvalue CAIRO_STATUS_LAST_STATUS */
    case LastStatus = UNKNOWN;


#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 14, 0)
    /** @cvalue CAIRO_STATUS_JBIG2_GLOBAL_MISSING */
    case JBIG2GlobalMissing = UNKNOWN;
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    /** @cvalue CAIRO_STATUS_WIN32_GDI_ERROR */
    case Win32GDIError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_FREETYPE_ERROR */
    case FreetypeError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_PNG_ERROR */
    case PNGError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_TAG_ERROR */
    case TagError = UNKNOWN;
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    /** @cvalue CAIRO_STATUS_DWRITE_ERROR */
    case DWriterError = UNKNOWN;

    /** @cvalue CAIRO_STATUS_SVG_FONT_ERROR */
    case SVGFontError = UNKNOWN;
#endif

    public function getMessage(): string {}
}
