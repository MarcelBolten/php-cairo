<?php
if (!in_array('PDF', \Cairo\Cairo::availableSurfaces())) {
    die('skip - PDF surface not available');
}
