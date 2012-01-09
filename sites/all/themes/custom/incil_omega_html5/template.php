<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Implements hook_preprocess_views_view_unformatted().
 */
/*
function incil_omega_html5_preprocess_views_view_unformatted($vars) {
  $view = $vars['view'];

  // We want to add node type classes
  if (isset($vars['rows'])) {
    if (isset($vars['classes_array']) && isset($view->result)) {
      // Go through result
      foreach ($view->result as $id => $result) {
        if (isset($view->result[$id]->node_type)) {
          $type = $view->result[$id]->node_type;
          // Set both to be sure
          $vars['classes_array'][$id] .= ' node-type-' . $type;
          $vars['classes'][$id][] = 'node-type-' . $type;
        }
      }
    }
  }
}
*/

/**
 * For whatever reason, utilizing the hook_preprocess_views_view_unformatted()
 * function to set some classes does not transfer over to the 
 * views_view_unformatted.tpl.php template.  See above.
 *
 * So, this is a function that cna be used in the template itself.
 */
function incil_omega_html5_preprocess_views_type_class($view, &$classes_array) {
  if (isset($view) && is_object($view)) {
    if (isset($classes_array) && isset($view->result)) {
      // Go through result
      foreach ($view->result as $id => $result) {
      
        // Check node types
        $node_types = array(
          'node_type',
          'node_field_data_field_country_type',
          'node_field_data_field_countries_type',
          'node_field_data_field_tools_type',
          'node_field_data_field_projects_type',
          'node_users_type',
        );
        foreach ($view->result[$id] as $p => $value) {
          if (in_array($p, $node_types) || strpos($p, '_node_type') > 0) {
            $type = $view->result[$id]->{$p};
            $classes_array[$id] .= ' node-type-' . check_plain($type);
          }
        }
        
        // Check for profile types
        $profile_types = array(
          'profile_type',
        );
        foreach ($view->result[$id] as $p => $value) {
          if (in_array($p, $profile_types) || strpos($p, '_profile_type') > 0 || 
            strpos($p, '_users_type') > 0) {
            $type = $view->result[$id]->{$p};
            $classes_array[$id] .= ' profile-type-' . check_plain($type);
          }
        }
      }
    }
  }
}