<?php

/**
 * @file
 * Block style for bt_cb_quote.
 */

/**
 * Module bt_cb_quote standard.
 */
function _bt_cb_quote_style_form_builder() {
  $block_style = [
    'text' => _text_styles_form_element_builder(),
  ];
  $n = 9;
  foreach (['source', 'link', 'symbol'] as $element) {
    $block_style[$element] = [
      '#type' => 'details',
      '#tree' => TRUE,
      '#weight' => $n + 1,
    ];
    $colors = _block_style_color($element);
    $block_style[$element]['color_select'] = $colors['color_select'];
    $block_style[$element]['color_custom'] = $colors['color_custom'];
  }
  $block_style['text']['#title'] = t('Text');
  $block_style['source']['#title'] = t('Source');
  $block_style['link']['#title'] = t('Link');
  $block_style['symbol']['#title'] = t('Symbol');

  return $block_style;

}

/**
 * Module bt_cb_quote layout builder.
 */
function _bt_cb_quote_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_quote_style_form_builder();

  $block_style['text']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_select');
  $block_style['text']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_custom');
  $block_style['text']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_font_family');

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');
  }

  foreach (['source', 'link', 'symbol'] as $element) {
    $block_style[$element]['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', $element . '_color_select');
    $block_style[$element]['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', $element . '_color_custom');
  }
  return $block_style;
}

/**
 * Module bt_cb_quote block layout.
 */
function _bt_cb_quote_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_quote_style_form_builder();

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'text');
  $block_style['text']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['text']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['text']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';
  }

  foreach (['source', 'link', 'symbol'] as $element) {
    $default_values = $block->getThirdPartySetting('bt_cbc', $element);
    $block_style[$element]['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
    $block_style[$element]['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';
  }
  return $block_style;
}

/**
 * Module bt_cb_quote layout builder sumbit.
 */
function _bt_cb_quote_style_layout_builder_form_submit($form_state, $section_component) {
  // text.
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
  }

  foreach (['source', 'link', 'symbol'] as $element) {
    $get_value = ['third_party_settings', 'bt_cbc', $element, 'color_select'];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, $element, $get_value);

    $get_value = ['third_party_settings', 'bt_cbc', $element, 'color_custom'];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, $element, $get_value);
  }
}

/**
 * Preprocess for bt_cb_quote blocks.
 */
function _bt_cb_quote_styles_block_preprocess($block, &$variables) {
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');

  foreach (['source', 'link', 'symbol'] as $element) {
    if ($block && $settings = $block->getThirdPartySetting('bt_cbc', $element)) {
      $variables['configuration']['block_style'][$element . '_color_select'] = $settings['color_select'];
      $variables['configuration']['block_style'][$element . '_color_custom'] = $settings['color_custom'];
    }
  }
}
