/**
 * @file
 * Main theme JS for INCIL theme.
 */
 
// Namespace jQuery
(function($) {
 
/**
 * Simple accordian for admin menus
 */
Drupal.behaviors.incilThemeAccordian = {
  attach: function(context, settings) {
    // Only handle once
    $('body').once('incil-accordian', function() {
      // Simple accordian for admin menus
      var s = {
        admin: '.region-sidebar-second .block-menu-administration',
        inno: '.region-sidebar-second .block-menu-innovation-advisor',
        user: '.region-sidebar-second .block-menu-user-content-menu'
      };
      $blocks = $(s.admin + ',  ' + s.inno + ', ' + s.user);
      
      // Simple function for click and initial state
      var accordiate = function(block, init) {
        // Close all, if init, then just hide
        if (init == true) {
          $blocks.find('div.content').hide();
        }
        else {
          $blocks.find('div.content').slideUp('normal');
        }
        $blocks.removeClass('incil-accordian-open');
        $blocks.addClass('incil-accordian-closed');
        
        // Show specific
        $(s[block]).find('div.content').slideDown('normal');
        $(s[block]).removeClass('incil-accordian-closed')
          .addClass('incil-accordian-open');
      };
      
      // Initial state
      accordiate('user', true);
      
      // Click handlers (weird event with loops)
      $(s.admin + ' h2.block-title').click(function(e) { accordiate('admin'); });
      $(s.inno + ' h2.block-title').click(function(e) { accordiate('inno'); });
      $(s.user + ' h2.block-title').click(function(e) { accordiate('user'); });
    });
  },
  detach: function(context, settings) {
    // ...
  }
};

})(jQuery);