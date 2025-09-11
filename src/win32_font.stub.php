<?php

/**
 * @generate-class-entries
 * @generate-legacy-arginfo 80100
 */

namespace Cairo\FontFace
{
    class Win32 extends \Cairo\FontFace
    {
        /**
         * @param null|array{lfHeight: int, lfWidth: int, lfEscapement: int, lfOrientation: int, lfWeight: int, lfItalic: bool, lfUnderline: bool, lfStrikeOut: bool, lfCharSet: int, lfOutPrecision: int, lfClipPrecision: int, lfQuality: int, lfPitchAndFamily: int, lfFaceName: string} $font_options An associative array of font options.  Compare to https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-logfontw
         */
        public function __construct(
            null|array $font_options = null,
        ) {}
    }
}

namespace Cairo\FontFace\Win32
{
    enum FontWeight: int
    {
        /** @cvalue FW_DONTCARE */
        case Dontcare = UNKNOWN;

        /** @cvalue FW_THIN */
        case Thin = UNKNOWN;

        /** @cvalue FW_EXTRALIGHT */
        case Extralight = UNKNOWN;

        /** @cvalue FW_ULTRALIGHT */
        case Ultralight = UNKNOWN;

        /** @cvalue FW_LIGHT */
        case Light = UNKNOWN;

        /** @cvalue FW_NORMAL */
        case Normal = UNKNOWN;

        /** @cvalue FW_REGULAR */
        case Regular = UNKNOWN;

        /** @cvalue FW_MEDIUM */
        case Medium = UNKNOWN;

        /** @cvalue FW_SEMIBOLD */
        case Semibold = UNKNOWN;

        /** @cvalue FW_DEMIBOLD */
        case Demibold = UNKNOWN;

        /** @cvalue FW_BOLD */
        case Bold = UNKNOWN;

        /** @cvalue FW_EXTRABOLD */
        case Extrabold = UNKNOWN;

        /** @cvalue FW_ULTRABOLD */
        case Ultrabold = UNKNOWN;

        /** @cvalue FW_HEAVY */
        case Heavy = UNKNOWN;

        /** @cvalue FW_BLACK */
        case Black = UNKNOWN;
    }

    enum FontCharset: int
    {
        /** @cvalue ANSI_CHARSET */
        case Ansi = UNKNOWN;

        /** @cvalue BALTIC_CHARSET */
        case Baltic = UNKNOWN;

        /** @cvalue CHINESEBIG5_CHARSET */
        case ChineseBig5 = UNKNOWN;

        /** @cvalue DEFAULT_CHARSET */
        case Default = UNKNOWN;

        /** @cvalue EASTEUROPE_CHARSET */
        case Easteurope = UNKNOWN;

        /** @cvalue GB2312_CHARSET */
        case GB2312 = UNKNOWN;

        /** @cvalue GREEK_CHARSET */
        case Greek = UNKNOWN;

        /** @cvalue HANGUL_CHARSET */
        case Hangul = UNKNOWN;

        /** @cvalue MAC_CHARSET */
        case Mac = UNKNOWN;

        /** @cvalue OEM_CHARSET */
        case Oem = UNKNOWN;

        /** @cvalue RUSSIAN_CHARSET */
        case Russian = UNKNOWN;

        /** @cvalue SHIFTJIS_CHARSET */
        case ShiftJIS = UNKNOWN;

        /** @cvalue SYMBOL_CHARSET */
        case Symbol = UNKNOWN;

        /** @cvalue TURKISH_CHARSET */
        case Turkish = UNKNOWN;

        /** @cvalue VIETNAMESE_CHARSET */
        case Vietnamese = UNKNOWN;

#if (WINVER >= 0x0400)
        /** @cvalue JOHAB_CHARSET */
        case Johab = UNKNOWN;

        /** @cvalue ARABIC_CHARSET */
        case Arabic = UNKNOWN;

        /** @cvalue HEBREW_CHARSET */
        case Hebrew = UNKNOWN;

        /** @cvalue THAI_CHARSET */
        case Thai = UNKNOWN;
#endif
/** WINVER >= 0x0400 */
    }

