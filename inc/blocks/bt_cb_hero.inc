<?php

/**
 * @file
 * Block style for bt_cb_hero.
 */

/**
 * Module bt_cb_hero standard.
 */
function _bt_cb_hero_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['buttons'] = _buttons_styles_form_element_builder(TRUE);

  return $block_style;
}

/**
 * Module bt_cb_hero layout builder.
 */
function _bt_cb_hero_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_hero_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style = _buttons_style_layout_builder_form_builder($section_component, $block_style, TRUE);

  return $block_style;
}

/**
 * Module bt_cb_hero block layout.
 */
function _bt_cb_hero_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_hero_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $block_style = _buttons_style_block_layout_form_builder($block, $block_style, TRUE);

  return $block_style;
}

/**
 * Module bt_cb_hero layout builder sumbit.
 */
function _bt_cb_hero_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
  _buttons_style_layout_builder_form_submit($form_state, $section_component, TRUE);
}

/**
 * Preprocess for bt_cb_hero blocks.
 */
function _bt_cb_hero_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Buttons.
  _buttons_styles_block_preprocess($block, $variables);
}
