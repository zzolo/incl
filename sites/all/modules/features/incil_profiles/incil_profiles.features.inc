<?php
/**
 * @file
 * incil_profiles.features.inc
 */

/**
 * Implementation of hook_default_profile2_type().
 */
function incil_profiles_default_profile2_type() {
  $items = array();
  $items['profile'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "profile",
    "label" : "Profile",
    "weight" : "0",
    "data" : { "registration" : 1 }
  }');
  return $items;
}
