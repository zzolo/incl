<?php

/**
 * HTML preprocesser.
 */
function incil_omega_html5_alpha_preprocess_html(&$vars) {
  global $user;

  // User role classes
  if (is_object($vars['user']) && $vars['user']->uid > 0) {
    foreach ($vars['user']->roles as $r => $role) {
      $vars['attributes_array']['class'][] = 'user-role-' . $role;
    }
  }
}