<?php

/**
 * @file
 * INCIL theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - regions[header_top] = Header top
 * - regions[header_bottom] = Header bottom
 * - regions[banner] = Banner
 * - regions[messages] = Messages
 * - regions[help] = Help
 * - regions[content] = Content
 * - regions[sidebar_right] = Sidebar right
 * - regions[footer_top] = Footer
 * - regions[footer_left] = Footer left
 * - regions[footer_right] = Footer right
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 */
?>

<div id="page-wrapper">
  <div id="page">

    <!-- Header -->
    <div id="header">
      <div class="section clearfix">

        <!-- Logo -->
        <?php if ($logo): ?>
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
        <?php endif; ?>

        <!-- Name and Slogan -->
        <?php if ($site_name || $site_slogan): ?>
          <div id="name-and-slogan">
            <?php if ($site_name): ?>
              <?php if ($title): ?>
                <div id="site-name"><strong>
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
                </strong></div>
              <?php else: /* Use h1 when the content title is empty */ ?>
                <h1 id="site-name">
                  <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a>
                </h1>
              <?php endif; ?>
            <?php endif; ?>
  
            <?php if ($site_slogan): ?>
              <div id="site-slogan"><?php print $site_slogan; ?></div>
            <?php endif; ?>
          </div>
        <?php endif; ?>

        <!-- Header Top -->
        <div class="header-top">
          <?php print render($page['header_top']); ?>
        </div>

        <!-- Header Bottom -->
        <div class="header-bottom">
          <!-- Main Menu -->
          <?php if ($main_menu || $secondary_menu): ?>
            <div id="navigation">
              <div class="section">
                <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Main menu'))); ?>
                <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Secondary menu'))); ?>
              </div>
            </div>
          <?php endif; ?>
          
          <?php print render($page['header_bottom']); ?>
        </div>
      </div>
    </div>
  
    <!-- Main Content -->
    <div id="main-wrapper">
      <div id="main" class="clearfix">
      
        <!-- Messages -->
        <div class="messages-container">
          <?php print $messages; ?>
        </div>
        
        <!-- Banner -->
        <?php if ($page['banner']): ?>
          <div class="banner-container">
            <?php print render($page['banner']); ?>
          </div>
        <?php endif; ?>
        
        <!-- Content -->
        <div id="content-container" class="column">
          <div class="section">
            <?php if ($page['highlighted']): ?>
              <div id="highlighted">
                <?php print render($page['highlighted']); ?>
              </div>
            <?php endif; ?>
            
            <a id="main-content"></a>
            
            <!-- Title -->
            <?php print render($title_prefix); ?>
            <?php if ($title): ?>
              <h1 class="title" id="page-title"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($title_suffix); ?>
            
            <!-- Tabs -->
            <?php if ($tabs): ?>
              <div class="tabs">
                <?php print render($tabs); ?>
              </div>
            <?php endif; ?>
            
            <!-- Help -->
            <?php if ($page['help']): ?>
              <div class="help-container">
                <?php print render($page['help']); ?>
              </div>
            <?php endif; ?>
            
            <!-- Action Links -->
            <?php if ($action_links): ?>
              <ul class="action-links">
                <?php print render($action_links); ?>
              </ul>
            <?php endif; ?>
            
            <!-- Actual Content -->
            <div class="content-container-inner">
              <?php print render($page['content']); ?>
            </div>
            
            <!-- Feed Icons -->
            <?php print $feed_icons; ?>
          </div>
        </div>
  
        <!-- Sidebar Right -->
        <?php if ($page['sidebar_right']): ?>
          <div id="sidebar-right" class="column sidebar">
            <div class="section">
              <?php print render($page['sidebar_first']); ?>
            </div>
          </div>
        <?php endif; ?>
  
      </div>
    </div>
  
    <!-- Footer -->
    <div id="footer">
      <div class="section">
        <!-- Footer Main -->
        <?php print render($page['footer']); ?>
        
        <!-- Footer Left -->
        <?php if ($page['footer_left']): ?>
          <div class="footer-left-container">
            <div class="section">
              <?php print render($page['footer_left']); ?>
            </div>
          </div>
        <?php endif; ?>
        
        <!-- Footer Right -->
        <?php if ($page['footer_right']): ?>
          <div class="footer-right-container">
            <div class="section">
              <?php print render($page['footer_right']); ?>
            </div>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
