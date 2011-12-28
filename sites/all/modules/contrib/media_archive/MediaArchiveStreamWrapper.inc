<?php

/**
 *  @file
 *  Create a Archive Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $archive = new ResourceArchiveStreamWrapper('archive://?v=[video-code]');
 */
class MediaArchiveStreamWrapper extends MediaReadOnlyStreamWrapper {
  protected $base_url = 'http://archive.org/file';

  function getTarget($f) {
    return FALSE;
  }

  static function getMimeType($uri, $mapping = NULL) {
    return 'video/archive';
  }

  function getOriginalThumbnailPath() {
    $parts = $this->get_parameters();
    return 'http://www.archive.org/download/'. check_plain($parts['v']) .'/' . check_plain($parts['v']) .'.thumbs/' . check_plain($parts['org']) .'_000001.jpg';

  }

  function getLocalThumbnailPath() {
    $parts = $this->get_parameters();
    $local_path = 'public://media-archive/' . check_plain($parts['v']) . '.jpg';
    if (!file_exists($local_path)) {
      $dirname = drupal_dirname($local_path);
      file_prepare_directory($dirname, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
      @copy($this->getOriginalThumbnailPath(), $local_path);
    }
    return $local_path;
  }
}
