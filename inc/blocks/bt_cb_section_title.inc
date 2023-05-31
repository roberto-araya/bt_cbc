<?php

/**
 * @file
 * Block style for bt_cb_section_title.
 */

/**
 * Module bt_cb_section_title standard.
 */
function _bt_cb_section_title_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  return $block_style;
}

/**
 * Module bt_cb_section_title layout builder.
 */
function _bt_cb_section_title_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_section_title_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);

  return $block_style;
}

/**
 * Module bt_cb_section_title block layout.
 */
function _bt_cb_section_title_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_section_title_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);

  return $block_style;
}

/**
 * Module bt_cb_section_title layout builder sumbit.
 */
function _bt_cb_section_title_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
}

/**
 * Preprocess for bt_cb_section_title blocks.
 */
function _bt_cb_section_title_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
}
