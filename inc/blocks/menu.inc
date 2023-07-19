<?php

/**
 * @file
 * Block styles for menus.
 */

/**
 * Block menu_block standard.
 */
function _menu_block_style_form_builder() {
  // Menu title.
  $block_style['title'] = _title_styles_form_element_builder();

  // Menu type.
  $block_style['type'] = [
    '#type' => 'select',
    '#options' => [
      'default' => t('Default'),
      'horizontal' => t('Horizontal'),
      'vertical' => t('Vertical'),
      'one' => t('Variant 1'),
      'two' => t('Variant 2'),
    ],
    '#title' => t('Menu Type'),
    '#description' => t("Select a type of presentation."),
  ];

  // Menu gap.
  $block_style['gap'] = [
    '#type' => 'textfield',
    '#title' => 'Gap',
    '#description' => t("The gap between elements, units: px, rem. Examples: 1rem, 16px."),
  ];

  // Item.
  $block_style['item'] = [
    '#type' => 'details',
    '#title' => t('Item'),
    '#tree' => TRUE,
    '#weight' => 10,
  ];

  // Item font family.
  $block_style['item']['font_family'] = _block_style_font_family();

  // Item font size.
  $block_style['item']['font_size'] = [
    '#type' => 'details',
    '#title' => t('Font Size'),
    '#tree' => TRUE,
  ];

  // Item color.
  $block_style['item']['color'] = [
    '#type' => 'details',
    '#title' => t('Color'),
    '#tree' => TRUE,
  ];

  $colors = _block_style_color('item');
  $block_style['item']['color']['color_select'] = $colors['color_select'];
  $block_style['item']['color']['color_select']['#title'] = t('Item Color');
  $block_style['item']['color']['color_select']['#weight'] = '5';

  $block_style['item']['color']['color_custom'] = $colors['color_custom'];
  $block_style['item']['color']['color_custom']['#title'] = t('Item Color Custom');
  $block_style['item']['color']['color_custom']['#weight'] = '6';
  $block_style['item']['color']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][item][color][color_select]"]' => ['value' => 'customColor'],
  ];

  // Item hover.
  $block_style['item']['color']['hover']['color_select'] = $colors['color_select'];
  $block_style['item']['color']['hover']['color_select']['#title'] = t('Item Hover Color');
  $block_style['item']['color']['hover']['#weight'] = '7';
  $block_style['item']['color']['hover']['color_select']['#weight'] = '7';

  $block_style['item']['color']['hover']['color_custom'] = $colors['color_custom'];
  $block_style['item']['color']['hover']['color_custom']['#title'] = t('Item Hover Color Custom');
  $block_style['item']['color']['hover']['color_custom']['#weight'] = '8';
  $block_style['item']['color']['hover']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][item][color][hover][color_select]"]' => ['value' => 'customColor'],
  ];

  // Item background.
  $block_style['item']['background'] = [
    '#type' => 'details',
    '#title' => t('Background'),
    '#tree' => TRUE,
  ];

  $colors = _block_style_color('background');

  $block_style['item']['background']['#weight'] = '10';
  $block_style['item']['background']['color_select'] = $colors['color_select'];
  $block_style['item']['background']['color_select']['#title'] = t('Item Background Color');

  $block_style['item']['background']['color_custom'] = $colors['color_custom'];
  $block_style['item']['background']['color_custom']['#title'] = t('Item Background Color Custom');
  $block_style['item']['background']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][item][background][color_select]"]' => ['value' => 'customColor'],
  ];

  // Item hover background.
  $block_style['item']['background']['hover']['color_select'] = $colors['color_select'];
  $block_style['item']['background']['hover']['color_select']['#title'] = t('Item Hover Background Color');

  $block_style['item']['background']['hover']['color_custom'] = $colors['color_custom'];
  $block_style['item']['background']['hover']['color_custom']['#title'] = t('Item Hover Background Color Custom');
  $block_style['item']['background']['hover']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][item][background][hover][color_select]"]' => ['value' => 'customColor'],
  ];

  // Item padding.
  $block_style['item']['padding'] = [
    '#type' => 'details',
    '#title' => t('Padding'),
    '#tree' => TRUE,
  ];

  return $block_style;
}

/**
 * Block menu_block layout builder.
 */
