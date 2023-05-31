<?php

/**
 * @file
 * Block style for bt_cb_highlighted_text_image.
 */

/**
 * Module bt_cb_highlighted_text_image standard.
 */
function _bt_cb_highlighted_text_image_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['highlighted'] = [
    '#type' => 'details',
    '#title' => t('Highlighted'),
    '#tree' => TRUE,
    '#weight' => 10,
  ];

  $colors = _block_style_color('highlighted');
  $block_style['highlighted']['color_select'] = $colors['color_select'];
  $block_style['highlighted']['color_custom'] = $colors['color_custom'];

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text_image layout builder.
 */
function _bt_cb_highlighted_text_image_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_highlighted_text_image_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style['highlighted']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_select');
  $block_style['highlighted']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_custom');

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text_image block layout.
 */
function _bt_cb_highlighted_text_image_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_highlighted_text_image_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $default_values = $block->getThirdPartySetting('bt_cbc', 'highlighted');
  $block_style['highlighted']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['highlighted']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text_image layout builder sumbit.
 */
function _bt_cb_highlighted_text_image_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);

  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);
}

/**
 * Preprocess for bt_cb_highlighted_text_image blocks.
 */
function _bt_cb_highlighted_text_image_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Highlighted.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'highlighted')) {
    $variables['configuration']['block_style']['highlighted_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['highlighted_color_custom'] = $settings['color_custom'];
  }
}
