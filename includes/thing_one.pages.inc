<?php
/**
 * @file
 * Page callbacks for Thing One.
 */

/**
 * Page callback to view a single blog.
 *
 * @param object $blog
 *   The loaded blog entity.
 *
 * @return string
 *   Markup to be sent to the browser for the blog.
 */
function blog_view($blog) {
  return entity_view('blog', array($blog->id => $blog));
}
