<?php
/**
 * @file
 * incil_pages.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function incil_pages_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implementation of hook_node_info().
 */
function incil_pages_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('Page is a single, mostly static, piece of content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Fill in the following to make a new page on the site.  Use the menu settings to add the page to a relevant menu.'),
    ),
  );
  return $items;
}
