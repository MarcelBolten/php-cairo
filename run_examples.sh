#!/bin/bash
cd examples
for file in *.php; do
    echo "Running $file"
    php "$file"
done
