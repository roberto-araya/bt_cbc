<?php

/**
 * @file
 * Custom elements styles form builders functions for block styles.
 */

/**
 * Return an form section for color element configurations.
 */
function _block_style_color($element) {
  return [
    'color_select' => [
      '#type' => 'select',
      '#options' => _get_theme_color_options(),
      '#title' => t('Color'),
      '#description' => t("Select a theme color or use a custom color."),
    ],
    'color_custom' => [
      '#type' => 'color',
      '#title' => t("Custom color"),
      '#description' => t("Click in the color to select a custom one."),
      '#states' => [
        'visible' => [
          ':input[name="third_party_settings[bt_cbc][' . $element . '][color_select]"]' => ['value' => 'customColor'],
        ],
      ],
    ],
  ];
}

/**
 * Return an form section for font select element configurations.
 */
function _block_style_font_family() {
  return [
    '#type' => 'select',
    '#options' => _get_font_family_options(),
  ];
}

/**
 * STYLES FORMS BUILDERS - BREAKPOINTS DEPENDED.
 */

/**
 * Return an block style form element configurations for padding elements.
 */
function _block_style_padding($breakpoint) {
  $padding = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];

  $padding['padding_left'] = [
    '#type' => 'select',
    '#title' => t('Padding left'),
    '#options' => _get_size_options(),
    '#description' => t("Block's padding left"),
  ];

  $padding['padding_top'] = [
    '#type' => 'select',
    '#title' => t('Padding top'),
    '#options' => _get_size_options(),
    '#description' => t("Block's padding top"),
  ];

  $padding['padding_right'] = [
    '#type' => 'select',
    '#title' => t('Padding right'),
    '#options' => _get_size_options(),
    '#description' => t("Block's padding right"),
  ];

  $padding['padding_bottom'] = [
    '#type' => 'select',
    '#title' => t('Padding bottom'),
    '#options' => _get_size_options(),
    '#description' => t("Block's padding bottom"),
  ];

  return $padding;

}

/**
 * Return an block style form element configurations for block align element.
 */
function _block_style_align($breakpoint) {
  $block_align = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];

  $block_align['block_align'] = [
    '#type' => 'select',
    '#title' => t('Block align'),
    '#options' => [
      'default' => t('Default'),
      'stretch' => t('Stretch'),
      'start' => t('Start'),
      'center' => t('Center'),
      'end' => t('End'),
    ],
    '#description' => t("Block's align"),
  ];

  return $block_align;
}

/**
 * Return an block style form element configurations for text align element.
 */
function _block_style_text_align($breakpoint) {
  $text_align = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];
  $text_align['text_align'] = [
    '#type' => 'select',
    '#title' => t('Text align'),
    '#options' => [
      'default' => t('Default'),
      'left' => t('Left'),
      'center' => t('Center'),
      'right' => t('Right'),
    ],
    '#description' => t("Block's text align"),
  ];

  return $text_align;
}

/**
 * Return an block style form element configurations for font size element.
 */
function _block_style_font_size($breakpoint) {
  $font_size = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];
  $font_size['font_size'] = [
    '#type' => 'textfield',
    '#title' => t('Font size.'),
    '#maxlength' => '7',
  ];

  return $font_size;
}
