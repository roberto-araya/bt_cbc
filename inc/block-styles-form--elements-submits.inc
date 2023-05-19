<?php

/**
 * @file
 * Custom submit functions for block styles in layout builder.
 */

/**
 * Form elements submit layout builder.
 */
function _element_style_layout_builder_configure_block_submit($form_state, $section_component, $element, $get_value) {
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', $element . '_' . $get_value[array_key_last($get_value)], $component_style);
  }
  else {
    $section_component->unsetThirdPartySetting('bt_cbc', $element . '_' . $get_value[array_key_last($get_value)]);
  }
}

/**
 * Form title submit layout builder.
 */
function _title_styles_layout_builder_form_element_sumbit($form_state, $section_component) {
  $get_value = ['third_party_settings', 'bt_cbc', 'title', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'title', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'title', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'title', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'title', 'font_family'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'title', $get_value);
}

/**
 * Form captions submit layout builder.
 */
function _caption_styles_layout_builder_form_element_sumbit($form_state, $section_component) {
  $get_value = ['third_party_settings', 'bt_cbc', 'caption', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'caption', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'caption', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'caption', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'caption', 'font_family'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'caption', $get_value);
}

/**
 * Form text submit layout builder.
 */
function _text_styles_layout_builder_form_element_sumbit($form_state, $section_component) {
  $get_value = ['third_party_settings', 'bt_cbc', 'text', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'text', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'text', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'text', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'text', 'font_family'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'text', $get_value);
}

/**
 * Submit for buttons.
 */
function _buttons_styles_layout_builder_form_element_submit($form_state, $section_component, $element) {
  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'buttons',
    $element,
    'color_select',
  ];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, $element, $get_value);

  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'buttons',
    $element,
    'color_custom',
  ];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, $element, $get_value);
}
