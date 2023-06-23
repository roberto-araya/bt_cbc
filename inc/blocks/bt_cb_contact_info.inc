<?php

/**
 * @file
 * Block style for bt_cb_contact_info.
 */

/**
 * Module bt_cb_contact_info standard.
 */
function _bt_cb_contact_info_style_form_builder() {
  $block_style = [
    'text' => _text_styles_form_element_builder(),
    'link' => [
      '#type' => 'details',
      '#tree' => TRUE,
      '#weight' => $n + 1,
    ],
  ];
  $colors = _block_style_color('link');
  $block_style['link']['color_select'] = $colors['color_select'];
  $block_style['link']['color_custom'] = $colors['color_custom'];
  return $block_style;
}

/**
 * Module bt_cb_contact_info layout builder.
 */
function _bt_cb_contact_info_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_contact_info_style_form_builder();

  $block_style['text']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_select');
  $block_style['text']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_custom');
  $block_style['text']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_font_family');

  $block_style['link']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'link_color_select');
  $block_style['link']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'link_color_custom');

  $screens = _get_screens_breakpoints();

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');
  }

  return $block_style;
}

/**
 * Module bt_cb_contact_info block layout.
 */
function _bt_cb_contact_info_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_contact_info_style_form_builder();

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'text');
  $block_style['text']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['text']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['text']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $link_default_values = $block->getThirdPartySetting('bt_cbc', 'link');
  $block_style['link']['color_select']['#default_value'] = $link_default_values ? $link_default_values['color_select'] : '';
  $block_style['link']['color_custom']['#default_value'] = $link_default_values ? $link_default_values['color_custom'] : '';

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';
  }

  return $block_style;
}

/**
 * Module bt_cb_contact_info layout builder sumbit.
 */
function _bt_cb_contact_info_style_layout_builder_form_submit($form_state, $section_component) {
  // Text.
  _text_styles_layout_builder_form_element_sumbit($form_state, $section_component);

  // Link color.
  $get_value = ['third_party_settings', 'bt_cbc', 'link', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'link', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'link', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'link', $get_value);

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
  }
}

/**
 * Preprocess for bt_cb_contact_info blocks.
 */
function _bt_cb_contact_info_styles_block_preprocess($block, &$variables) {
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Link.
  $variables['configuration']['block_style']['link_color_select'] = $settings['color_select'];
  $variables['configuration']['block_style']['link_color_custom'] = $settings['color_custom'];
}
