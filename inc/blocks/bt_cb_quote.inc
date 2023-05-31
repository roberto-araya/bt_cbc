<?php

/**
 * @file
 * Block style for bt_cb_quote.
 */

/**
 * Module bt_cb_quote standard.
 */
function _bt_cb_quote_style_form_builder() {
  $block_style = [];
  $n = 9;
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
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
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
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

  foreach (['text', 'source', 'link', 'symbol'] as $element) {
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
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
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
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
    if ($block && $settings = $block->getThirdPartySetting('bt_cbc', $element)) {
      $variables['configuration']['block_style'][$element . '_color_select'] = $settings['color_select'];
      $variables['configuration']['block_style'][$element . '_color_custom'] = $settings['color_custom'];
    }
  }
}
