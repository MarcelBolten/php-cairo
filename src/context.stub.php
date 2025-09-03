<?php

/** @generate-class-entries */

namespace Cairo;

require_once '/cairo.stub.php';

class Context
{
    public function __construct(Surface $surface) {}

    public function getStatus(): Status {}

    public function save(): void {}

    public function restore(): void {}

    public function pushGroup(): void {}

    public function pushGroupWithContent(Surface\Content $content): void {}

    public function popGroup(): void {}

    public function popGroupToSource(): void {}

    public function getGroupSurface(): Surface {}

    public function setSourceRGB(float $red, float $green, float $blue): void {}

    public function setSourceRGBA(float $red, float $green, float $blue, float $alpha): void {}

    public function setSurface(Surface $surface, float $x, float $y): void {}

    public function getSurface(): Surface {}

    public function setPattern(Pattern $pattern): void {}

    public function getPattern(): Pattern {}

    public function setAntialias(Antialias $antialias): void {}

    public function getAntialias(): Antialias {}

    public function setDash(array $dashes, float $offset = 0.0): void {}

    public function getDashCount(): int {}

    public function getDash(): array {}

    public function setFillRule(FillRule $fillrule): void {}

    public function getFillRule(): FillRule {}

    public function setLineCap(LineCap $linecap): void {}

    public function getLineCap(): LineCap {}

    public function setLineJoin(LineJoin $linejoin): void {}

    public function getLineJoin(): LineJoin {}

    public function setLineWidth(float $width): void {}

    public function getLineWidth(): float {}

    public function setMiterLimit(float $limit): void {}

    public function getMiterLimit(): float {}

    public function setOperator(Operator $operator): void {}

    public function getOperator(): Operator {}

    public function setTolerance(float $tolerance): void {}

    public function getTolerance(): float {}

    public function clip(): void {}

    public function inClip(float $x, float $y): bool {}

    public function clipPreserve(): void {}

    public function resetClip(): void {}

    public function getClipExtents(): array {}

    public function clipRectangleList(): array {}

    public function fill(): void {}

    public function fillPreserve(): void {}

    public function getFillExtents(): array {}

    public function inFill(float $x, float $y): bool {}

    public function mask(Pattern $pattern): void {}

    public function maskSurface(Surface $surface, float $x = 0.0, float $y = 0.0): void {}

    public function paint(): void {}

    public function paintWithAlpha(float $alpha): void {}

    public function stroke(): void {}

    public function strokePreserve(): void {}

    public function getStrokeExtents(): array {}

    public function inStroke(float $x, float $y): bool {}

    public function copyPage(): void {}

    public function showPage(): void {}

    public function translate(float $x, float $y): void {}

    public function scale(float $sx, float $sy): void {}

    public function angle(float $angle): void {}

    public function transform(Matrix $matrix): void {}

    public function setMatrix(Matrix $matrix): void {}

    public function getMatrix(): Matrix {}

    public function identityMatrix(): void {}

    public function userToDevice(float $x, float $y): array {}

    public function userToDeviceDistance(float $x, float $y): array {}

    public function deviceToUser(float $x, float $y): array {}

    public function deviceToUserDistance(float $x, float $y): array {}

    public function copyPath(): Path {}

    public function copyPathFlat(): Path {}

    public function appendPath(Path $path): void {}

    public function hasCurrentPoint(): bool {}

    public function getCurrentPoint(): array {}

    public function newPath(): void {}

    public function newSubPath(): void {}

    public function closePath(): void {}

    public function arc(float $xc, float $yc, float $radius, float $angle1, float $angle2): void {}

    public function arcNegative(float $xc, float $yc, float $radius, float $angle1, float $angle2): void {}

    public function curveTo(float $x1, float $y1, float $x2, float $y2, float $x3, float $y3): void {}

    public function lineTo(float $x, float $y): void {}

    public function moveTo(float $x, float $y): void {}

    public function rectangle(float $x, float $y, float $width, float $height): void {}

    public function glyphPath(array $glyphs): void {}

    public function showGlyphs(array $glyphs): void {}

    public function showTextGlyphs(string $text, array $glyphs, array $clusters): void {}

    public function textPath(string $text): void {}

    public function relCurveTo(float $x1, float $y1, float $x2, float $y2, float $x3, float $y3): void {}

    public function relLineTo(float $x, float $y): void {}

    public function relMoveTo(float $x, float $y): void {}

    public function getPathExtents(): array {}

    public function selectFontFace(
        string $family,
        FontSlant $slant = FontSlant::Normal,
        FontWeight $weight = FontWeight::Normal
    ): void {}

    public function setFontSize(float $size): void {}

    public function setFontMatrix(Matrix $matrix): void {}

    public function getFontMatrix(): Matrix {}

    public function setFontOptions(FontOptions $options): void {}

    public function getFontOptions(): FontOptions {}

    public function setFontFace(FontFace $font_face): void {}

    public function getFontFace(): FontFace {}

    public function setScaledFont(ScaledFont $scaled_font): void {}

    public function getScaledFont(): ScaledFont {}

    public function showText(string $text): void {}

    public function getFontExtents(): array {}

    public function getTextExtents(string $text): array {}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
    public function setHairline(bool $hairline): void {}

    public function getHairline(): bool {}
#endif
}

enum Antialias: int
{
    /** @cvalue CAIRO_ANTIALIAS_DEFAULT */
    case Default = UNKNOWN;

    /** @cvalue CAIRO_ANTIALIAS_NONE */
    case None = UNKNOWN;

    /** @cvalue CAIRO_ANTIALIAS_GRAY */
    case Gray = UNKNOWN;

    /** @cvalue CAIRO_ANTIALIAS_SUBPIXEL */
    case Subpixel = UNKNOWN;

    /** @cvalue CAIRO_ANTIALIAS_FAST */
    case Fast = UNKNOWN;

    /** @cvalue CAIRO_ANTIALIAS_GOOD */
    case Good = UNKNOWN;

    /** @cvalue CAIRO_ANTIALIAS_BEST */
    case Best = UNKNOWN;
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
