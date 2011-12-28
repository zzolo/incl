<?php

/**
 * @file media_archive/includes/themes/media_archive.theme.inc
 *
 * Theme and preprocess functions for Media: Archive.
 */

/**
 * Preprocess function for theme('media_archive_video').
 */
function media_archive_preprocess_media_archive_video(&$variables) {
  // Build the URL for display.
  $uri = $variables['uri'];
  $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
  $parts = $wrapper->get_parameters();
  $variables['video_id'] = check_plain($parts['v']);
  
  //convert episode id from filepath to embed code
  $variables['embed_code'] = media_archive_embedcode_lookup($variables['video_id']);
  
  $variables['width'] = isset($variables['width']) ? $variables['width'] : media_archive_variable_get('width');
  $variables['height'] = isset($variables['height']) ? $variables['height'] : media_archive_variable_get('height');
  $variables['autoplay'] = isset($variables['autoplay']) ? $variables['autoplay'] : media_archive_variable_get('autoplay');
  $variables['fullscreen'] = isset($variables['fullscreen']) ? $variables['fullscreen'] : media_archive_variable_get('fullscreen');
  $variables['autoplay'] = $variables['autoplay'] ? 1 : 1;
  $variables['fullscreen'] = $variables['fullscreen'] ? 'true' : 'false';

  $variables['wrapper_id'] = 'media_archive_' . $variables['video_id'] . '_' . $variables['id'];
  
  $mp4URL = 'http://www.archive.org/download/' . $variables['video_id'] . '/' . $variables['embed_code'] . '_512kb.mp4';
  $ogvURL = 'http://www.archive.org/download/' . $variables['video_id'] . '/' . $variables['embed_code'] . '.ogv';
  
  //Fix for IE!!

  //<object width="640" height="506" classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000"><param value="true" name="allowfullscreen"/><param value="always" name="allowscriptaccess"/><param value="high" name="quality"/><param value="true" name="cachebusting"/><param value="#000000" name="bgcolor"/><param name="movie" value="http://www.archive.org/flow/flowplayer.commercial-3.2.1.swf" /><param value="config={'key':'#$aa4baff94a9bdcafce8','playlist':['format=Thumbnail?.jpg',{'autoPlay':false,'url':'Domino_Theory_512kb.mp4'}],'clip':{'autoPlay':true,'baseUrl':'http://www.archive.org/download/bavc-77620-dominotheory/','scaling':'fit','provider':'h264streaming'},'canvas':{'backgroundColor':'#000000','backgroundGradient':'none'},'plugins':{'controls':{'playlist':false,'fullscreen':true,'height':26,'backgroundColor':'#000000','autoHide':{'fullscreenOnly':true}},'h264streaming':{'url':'http://www.archive.org/flow/flowplayer.pseudostreaming-3.2.1.swf'}},'contextMenu':[{},'-','Flowplayer v3.2.1']}" name="flashvars"/><embed src="http://www.archive.org/flow/flowplayer.commercial-3.2.1.swf" type="application/x-shockwave-flash" width="640" height="506" allowfullscreen="true" allowscriptaccess="always" cachebusting="true" bgcolor="#000000" quality="high" flashvars="config={'key':'#$aa4baff94a9bdcafce8','playlist':['format=Thumbnail?.jpg',{'autoPlay':false,'url':'Domino_Theory_512kb.mp4'}],'clip':{'autoPlay':true,'baseUrl':'http://www.archive.org/download/bavc-77620-dominotheory/','scaling':'fit','provider':'h264streaming'},'canvas':{'backgroundColor':'#000000','backgroundGradient':'none'},'plugins':{'controls':{'playlist':false,'fullscreen':true,'height':26,'backgroundColor':'#000000','autoHide':{'fullscreenOnly':true}},'h264streaming':{'url':'http://www.archive.org/flow/flowplayer.pseudostreaming-3.2.1.swf'}},'contextMenu':[{},'-','Flowplayer v3.2.1']}"> </embed></object>
  

  $variables['output'] =  '<video width="' . $variables['width'] .'" height="' . $variables['height'] .'" controls>
  <source src="' . $mp4URL . '"  type=\'video/mp4; codecs="avc1.42E01E, mp4a.40.2"\'>
  <source src="' . $ogvURL . '"  type=\'video/ogg; codecs="theora, vorbis"\'>
</video>';
  
  // For users with JavaScript, these object and embed tags will be replaced
  // by an iframe, so that we can support users without Flash.
 /*
 $variables['output'] = '<object width="' . $variables['width'] . '" height="' . $variables['height'] . '">';
  $variables['output'] .= '<param value="true" name="allowfullscreen"/><param value="always" name="allowscriptaccess"/><param value="high" name="quality"/><param value="true" name="cachebusting"/><param value="#000000" name="bgcolor"/>';
  $variables['output'] .= '<param name="movie" value="http://www.archive.org/flow/flowplayer.commercial-3.2.1.swf"></param>';
  $variables['output'] .= '<param name="allowFullScreen" value="' . $variables['fullscreen'] . '"></param>';
  $variables['output'] .= '<param name="wmode" value="transparent" />';
  
  $variables['output'] .= "<param value=\"config={'key':'#$aa4baff94a9bdcafce8','playlist':['format=Thumbnail?.jpg',{'autoPlay':false,'url':'" . $variables['embed_code'] . "_512kb.mp4'}],'clip':{'autoPlay':true,'baseUrl':'http://www.archive.org/download/bavc-77620-dominotheory/','scaling':'fit','provider':'h264streaming'},'canvas':{'backgroundColor':'#000000','backgroundGradient':'none'},'plugins':{'controls':{'playlist':false,'fullscreen':true,'height':26,'backgroundColor':'#000000','autoHide':{'fullscreenOnly':true}},'h264streaming':{'url':'http://www.archive.org/flow/flowplayer.pseudostreaming-3.2.1.swf'}},'contextMenu':[{},'-','Flowplayer v3.2.1']}\" name=\"flashvars\"/>";
  
  $config = "'key':\'#$aa4baff94a9bdcafce8','playlist':['format=Thumbnail?.jpg',{'autoPlay':false,'url':'" . $variables['embed_code'] . "_512kb.mp4'}],'clip':{'autoPlay':true,'baseUrl':'http://www.archive.org/download/" . $variables['video_id'] . "/','scaling':'fit','provider':'h264streaming'},'canvas':{'backgroundColor':'#000000','backgroundGradient':'none'},'plugins':{'controls':{'playlist':false,'fullscreen':true,'height':26,'backgroundColor':'#000000','autoHide':{'fullscreenOnly':true}},'h264streaming':{'url':'http://www.archive.org/flow/flowplayer.pseudostreaming-3.2.1.swf'}},'contextMenu':[{},'-','Flowplayer v3.2.1']";


  $variables['output'] .= '<embed src="http://www.archive.org/flow/flowplayer.commercial-3.2.1.swf" type="application/x-shockwave-flash" width="' . $variables['width'] . '" height="' . $variables['height'] . '" allowfullscreen="' . $variables['fullscreen'] . 'allowfullscreen="true" allowscriptaccess="always" cachebusting="true" bgcolor="#000000" quality="high" flashvars="config={' . $config . '}"></embed>';
  $variables['output'] .= '</object>';
*/
  
/*

  $variables['output'] = <<<OUTPUT
    <object width="{$variables['width']}" height="{$variables['height']}">
      <param name="movie" value="http://www.archive.org/play/{$variables['embed_code']}"></param>
      <param name="allowFullScreen" value="{$variables['fullscreen']}"></param>
      <param name="wmode" value="transparent" />
      <embed src="http://www.archive.org/play/{$variables['embed_code']}" type="application/x-shockwave-flash" width="{$variables['width']}" height="{$variables['height']}" allowfullscreen="{$variables['fullscreen']}"></embed>
    </object>
OUTPUT;
*/

  // @todo Replace this inline JavaScript with at least calls to
  //   drupal_add_js()/drupal_get_js(), and ideally, with a behavior. Keep
  //   in mind that the solution needs to work when inside a colorbox or
  //   otherwise in an AJAX response, but that should now be possible in D7.
  
  /*

  $iframe_id = drupal_json_encode($variables['wrapper_id'] .'_iframe');
  $wrapper_id = drupal_json_encode($variables['wrapper_id']);
  $JSObject = 'Drupal.settings.media_archive[' . $wrapper_id . ']';
  $variables['output'] .= <<<OUTPUT
    <script type="text/javascript">
      if (Drupal.settings && Drupal.media_archive) {
        Drupal.settings.media_archive = Drupal.settings.media_archive || {};
        $JSObject = {};
        $JSObject.width = {$variables['width']};
        $JSObject.height = {$variables['height']};
        $JSObject.video_id = "{$variables['video_id']}";
        $JSObject.fullscreen = {$variables['fullscreen']};
        $JSObject.id = $iframe_id;
        Drupal.media_archive.insertEmbed($wrapper_id);
      }
    </script>
OUTPUT;
*/

  //drupal_add_js(drupal_get_path('module', 'media_archive') . '/js/media_archive.js');
  drupal_add_css(drupal_get_path('module', 'media_archive') . '/css/media_archive.css');
  drupal_add_js(drupal_get_path('module', 'media_archive') . '/js/flash_detect_min.js');
}

