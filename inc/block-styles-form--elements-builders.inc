<?php

/**
 * @file
 * Custom elements form builders functions for block styles.
 */

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

  // Font select.
  $title['font_family'] = _block_style_font_family();
  $title['font_family']['#title'] = t("Title's font.");

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

  // Font select.
  $caption['font_family'] = _block_style_font_family();
  $caption['font_family']['#title'] = t("Caption's font.");

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

  // Font select.
  $text['font_family'] = _block_style_font_family();
  $text['font_family']['#title'] = t("Text's font.");

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
