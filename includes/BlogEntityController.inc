<?php

/**
 * Class BlogEntityController
 */
class BlogEntityController extends EntityAPIController {

  public function create(array $values = array()) {
    global $user;

    // Add the created/updated time and the uid automatically.
    $values += array(
      'uid' => $user->uid,
    );
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Set the creation time if this is a new blog.
    if (isset($entity->is_new)) {
      $entity->created = REQUEST_TIME;
    }

    // Always update the update time.
    $entity->changed = REQUEST_TIME;
    parent::save($entity, $transaction);
  }
}
