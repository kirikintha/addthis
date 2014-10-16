/**
 * Wishlist API JS
 *  Since the links can be placed dynamically, we can't run ajax through the normal
 *  Api.
 * @param {objecy} $ Jquery API
 */
(function ($) {
  //Wishlist Behavior.
  Drupal.behaviors.addThis = {
    settings: {},
    //Attach.
    attach: function (context, settings) {
      if (settings.addThis !== undefined) {
        this.addThisInit(context, settings);
      }
    },
    //Add This async integration.
    addThisInit: function (context, settings) {
      console.debug(settings.addThis);
      //Initialixe Add this.
      addthis_config.pubid = settings.addThis.pubId;
      //Pinterest Options.
      if (settings.addThis.image_include !== undefined) {
        addthis_config.image_include = settings.addThis.image_include;
      }
      if (settings.addThis.image_exclude !== undefined) {
        addthis_config.image_exclude = settings.addThis.image_exclude;
      }
      if (settings.addThis.image_container !== undefined) {
        addthis_config.image_container = settings.addThis.image_container;
      }
      addthis.init();
      this.buildSocialLinks();
    },
    buildSocialLinks: function () {
      //Reset addthis toolbox.
      var toolbox = $('.addthis_toolbox');
      if (toolbox.length > 0) {
        addthis.toolbox('.addthis_toolbox');
      }
    }
  };
//End.
})(jQuery);