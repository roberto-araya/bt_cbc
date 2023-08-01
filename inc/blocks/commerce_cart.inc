<?php

/**
 * @file
 * Block style for commerce_cart_block.
 */

/**
 * Module commerce_cart_block standard.
 */
function _commerce_cart_block_style_form_builder() {
  $block_style = [
    'text' => _text_styles_form_element_builder(),
  ];
  return $block_style;
}

/**
 * Module commerce_cart_block layout builder.
 */
function _commerce_cart_block_style_layout_builder_form_builder(&$section_component) {
  $block_style = _commerce_cart_block_style_form_builder();

  $block_style['text']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_select');
  $block_style['text']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_custom');
  $block_style['text']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_font_family');

  $screens = _get_screens_breakpoints();

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');
  }

  return $block_style;
}

/**
 * Module commerce_cart_block block layout.
 */
function _commerce_cart_block_style_block_layout_form_builder($block) {
  $block_style = _commerce_cart_block_style_form_builder();

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'text');
  $block_style['text']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['text']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['text']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';
  }

  return $block_style;
}

/**
 * Module commerce_cart_block layout builder sumbit.
 */
function _commerce_cart_block_style_layout_builder_form_submit($form_state, $section_component) {
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
}

/**
 * Preprocess for commerce_cart_block blocks.
 */
function _commerce_cart_block_styles_block_preprocess($block, &$variables) {
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
}
