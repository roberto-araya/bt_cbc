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
 * Title, caption, text layout builder sumbit.
 */
function _title_caption_text_style_layout_builder_form_submit($form_state, $section_component) {
  // Title.
  _title_styles_layout_builder_form_element_sumbit($form_state, $section_component);
  // Caption.
  _caption_styles_layout_builder_form_element_sumbit($form_state, $section_component);
  // Text.
  _text_styles_layout_builder_form_element_sumbit($form_state, $section_component);

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

/**
 * Buttons layout builder sumbit.
 */
function _buttons_style_layout_builder_form_submit($form_state, $section_component, $secondary = FALSE) {
  // Button.
  _buttons_styles_layout_builder_form_element_submit($form_state, $section_component, 'button');
  // Button link.
  _buttons_styles_layout_builder_form_element_submit($form_state, $section_component, 'button_link');
  if ($secondary) {
    // Button secondary.
    _buttons_styles_layout_builder_form_element_submit($form_state, $section_component, 'button_secondary');
    // Button secondary link.
    _buttons_styles_layout_builder_form_element_submit($form_state, $section_component, 'button_secondary_link');
  }
}
