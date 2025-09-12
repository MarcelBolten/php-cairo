// The three functions below are needed to compile on Windows for PHP <= 8.3 on x86
// I don't have a better solution for now

/*
  relevant output from linker when these are missing:
  cairo.lib(cairo-path-stroke-polygon.c.obj) : error LNK2019: unresolved external symbol __dtoul3_legacy referenced in function __cairo_path_fixed_stroke_to_polygon
  pixman-1.lib(pixman-gradient-walker.c.obj) : error LNK2019: unresolved external symbol __ltof3 referenced in function __pixman_gradient_walker_fill_wide
  libexpatMT.lib(xmlparse.c.obj) : error LNK2019: unresolved external symbol __ultof3 referenced in function _accountingGetCurrentAmplification
*/

#ifndef LEGACY_MATH_H
#define LEGACY_MATH_H

#if defined(_WIN32) \
    && (defined(_M_IX86) || defined(__i386__) || defined(_X86_) || defined(__X86__)) \
    && PHP_VERSION_ID >= 80100 \
    && PHP_VERSION_ID < 80400

#include <math.h>
#include <float.h>

// Convert double to unsigned long (legacy version)
static inline unsigned long __dtoul3_legacy(double d) {
    if (d < 0.0) {
        return 0UL;
    }
    if (d >= (double)ULONG_MAX) {
        return ULONG_MAX;
    }
    return (unsigned long)d;
}

// Convert long to float (legacy version)
static inline float __ltof3(long l) {
    return (float)l;
}

// Convert unsigned long to float (legacy version)
static inline float __ultof3(unsigned long ul) {
    return (float)ul;
}

#endif // _WIN32

#endif // LEGACY_MATH_H
