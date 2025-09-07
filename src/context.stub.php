<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo;

class Context
{
    public function __construct(
        Surface $surface
    ) {}

    public function getStatus(): Status {}

    public function save(): void {}

    public function restore(): void {}

    public function pushGroup(): void {}

    public function pushGroupWithContent(
        Surface\Content $content
    ): void {}

    public function popGroup(): Pattern {}

    public function popGroupToSource(): void {}

    public function getGroupSurface(): Surface {}

    public function setSourceRgba(
        float $red,
        float $green,
        float $blue,
        null|float $alpha = null
    ): void {}

    public function setSurface(
        Surface $surface,
        float $x = 0.0,
        float $y = 0.0
    ): void {}

    public function getSurface(): Surface {}

    public function setPattern(
        Pattern $pattern
    ): void {}

    public function getPattern(): Pattern {}

    public function setAntialias(
        Antialias $antialias
    ): void {}

    public function getAntialias(): Antialias {}

    /**
     * @param float[] $dashes
     */
    public function setDash(
        array $dashes,
        float $offset = 0.0
    ): void {}

    public function getDashCount(): int {}

    /**
     * @return array{dashes: array<float>, offset: float}
     */
    public function getDash(): array {}

    public function setFillRule(
        FillRule $fillrule
    ): void {}

    public function getFillRule(): FillRule {}

    public function setLineCap(
        LineCap $linecap
    ): void {}

    public function getLineCap(): LineCap {}

    public function setLineJoin(
        LineJoin $linejoin
    ): void {}

    public function getLineJoin(): LineJoin {}

    public function setLineWidth(
        float $width
    ): void {}

    public function getLineWidth(): float {}

    public function setMiterLimit(
        float $limit
    ): void {}

    public function getMiterLimit(): float {}

    public function setOperator(
        Operator $operator
    ): void {}

    public function getOperator(): Operator {}

    public function setTolerance(
        float $tolerance
    ): void {}

    public function getTolerance(): float {}

    public function clip(): void {}

    public function inClip(
        float $x,
        float $y
    ): bool {}

    public function clipPreserve(): void {}

    public function resetClip(): void {}

    /**
     * @return array{x1: float, y1: float, x2: float, y2: float}
     */
    public function getClipExtents(): array {}

    /**
     * @return array<array{x: float, y: float, width: float, height: float}>
     */
    public function getClipRectangleList(): array {}

    public function fill(): void {}

    public function fillPreserve(): void {}

    /**
     * @return array{x1: float, y1: float, x2: float, y2: float}
     */
    public function getFillExtents(): array {}

    public function inFill(
        float $x,
        float $y
    ): bool {}

    public function mask(
        Pattern $pattern
    ): void {}

    public function maskSurface(
        Surface $surface,
        float $x = 0.0,
        float $y = 0.0
    ): void {}

    public function paint(): void {}

    public function paintWithAlpha(
        float $alpha
    ): void {}

    public function stroke(): void {}

    public function strokePreserve(): void {}

    /**
     * @return array{x1: float, y1: float, x2: float, y2: float}
     */
    public function getStrokeExtents(): array {}

    public function inStroke(
        float $x,
        float $y
    ): bool {}

    public function copyPage(): void {}

    public function showPage(): void {}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    public function setHairline(
        bool $hairline
    ): void {}

    public function getHairline(): bool {}
#endif

    //
    // Transformation methods
    //

    public function translate(
        float $x,
        float $y
    ): void {}

    public function scale(
        float $x,
        float $y
    ): void {}

    public function rotate(
        float $angle
    ): void {}

    public function transform(
        Matrix $matrix
    ): void {}

    public function setMatrix(
        Matrix $matrix
    ): void {}

    public function getMatrix(): Matrix {}

    public function identityMatrix(): void {}

    /**
     * @return array{x: float, y: float}
     */
    public function userToDevice(
        float $x,
        float $y
    ): array {}

    /**
     * @return array{x: float, y: float}
     */
    public function userToDeviceDistance(
        float $x,
        float $y
    ): array {}

    /**
     * @return array{x: float, y: float}
     */
    public function deviceToUser(
        float $x,
        float $y
    ): array {}

    /**
     * @return array{x: float, y: float}
     */
    public function deviceToUserDistance(
        float $x,
        float $y
    ): array {}

    //
    // Paths methods
    //

    public function copyPath(): Path {}

    public function copyPathFlat(): Path {}

    public function appendPath(
        Path $path
    ): void {}

    public function hasCurrentPoint(): bool {}

    /**
     * @return array{x: float, y: float}
     */
    public function getCurrentPoint(): array {}

    public function newPath(): void {}

    public function newSubPath(): void {}

    public function closePath(): void {}

    public function arc(
        float $x,
        float $y,
        float $radius,
        float $angle1,
        float $angle2
    ): void {}

    public function arcNegative(
        float $x,
        float $y,
        float $radius,
        float $angle1,
        float $angle2
    ): void {}

