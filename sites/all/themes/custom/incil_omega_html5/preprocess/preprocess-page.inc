<?php

/**
 * Page preprocesser.
 */
function incil_omega_html5_alpha_preprocess_page(&$vars) {
  global $user;
  
  // Use different logo for anonymous users
  if (is_object($user) && empty($user->uid)) {
    $path = drupal_get_path('theme', 'incil_omega_html5') . '/images/logo-old.png';
    $vars['logo'] = url($path, array('absolute' => TRUE));
  }
}