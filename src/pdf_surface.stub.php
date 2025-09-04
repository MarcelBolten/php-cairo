<?php

/** @generate-class-entries */

namespace Cairo\Surface
{
    class Pdf extends \Cairo\Surface
    {
#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
        /**
         * @var int
         * @cvalue CAIRO_PDF_OUTLINE_ROOT
         */
        public const OUTLINE_ROOT = UNKNOWN;
#endif

        /**
         * @param null|string|resource $file
         */
        public function __construct(
            $file,
            float $width,
            float $height
        ) {}

        public function restrictToVersion(
            Pdf\Version $version
        ): void {}

        /**
         * @return Pdf\Version[]
         */
        public static function getVersions(): array {}

        public static function versionToString(
            Pdf\Version $version
        ): string {}

        public function setSize(
            float $width,
            float $height
        ): void {}

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
        /**
         * Add an item to the document outline hierarchy with a name that links to the location specified by link_attribs.
         * Link attributes have the same keys and values as the Link Tag, excluding the "rect" attribute.
         * The item will be a child of the item with id parent_id.
         * Use Pdf::OUTLINE_ROOT as the parent id of top level items.
         * Returns the id for the added item.
         */
        public function addOutline(
            int $parent_id,
            string $name,
            string $link_attribs,
            Pdf\OutlineFlags $outline_flag,
        ): int {}

        public function setMetadata(
            Pdf\Metadata $field,
            string $value = ""
        ): void {}

        public function setPageLabel(
            string $label
        ): void {}

        public function setThumbnailSize(
            int $width,
            int $height
        ): void {}
#endif

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
        /**
         * Set custom metadata for the PDF document.
         * $field may be any string except for the following names reserved by PDF:
         * Title, Author, Subject, Keywords, Creator, Producer, CreationDate, ModDate, Trapped
         */
        public function setCustomMetadata(
            string $field,
            string $value
        ): void {}
#endif
    }
}

namespace Cairo\Surface\Pdf
{
    enum Version: int
    {
        /** @cvalue CAIRO_PDF_VERSION_1_4 */
        case Version_1_4 = UNKNOWN;

        /** @cvalue CAIRO_PDF_VERSION_1_5 */
        case Version_1_5 = UNKNOWN;

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 18, 0)
        /** @cvalue CAIRO_PDF_VERSION_1_6 */
        case Version_1_6 = UNKNOWN;

        /** @cvalue CAIRO_PDF_VERSION_1_7 */
        case Version_1_7 = UNKNOWN;
#endif
    }

#if CAIRO_VERSION >= CAIRO_VERSION_ENCODE(1, 16, 0)
    enum OutlineFlags: int
    {
        /** @cvalue CAIRO_PDF_OUTLINE_FLAG_OPEN */
        case Open = UNKNOWN;

        /** @cvalue CAIRO_PDF_OUTLINE_FLAG_BOLD */
        case Bold = UNKNOWN;

        /** @cvalue CAIRO_PDF_OUTLINE_FLAG_ITALIC */
        case Italic = UNKNOWN;
    }

    enum Metadata: int
    {
        /** @cvalue CAIRO_PDF_METADATA_TITLE */
        case Title = UNKNOWN;

        /** @cvalue CAIRO_PDF_METADATA_AUTHOR */
        case Author = UNKNOWN;

        /** @cvalue CAIRO_PDF_METADATA_SUBJECT */
        case Subject = UNKNOWN;

        /** @cvalue CAIRO_PDF_METADATA_KEYWORDS */
        case Keywords = UNKNOWN;

        /** @cvalue CAIRO_PDF_METADATA_CREATOR */
        case Creator = UNKNOWN;

        /** @cvalue CAIRO_PDF_METADATA_CREATE_DATE */
        case CreateDate = UNKNOWN;

        /** @cvalue CAIRO_PDF_METADATA_MOD_DATE */
        case ModDate = UNKNOWN;
    }
#endif
}