function _menu_block_style_layout_builder_form_builder(&$section_component) {
  $screens = _get_screens_breakpoints();

  $block_style = _menu_block_style_form_builder();

  // Title color.
  $block_style['title']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_select');
  $block_style['title']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_custom');

  // Title font family.
  $block_style['title']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_font_family');

  // Type.
  $block_style['type']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'type');

  // Gap.
  $block_style['gap']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'gap');

  // Item font family.
  $block_style['item']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_font_family');

  // Item color.
  $block_style['item']['color']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_color_select');
  $block_style['item']['color']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_color_custom');

  // Item color hover.
  $block_style['item']['color']['hover']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_hover_color_select');
  $block_style['item']['color']['hover']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_hover_color_custom');

  // Item background.
  $block_style['item']['background']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_background_color_select');
  $block_style['item']['background']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_background_color_custom');

  // Item background hover.
  $block_style['item']['background']['hover']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_background_hover_color_select');
  $block_style['item']['background']['hover']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_background_hover_color_custom');

  // Font size and padding.
  foreach ($screens as $prefix => $breakpoint) {
    $font_size_details = _block_style_font_size($breakpoint);
    // Title font size.
    $block_style['title']['font_size'][$prefix] = $font_size_details;
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_' . $prefix . '_font_size');

    // Item font size.
    $block_style['item']['font_size'][$prefix] = $font_size_details;
    $block_style['item']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_' . $prefix . '_font_size');

    // Padding.
    $block_style['item']['padding'][$prefix] = _block_style_margin_padding($breakpoint, 'padding');
    $block_style['item']['padding'][$prefix]['padding_left']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_' . $prefix . '_padding_left');
    $block_style['item']['padding'][$prefix]['padding_top']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_' . $prefix . '_padding_top');
    $block_style['item']['padding'][$prefix]['padding_right']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_' . $prefix . '_padding_right');
    $block_style['item']['padding'][$prefix]['padding_bottom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'item_' . $prefix . '_padding_bottom');
  }

  return $block_style;
}

/**
 * Block menu_block block layout.
 */
function _menu_block_style_block_layout_form_builder($block) {
  $screens = _get_screens_breakpoints();

  $block_style = _menu_block_style_form_builder();

  // Title.
  $title_values = $block->getThirdPartySetting('bt_cbc', 'title');
  // Title color.
  $block_style['title']['color_select']['#default_value'] = $title_values ? $title_values['color_select'] : '';
  $block_style['title']['color_custom']['#default_value'] = $title_values ? $title_values['color_custom'] : '';

  // Title font family.
  $block_style['title']['font_family']['#default_value'] = $title_values ? $title_values['font_family'] : '';

  // Type.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'type');
  $block_style['type']['#default_value'] = $default_values ? $default_values : '';

  // Gap.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'gap');
  $block_style['gap']['#default_value'] = $default_values ? $default_values : '';

  // Item.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'item');

  // Item font family.
  $block_style['item']['font_family']['#default_value'] = $default_values ? $default_values['font_family'] : '';

  // Item color.
  $block_style['item']['color']['color_select']['#default_value'] = $default_values ? $default_values['color']['color_select'] : '';
  $block_style['item']['color']['color_custom']['#default_value'] = $default_values ? $default_values['color']['color_custom'] : '';

  // Item background.
  $block_style['item']['background']['color_select']['#default_value'] = $default_values ? $default_values['background']['color_select'] : '';
  $block_style['item']['background']['color_custom']['#default_value'] = $default_values ? $default_values['background']['color_custom'] : '';

  // Item hover.
  $block_style['item']['color']['hover']['color_select']['#default_value'] = $default_values ? $default_values['color']['hover']['color_select'] : '';
  $block_style['item']['color']['hover']['color_custom']['#default_value'] = $default_values ? $default_values['color']['hover']['color_custom'] : '';

  // Item hover background.
  $block_style['item']['background']['hover']['color_select']['#default_value'] = $default_values ? $default_values['background']['hover']['color_select'] : '';
  $block_style['item']['background']['hover']['color_custom']['#default_value'] = $default_values ? $default_values['background']['hover']['color_custom'] : '';

  // Font size and padding.
  foreach ($screens as $prefix => $breakpoint) {
    $font_size_details = _block_style_font_size($breakpoint);
    // Title font size.
    $block_style['title']['font_size'][$prefix] = $font_size_details;
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $title_values ? $title_values['font_size'][$prefix]['font_size'] : '';

    // Item font size.
    $block_style['item']['font_size'][$prefix] = $font_size_details;
    $block_style['item']['font_size'][$prefix]['font_size']['#default_value'] = $default_values ? $default_values['font_size'][$prefix]['font_size'] : '';

    // Padding.
    $block_style['item']['padding'][$prefix] = _block_style_margin_padding($breakpoint, 'padding');
    $block_style['item']['padding'][$prefix]['padding_left']['#default_value'] = $default_values ? $default_values['padding'][$prefix]['padding_left'] : '';
    $block_style['item']['padding'][$prefix]['padding_top']['#default_value'] = $default_values ? $default_values['padding'][$prefix]['padding_top'] : '';
    $block_style['item']['padding'][$prefix]['padding_right']['#default_value'] = $default_values ? $default_values['padding'][$prefix]['padding_right'] : '';
    $block_style['item']['padding'][$prefix]['padding_bottom']['#default_value'] = $default_values ? $default_values['padding'][$prefix]['padding_bottom'] : '';
  }

  return $block_style;
}

