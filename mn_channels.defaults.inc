<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_channels_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-channels';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'channel' => 'channel',
      ),
      'options' => array(
        'node_form' => 1,
      ),
    ),
    'views' => array(
      'values' => array(
        'mn_channels' => 'mn_channels',
        'mn_channels_news' => 'mn_channels_news',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mn_core-print' => array(
          'module' => 'mn_core',
          'delta' => 'print',
          'region' => 'palette',
          'weight' => 0,
        ),
        'views_modes-modes' => array(
          'module' => 'views_modes',
          'delta' => 'modes',
          'region' => 'page_tools',
          'weight' => 0,
        ),
        'mn_core-formats' => array(
          'module' => 'mn_core',
          'delta' => 'formats',
          'region' => 'page_tools',
          'weight' => 1,
        ),
        'views-mn_channels-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_channels-block_1',
          'region' => 'left',
          'weight' => 0,
        ),
        'views-mn_channels-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_channels-block_2',
          'region' => 'right',
          'weight' => 0,
        ),
        'views-mn_channels_news-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_channels_news-block_1',
          'region' => 'right',
          'weight' => 1,
        ),
        'views-mn_channels_news-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_channels_news-block_2',
          'region' => 'right',
          'weight' => 2,
        ),
      ),
    ),
    'menu' => 'channels',
  );

  $export['mn-section-channels'] = $context;
  return $export;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _mn_channels_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "context" && $api == "context") {
    return array("version" => 3);
  }
  else if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _mn_channels_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Channels',
    'path' => 'channels',
    'weight' => '2',
    'description' => 'Channels contain news organized around topics. People can view, print and subscribe to the items in channels.',
  );
  // Translatables
  array(
    t('Channels'),
    t('Channels contain news organized around topics. People can view, print and subscribe to the items in channels.'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _mn_channels_user_default_permissions() {
  $permissions = array();

  // Exported permission: create channel content
  $permissions[] = array(
    'name' => 'create channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any channel content
  $permissions[] = array(
    'name' => 'delete any channel content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own channel content
  $permissions[] = array(
    'name' => 'delete own channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit any channel content
  $permissions[] = array(
    'name' => 'edit any channel content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own channel content
  $permissions[] = array(
    'name' => 'edit own channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _mn_channels_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_channel';
  $strongarm->value = array(
    '0' => 'status',
  );

  $export['node_options_channel'] = $strongarm;
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'upload_channel';
  $strongarm->value = '0';

  $export['upload_channel'] = $strongarm;
  return $export;
}
