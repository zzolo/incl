<?php
/**
 * @file
 * incil_permissions.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function incil_permissions_user_default_roles() {
  $roles = array();

  // Exported role: content administrator
  $roles['content administrator'] = array(
    'name' => 'content administrator',
    'weight' => '4',
  );

  // Exported role: innovation leader
  $roles['innovation leader'] = array(
    'name' => 'innovation leader',
    'weight' => '3',
  );

  return $roles;
}
