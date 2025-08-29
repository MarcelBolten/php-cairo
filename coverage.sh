#!/bin/bash
# coverage.sh

echo "Running tests..."
php run-tests.php -q -j$(nproc)

echo "Generating coverage report..."
lcov --capture --directory src/.libs --output-file coverage_raw.info

echo "Filtering coverage data..."
lcov --remove coverage_raw.info \
  '/usr/local/include/php/*' \
  --output-file coverage.info \
  --quiet

echo "Generating HTML report..."
genhtml coverage.info \
  --output-directory coverage_html \
  --title "PHP Cairo Extension Coverage" \
  --show-details \
  --ignore-errors source \
  --quiet \
  --show-details \
  --num-spaces 4

echo "Coverage report generated in coverage_html/"
echo "Open coverage_html/index.html in your browser"

# Cleanup
rm coverage_raw.info
