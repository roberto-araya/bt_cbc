<?php

namespace Drupal\bt_cbc;

use Drupal\Core\Entity\EntityInterface;
use Drupal\layout_builder\LayoutEntityHelperTrait;

/**
 * Utility class to get the entity layout builder sections.
 */
class EntitySections {
  use LayoutEntityHelperTrait;

  /**
   * Return an array of sections.
   *
   * @param Drupal\Core\Entity\EntityInterface $entity
   *   The entity.
   */
  public function getSections(EntityInterface $entity) {
    return $this->getEntitySections($entity);
  }

}
