<?php
/**
 * @file
 * incil_admin.features.inc
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function incil_admin_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
