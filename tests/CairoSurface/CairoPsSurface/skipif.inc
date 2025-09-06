<?php
if (!in_array('PS', \Cairo\Cairo::availableSurfaces())) {
    die('skip - PS surface not available');
}
