<?php

/**
 * Node preprocesser.
 */
function incil_omega_html5_alpha_preprocess_node(&$vars) {
  // Change how submitted string is.
  $vars['submitted'] = t('Created on !datetime by !username.', array(
    '!username' => $vars['name'], 
    '!datetime' => format_date(strtotime($vars['date']), 'long_date'),
  ));
}