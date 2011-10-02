<?php
/**
 * @file
 * incil_admin.features.user_role.inc
 */

/**
 * Implementation of hook_user_default_roles().
 */
function incil_admin_user_default_roles() {
  $roles = array();

  // Exported role: administrator
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => '5',
  );

  return $roles;
}
