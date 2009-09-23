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
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _mn_channels_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "openlayers" && $api == "openlayers_presets") {
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
    'description' => 'Channels are continuously updated collections of news that you can subscribe to. news that ',
  );
  // Translatables
  array(
    t('Channels'),
    t('Channels are continuously updated collections of news that you can subscribe to. news that '),
  );


  return $items;
}

/**
 * Helper to implementation of hook_openlayers_presets().
 */
function _mn_channels_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_channels';
  $openlayers_presets->title = 'MN channels';
  $openlayers_presets->description = 'A simple basemap of the world w00t foo bar hello world';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '200px',
    'image_path' => 'sites/all/themes/jake/openlayers',
    'center' => array(
      'lat' => '2555882.9842109',
      'lon' => '771708.23746027',
      'zoom' => '2',
    ),
    'behaviors' => array(
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
      'openlayers_behavior_navigation' => array(),
    ),
    'default_layer' => 'world',
    'layers' => array(
      'world' => 'world',
      'mn_channels_news_attachment_1' => 'mn_channels_news_attachment_1',
    ),
    'layer_styles' => array(),
    'projection' => '900913',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => array(
      'displayProjection' => '4326',
      'maxResolution' => '156543.0339',
      'maxExtent' => array(
        'left' => '-20037508.34',
        'right' => '20037508.34',
        'top' => '20037508.34',
        'bottom' => '-20037508.34',
      ),
    ),
  );

  $export['mn_channels'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_fullscreen_channels';
  $openlayers_presets->title = 'MN fullscreen channels';
  $openlayers_presets->description = 'A simple fullscreen map of the world.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => 'auto',
    'image_path' => 'sites/all/themes/jake/openlayers',
    'center' => array(
      'lat' => '2555882.9842109',
      'lon' => '771708.23746027',
      'zoom' => '2',
    ),
    'behaviors' => array(
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_panzoombar' => array(),
    ),
    'default_layer' => 'world_light',
    'layers' => array(
      'world_light' => 'world_light',
      'world' => 'world',
      'osmmapnik' => 'osmmapnik',
      'mn_channels_news_attachment_1' => 'mn_channels_news_attachment_1',
    ),
    'layer_styles' => array(),
    'projection' => '900913',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => array(
      'displayProjection' => '4326',
      'maxResolution' => '156543.0339',
      'maxExtent' => array(
        'left' => '-20037508.34',
        'right' => '20037508.34',
        'top' => '20037508.34',
        'bottom' => '-20037508.34',
      ),
    ),
  );

  $export['mn_fullscreen_channels'] = $openlayers_presets;
  return $export;
}
