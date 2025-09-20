Cairo for PHP 8.1+
=============

[Cairo](https://www.cairographics.org/) is a 2D graphics library with support for multiple output devices. Output
targets include the X Window System (via both Xlib and XCB), Quartz, Win32,
image buffers, PostScript, PDF, and SVG files.

This extension provides access to Cairo functionality in PHP 8.1+ in the Cairo namespace.

[![Build and Test](https://github.com/MarcelBolten/php-cairo/actions/workflows/ci.yml/badge.svg?branch=overhaul)](https://github.com/MarcelBolten/php-cairo/actions/workflows/ci.yml)

Requirements
=============
 * PHP 8.1.0+
 * Cairo 1.12.0+

Additional features are supported up to Cairo version 1.18.4.

Features are enabled at compile time based on the library version they are compiled against.

Documentation and information about the underlying library can be found at [cairographics.org](http://cairographics.org/manual/).

Installation
=============
There are plans to make this available via [PIE (PHP Installer for Extensions)](https://github.com/php/pie)

Until then, please compile and install the cairo extensions and enable it in your php.ini file.

```
extension=cairo.so
```

Compile
=============

This extension can be compiled and tested using phpize.

The cairo extension also requires cairo development files.  You can build the package
manually or use your system's package manager.  For example on ubuntu use:

```
apt-get install libcairo2-dev libfreetype6-dev fontconfig libjpeg-dev
```

Then you can use phpize to install the extension against your current PHP install:

```
phpize
./configure
make && make test && make install
```

If you want to use a non-standard location for your PHP use:

```
/path/to/phpize
./configure --with-php-config=/path/to/php-config
make && make test && make install
```

`make install` copies `cairo.so` to the right location, but you still need to enable the module
in your php.ini file.

Codec overage reports
=====================

A [coverage report](https://marcelbolten.github.io/php-cairo/src/) is uploaded to gh-pages during every [Build and Test](https://github.com/MarcelBolten/php-cairo/actions/workflows/ci.yml) workflow.

Requirements: lcov, gzip.

To obtain a code coverage report the extension must be compiled with additional flags:

```
phpize
CAIRO_COVERAGE=yes ./configure
make && make install
coverage.sh
```

This will run all tests and create an html report.

Examples
====
The examples directory holds samples of all currently working utilities for the extension.

Community
=====
You can find us on [freenode](http://freenode.org) on #gtkforphp

The main website is [Gtk For PHP](http://gtkforphp.net)

You can view commits and released on [twitter](http://twitter.com/gtkforphp)

You can send comments, patches, questions [here on github](https://github.com/gtkforphp/cairo/issues)


Authors
====
Elizabeth M Smith | Swen Zanon | Marcel Bolten | Bernhard R. Fischer (JPEG-integration)

License
=====
PHP extension binding code released under the [MIT license](http://opensource.org/licenses/MIT)
See [LICENSE](LICENSE)

The Cairo Graphics library is is released under the [LGPL](https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html)

Documentation
=====
What little documentation we currently have is in code comments and the docs directory.

We'd like to use some kind of markdown or rst format for docs, a decision isn't final yet.
