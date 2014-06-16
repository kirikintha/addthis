<?php

/**
 * @file admin.addthis.inc
 *  Main Admin section is here.
 */
function addthis_admin() {
  $form = drupal_get_form('addthis_admin_form');

  $page['content'] = array(
    'admin_form' => $form,
  );
  return drupal_render($page);
}

/**
 * Addthis admin form.
 *  This saves the configuration options for add this.
 * @param array $form
 * @param type $form_state
 * @return array
 */
function addthis_admin_form($form, &$form_state) {
  $pubid = ADDTHIS_PUBID;
  //Create Form.
  $form['#theme'] = 'addthis_admin_form';
  $form['addthis_pubid'] = array(
    '#type' => 'textfield',
    '#required' => true,
    '#title' => t('PubId'),
    '#description' => t('This field must start with "ra-%youridhere"'),
    '#attributes' => array(
      'placeholder' => t('Enter your "pubid" here'),
      'autocomplete' => 'off',
    ),
    '#default_value' => $pubid,
  );
  $msg = array(
    '@msg' => 'Asynchronous loading allows you to put our bootloader script – addthis_widget.js – on your page without loading the other assets until you’re ready.',
    '!link' => l('click here for more info', 'http://support.addthis.com/customer/portal/articles/1293805-using-addthis-asynchronously#.U58Nzo1dU9V'),
  );
  $form['addthis_async'] = array(
    '#type' => 'checkbox',
    '#title' => t('Asynchronous Loading'),
    '#description' => t('@msg !link', $msg),
    '#default_value' => variable_get('addthis_async', null),
  );
  $form['addthis_disallowed'] = array(
    '#type' => 'textarea',
    '#title' => 'Disallowed paths',
    '#description' => 'Add paths you want to disallow. One per line. /admin and /user paths are *always* disallowed. '
    . 'Note, this only disables the script. You can always choose to manage your add this account on your own, or simply do not place '
    . 'any buttons on a page. The addthis script is only a few bytes, so it is incredibly small.',
    '#default_value' => variable_get('addthis_disallowed', null),
  );
  return system_settings_form($form);
}

/**
 * Validate admin form
 * @param type $form
 * @param type $form_state
 */
function addthis_admin_form_validate(&$form, &$form_state) {
  //If we have a value, then make sure it is correct.
  $pattern = '/^ra\-[a-zA-z0-9]+/';
  $pubid = $form_state['values']['addthis_pubid'];
  if (!preg_match($pattern, $pubid)) {
    $message = 'PubId must start with "ra-" and can contain only letters and numbers';
    form_set_error('pubid', $message);
  }
}
