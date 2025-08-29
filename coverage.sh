#!/bin/bash

echo "Running tests..."
php run-tests.php -q -j$(nproc) --no-color > test_results.txt

if [ $? -eq 0 ]; then
    echo "✓ Tests passed"
else
    echo "✗ Some tests failed - check test_results.txt"
fi

echo "Generating coverage report..."
lcov --capture \
  --directory src/.libs \
  --output-file coverage_raw.info \
  --quiet \
  -j $(nproc)

echo "Filtering coverage data..."
lcov --remove coverage_raw.info \
  '/usr/local/include/php/*' \
  --output-file coverage.info \
  --quiet \
  -j $(nproc)

echo "Generating HTML report..."
genhtml coverage.info \
  --output-directory coverage_html \
  --title "PHP Cairo Extension Coverage" \
  --show-details \
  --ignore-errors source \
  --quiet \
  --show-details \
  --num-spaces 4 \
  -j $(nproc)

echo "Coverage report generated in coverage_html/"
echo "Open coverage_html/index.html in your browser"

# Cleanup
rm coverage_raw.info
