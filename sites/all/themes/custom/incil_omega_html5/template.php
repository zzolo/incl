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
        if (isset($view->result[$id]->node_type)) {
          $type = $view->result[$id]->node_type;
          $classes_array[$id] .= ' node-type-' . check_plain($type);
        }
        elseif (isset($view->result[$id]->profile_type)) {
          $type = $view->result[$id]->profile_type;
          $classes_array[$id] .= ' profile-type-' . check_plain($type);
        }
        else {
          // Check for a similar property
          foreach ($view->result[$id] as $p => $value) {
            if (strpos($p, '_node_type') > 0) {
              $type = $view->result[$id]->{$p};
              $classes_array[$id] .= ' node-type-' . check_plain($type);
            }
          }
        }
      }
    }
  }
}