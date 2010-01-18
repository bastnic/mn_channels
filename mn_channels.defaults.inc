<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_channels_context_default_contexts() {
  $export = array();
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-channels-tools';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        '0' => 'channel',
      ),
      'options' => array(
        'node_form' => TRUE,
      ),
    ),
    'path' => array(
      'values' => array(
        'feeds*' => 'feeds*',
        'search*' => 'search*',
        'stored-views*' => 'stored-views*',
      ),
      'options' => array(),
    ),
    'views' => array(
      'values' => array(
        '0' => 'mn_channels',
        '1' => 'mn_channels_news',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'data_node-feeds_data_syndication' => array(
          'module' => 'data_node',
          'delta' => 'feeds_data_syndication',
          'weight' => 18,
          'region' => 'palette',
          'status' => '0',
          'label' => 'Data node: Active node form for Syndication',
          'type' => 'context_ui',
        ),
      ),
    ),
  );

  $export['mn-channels-tools'] = $context;
  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'mn-section-channels';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        '0' => 'channel',
      ),
      'options' => array(
        'node_form' => TRUE,
      ),
    ),
    'views' => array(
      'values' => array(
        '0' => 'mn_channels',
        '1' => 'mn_channels_news',
      ),
      'options' => array(),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'mn_core-print' => array(
          'module' => 'mn_core',
          'delta' => 'print',
          'weight' => 20,
          'region' => 'palette',
          'status' => '0',
          'label' => 'MN: Print controls',
          'type' => 'context_ui',
        ),
        'views_modes-modes' => array(
          'module' => 'views_modes',
          'delta' => 'modes',
          'weight' => 20,
          'region' => 'page_tools',
          'status' => '0',
          'label' => 'Views mode links',
          'type' => 'context_ui',
        ),
        'mn_core-formats' => array(
          'module' => 'mn_core',
          'delta' => 'formats',
          'weight' => 21,
          'region' => 'page_tools',
          'status' => '0',
          'label' => 'MN: Alternative formats',
          'type' => 'context_ui',
        ),
        'views-mn_channels-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_channels-block_1',
          'weight' => -21,
          'region' => 'left',
          'status' => '0',
          'label' => 'mn_channels: Block: list of channels',
          'type' => 'context_ui',
        ),
        'views-mn_channels-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_channels-block_2',
          'weight' => 20,
          'region' => 'right',
          'status' => '0',
          'label' => 'mn_channels: Block: channel node',
          'type' => 'context_ui',
        ),
        'views-mn_channels_news-block_1' => array(
          'module' => 'views',
          'delta' => 'mn_channels_news-block_1',
          'weight' => 21,
          'region' => 'right',
          'status' => '0',
          'label' => 'mn_channels_news: Block: Trend graph',
          'type' => 'context_ui',
        ),
        'views-mn_channels_news-block_2' => array(
          'module' => 'views',
          'delta' => 'mn_channels_news-block_2',
          'weight' => 22,
          'region' => 'right',
          'status' => '0',
          'label' => 'mn_channels_news: Block: Map',
          'type' => 'context_ui',
        ),
      ),
    ),
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
