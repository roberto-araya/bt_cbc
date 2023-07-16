<?php

/**
 * @file
 * Block style for bt_cb_section_title.
 */

/**
 * Module bt_cb_section_title standard.
 */
function _bt_cb_section_title_style_form_builder() {
  $block_style = [
    'title' => _title_styles_form_element_builder(),
    'caption' => _caption_styles_form_element_builder(),
  ];

  return $block_style;
}

/**
 * Module bt_cb_section_title layout builder.
 */
function _bt_cb_section_title_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_section_title_style_form_builder();

  $block_style['title']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_select');
  $block_style['title']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_custom');
  $block_style['title']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_font_family');

  $block_style['caption']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_select');
  $block_style['caption']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_custom');
  $block_style['caption']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_font_family');

  $screens = _get_screens_breakpoints();

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_' . $prefix . '_font_size');

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');
  }

  return $block_style;
}

/**
 * Module bt_cb_section_title block layout.
 */
function _bt_cb_section_title_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_section_title_style_form_builder();

  $title_default_values = $block->getThirdPartySetting('bt_cbc', 'title');
  $block_style['title']['color_select']['#default_value'] = $title_default_values ? $title_default_values['color_select'] : '';
  $block_style['title']['color_custom']['#default_value'] = $title_default_values ? $title_default_values['color_custom'] : '';
  $block_style['title']['font_family']['#default_value'] = $title_default_values ? $title_default_values['font_family'] : '';

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'caption');
  $block_style['caption']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['caption']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['caption']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $screens = _get_screens_breakpoints();

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $title_default_values ? $title_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';
  }

  return $block_style;
}

/**
 * Module bt_cb_section_title layout builder sumbit.
 */
function _bt_cb_section_title_style_layout_builder_form_submit($form_state, $section_component) {
  // title.
  _title_styles_layout_builder_form_element_sumbit($form_state, $section_component);
  // caption.
  _caption_styles_layout_builder_form_element_sumbit($form_state, $section_component);

  // Font size.
  foreach (['sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
    // Title Font Size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'title',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'title_' . $prefix, $get_value);

    // Caption Font Size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'caption',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'caption_' . $prefix, $get_value);
  }
}

/**
 * Preprocess for bt_cb_section_title blocks.
 */
function _bt_cb_section_title_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
}
