<?php
if (!in_array('RECORDING', \Cairo\Cairo::availableSurfaces())) {
    die('skip - RECORDING surface not available');
}
