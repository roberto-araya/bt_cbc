<?php

/**
 * @file
 * Custom elements form builders functions for block styles.
 */

/**
 * Title, caption, text.
 */
function _title_caption_text_style_form_builder() {
  $block_style = [
    'title' => _title_styles_form_element_builder(),
    'caption' => _caption_styles_form_element_builder(),
    'text' => _text_styles_form_element_builder(),
  ];

  return $block_style;
}

/**
 * Title, caption, text layout builder.
 */
function _title_caption_text_style_layout_builder_form_builder(&$section_component, $block_style) {
  // Default Values.
  $block_style['title']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_select');
  $block_style['title']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_custom');
  $block_style['title']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_font_family');

  $block_style['caption']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_select');
  $block_style['caption']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_custom');
  $block_style['caption']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_font_family');

  $block_style['text']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_select');
  $block_style['text']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_custom');
  $block_style['text']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_font_family');

  $screens = _get_screens_breakpoints();

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_' . $prefix . '_font_size');

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_' . $prefix . '_font_size');

    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');
  }
  return $block_style;
}

/**
 * Buttons layout builder.
 */
function _buttons_style_layout_builder_form_builder(&$section_component, $block_style, $secondary = FALSE) {
  // Default Values.
  $block_style['buttons']['button']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_color_select');
  $block_style['buttons']['button']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_color_custom');

  $block_style['buttons']['button_link']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_link_color_select');
  $block_style['buttons']['button_link']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_link_color_custom');
  if ($secondary) {
    $block_style['buttons']['button_secondary']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_secondary_color_select');
    $block_style['buttons']['button_secondary']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_secondary_color_custom');

    $block_style['buttons']['button_secondary_link']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_secondary_link_color_select');
    $block_style['buttons']['button_secondary_link']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'button_secondary_link_color_custom');
  }

  return $block_style;
}

/**
 * Title, caption, text block layout.
 */
function _title_caption_text_style_block_layout_form_builder($block, $block_style) {
  // Default Values.
  $title_default_values = $block->getThirdPartySetting('bt_cbc', 'title');
  $block_style['title']['color_select']['#default_value'] = $title_default_values ? $title_default_values['color_select'] : '';
  $block_style['title']['color_custom']['#default_value'] = $title_default_values ? $title_default_values['color_custom'] : '';
  $block_style['title']['font_family']['#default_value'] = $title_default_values ? $title_default_values['font_family'] : '';

  $caption_default_values = $block->getThirdPartySetting('bt_cbc', 'caption');
  $block_style['caption']['color_select']['#default_value'] = $caption_default_values ? $caption_default_values['color_select'] : '';
  $block_style['caption']['color_custom']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';
  $block_style['caption']['font_family']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'text');
  $block_style['text']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['text']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['text']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $screens = _get_screens_breakpoints();

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $title_default_values ? $title_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $caption_default_values ? $caption_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';
  }

  return $block_style;

}

/**
 * Buttons block layout.
 */
function _buttons_style_block_layout_form_builder($block, $block_style, $secondary = FALSE) {
  // Default Values.
  $buttons_default_values = $block->getThirdPartySetting('bt_cbc', 'buttons');
  $block_style['buttons']['button']['color_select']['#default_value'] = $buttons_default_values ? $buttons_default_values['button']['color_select'] : '';
  $block_style['buttons']['button']['color_custom']['#default_value'] = $buttons_default_values ? $buttons_default_values['button']['color_custom'] : '';

  $block_style['buttons']['button_link']['color_select']['#default_value'] = $buttons_default_values ? $buttons_default_values['button_link']['color_select'] : '';
  $block_style['buttons']['button_link']['color_custom']['#default_value'] = $buttons_default_values ? $buttons_default_values['button_link']['color_custom'] : '';

  if ($secondary) {
    $block_style['buttons']['button_secondary']['color_select']['#default_value'] = $buttons_default_values ? $buttons_default_values['button_secondary']['color_select'] : '';
    $block_style['buttons']['button_secondary']['color_custom']['#default_value'] = $buttons_default_values ? $buttons_default_values['button_secondary']['color_custom'] : '';

    $block_style['buttons']['button_secondary_link']['color_select']['#default_value'] = $buttons_default_values ? $buttons_default_values['button_secondary_link']['color_select'] : '';
    $block_style['buttons']['button_secondary_link']['color_custom']['#default_value'] = $buttons_default_values ? $buttons_default_values['button_secondary_link']['color_custom'] : '';
  }

  return $block_style;
}

