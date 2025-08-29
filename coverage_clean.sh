#!/bin/bash

# Cleanup coverage files
find . -name "*.gcda" | xargs rm -f
rm -f coverage.info
rm -rf coverage_html
rm test_results.txt
