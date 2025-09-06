<?php
if (!in_array('SVG', \Cairo\Cairo::availableSurfaces())) {
    die('skip - SVG surface not available');
}
