<?php
/**
 * @file
 * incil_tools.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function incil_tools_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function incil_tools_node_info() {
  $items = array(
    'tool' => array(
      'name' => t('Tool'),
      'base' => 'node_content',
      'description' => t('Tools are specific technologies or techniques that are relevant to the InterNews community.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Fill out the following information as most completely as you can.  (TODO: fill this help in more.)'),
    ),
  );
  return $items;
}
