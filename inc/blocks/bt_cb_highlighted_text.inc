<?php

/**
 * @file
 * Block style for bt_cb_highlighted_text.
 */

/**
 * Module bt_cb_highlighted_text standard.
 */
function _bt_cb_highlighted_text_style_form_builder() {
  $block_style = [
    'text' => _text_styles_form_element_builder(),
    'highlighted' => [
      '#type' => 'details',
      '#title' => t('Highlighted'),
      '#tree' => TRUE,
      '#weight' => 10,
    ],
  ];
  $colors = _block_style_color('highlighted');
  $block_style['highlighted']['color_select'] = $colors['color_select'];
  $block_style['highlighted']['color_custom'] = $colors['color_custom'];

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text layout builder.
 */
function _bt_cb_highlighted_text_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_highlighted_text_style_form_builder();

  $block_style['text']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_select');
  $block_style['text']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_custom');
  $block_style['text']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_font_family');

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');
  }

  $block_style['highlighted']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_select');
  $block_style['highlighted']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_custom');

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text block layout.
 */
function _bt_cb_highlighted_text_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_highlighted_text_style_form_builder();

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'text');
  $block_style['text']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['text']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['text']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';
  }

  $default_values = $block->getThirdPartySetting('bt_cbc', 'highlighted');
  $block_style['highlighted']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['highlighted']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text layout builder sumbit.
 */
function _bt_cb_highlighted_text_style_layout_builder_form_submit($form_state, $section_component) {
  // Text.
  _text_styles_layout_builder_form_element_sumbit($form_state, $section_component);

  // Font size.
  foreach (['xs', 'sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
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

  // Highlighted.
  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);
}

/**
 * Preprocess for bt_cb_highlighted_text blocks.
 */
function _bt_cb_highlighted_text_styles_block_preprocess($block, &$variables) {
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');

  // Highlighted.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'highlighted')) {
    $variables['configuration']['block_style']['highlighted_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['highlighted_color_custom'] = $settings['color_custom'];
  }
}
