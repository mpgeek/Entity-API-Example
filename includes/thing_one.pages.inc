<?php
/**
 * @file
 * Page callbacks for Thing One.
 */

/**
 * Render builder and page callback for preparing a single blog to be viewed.
 *
 * @param object $blog
 *   The loaded blog entity.
 *
 * @return array
 *   A renderable array, as expected by drupal_render().
 */
function blog_view($blog) {
  return entity_view('blog', array($blog->id => $blog));
}

/**
 * Render builder and page callback for preparing multiple blogs to be viewed.
 *
 * @param array $ids
 *   The entity ids of the blogs to prepare.
 * @param string $view_mode
 *   Then entity view mode to prepare.
 *
 * @return array
 *   A renderable array, as expected by drupal_render().
 */
function blog_view_multiple($ids = array(), $view_mode = 'full') {
  return entity_view('blog', $ids, $view_mode);
}

/**
 * Render builder and page callback to view a blog listing.
 *
 * @return string
 *   Markup to be returned to the browser for the listing.
 */
function blog_listing_view() {
  // Query for the blogs, 10 per page.
  $results_per_page = 10;
  $query = new EntityFieldQuery();
  $query
    ->entityCondition('entity_type', 'blog')
    ->pager($results_per_page);

  $results = $query->execute();

  // We want teasers in the listing.
  $view_mode = 'teaser';
  $content = blog_view_multiple(
    blog_load_multiple(array_keys($results['blog'])), $view_mode
  );

  // Build the output as a render array.
  $build = array(
    'content' => $content,
    'pager' => array(
      '#markup' => theme('pager'),
      '#wieght' => 10,
    ),
  );
  return $build;
}
