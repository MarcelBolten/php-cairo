#!/bin/bash
cd examples
for file in *.php; do
    echo "Running $file"
    [[ "$file" == "compare_example_images.php" ]] && continue
    php "$file"
done
