<?php

/**
 * @file addthis_handler_field_addthis_widget.inc
 * Handler for node add this field.
 */

/**
 * Field handler to present an add this widget to your node view.
 *
 * @ingroup views_field_handlers
 */
class addthis_handler_field_addthis_widget extends views_handler_field {

  private $__theme;
  private $__widget;
  private $__toolbox_link = 'http://support.addthis.com/customer/portal/articles/381238-addthis-toolbox';
  private $__pinterest_link = 'http://support.addthis.com/customer/portal/articles/1300322-pinterest-image-sharing';

  function construct() {
    parent::construct();
    $this->__theme = addthis_theme();
    $this->__widget = $this->__theme['addthis_widget'];
  }

  function query() {
    //Do Nothing
  }

  function option_definition() {
    $options = parent::option_definition();
    //Create Options for he widget.
    $options['addthis']['classes'] = array('default' => $this->__widget['addthis']['classes']);
    $options['addthis']['buttons'] = array('default' => $this->__widget['addthis']['buttons']);
    //Url, Title and Description can accept replacement patterns.
    $options['addthis']['url'] = array('default' => '');
    $options['addthis']['title'] = array('default' => '');
    $options['addthis']['description'] = array('default' => '');
    //Pinterest Image Sharing Options.
    $options['addthis']['image_include'] = array('default' => '');
    $options['addthis']['image_exclude'] = array('default' => '');
    $options['addthis']['image_container'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $link_attributes = array('attributes' => array('target' => '_blank'));
    $links = array(
      '!toolbox_link' => l($this->__toolbox_link, $this->__toolbox_link, $link_attributes),
      '!pinterest_link' => l($this->__pinterest_link, $this->__pinterest_link, $link_attributes)
    );
    $form['addthis'] = array(
      '#title' => t('Add This Widget'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => FALSE,
      '#weight' => 0,
      '#tree' => TRUE,
    );
    //Widget Options.
    $form['addthis']['classes'] = array(
      '#type' => 'textarea',
      '#required' => true,
      '#title' => t('Widget Classes'),
      '#description' => t('These are the default classes for a widget. See: !toolbox_link', $links),
      '#default_value' => $this->options['addthis']['classes'],
    );
    $form['addthis']['buttons'] = array(
      '#type' => 'textarea',
      '#required' => true,
      '#title' => t('Widget Buttons'),
      '#description' => t('These are the default buttons for a widget.'),
      '#default_value' => $this->options['addthis']['buttons'],
    );
    //Sharing Pieces
    $form['addthis']['url'] = array(
      '#type' => 'textfield',
      '#required' => true,
      '#title' => t('Widget Url'),
      '#description' => t('This is the url, you can use the tokens below for this.'),
      '#default_value' => $this->options['addthis']['url'],
    );
    $form['addthis']['title'] = array(
      '#type' => 'textfield',
      '#required' => true,
      '#title' => t('Widget Title'),
      '#description' => t('This is the title, you can use the tokens below for this.'),
      '#default_value' => $this->options['addthis']['title'],
    );
    $form['addthis']['description'] = array(
      '#type' => 'textfield',
      '#required' => true,
      '#title' => t('Widget Description'),
      '#description' => t('This is the description, you can use the tokens below for this.'),
      '#default_value' => $this->options['addthis']['description'],
    );
    $form['addthis']['help']['#markup'] = $form['alter']['help']['#value'];
    //Pinterest Image Sharing.
    $form['addthis']['image_include'] = array(
      '#type' => 'textfield',
      '#title' => t('Pinterest: Image Include'),
      '#description' => t('You can instruct the pinterest share preview to only grab specific images from the page by using the “image_include” configuration option. See: !pinterest_link', $links),
      '#default_value' => $this->options['addthis']['image_include'],
    );
    $form['addthis']['image_exclude'] = array(
      '#type' => 'textfield',
      '#title' => t('Pinterest: Image Exclude'),
      '#description' => t('You can instruct the pinterest share preview to ignore specific images from the page by using the image_exclude configuration option. See: !pinterest_link', $links),
      '#default_value' => $this->options['addthis']['image_exclude'],
    );
    $form['addthis']['image_container'] = array(
      '#type' => 'textfield',
      '#title' => t('Pinterest: Image Container'),
      '#description' => t('You can also instruct the pinterest share preview to grab images from a specific container, such as all the images contained within the class or id that has a Pinterest share button. See: !pinterest_link', $links),
      '#default_value' => $this->options['addthis']['image_container'],
    );
  }

  function render($values) {
    //Get replacement tokens.
    $tokens = $this->get_render_tokens($this->options['alter']);
    //Make sure the classes are in tact.
    $widget = array();
    $widget['classes'] = filter_xss_admin($this->options['addthis']['classes']);
    $widget['buttons'] = filter_xss_admin($this->options['addthis']['buttons']);
    //Pinterest Image Sharing Adjustments.
    $widget['image_include'] = filter_xss_admin($this->options['addthis']['image_include']);
    $widget['image_exclude'] = filter_xss_admin($this->options['addthis']['image_exclude']);
    $widget['image_container'] = filter_xss_admin($this->options['addthis']['image_container']);
    //Replacement Patterns.
    $url = filter_xss_admin($this->options['addthis']['url']);
    $title = filter_xss_admin($this->options['addthis']['title']);
    $description = filter_xss_admin($this->options['addthis']['description']);
    $widget['url'] = strtr($url, $tokens);
    $widget['title'] = strtr($title, $tokens);
    $widget['description'] = strtr($description, $tokens);
    return theme('addthis_widget', array('addthis' => $widget));
  }

}
