<?php
/**
 * Class BlogEntity
 */
class BlogEntity extends Entity {

  /**
   * Specify a default URI for a blog entity.
   */
  protected function defaultUri() {
    return array('path' => 'blog/' . $this->identifier());
  }
}
