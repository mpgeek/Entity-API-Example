<?php
/**
 * @file
 * Page callbacks for Thing One.
 */
function thing_one_view_blog($id) {
  $blog = entity_load_single('blog', $id);
  return entity_view('blog', array($blog));
}