/**
 * Return a title style form element.
 */
function _title_styles_form_element_builder() {
  // Details.
  $title = [
    '#type' => 'details',
    '#title' => t('Title'),
    '#tree' => TRUE,
    '#weight' => 1,
  ];

  // Color.
  $color = _block_style_color('title');
  $title['color_select'] = $color['color_select'];
  $title['color_custom'] = $color['color_custom'];

  // Font family.
  $title['font_family'] = _block_style_font_family();

  // Font size.
  $title['font_size'] = [
    '#type' => 'details',
    '#title' => t('Font Size'),
    '#tree' => TRUE,
  ];

  return $title;
}

/**
 * Return a caption style form element.
 */
function _caption_styles_form_element_builder() {
  // Details.
  $caption = [
    '#type' => 'details',
    '#title' => t('Caption'),
    '#tree' => TRUE,
    '#weight' => 2,
  ];

  // Color.
  $color = _block_style_color('caption');
  $caption['color_select'] = $color['color_select'];
  $caption['color_custom'] = $color['color_custom'];

  // Font family.
  $caption['font_family'] = _block_style_font_family();

  // Font size.
  $caption['font_size'] = [
    '#type' => 'details',
    '#title' => t('Font Size'),
    '#tree' => TRUE,
  ];

  return $caption;
}

/**
 * Return a text style form element.
 */
function _text_styles_form_element_builder() {
  // Details.
  $text = [
    '#type' => 'details',
    '#title' => t('Text'),
    '#tree' => TRUE,
    '#weight' => '3',
  ];

  // Color.
  $color = _block_style_color('text');
  $text['color_select'] = $color['color_select'];
  $text['color_custom'] = $color['color_custom'];

  // Font family.
  $text['font_family'] = _block_style_font_family();

  // Font size.
  $text['font_size'] = [
    '#type' => 'details',
    '#title' => t('Font Size'),
    '#tree' => TRUE,
  ];

  return $text;

}

/**
 * Return a buttons style form elements.
 */
function _buttons_styles_form_element_builder($secondary = FALSE) {
  $buttons = [
    '#type' => 'details',
    '#title' => t('Buttons'),
    '#tree' => TRUE,
    '#weight' => '10',
  ];

  $color = _block_style_color('button');
  $buttons['button'] = [
    'color_select' => $color['color_select'],
    'color_custom' => $color['color_custom'],
  ];
  $buttons['button']['color_select']['#title'] = t('Button Color');
  $buttons['button']['color_custom']['#title'] = t('Button Color Custom');
  $buttons['button']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][buttons][button][color_select]"]' => ['value' => 'customColor'],
  ];

  $color = _block_style_color('button_link');
  $buttons['button_link'] = [
    'color_select' => $color['color_select'],
    'color_custom' => $color['color_custom'],
  ];
  $buttons['button_link']['color_select']['#title'] = t('Button Link Color');
  $buttons['button_link']['color_custom']['#title'] = t('Button Link Color Custom');
  $buttons['button_link']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][buttons][button_link][color_select]"]' => ['value' => 'customColor'],
  ];

  if ($secondary) {
    $color = _block_style_color('button_secondary');
    $buttons['button_secondary'] = [
      'color_select' => $color['color_select'],
      'color_custom' => $color['color_custom'],
    ];
    $buttons['button_secondary']['color_select']['#title'] = t('Button Secondary Color');
    $buttons['button_secondary']['color_custom']['#title'] = t('Button Secondary Color Custom');
    $buttons['button_secondary']['color_custom']['#states']['visible'] = [
      ':input[name="third_party_settings[bt_cbc][buttons][button_secondary][color_select]"]' => ['value' => 'customColor'],
    ];

    $color = _block_style_color('button_secondary_link');
    $buttons['button_secondary_link'] = [
      'color_select' => $color['color_select'],
      'color_custom' => $color['color_custom'],
    ];
    $buttons['button_secondary_link']['color_select']['#title'] = t('Button Secondary Link Color');
    $buttons['button_secondary_link']['color_custom']['#title'] = t('Button Secondary link Color Custom');
    $buttons['button_secondary_link']['color_custom']['#states']['visible'] = [
      ':input[name="third_party_settings[bt_cbc][buttons][button_secondary_link][color_select]"]' => ['value' => 'customColor'],
    ];
  }

  return $buttons;

}

