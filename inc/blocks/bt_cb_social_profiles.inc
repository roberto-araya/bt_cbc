<?php

/**
 * @file
 * Block style for bt_cb_social_profiles.
 */

/**
 * Module bt_cb_social_profiles standard.
 */
function _bt_cb_social_profiles_style_form_builder() {
  $block_style = [
    'text' => _text_styles_form_element_builder(),
    'icon' => [
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
    ],
  ];

  $colors = _block_style_color_opacity('icon');
  $block_style['icon']['color_select'] = $colors['color_select'];
  $block_style['icon']['color_custom'] = $colors['color_custom'];
  $block_style['icon']['color_opacity'] = $colors['color_opacity'];
  $block_style['icon']['color_custom_opacity'] = $colors['color_custom_opacity'];

  return $block_style;
}

/**
 * Module bt_cb_social_profiles layout builder.
 */
function _bt_cb_social_profiles_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_social_profiles_style_form_builder();

  $block_style['text']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_select');
  $block_style['text']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_custom');
  $block_style['text']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_font_family');

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');

    $block_style['icon']['size'][$prefix] = _block_style_icon_size($breakpoint);
    $block_style['icon']['size'][$prefix]['size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_' . $prefix . '_size');
  }

  $block_style['icon']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_select');
  $block_style['icon']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_custom');
  $block_style['icon']['color_opacity']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_opacity');
  $block_style['icon']['color_custom_opacity']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_custom_opacity');

  return $block_style;
}

/**
 * Module bt_cb_social_profiles block layout.
 */
function _bt_cb_social_profiles_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_social_profiles_style_form_builder();

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'text');
  $block_style['text']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['text']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['text']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $icon_default_values = $block->getThirdPartySetting('bt_cbc', 'icon');
  $block_style['icon']['color_select']['#default_value'] = $icon_default_values ? $icon_default_values['color_select'] : '';
  $block_style['icon']['color_custom']['#default_value'] = $icon_default_values ? $icon_default_values['color_custom'] : '';
  $block_style['icon']['color_opacity']['#default_value'] = $icon_default_values ? $icon_default_values['color_opacity'] : '';
  $block_style['icon']['color_custom_opacity']['#default_value'] = $icon_default_values ? $icon_default_values['color_custom_opacity'] : '';

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['icon']['size'][$prefix] = _block_style_icon_size($breakpoint);
    $block_style['icon']['size'][$prefix]['size']['#default_value'] = $icon_default_values ? $icon_default_values['size'][$prefix]['size'] : '';
  }

  return $block_style;
}

/**
 * Module bt_cb_social_profiles layout builder sumbit.
 */
function _bt_cb_social_profiles_style_layout_builder_form_submit($form_state, $section_component) {
  // Text.
  _text_styles_layout_builder_form_element_sumbit($form_state, $section_component);

  // Font size.
  foreach (['sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
    // Text Font Size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'text',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'text_' . $prefix, $get_value);

    // Text Font Size.
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

  // icon.
  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_opacity'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = [
    'third_party_settings',
    'bt_cbc', 'icon',
    'color_custom_opacity',
  ];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);
}

/**
 * Preprocess for bt_cb_social_profiles blocks.
 */
function _bt_cb_social_profiles_styles_block_preprocess($block, &$variables) {
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
}
