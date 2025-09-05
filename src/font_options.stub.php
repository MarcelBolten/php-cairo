<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo;

class FontOptions {

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	/**
	 * The default color palette index.
	 *
	 * @var int
	 * @cvalue CAIRO_COLOR_PALETTE_DEFAULT
	 */
	public const PALETTE_DEFAULT = UNKNOWN;
#endif

	public function __construct() {}

	public function getStatus(): Status {}

	public function merge(
		FontOptions $other
	): void {}

	public function hash(): int {}

	public function equal(
		FontOptions $other
	): bool {}

	public function setAntialias(
		Antialias $antialias
	): void {}

	public function getAntialias(): Antialias {}

	public function setSubpixelOrder(
		SubPixelOrder $subpixel_order = SubPixelOrder::Default
	): void {}

	public function getSubpixelOrder(): SubPixelOrder {}

	public function setHintStyle(
		HintStyle $hint_style = HintStyle::Default
	): void {}

	public function getHintStyle(): HintStyle {}

	public function setHintMetrics(
		HintMetrics $hint_metrics = HintMetrics::Default
	): void {}

	public function getHintMetrics(): HintMetrics {}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
	public function setVariations(
		string $variations
	): void {}

	public function getVariations(): string {}
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
	public function getColorMode(): ColorMode {}

	public function setColorMode(
		ColorMode $color_mode = ColorMode::Default
	): void {}

	public function getColorPalette(): int {}

	public function setColorPalette(
		int $palette = FontOptions::PALETTE_DEFAULT
	): void {}

	public function setCustomPaletteColor(
		int $colorId,
		float $red,
		float $green,
		float $blue,
		float $alpha = 1.0
	): void {}

	/**
	 * @return array{red: float, green: float, blue: float, alpha: float}
	 */
	public function getCustomPaletteColor(
		int $colorId
	): array {}
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

enum SubPixelOrder: int
{
	/** @cvalue CAIRO_SUBPIXEL_ORDER_DEFAULT */
	case Default = UNKNOWN;

	/** @cvalue CAIRO_SUBPIXEL_ORDER_RGB */
	case RGB = UNKNOWN;

	/** @cvalue CAIRO_SUBPIXEL_ORDER_BGR */
	case BGR = UNKNOWN;

	/** @cvalue CAIRO_SUBPIXEL_ORDER_VRGB */
	case VRGB = UNKNOWN;

	/** @cvalue CAIRO_SUBPIXEL_ORDER_VBGR */
	case VBGR = UNKNOWN;
}

enum HintStyle: int
{
	/** @cvalue CAIRO_HINT_STYLE_DEFAULT */
	case Default = UNKNOWN;

	/** @cvalue CAIRO_HINT_STYLE_NONE */
	case None = UNKNOWN;

	/** @cvalue CAIRO_HINT_STYLE_SLIGHT */
	case Slight = UNKNOWN;

	/** @cvalue CAIRO_HINT_STYLE_MEDIUM */
	case Medium = UNKNOWN;

	/** @cvalue CAIRO_HINT_STYLE_FULL */
	case Full = UNKNOWN;
}

enum HintMetrics: int
{
	/** @cvalue CAIRO_HINT_METRICS_DEFAULT */
	case Default = UNKNOWN;

	/** @cvalue CAIRO_HINT_METRICS_OFF */
	case Off = UNKNOWN;

	/** @cvalue CAIRO_HINT_METRICS_ON */
	case On = UNKNOWN;
}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
enum ColorMode: int
{
	/** @cvalue CAIRO_COLOR_MODE_DEFAULT */
	case Default = UNKNOWN;

	/** @cvalue CAIRO_COLOR_MODE_NO_COLOR */
	case NoColor = UNKNOWN;

	/** @cvalue CAIRO_COLOR_MODE_COLOR */
	case Color = UNKNOWN;
}
#endif