    public function curveTo(
        float $x1,
        float $y1,
        float $x2,
        float $y2,
        float $x3,
        float $y3
    ): void {}

    public function lineTo(
        float $x,
        float $y
    ): void {}

    public function moveTo(
        float $x,
        float $y
    ): void {}

    public function rectangle(
        float $x,
        float $y,
        float $width,
        float $height
    ): void {}

    /**
     * @param Glyph[] $glyphs
     */
    public function glyphPath(
        array $glyphs
    ): void {}

    public function textPath(
        string $text
    ): void {}

    public function relCurveTo(
        float $x1,
        float $y1,
        float $x2,
        float $y2,
        float $x3,
        float $y3
    ): void {}

    public function relLineTo(
        float $x,
        float $y
    ): void {}

    public function relMoveTo(
        float $x,
        float $y
    ): void {}

    /**
     * @return array{x1: float, y1: float, x2: float, y2: float}
     */
    public function getPathExtents(): array {}

    //
    // Text methods
    //

    public function selectFontFace(
        string $family,
        FontSlant $slant = FontSlant::Normal,
        FontWeight $weight = FontWeight::Normal
    ): void {}

    public function setFontSize(
        float $size
    ): void {}

    public function setFontMatrix(
        Matrix $matrix
    ): void {}

    public function getFontMatrix(): Matrix {}

    public function setFontOptions(
        FontOptions $options
    ): void {}

    public function getFontOptions(): FontOptions {}

    public function setFontFace(
        FontFace $font_face
    ): void {}

    public function getFontFace(): FontFace {}

    public function setScaledFont(
        ScaledFont $scaled_font
    ): void {}

    public function getScaledFont(): ScaledFont {}

    public function showText(
        string $text
    ): void {}

    /**
     * @param Glyph[] $glyphs
     */
    public function showGlyphs(
        array $glyphs
    ): void {}

    /**
     * @param Glyph[] $glyphs
     * @param TextCluster[] $clusters
     */
    public function showTextGlyphs(
        string $text,
        array $glyphs,
        array $clusters,
        int $cluster_flags
    ): void {}

    /**
     * @return array{ascent: float, descent: float, height: float, max_x_advance: float, max_y_advance: float}
     */
    public function getFontExtents(): array {}

    /**
     * @return array{x_bearing: float, y_bearing: float, width: float, height: float, x_advance: float, y_advance: float}
     */
    public function getTextExtents(
        string $text
    ): array {}

    /**
     * @param Glyph[] $glyphs
     * @return array{x_bearing: float, y_bearing: float, width: float, height: float, x_advance: float, y_advance: float}
     */
    public function getGlyphExtents(
        array $glyphs
    ): array {}
}

enum FillRule: int
{
    /** @cvalue CAIRO_FILL_RULE_WINDING */
    case Winding = UNKNOWN;

    /** @cvalue CAIRO_FILL_RULE_EVEN_ODD */
    case EvenOdd = UNKNOWN;
}

enum LineCap: int
{
    /** @cvalue CAIRO_LINE_CAP_BUTT */
    case Butt = UNKNOWN;

    /** @cvalue CAIRO_LINE_CAP_ROUND */
    case Round = UNKNOWN;

    /** @cvalue CAIRO_LINE_CAP_SQUARE */
    case Square = UNKNOWN;
}

enum LineJoin: int
{
    /** @cvalue CAIRO_LINE_JOIN_MITER */
    case Miter = UNKNOWN;

    /** @cvalue CAIRO_LINE_JOIN_ROUND */
    case Round = UNKNOWN;

    /** @cvalue CAIRO_LINE_JOIN_BEVEL */
    case Bevel = UNKNOWN;
}

enum Operator: int
{
    /** @cvalue CAIRO_OPERATOR_CLEAR */
    case Clear = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_SOURCE */
    case Source = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_OVER */
    case Over = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_IN */
    case In = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_OUT */
    case Out = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_ATOP */
    case Atop = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_DEST */
    case Dest = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_DEST_OVER */
    case DestOver = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_DEST_IN */
    case DestIn = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_DEST_OUT */
    case DestOut = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_DEST_ATOP */
    case DestAtop = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_XOR */
    case Xor = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_ADD */
    case Add = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_SATURATE */
    case Saturate = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_MULTIPLY */
    case Multiply = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_SCREEN */
    case Screen = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_OVERLAY */
    case Overlay = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_DARKEN */
    case Darken = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_LIGHTEN */
    case Lighten = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_COLOR_DODGE */
    case ColorDodge = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_COLOR_BURN */
    case ColorBurn = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_HARD_LIGHT */
    case HardLight = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_SOFT_LIGHT */
    case SoftLight = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_DIFFERENCE */
    case Difference = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_EXCLUSION */
    case Exclusion = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_HSL_HUE */
    case HslHue = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_HSL_SATURATION */
    case HslSaturation = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_HSL_COLOR */
    case HslColor = UNKNOWN;

    /** @cvalue CAIRO_OPERATOR_HSL_LUMINOSITY */
    case HslLuminosity = UNKNOWN;
}
