<?php

/**
 * Comment preprocesser.
 */
function incil_omega_html5_alpha_preprocess_comment(&$vars) {
  // Get profile image
  $profile = profile2_load_by_user($vars['user'], 'profile');
  $image = field_view_field('profile2', $profile, 'field_profile_image');
  // Define specific style
  $image[0]['#image_style'] = 'incil_small';
  $vars['picture'] = drupal_render($image);
}