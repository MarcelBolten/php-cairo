<?php

final class RgbaPixel
{
    public function __construct(
        public int $r,
        public int $g,
        public int $b,
        public int $a,
    ) {}
}

function getPixelData(Cairo\Surface\Image $image): array {
    $data = $image->getData();
    $width = $image->getWidth();
    $stride = $image->getStride();

    $rows = str_split($data, $stride);
    $bytesPerPixel = $stride / $width;
    $result = [];
    foreach ($rows as $y => $row) {
        $pixels = str_split($row, $bytesPerPixel);
        foreach ($pixels as $x => $pixel) {
            $rgba = array_map('ord', str_split($pixel));
            $result[$y][$x] = new RgbaPixel($rgba[1], $rgba[2], $rgba[3], $rgba[0]);
        }
    }

    return $result;
}

function compareImages(string $case, string $exampleDir): void {
    $expected = Cairo\Surface\Image::createFromPng("{$exampleDir}/{$case}-php-expected.png");
    $observed = Cairo\Surface\Image::createFromPng("{$exampleDir}/{$case}-php.png");

    $eWidth = $expected->getWidth();
    $eHeight = $expected->getHeight();
    $oWidth = $observed->getWidth();
    $oHeight = $observed->getHeight();

    if ($eWidth !== $oWidth
        || $eHeight !== $oHeight
    ) {
        echo "Expected dimensions: {$eWidth}x{$eHeight}", PHP_EOL;
        echo "Observed dimensions: {$oWidth}x{$oHeight}", PHP_EOL;
        echo "Dimenions are not equal. Skip pixel comparison.";
        return;
    }

    $expectedData = getPixelData($expected);
    $observedData = getPixelData($observed);

    $diffs = [];
    foreach ($expectedData as $y => $row) {
        foreach ($row as $x => $pixel) {
            $observedPixel = $observedData[$y][$x];
            if ($pixel != $observedPixel) {
                $diffs[] = [
                    'x' => $x,
                    'y' => $y,
                ];
            }
        }
    }

    if (count($diffs) === 0) {
        echo "No differences found.", PHP_EOL;
        return;
    }

    echo count($diffs), " different Pixels found.", PHP_EOL;

    $diffImage = new Cairo\Surface\Image($observed->getFormat(), $eWidth, $eHeight);
    $cr = new Cairo\Context($diffImage);
    $cr->setSourceRgba(1, 1, 1);
    $cr->paint();

    foreach ($diffs as $diff) {
        $cr->setSourceRgba(1, 0, 0);
        $cr->rectangle($diff['x'], $diff['y'], 1, 1);
        $cr->fill();
    }

    $diffImage->writeToPng("{$exampleDir}/{$case}-php-diff.png");
    echo "Diff image written to {$exampleDir}/{$case}-php-diff.png", PHP_EOL;
}

// iterate over all .php files in examples directory
$exampleDir = __DIR__;
$dir = new DirectoryIterator($exampleDir);
foreach ($dir as $fileinfo) {
    if ($fileinfo->isFile() && $fileinfo->getExtension() === 'php') {
        $fileName = $fileinfo->getBasename('.php');
        $expectedFile = $exampleDir . "/{$fileName}-php-expected.png";

        // not all examples have expected images
        if (!file_exists($expectedFile)) {
            continue;
        }

        $observedFile = $exampleDir . "/{$fileName}-php.png";

        if (!file_exists($observedFile)) {
            echo "Running example: ", $fileinfo->getFilename(), PHP_EOL;
            $process = exec("php " . escapeshellarg($fileinfo->getPathname()), $output, $returnVar);

            if ($returnVar !== 0) {
                echo "Error running example ", $fileinfo->getFilename(), ": ", implode(PHP_EOL, $output), PHP_EOL;
                continue;
            }
        }

        echo "Comparing images for example: ", $fileinfo->getFilename(), PHP_EOL;
        compareImages($fileName, $exampleDir);
    }
}
