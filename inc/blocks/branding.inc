<?php

/**
 * @file
 * Block style for branding block.
 */

/**
 * Block branding_block standard.
 */
function _branding_block_style_form_builder() {
  // Type.
  $block_style['type'] = [
    '#type' => 'select',
    '#options' => [
      'horizontal' => t('Horizontal'),
      'vertical' => t('Vertical'),
      'horizontal_inverted' => t('Horizontal Inverted'),
      'vertical_inverted' => t('Vertical Inverted'),
    ],
    '#title' => t('Branding Presentation'),
    '#description' => t("Select a type of presentation."),
    '#weight' => 1,
  ];

  // Logo.
  $block_style['logo_size'] = [
    '#type' => 'textfield',
    '#title' => t('Logo Size'),
    '#description' => t("CSS Property. Examples: 100px; 10vh; 30%;"),
    '#weight' => 2,
  ];

  // Name.
  $block_style['name'] = _title_styles_form_element_builder();
  $block_style['name']['#title'] = t('Name');
  $block_style['name']['#weight'] = 11;
  $block_style['name']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][name][color_select]"]' => ['value' => 'customColor'],
  ];

  // Slogan.
  $block_style['slogan'] = _title_styles_form_element_builder();
  $block_style['slogan']['#title'] = t('Slogan');
  $block_style['slogan']['#weight'] = 12;
  $block_style['slogan']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][slogan][color_select]"]' => ['value' => 'customColor'],
  ];

  return $block_style;
}

/**
 * Block branding_block layout builder.
 */
function _branding_block_style_layout_builder_form_builder(&$section_component) {
  $block_style = _branding_block_style_form_builder();
  // Type.
  $block_style['type']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'type');

  // Logo size.
  $block_style['logo_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'logo_size');

  // Name color.
  $block_style['name']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'name_color_select');
  $block_style['name']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'name_color_custom');

  // Name font family.
  $block_style['name']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'name_font_family');

  // Slogan color.
  $block_style['slogan']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'slogan_color_select');
  $block_style['slogan']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'slogan_color_custom');

  // Name font family.
  $block_style['slogan']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'slogan_font_family');

  // Font size.
  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    // Name font size.
    $block_style['name']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['name']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'name_' . $prefix . '_font_size');

    // Slogan font size.
    $block_style['slogan']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['slogan']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'slogan_' . $prefix . '_font_size');

  }

  return $block_style;
}

/**
 * Block branding_block block layout.
 */
function _branding_block_style_block_layout_form_builder($block) {
  $block_style = _branding_block_style_form_builder();

  // Type.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'type');
  $block_style['type']['#default_value'] = $default_values ? $default_values : '';

  // Logo size.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'logo_size');
  $block_style['logo_size']['#default_value'] = $default_values ? $default_values : '';

  // Name.
  $name_values = $block->getThirdPartySetting('bt_cbc', 'name');
  // Name color.
  $block_style['name']['color_select']['#default_value'] = $name_values ? $name_values['color_select'] : '';
  $block_style['name']['color_custom']['#default_value'] = $name_values ? $name_values['color_custom'] : '';
  // Name font family.
  $block_style['name']['font_family']['#default_value'] = $name_values ? $name_values['font_family'] : '';

  // Slogan.
  $slogan_values = $block->getThirdPartySetting('bt_cbc', 'slogan');
  // Slogan color.
  $block_style['slogan']['color_select']['#default_value'] = $slogan_values ? $slogan_values['color_select'] : '';
  $block_style['slogan']['color_custom']['#default_value'] = $slogan_values ? $slogan_values['color_custom'] : '';
  // Slogan font family.
  $block_style['slogan']['font_family']['#default_value'] = $slogan_values ? $slogan_values['font_family'] : '';

  // Font size.
  $screens = _get_screens_breakpoints();
  foreach ($screens as $prefix => $breakpoint) {
    // Name font size.
    $block_style['name']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['name']['font_size'][$prefix]['font_size']['#default_value'] = $name_values ? $name_values['font_size'][$prefix]['font_size'] : '';

    // Slogan font size.
    $block_style['slogan']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['slogan']['font_size'][$prefix]['font_size']['#default_value'] = $slogan_values ? $slogan_values['font_size'][$prefix]['font_size'] : '';
  }

  return $block_style;
}

/**
 * Block branding_block layout builder sumbit.
 */
function branding_block_style_layout_builder_form_submit($form_state, $section_component) {
  // Type.
  $get_value = ['third_party_settings', 'bt_cbc', 'type'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'type', $component_style);
  }

  // Logo size.
  $get_value = ['third_party_settings', 'bt_cbc', 'logo_size'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'logo_size', $component_style);
  }

  // Name.
  $get_value = ['third_party_settings', 'bt_cbc', 'name', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'name', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'name', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'name', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'name', 'font_family'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'name', $get_value);

  // Slogan.
  $get_value = ['third_party_settings', 'bt_cbc', 'slogan', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'slogan', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'slogan', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'slogan', $get_value);
  $get_value = ['third_party_settings', 'bt_cbc', 'slogan', 'font_family'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'slogan', $get_value);

  // Font size.
  foreach (['sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
    // Name font size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'name',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'name_' . $prefix, $get_value);

    // Slogan font size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'slogan',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'slogan_' . $prefix, $get_value);
  }

}

/**
 * Preprocess for branding_block blocks.
 */
function _branding_block_styles_block_preprocess($block, &$variables) {
  // Type.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'type')) {
    $variables['configuration']['block_style']['type'] = $settings;
  }

  // Logo Size.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'logo_size')) {
    $variables['configuration']['block_style']['logo_size'] = $settings;
  }

  // Name Font Size.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'name')) {
    $variables['configuration']['block_style']['name_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['name_color_custom'] = $settings['color_custom'];
    $variables['configuration']['block_style']['name_font_family'] = $settings['font_family'];

    // Name font size.
    foreach (['sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
      $variables['configuration']['block_style']['name_' . $prefix . '_font_size'] = $settings['font_size'][$prefix]['font_size'];
    }
  }

  // Slogan Font Size.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'slogan')) {
    $variables['configuration']['block_style']['slogan_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['slogan_color_custom'] = $settings['color_custom'];
    $variables['configuration']['block_style']['slogan_font_family'] = $settings['font_family'];

    // Name font size.
    foreach (['sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
      $variables['configuration']['block_style']['slogan_' . $prefix . '_font_size'] = $settings['font_size'][$prefix]['font_size'];
    }
  }

}
