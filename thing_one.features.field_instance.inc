<?php
/**
 * @file
 * thing_one.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function thing_one_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'blog-blog-field_body'.
  $field_instances['blog-blog-field_body'] = array(
    'bundle' => 'blog',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the text of the blog post here.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 300,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'blog',
    'field_name' => 'field_body',
    'label' => 'body',
    'required' => 1,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Enter the text of the blog post here.');
  t('body');

  return $field_instances;
}
