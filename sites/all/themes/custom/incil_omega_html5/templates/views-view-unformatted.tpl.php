<?php
/**
 * @file views-view-unformatted.tpl.php
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

// Add classes to row array
incil_omega_html5_preprocess_views_type_class($view, $classes_array);
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="<?php print $classes_array[$id]; ?> clearfix">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>