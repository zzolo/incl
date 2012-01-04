<?php

/**
 * Page preprocesser.
 */
function incil_omega_html5_alpha_preprocess_page(&$vars) {
  // Let's do some special things for node pages
  if (isset($vars['node']) && is_object($vars['node'])) {
    $exclude_submitted = array('page');
    $node = $vars['node'];
    $type = node_type_get_type($node);
    
    // Add some classes
    $vars['classes_array'][] = 'node-type-' . $node->type;
    
    // Add submitted to title suffix.  Unfortunately loading
    // node types doesn't give us the node_submitted value.  WTF.
    // So we use a manual exclusion.
    if (!in_array($node->type, $exclude_submitted)) {
      $name = l(check_plain($node->name), 'user/' . $node->uid);
      $submitted = '<div class="title-submitted">' .
          t('Created on !datetime by !username.', array(
              '!username' => $name, 
              '!datetime' => format_date($node->created, 'long_date'),
          )) . '
          </div>
        ';
      $vars['title_suffix']['node_submitted'] = array(
        '#markup' => $submitted,
      );
    }
  }
}