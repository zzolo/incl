<?php

/**
 *  @file
 *  Administrative page callbacks for Media: Archive.
 */

/**
 *  Callback for /media/add/media_archive and
 *  /admin/content/media/add/media_archive.
 */
function media_archive_add($form, &$form_state = array(), $redirect = NULL) {
  global $user;

  $form = array();
  $form['archive'] = array(
    '#type' => 'vertical_tabs',
  );
  $form['archive']['all'] = array(
    '#type' => 'fieldset',
    '#title' => t('All Archive videos'),
  );

  // Get all archive files for this user
  $results = db_query("SELECT fid FROM {file_managed} WHERE uid = :uid AND uri LIKE :uri", array(
    ':uid' => $user->uid,
    ':uri' => 'archive%%'
  ))->fetchAll();

  foreach ($results as $result) {
    $file = file_load($result->fid);
    $output = theme('image', array(
      'path' => 'http://img.archive.org/vi/' . pathinfo($file->uri, PATHINFO_FILENAME) . '/0.jpg',
      'title' => 'title',
      'alt' => 'alt',
      'attributes' => array('width' => 150),
      'getsize' => FALSE,
    ));
    $form['archive']['all'][$file->fid] = array(
      '#markup' => $output,
    );
  }

/*  $form['archive']['all']['test'] = array(
    '#type' => 'checkbox',
    '#title' => 'test',
  );*/
  $form['archive']['add_from_url'] = array(
    '#type' => 'fieldset',
    '#title' => t('Add from URL'),
  );
  $form['archive']['add_from_url']['url'] = array(
    '#type' => 'textfield',
    '#title' => 'URL',
    '#description' => 'Input the URL of the desired Archive video page.',
  );
  $form['redirect'] = array(
    '#type' => 'value',
    '#value' => $redirect,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}

/**
 *  Validation for media_archive_add().
 */
function media_archive_add_validate($form, &$form_state) {
  if (!preg_match('@blip\.tv/file/([^"\& ]+)@i', $form_state['values']['url'], $matches)) {
    form_set_error('url', t('Please submit a valid Archive video URL.'));
  }
}

/**
 *  Submission for media_archive_add().
 *
 *  This will create a file object for the Archive video.
 */
function media_archive_add_submit($form, &$form_state) {
  $defaults = array (
    'display' => TRUE,
  );

  $uri = media_archive_media_parse($form_state['values']['url']);

  // Check to see if this a duplicate of an existing file
  $files = file_load_multiple(NULL, array('uri' => $uri));
  if ($files) {
    // This is ugly.
    $file = array_shift($files);
  }
  else {
    // @TODO: This won't work for Archive and many other streams.
    // copy($url, $destination);
    $file = file_uri_to_object($uri);
    file_save($file);
  }

  // field_attach_insert('media', $file);
  if ($file) {
    $form_state['redirect'] = 'media/' . $file->fid . '/edit';
    field_attach_submit('media', $file, $form, $form_state);
    field_attach_insert('media', $file);
  }
  else {
    drupal_set_message(t('An error occurred and no file was saved.'), 'error');
  }

  $form_state['redirect'] = !empty($form_state['values']['redirect']) ? $form_state['values']['redirect'] : 'media/' . $file->fid . '/edit';
}
