<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_channels_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'section',
    'value' => 'channels',
    'description' => '',
    'node' => array(
      '0' => 'channel',
    ),
    'views' => array(
      '0' => 'mn_channels',
      '1' => 'mn_channels_news',
    ),
    'block' => array(
      'mn_core_print' => array(
        'module' => 'mn_core',
        'delta' => 'print',
        'weight' => 20,
        'region' => 'palette',
        'status' => '0',
        'label' => 'MN: Print controls',
        'type' => 'context_ui',
      ),
      'views_modes_modes' => array(
        'module' => 'views_modes',
        'delta' => 'modes',
        'weight' => 20,
        'region' => 'page_tools',
        'status' => '0',
        'label' => 'Views mode links',
        'type' => 'context_ui',
      ),
      'mn_core_formats' => array(
        'module' => 'mn_core',
        'delta' => 'formats',
        'weight' => 21,
        'region' => 'page_tools',
        'status' => '0',
        'label' => 'MN: Alternative formats',
        'type' => 'context_ui',
      ),
      'views_mn_channels-block_1' => array(
        'module' => 'views',
        'delta' => 'mn_channels-block_1',
        'weight' => -21,
        'region' => 'left',
        'status' => '0',
        'label' => 'mn_channels: Block: list of channels',
        'type' => 'context_ui',
      ),
      'views_mn_channels-block_2' => array(
        'module' => 'views',
        'delta' => 'mn_channels-block_2',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_channels: Block: channel node',
        'type' => 'context_ui',
      ),
      'views_mn_channels_news-block_1' => array(
        'module' => 'views',
        'delta' => 'mn_channels_news-block_1',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_channels_news: Block: Trend graph',
        'type' => 'context_ui',
      ),
      'views_mn_channels_news-block_2' => array(
        'module' => 'views',
        'delta' => 'mn_channels_news-block_2',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_channels_news: Block: Map',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
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
    'description' => 'Channels are continuously updated collections of news that you can subscribe to. news that ',
  );
  // Translatables
  array(
    t('Channels'),
    t('Channels are continuously updated collections of news that you can subscribe to. news that '),
  );


  return $items;
}
