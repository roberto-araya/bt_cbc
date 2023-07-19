<?php

/**
 * @file
 * Block style for bt_cb_title_icon.
 */

/**
 * Module bt_cb_title_icon standard.
 */
function _bt_cb_title_icon_style_form_builder() {
  $block_style = [
    'title' => _title_styles_form_element_builder(),
    'caption' => _caption_styles_form_element_builder(),
  ];
  $block_style['icon'] = [
    '#type' => 'details',
    '#title' => t('Icon'),
    '#tree' => TRUE,
    '#weight' => 10,
    'size' => [
      '#type' => 'details',
      '#title' => t('Size'),
      '#tree' => TRUE,
      '#weight' => 10,
    ],
  ];

  $colors = _block_style_color('icon');
  $block_style['icon']['color_select'] = $colors['color_select'];
  $block_style['icon']['color_custom'] = $colors['color_custom'];

  return $block_style;
}

/**
 * Module bt_cb_title_icon layout builder.
 */
function _bt_cb_title_icon_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_title_icon_style_form_builder();

  $block_style['title']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_select');
  $block_style['title']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_custom');
  $block_style['title']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_font_family');

  $block_style['caption']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_select');
  $block_style['caption']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_custom');
  $block_style['caption']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_font_family');

  $block_style['icon']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_select');
  $block_style['icon']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_custom');

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_' . $prefix . '_font_size');

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_' . $prefix . '_font_size');

    $block_style['icon']['size'][$prefix] = _block_style_icon_size($breakpoint);
    $block_style['icon']['size'][$prefix]['size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_' . $prefix . '_size');
  }

  return $block_style;
}

/**
 * Module bt_cb_title_icon block layout.
 */
function _bt_cb_title_icon_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_title_icon_style_form_builder();
  $title_default_values = $block->getThirdPartySetting('bt_cbc', 'title');
  $block_style['title']['color_select']['#default_value'] = $title_default_values ? $title_default_values['color_select'] : '';
  $block_style['title']['color_custom']['#default_value'] = $title_default_values ? $title_default_values['color_custom'] : '';
  $block_style['title']['font_family']['#default_value'] = $title_default_values ? $title_default_values['font_family'] : '';

  $caption_default_values = $block->getThirdPartySetting('bt_cbc', 'caption');
  $block_style['caption']['color_select']['#default_value'] = $caption_default_values ? $caption_default_values['color_select'] : '';
  $block_style['caption']['color_custom']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';
  $block_style['caption']['font_family']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';

  $screens = _get_screens_breakpoints();

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $title_default_values ? $title_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $caption_default_values ? $caption_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['icon']['size'][$prefix] = _block_style_icon_size($breakpoint);
    $block_style['icon']['size'][$prefix]['size']['#default_value'] = $default_values ? $default_values['size'][$prefix]['size'] : '';
  }

  $default_values = $block->getThirdPartySetting('bt_cbc', 'icon');
  $block_style['icon']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['icon']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Module bt_cb_title_icon layout builder sumbit.
 */
function _bt_cb_title_icon_style_layout_builder_form_submit($form_state, $section_component) {
  // title.
  _title_styles_layout_builder_form_element_sumbit($form_state, $section_component);
  // caption.
  _caption_styles_layout_builder_form_element_sumbit($form_state, $section_component);

  foreach (['xs', 'sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
    // Title Font Size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'title',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'title_' . $prefix, $get_value);

    // Caption Font Size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'caption',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'caption_' . $prefix, $get_value);

    // Icon size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'icon',
      'size',
      $prefix,
      'size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon_' . $prefix, $get_value);
  }

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'size'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);
}

/**
 * Preprocess for bt_cb_title_icon blocks.
 */
function _bt_cb_title_icon_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');

  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'icon')) {
    foreach ($settings as $setting => $value) {
      if ($setting == 'size') {
        foreach ($value as $prefix => $val) {
          $variables['configuration']['block_style'][$element . '_' . $prefix . '_' . $setting] = $val['size'];
        }
      }
      else {
        $variables['configuration']['block_style'][$element . '_' . $setting] = $value;
      }
    }
  }
}