    enum FontOutputPrecision: int
    {
        /** @cvalue OUT_CHARACTER_PRECIS */
        case Character = UNKNOWN;

        /** @cvalue OUT_DEFAULT_PRECIS */
        case Default = UNKNOWN;

        /** @cvalue OUT_DEVICE_PRECIS */
        case Device = UNKNOWN;

        /** @cvalue OUT_OUTLINE_PRECIS */
        case Outline = UNKNOWN;

        /** @cvalue OUT_PS_ONLY_PRECIS */
        case PsOnly = UNKNOWN;

        /** @cvalue OUT_RASTER_PRECIS */
        case Raster = UNKNOWN;

        /** @cvalue OUT_STRING_PRECIS */
        case String = UNKNOWN;

        /** @cvalue OUT_STROKE_PRECIS */
        case Stroke = UNKNOWN;

        /** @cvalue OUT_TT_ONLY_PRECIS */
        case TtOnly = UNKNOWN;

        /** @cvalue OUT_TT_PRECIS */
        case Tt = UNKNOWN;
    }

    enum FontClipPrecision: int
    {
        /** @cvalue CLIP_CHARACTER_PRECIS */
        case Character = UNKNOWN;

        /** @cvalue CLIP_DEFAULT_PRECIS */
        case Default = UNKNOWN;

#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
        /** @cvalue CLIP_DFA_DISABLE */
        case DfaDisable = UNKNOWN;
#endif
/** _WIN32_WINNT >= _WIN32_WINNT_LONGHORN */

        /** @cvalue CLIP_EMBEDDED */
        case Embedded = UNKNOWN;

        /** @cvalue CLIP_LH_ANGLES */
        case LhAngles = UNKNOWN;

        /** @cvalue CLIP_MASK */
        case Mask = UNKNOWN;

#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
        /*
        * https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-logfontw
        * CLIP_DFA_OVERRIDE: Turns off font association for the font. This is identical to CLIP_DFA_DISABLE,
        * but it can have problems in some situations; the recommended flag to use is CLIP_DFA_DISABLE.
        */
        /** @cvalue CLIP_DFA_OVERRIDE */
        // case DfaOverride = UNKNOWN;
#endif
/** _WIN32_WINNT >= _WIN32_WINNT_LONGHORN */

        /** @cvalue CLIP_STROKE_PRECIS */
        case Stroke = UNKNOWN;

        /** @cvalue CLIP_TT_ALWAYS */
        case TtAlways = UNKNOWN;
    }

    enum FontQuality: int
    {
        /** @cvalue ANTIALIASED_QUALITY */
        case Antialiased = UNKNOWN;

        /** @cvalue CLEARTYPE_QUALITY */
        case Cleartype = UNKNOWN;

        /** @cvalue DEFAULT_QUALITY */
        case Default = UNKNOWN;

        /** @cvalue DRAFT_QUALITY */
        case Draft = UNKNOWN;

        /** @cvalue NONANTIALIASED_QUALITY */
        case NonAntialiased = UNKNOWN;

        /** @cvalue PROOF_QUALITY */
        case Proof = UNKNOWN;
    }

    enum FontPitch: int
    {
        /** @cvalue DEFAULT_PITCH */
        case Default = UNKNOWN;

        /** @cvalue FIXED_PITCH */
        case Fixed = UNKNOWN;

        /** @cvalue VARIABLE_PITCH */
        case Variable = UNKNOWN;
    }

    enum FontFamily: int
    {
        /** @cvalue FF_DECORATIVE */
        case Decorative = UNKNOWN;

        /** @cvalue FF_DONTCARE */
        case Dontcare = UNKNOWN;

        /** @cvalue FF_MODERN */
        case Modern = UNKNOWN;

        /** @cvalue FF_ROMAN */
        case Roman = UNKNOWN;

        /** @cvalue FF_SCRIPT */
        case Script = UNKNOWN;

        /** @cvalue FF_SWISS */
        case Swiss = UNKNOWN;
    }
}
