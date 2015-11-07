<?php
/**
 * @file
 * Blog entity hook implementations.
 */

/**
 * Blog load single.
 *
 * @param int $id
 *   The unique identifier for a blog to load.
 * @param bool $reset
 *   Whether to reset the internal cahce for the Blog entity type.
 *
 * @return array
 *   An array of renderable blogs.
 */
function blog_load($id, $reset = FALSE) {
  $blogs = blog_load_multiple(array($id), array(), $reset);
  return reset($blogs);
}

/**
 * Blog load multiple.
 */
function blog_load_multiple($ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('blog', $ids, $conditions, $reset);
}

/**
 * Blog save.
 */
function blog_save($blog) {
  entity_save('blog', $blog);
}

/**
 * Blog delete.
 */
function blog_delete($blog) {
  entity_delete('blog', entity_id('blog', $blog));
}

/**
 * Blog delete multiple.
 */
function blog_delete_multiple($ids) {
  entity_delete_multiple('blog', ids);
}

/**
 * Implements hook_form() for the Blog entity.
 *
 * Admin UI for creating or updating a blog.
 */
function blog_form($form, &$form_state, $blog = NULL) {
  $form = array();

  $form['title'] = array(
    '#title' => t('Project name'),
    '#type' => 'textfield',
    '#default_value' => isset($blog->title) ? $blog->title : '',
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => isset($blog->id) ? t('Update blog') : t('Save blog'),
    '#weight' => 50,
  );

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function blog_form_submit($form, &$form_state) {
  // Save or update.
  $blog = entity_ui_form_submit_build_entity($form, $form_state);
  $blog->save();

  // Inform the user.
  drupal_set_message(t('The blog @title has been saved.', array(
    '@title' => $blog->title
  )));

  // Go to the admin UI landing page.
  $form_state['redirect'] = 'admin/blogs';
}
