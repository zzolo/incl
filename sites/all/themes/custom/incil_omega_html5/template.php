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
 * Implements theme_menu_link().
 */
function incil_omega_html5_menu_link__menu_front_page(array &$vars) {
  // We alter the menu items here because the interface does not
  // allow for all this text.
  
  switch ($vars['element']['#href']) {
    case 'node/12':
      // Explore
      $vars['element']['#title'] = t('Come here to learn about innovative projects happening around the world, use the Center’s Media Map to find and download global data about media and development, and discover how research on experiments can enrich the design of your own programs.');
      break;
      
    case 'node/98':
      // Implement
      $vars['element']['#title'] = t('Want to avoid reinventing the wheel? In this section, you can access our catalogue of tools and see how others are using them to implement projects. Get inspired to integrate new technologies into your work and think outside the box. Here you can also find information on the pilots the Center is conducting and link to our Innovation Advisors’ blogs for an inside perspective on getting them up and running.');
      break;
      
    case 'node/4':
      // Interact
      $vars['element']['#title'] = t('The Internews Center for Innovation and Learning is dedicated to promoting a culture of learning and a spirit of curiosity and exploration across the organization. Join the interactive discussion about ongoing experiments through our Innovation Advisors’ regional blogs, our pilot research blog, and the DC Headquarters blog. Use our expert database to connect with tool and project specialists and stay in the loop about upcoming events and conferences with our innovation calendar.');
      break;
  }
  
  // Handle the normal way
  return theme_menu_link($vars);
}

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