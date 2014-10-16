<?php

/**
 * @file addthis.views.inc
 * Provide views data and handlers for addthis.module.
 *
 * @ingroup views_module_handlers
 */

/**
 * Implements hook_views_data().
 */
function addthis_views_data() {

  $data = array();

  $data['addthis']['table']['group'] = t('Add This');

  $data['addthis']['table']['join'] = array(
    '#global' => array(),
  );

  $data['addthis']['widget'] = array(
    'field' => array(
      'title' => t('Add This'),
      'help' => t('Add This widget'),
      'handler' => 'addthis_handler_field_addthis_widget',
    ),
  );

  return $data;
}
