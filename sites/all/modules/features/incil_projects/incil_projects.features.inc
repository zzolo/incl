<?php
/**
 * @file
 * incil_projects.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function incil_projects_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function incil_projects_node_info() {
  $items = array(
    'project' => array(
      'name' => t('Project'),
      'base' => 'node_content',
      'description' => t('Project is a specific use of tools for a specific place or group of people.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Please fill in the information as completely as possible.  (TODO: fill this help in better)'),
    ),
  );
  return $items;
}
