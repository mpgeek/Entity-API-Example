<?php
/**
 * @file
 * Page callbacks for Thing One.
 */

/**
 * Page callback to view a single blog.
 *
 * @param int $id
 *   The entity id of the blog to view.
 *
 * @return string
 *   Markup to be sent to the browser for the blog.
 */
function thing_one_blog_view($id) {
  $blog = blog_load($id);
  drupal_set_title($blog->title);
  //return entity_view('blog', array($blog));
  return 'blah';
}
