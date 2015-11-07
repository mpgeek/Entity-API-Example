<?php

/**
 * Class BlogEntityController
 */
class BlogEntityController extends EntityAPIController {

  public function create(array $values = array()) {
    global $user;

    // Add the created/updated time and the uid automatically.
    $values += array(
      'created' => REQUEST_TIME,
      'changed' => REQUEST_TIME,
      'uid' => $user->uid,
    );

    // Let Entity API handle the creation.
    return parent::create($values);
  }

  public function save($entity, DatabaseTransaction $transaction = NULL) {
    // Nothing special, just let Entity API handle it.
    parent::save($entity, $transaction);
  }
}
