#!/bin/bash
cd examples
for file in *.php; do
    echo "Running $file"
    php "$file"

    # # Check if output PNG exists
    # output_png="${file%.php}-php.png"
    # expected_png="${file%.php}-php-expected.png"
    # if [[ -f "$output_png" && -f "$expected_png" ]]; then
    #     hash_actual=$(sha256sum "$output_png" | awk '{print $1}')
    #     hash_expected=$(sha256sum "$expected_png" | awk '{print $1}')
    #     if [ "$hash_actual" = "$hash_expected" ]; then
    #         echo "[OK] $output_png matches expected."
    #     else
    #         echo "[FAIL] $output_png does not match expected!"
    #     fi
    # fi
done