/**
 * Block menu_block layout builder sumbit.
 */
function _menu_block_style_layout_builder_form_submit($form_state, $section_component) {
  _title_styles_layout_builder_form_element_sumbit($form_state, $section_component);

  // Type.
  $get_value = ['third_party_settings', 'bt_cbc', 'type'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'type', $component_style);
  }

  // Gap.
  $get_value = ['third_party_settings', 'bt_cbc', 'gap'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'gap', $component_style);
  }

  // Item color.
  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'color',
    'color_select',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_color_select', $component_style);
  }

  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'color',
    'color_custom',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_color_custom', $component_style);
  }
  // Item hover color.
  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'color',
    'hover',
    'color_select',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_hover_color_select', $component_style);
  }

  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'color',
    'hover',
    'color_custom',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_hover_color_custom', $component_style);
  }
  // Item background.
  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'background',
    'color_select',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_background_color_select', $component_style);
  }

  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'background',
    'color_custom',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_background_color_custom', $component_style);
  }
  // Item hover background.
  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'background',
    'hover',
    'color_select',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_background_hover_color_select', $component_style);
  }

  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'item',
    'background',
    'hover',
    'color_custom',
  ];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'item_background_hover_color_custom', $component_style);
  }

  // Font size and padding.
  foreach (['xs', 'sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
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

    // Item Font Size.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'item',
      'font_size',
      $prefix,
      'font_size',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'item_' . $prefix, $get_value);

    // Padding.
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'item',
      'padding',
      $prefix,
      'padding_left',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'item_' . $prefix, $get_value);
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'item',
      'padding',
      $prefix,
      'padding_top',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'item_' . $prefix, $get_value);
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'item',
      'padding',
      $prefix,
      'padding_right',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'item_' . $prefix, $get_value);
    $get_value = [
      'third_party_settings',
      'bt_cbc',
      'item',
      'padding',
      $prefix,
      'padding_bottom',
    ];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'item_' . $prefix, $get_value);
  }
}

/**
 * Preprocess for menu_block blocks.
 */
function _menu_block_styles_block_preprocess($block, &$variables) {
  // Title.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'title')) {
    // Title font family.
    $variables['configuration']['block_style']['title_font_family'] = $settings['font_family'];
    // Title color.
    $variables['configuration']['block_style']['title_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['title_color_custom'] = $settings['color_custom'];

    // Title font size.
    foreach (['xs', 'sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
      $variables['configuration']['block_style']['title_' . $prefix . '_font_size'] = $settings['font_size'][$prefix]['font_size'];
    }
  }

  // Type.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'type')) {
    $variables['configuration']['block_style']['type'] = $settings;
  }

  // Gap.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'gap')) {
    $variables['configuration']['block_style']['gap'] = $settings;
  }

  // Item.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'item')) {
    // Item font family.
    $variables['configuration']['block_style']['item_font_family'] = $settings['font_family'];

    // Item color.
    $variables['configuration']['block_style']['item_color_select'] = $settings['color']['color_select'];
    $variables['configuration']['block_style']['item_color_custom'] = $settings['color']['color_custom'];

    // Item color hover.
    $variables['configuration']['block_style']['item_hover_color_select'] = $settings['color']['hover']['color_select'];
    $variables['configuration']['block_style']['item_hover_color_custom'] = $settings['color']['hover']['color_custom'];

    // Item background.
    $variables['configuration']['block_style']['item_background_color_select'] = $settings['background']['color_select'];
    $variables['configuration']['block_style']['item_background_color_custom'] = $settings['background']['color_custom'];

    // Item background hover.
    $variables['configuration']['block_style']['item_background_hover_color_select'] = $settings['background']['hover']['color_select'];
    $variables['configuration']['block_style']['item_background_hover_color_custom'] = $settings['background']['hover']['color_custom'];

    // Item font size and padding.
    foreach (['xs', 'sm', 'md', 'lg', 'xl', 'xxl'] as $prefix) {
      // Item font size.
      $variables['configuration']['block_style']['item_' . $prefix . '_font_size'] = $settings['font_size'][$prefix]['font_size'];

      // Item padding.
      $variables['configuration']['block_style']['item_' . $prefix . '_padding_left'] = $settings['padding'][$prefix]['padding_left'];
      $variables['configuration']['block_style']['item_' . $prefix . '_padding_top'] = $settings['padding'][$prefix]['padding_top'];
      $variables['configuration']['block_style']['item_' . $prefix . '_padding_right'] = $settings['padding'][$prefix]['padding_right'];
      $variables['configuration']['block_style']['item_' . $prefix . '_padding_bottom'] = $settings['padding'][$prefix]['padding_bottom'];
    }
  }
}