function theme_media_archive_field_formatter_styles($variables) {
  $element = $variables['element'];
  $style = $variables['style'];
  $variables['file'] = $element['#item'];
  $variables['uri'] = $variables['file']['uri'];
  $variables['style_name'] = $style['name'];
  return theme('media_archive_embed', $variables);
}

/**
 * Preview for Styles UI.
 */
function theme_media_archive_preview_style($variables) {
  $variables['uri'] = media_archive_variable_get('preview_uri');
  $variables['field_type'] = 'file';
  $variables['object'] = file_uri_to_object($variables['uri']);

  return theme('styles', $variables);
}

/**
 * NOTE: Deprecated with Styles version 2.
 */
function theme_media_archive_styles($variables) {
  $style = $variables['style'];
  $variables['file'] = $variables['object'];
  $variables['uri'] = $variables['object']->uri;
  $variables['style_name'] = $style['name'];
  return theme('media_archive_embed', $variables);
}

/**
 * @todo: get this working
 *
 * This code is for embedding videos in WYSIYWG areas, not currently working.
 * NOTE: Deprecated with Styles version 2.
 */
function theme_media_archive_embed($variables) {
  $preset_name = $variables['preset_name'];
  $preset = styles_containers_available_styles('file', 'media_archive', $preset_name);
  $output = '';
  if (!empty($preset)) {
    // Build the URL for display.
    $uri = $variables['uri'];
    $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
    $parts = $wrapper->get_parameters();

    $fullscreen_value = $autoplay = 'false';
    $in_browser = $thumbnail = FALSE;

    foreach ($preset['effects'] as $effect) {
      switch ($effect['name']) {
        case 'autoplay':
          $autoplay = $effect['data']['autoplay'] ? 'true' : 'false';
          break;
        case 'resize':
          $width = $effect['data']['width'];
          $height = $effect['data']['height'];
          break;
        case 'fullscreen':
          $fullscreen_value = $effect['data']['fullscreen'] ? 'true' : 'false';
          break;
        case 'thumbnail':
          $thumbnail = $effect['data']['thumbnail'];
      }
    }
    if (isset($variables['object']->override)) {
      $override = $variables['object']->override;
      if (isset($override['width'])) {
        $width = $override['width'];
      }
      if (isset($override['height'])) {
        $height = $override['height'];
      }
      if (isset($override['wysiwyg'])) {
        $thumbnail = TRUE;
      }
      if (isset($override['browser']) && $override['browser']) {
        $in_browser = TRUE;
        $thumbnail = TRUE;
      }
    }
    $width = isset($width) ? $width : media_archive_variable_get('width');
    $height = isset($height) ? $height : media_archive_variable_get('height');
    $video_id = check_plain($parts['v']);
    if ($thumbnail) {
      // @todo Clean this up.
      $image_variables = array(
        'path' => $wrapper->getOriginalThumbnailPath(),
        'alt' => $variables['alt'],
        'title' => $variables['title'],
        'getsize' => FALSE,
      );
      if (isset($preset['image_style'])) {
        $image_variables['path'] = $wrapper->getLocalThumbnailPath();
        $image_variables['style_name'] = $preset['image_style'];
        $output = theme('image_style', $image_variables);
      }
      else {
        // We need to add this style attribute here so that it doesn't get lost
        // If you resize a video in a node, save it, edit it, but don't adjust
        // the sizing of the video while editing, the size will revert to the
        // default.  Adding the specific size here retains the original resizing
        $WYSIWYG = isset($variables['object']->override['style']) ? $variables['object']->override['style'] : '';
        $image_variables['attributes'] = array('width' => $width, 'height' => $height, 'style' => $WYSIWYG);
        $output = theme('image', $image_variables);
      }
      if ($in_browser) {
        // Add an overlay that says 'Archive' to media library browser thumbnails.
        $output .= '<span />';
      }
    }
    else {
      $output = theme('media_archive_video', array('uri' => $uri, 'width' => $width, 'height' => $height, 'autoplay' => ($autoplay == 'true' ? TRUE : NULL), 'fullscreen' => ($fullscreen_value == 'true' ? TRUE : NULL)));
    }
  }
  return $output;
}
