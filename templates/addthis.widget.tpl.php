<?php
/**
 * @file addthis.widget.tpl
 *  This is the template for your add this widget.
 *  This does not handle custom images, but you could easily just roll your own
 *  Widget with another template file, and design it yourself!
 *  
 *  Default Classes: 
 *    addthis_toolbox 
 *    addthis_default_style 
 *    addthis_32x32_style
 * 
 *  Default Buttons: 
 *    addthis_button_preferred_1 
 *    addthis_button_preferred_2 
 *    addthis_button_preferred_3 
 *    addthis_button_preferred_4
 * 
 *  Additional Button Options:
 *    addthis_button_email
 *    addthis_button_pinterest_share
 *    addthis_button_facebook
 *    addthis_button_twitter
 *    addthis_button_google_plusone_share
 *    addthis_button_compact
 */
?>
<?php if (!empty($variables['addthis']['url']) && !empty($variables['addthis']['title']) 
  && !empty($variables['addthis']['description']) && !empty($variables['addthis']['buttons'])): ?>
<!--Add This Widget-->
<div class="<?php echo $variables['addthis']['classes']; ?>" 
     addthis:url="<?php echo $variables['addthis']['url']; ?>" 
     addthis:title="<?php echo $variables['addthis']['title']; ?>" 
     addthis:description="<?php echo $variables['addthis']['description']; ?>">
  <?php foreach ($variables['addthis']['buttons'] as $button): ?>
    <a class="<?php echo $button; ?>" <?php if ($button === 'addthis_button_facebook_like') : echo 'fb:like:layout="button_count"'; endif; ?>></a>
  <?php  endforeach; ?>
</div>
<?php endif; ?>