<?php

/**
 * @file
 * Block style for bt_cb_text_icon.
 */

/**
 * Module bt_cb_text_icon standard.
 */
function _bt_cb_text_icon_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
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
  $block_style['buttons'] = _buttons_styles_form_element_builder(FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text_icon layout builder.
 */
function _bt_cb_text_icon_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_text_icon_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style = _buttons_style_layout_builder_form_builder($section_component, $block_style, FALSE);
  $block_style['icon']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_select');
  $block_style['icon']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_custom');

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['icon']['size'][$prefix] = _block_style_icon_size($breakpoint);
    $block_style['icon']['size'][$prefix]['size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_' . $prefix . '_size');
  }

  return $block_style;
}

/**
 * Module bt_cb_text_icon block layout.
 */
function _bt_cb_text_icon_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_text_icon_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $block_style = _buttons_style_block_layout_form_builder($block, $block_style, FALSE);
  $default_values = $block->getThirdPartySetting('bt_cbc', 'icon');
  $block_style['icon']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['icon']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['icon']['size'][$prefix] = _block_style_icon_size($breakpoint);
    $block_style['icon']['size'][$prefix]['size']['#default_value'] = $default_values ? $default_values['size'][$prefix]['size'] : '';
  }

  return $block_style;
}

/**
 * Module bt_cb_text_icon layout builder sumbit.
 */
function _bt_cb_text_icon_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
  _buttons_style_layout_builder_form_submit($form_state, $section_component, FALSE);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  // Icon size.
  foreach (['sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
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

}

/**
 * Preprocess for bt_cb_text_icon blocks.
 */
function _bt_cb_text_icon_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Icon.
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
  // Buttons.
  _buttons_styles_block_preprocess($block, $variables);
}
