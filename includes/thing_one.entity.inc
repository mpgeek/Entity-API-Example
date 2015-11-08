<?php
/**
 * @file
 * Blog entity hook implementations.
 */

/**
 * Blog load single, also used for menu autoload.
 *
 * @see blog_load_multiple().
 */
function blog_load($id, $reset = FALSE) {
  $blogs = blog_load_multiple(array($id), array(), $reset);
  return reset($blogs);
}

/**
 * Blog load multiple.
 *
 * @see entity_load_multiple
 */
function blog_load_multiple($ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('blog', $ids, $conditions, $reset);
}

/**
 * Blog save.
 *
 * @see entity_save().
 */
function blog_save($blog) {
  entity_save('blog', $blog);
}

/**
 * Blog delete.
 *
 * @see entity_delete().
 */
function blog_delete($blog) {
  entity_delete('blog', entity_id('blog', $blog));
}

/**
 * Blog delete multiple.
 *
 * @see entity_delete_multiple().
 */
function blog_delete_multiple($ids) {
  entity_delete_multiple('blog', $ids);
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
