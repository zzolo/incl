<?php
/**
 * @file
 * Main template file for the INCIL Admin theme.
 */

/**
 * Implements hook_theme_registry_alter.
 */
function incil_admin_theme_registry_alter(&$theme_registry) {
  // The two column approach is kind of cool, but
  // bad use of space IMO
  $theme_registry['node_form']['template'] = 'form-simple';
}

/**
 * Theme override theme_filter_guidelines().
 */
function incil_admin_filter_guidelines($variables) {
  // Put back to the original implementation.  Rubik just blows it away.
  $format = $variables['format'];
  $attributes['class'][] = 'filter-guidelines-item';
  $attributes['class'][] = 'filter-guidelines-' . $format->format;
  $output = '<div' . drupal_attributes($attributes) . '>';
  $output .= '<h3>' . check_plain($format->name) . '</h3>';
  $output .= theme('filter_tips', array('tips' => _filter_tips($format->format, FALSE)));
  $output .= '</div>';
  return $output;
}