/**
 * Return a animation styles form elements.
 */
function _animation_styles_form_element_builder() {
  $animation = [
    '#type' => 'details',
    '#title' => t('Animation'),
    '#tree' => TRUE,
    '#weight' => 20,
    '#description' => t("Select an animation for the block."),
  ];

  $animation['option'] = [
    '#type' => 'checkbox',
    '#title' => t("Add animation"),
  ];

  // When the animation start.
  $animation['trigger'] = [
    '#type' => 'select',
    '#options' => [
      'on_page_load' => t("On page load"),
      'on_scroll' => t("On scroll"),
    ],
    '#title' => t('Trigger'),
    '#description' => t("Select when trigger animation."),
    '#states' => [
      'visible' => [
        ':input[name="third_party_settings[bt_cbc][animation][option]"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // Type of animation.
  $animation['type'] = [
    '#type' => 'select',
    '#options' => _get_animation_options(),
    '#title' => t('Type'),
    '#description' => t("Select a type of animation. Default: Fade In."),
    '#states' => [
      'visible' => [
        ':input[name="third_party_settings[bt_cbc][animation][option]"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // Animation duration.
  $animation['duration'] = [
    '#type' => 'textfield',
    '#title' => t("Duration"),
    '#description' => t("Enter the duration for the animation in seconds or miliseconds. Default (1s) for empty."),
    '#attributes' => [
      'placeholder' => 'examples: 800ms,0.8s',
    ],
    '#states' => [
      'visible' => [
        ':input[name="third_party_settings[bt_cbc][animation][option]"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // Animation count.
  $animation['count'] = [
    '#type' => 'textfield',
    '#title' => t("Count"),
    '#description' => t("Enter the number of cycles for the animation. Default (1) for empty."),
    '#attributes' => [
      'placeholder' => 'examples: 1, 2, 5',
    ],
    '#states' => [
      'visible' => [
        ':input[name="third_party_settings[bt_cbc][animation][option]"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // Animation delay.
  $animation['delay'] = [
    '#type' => 'textfield',
    '#title' => t("Delay"),
    '#description' => t("Enter the delay for the animation in seconds or miliseconds. Default (0) for empty."),
    '#attributes' => [
      'placeholder' => 'examples: 1s, 1000ms',
    ],
    '#states' => [
      'visible' => [
        ':input[name="third_party_settings[bt_cbc][animation][option]"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // Animation function.
  $animation['function'] = [
    '#type' => 'select',
    '#title' => t("Function"),
    '#options' => [
      'default' => t('Default'),
      'ease' => t('Ease'),
      'ease-in' => t('Ease In'),
      'ease-out' => t('Ease Out'),
      'ease-in-out' => t('Ease In Out'),
      'linear' => t('Linear'),
    ],
    '#description' => t("Select the transition timing function. Default: Ease."),
    '#states' => [
      'visible' => [
        ':input[name="third_party_settings[bt_cbc][animation][option]"]' => ['checked' => TRUE],
      ],
    ],
  ];

  // Animation fill mode.
  $animation['fill'] = [
    '#type' => 'select',
    '#title' => t("Fill Mode"),
    '#options' => [
      'default' => t('Default'),
      'none' => t('None'),
      'forwards' => t('Forwards'),
      'backwards' => t('Backwards'),
      'both' => t('Both'),
      'initial' => t('Initial'),
      'inherit' => t('Inherit'),
    ],
    '#description' => t("Select the animation-fill-mode property. Default: Both."),
    '#states' => [
      'visible' => [
        ':input[name="third_party_settings[bt_cbc][animation][option]"]' => ['checked' => TRUE],
      ],
    ],
  ];

  return $animation;
}

/**
 * Return a custom class textfield element.
 */
function _custom_classes_form_element_builder() {
  return [
    '#type' => 'textfield',
    '#title' => t('CSS class(es)'),
    '#description' => t('Customize the styling of this block by adding CSS classes. Separate multiple classes by spaces.'),
    '#weight' => '100',
  ];
}

/**
 * Builder uitls.
 */

/**
 * Return an form section for color and opacity elements configurations.
 */
function _block_style_color_opacity($element) {
  return [
    'color_select' => [
      '#type' => 'select',
      '#options' => _get_theme_color_options(),
      '#title' => t('Color'),
      '#description' => t("Select a theme color or use a custom color."),
    ],

    'color_custom' => [
      '#type' => 'color',
      '#title' => t('Custom Color'),
      '#description' => t("Click in the color to select a custom one."),
      '#states' => [
        'visible' => [
          ':input[name="third_party_settings[bt_cbc][' . $element . '][color_select]"]' => ['value' => 'customColor'],
        ],
      ],
    ],

    'color_opacity' => [
      '#type' => 'select',
      '#options' => _get_opacity_options('decimal'),
      '#title' => t('Color Opacity'),
      '#description' => t("Select an opacity for color."),
      '#states' => [
        'invisible' => [
          ':input[name="third_party_settings[bt_cbc][' . $element . '][color_select]"]' => ['value' => 'customColor'],
        ],
      ],
    ],

    'color_custom_opacity' => [
      '#type' => 'select',
      '#options' => _get_opacity_options('hexadecimal'),
      '#title' => t('Color Opacity'),
      '#description' => t("Select an opacity for color."),
      '#states' => [
        'visible' => [
          ':input[name="third_party_settings[bt_cbc][' . $element . '][color_select]"]' => ['value' => 'customColor'],
        ],
      ],
    ],
  ];
}

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
    '#title' => t("Font Family"),
  ];
}

/**
 * STYLES FORMS BUILDERS - BREAKPOINTS DEPENDED.
 */

/**
 * Return a block style form element configurations for margin and padding.
 */
function _block_style_margin_padding($breakpoint, $type) {
  $return = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];

  $sides = [
    'left' => t('Left'),
    'top' => t('Top'),
    'right' => t('Right'),
    'bottom' => t('Bottom'),
  ];

  foreach ($sides as $side => $title) {
    $return[$type . '_' . $side] = [
      '#type' => 'textfield',
      '#title' => $title,
      '#maxlength' => '6',
      '#description' => t("Units: px, rem, vw. Examples: 2rem, 0.5vw"),
    ];
  }

  return $return;

}

/**
 * Return an block style form element configurations for align element.
 */
function _block_style_align($breakpoint) {
  $block_align = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];

  $block_align['align'] = [
    '#type' => 'select',
    '#title' => t('Align'),
    '#options' => [
      'default' => t('Default'),
      'auto' => t('Auto'),
      'baseline' => t('Baseline'),
      'center' => t('Center'),
      'end' => t('End'),
      'first-baseline' => t('First Baseline'),
      'flex-end' => t('Flex End'),
      'flex-start' => t('Flex Start'),
      'inherit' => t('Inherit'),
      'initial' => t('Initial'),
      'last-baseline' => t('Last Baseline'),
      'left' => t('Left'),
      'normal' => t('Normal'),
      'revert' => t('Revert'),
      'revert-layer' => t('Revert Layer'),
      'right' => t('Right'),
      'safe' => t('Safe'),
      'self-end' => t('Self End'),
      'self-start' => t('Self Start'),
      'start' => t('Start'),
      'stretch' => t('Stretch'),
      'unsafe' => t('Unsafe'),
      'unset' => t('Unset'),
    ],
    '#description' => t("Align"),
  ];

  return $block_align;
}

/**
 * Return an block style form element configurations for justify element.
 */
function _block_style_justify($breakpoint) {
  $block_align = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];

  $block_align['justify'] = [
    '#type' => 'select',
    '#title' => t('Justify'),
    '#options' => [
      'default' => t('Default'),
      'center' => t('Center'),
      'end' => t('End'),
      'flex-end' => t('Flex End'),
      'flex-start' => t('Flex Start'),
      'inherit' => t('Inherit'),
      'initial' => t('Initial'),
      'left' => t('Left'),
      'normal' => t('Normal'),
      'revert' => t('Revert'),
      'revert-layer' => t('Revert Layer'),
      'right' => t('Right'),
      'safe' => t('Safe'),
      'start' => t('Start'),
      'stretch' => t('Stretch'),
      'unsafe' => t('Unsafe'),
      'unset' => t('Unset'),
    ],
    '#description' => t("Justify"),
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

/**
 * Return an block style form element configurations for max_width element.
 */
function _block_style_max_width($breakpoint) {
  $font_size = [
    '#type' => 'details',
    '#title' => $breakpoint,
    '#tree' => TRUE,
  ];
  $font_size['max_width'] = [
    '#type' => 'textfield',
    '#title' => t('Max width.'),
    '#maxlength' => '7',
  ];

  return $font_size;
}
