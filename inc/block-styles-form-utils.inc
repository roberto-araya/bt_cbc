<?php

/**
 * @file
 * Utils functions for block styles.
 */

/**
 * Returns a list of all blocks to which custom style settings will be applied.
 */
function _get_custom_styled_blocks() {
  $blocks = [
    'bt_cb_accordion',
    'bt_cb_faq',
    'bt_cb_contact_info',
    'bt_cb_cta',
    'bt_cb_hero',
    'bt_cb_highlighted_text_image',
    'bt_cb_text_icon',
    'bt_cb_text_image',
    'bt_cb_quote',
    'bt_cb_section_title',
    'bt_cb_social_profiles',
    'bt_cb_text',
    'bt_cb_title_icon',
    'bt_cb_title_image',
    'bt_cb_testimonial',
    'bt_cb_highlighted_text',
    'bt_embedded_video',
    'bt_image_link',
    'menu_block',
    'branding_block',
    'page_title_block',
    'commerce_cart',
    'system_breadcrumb_block',
    'text_fields_block',
  ];
  return $blocks;
}

/**
 * Returns a list of breakpoint screen sizes.
 */
function _get_screens_breakpoints() {
  return [
    'xs' => t('max-width: 575px'),
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];
}

/**
 * Return a font select options.
 */
function _get_font_family_options() {
  $options = [
    'default' => 'Default',
    'roboto' => 'Roboto',
    'jolly-lodger' => 'Jolly Lodger',
    'oswald' => 'Oswald',
    'zen-antique' => 'Zen Antique',
    'amatic-sc' => 'Amatic SC',
    'kalam' => 'Kalam',
    'russo-one' => 'Russo One',
    'archivo-black' => 'Archivo Black',
    'el-messiri' => 'El Messiri',
    'akaya-telivigala' => 'Akaya Telivigala',
    'baloo-2' => 'Baloo 2',
    'noticia-text' => 'Noticia Text',
    'kaushan-script' => 'Kaushan Script',
    'titan-one' => 'Titan One',
    'montserrat' => 'Montserrat',
    'ubuntu' => 'Ubuntu',
    'merriweather' => 'Merriweather',
    'playfair-display' => 'Playfair Display',
    'kanit' => 'Kanit',
    'lora' => 'Lora',
    'fira-sans' => 'Fira Sans',
    'quicksand' => 'Quicksand',
    'barlow' => 'Barlow',
    'titillium-web' => 'Titillium Web',
    'trispace' => 'Trispace',
    'josefin-sans' => 'Josefin Sans',
    'shalimar' => 'Shalimar',
    'anton' => 'Anton',
    'dancing-script' => 'Dancing Script',
    'secular-one' => 'Secular One',
    'lobster' => 'Lobster',
    'fjalla-one' => 'Fjalla One',
    'exo-2' => 'Exo 2',
    'caveat' => 'Caveat',
  ];

  return $options;
}

/**
 * Return a color opacity select options.
 */
function _get_opacity_options($type) {
  if ($type == 'hexadecimal') {
    return [
      'FF' => "100%",
      'F2' => "95%",
      'E6' => "90%",
      'D9' => "85%",
      'CC' => "80%",
      'BF' => "75%",
      'B3' => "70%",
      'A6' => "65%",
      '99' => "60%",
      '8C' => "55%",
      '80' => "50%",
      '73' => "45%",
      '66' => "40%",
      '59' => "35%",
      '4D' => "30%",
      '40' => "25%",
      '33' => "20%",
      '26' => "15%",
      '1A' => "10%",
      '0D' => "5%",
      '00' => "0%",
    ];
  }
  elseif ($type == 'decimal') {
    return [
      '1.00' => "100%",
      '0.95' => "95%",
      '0.90' => "90%",
      '0.85' => "85%",
      '0.80' => "80%",
      '0.75' => "75%",
      '0.70' => "70%",
      '0.65' => "65%",
      '0.60' => "60%",
      '0.55' => "55%",
      '0.50' => "50%",
      '0.45' => "45%",
      '0.40' => "40%",
      '0.35' => "35%",
      '0.30' => "30%",
      '0.25' => "25%",
      '0.20' => "20%",
      '0.15' => "15%",
      '0.10' => "10%",
      '0.05' => "5%",
      '0.00' => "0%",
    ];
  }
}

/**
 * Return an array of theme's color name.
 */
function _get_theme_color_options() :array {
  return [
    'default' => t('Default'),
    'primary' => t('Primary'),
    'primary-050' => t('Primary 50'),
    'primary-100' => t('Primary 100'),
    'primary-200' => t('Primary 200'),
    'primary-300' => t('Primary 300'),
    'primary-400' => t('Primary 400'),
    'primary-500' => t('Primary 500'),
    'primary-600' => t('Primary 600'),
    'primary-700' => t('Primary 700'),
    'primary-800' => t('Primary 800'),
    'primary-900' => t('Primary 900'),
    'secondary' => t('Secondary'),
    'secondary-050' => t('Secondary 50'),
    'secondary-100' => t('Secondary 100'),
    'secondary-200' => t('Secondary 200'),
    'secondary-300' => t('Secondary 300'),
    'secondary-400' => t('Secondary 400'),
    'secondary-500' => t('Secondary 500'),
    'secondary-600' => t('Secondary 600'),
    'secondary-700' => t('Secondary 700'),
    'secondary-800' => t('Secondary 800'),
    'secondary-900' => t('Secondary 900'),
    'accent' => t('Accent'),
    'accent-050' => t('Accent 50'),
    'accent-100' => t('Accent 100'),
    'accent-200' => t('Accent 200'),
    'accent-300' => t('Accent 300'),
    'accent-400' => t('Accent 400'),
    'accent-500' => t('Accent 500'),
    'accent-600' => t('Accent 600'),
    'accent-700' => t('Accent 700'),
    'accent-800' => t('Accent 800'),
    'accent-900' => t('Accent 900'),
    'success' => t('Success'),
    'info' => t('Info'),
    'warning' => t('Warning'),
    'danger' => t('Danger'),
    'light' => t('Light'),
    'dark' => t('Dark'),
    'blue' => t('Blue'),
    'indigo' => t('Indigo'),
    'purple' => t('Purple'),
    'pink' => t('Pink'),
    'red' => t('Red'),
    'orange' => t('Orange'),
    'yellow' => t('Yellow'),
    'green' => t('Green'),
    'teal' => t('Teal'),
    'cyan' => t('Cyan'),
    'white' => t('White'),
    'gray-050' => t('Gray 50'),
    'gray-100' => t('Gray 100'),
    'gray-200' => t('Gray 200'),
    'gray-300' => t('Gray 300'),
    'gray-400' => t('Gray 400'),
    'gray-500' => t('Gray 500'),
    'gray-600' => t('Gray 600'),
    'gray-700' => t('Gray 700'),
    'gray-800' => t('Gray 800'),
    'gray-900' => t('Gray 900'),
    'customColor' => t('Custom Color'),
  ];
}

/**
 * Return an array of sizes to apply in block styles form.
 */
function _get_size_options() :array {
  return [
    'default' => t('Default'),
    'none' => t('None'),
    '0.5rem' => t('Half'),
    '1rem' => t('Normal'),
    '2rem' => t('Double'),
    '3rem' => t('Triple'),
  ];
}

/**
 * Return an animations select options.
 */
function _get_animation_options() {
  return [
    'bounce' => 'Bounce',
    'flash' => 'Flash',
    'jello' => 'Jello',
    'pulse' => 'Pulse',
    'rubberBand' => 'Rubber Band',
    'shake' => 'Shake',
    'swing' => 'Swing',
    'tada' => 'Tada',
    'wooble' => 'Wooble',
    'bounceIn' => 'Bounce In',
    'bounceInDown' => 'Bounce In Down',
    'bounceInLeft' => 'Bounce In Left',
    'bounceInRight' => 'Bounce In Right',
    'bounceInUp' => 'Bounce In UP',
    'bounceOut' => 'Bounce Out',
    'bounceOutDown' => 'Bounce Out Down',
    'bounceOutLeft' => 'Bounce Out Left',
    'bounceOutRight' => 'Bounce Out Right',
    'bounceOutUp' => 'Bounce Out UP',
    'fadeIn' => 'Fade In',
    'fadeInDown' => 'Fade In Down',
    'fadeInDownBig' => 'Fade In Down Big',
    'fadeInLeft' => 'Fade In Left',
    'fadeInLeftBig' => 'Fade In Left Big',
    'fadeInRight' => 'Fade In Right',
    'fadeInRightBig' => 'Fade In Right Big',
    'fadeInUp' => 'Fade In Up',
    'fadeInUpBig' => 'Fade In Up Big',
    'fadeOut' => 'Fade Out',
    'fadeOutDown' => 'Fade Out Down',
    'fadeOutDownBig' => 'Fade Out Down Big',
    'fadeOutLeft' => 'Fade Out Left',
    'fadeOutLeftBig' => 'Fade Out Left Big',
    'fadeOutRight' => 'Fade Out Right',
    'fadeOutRightBig' => 'Fade Out Right Big',
    'fadeOutUp' => 'Fade Out Up',
    'fadeOutUpBig' => 'Fade Out Up Big',
    'flip' => 'Flip',
    'flipInX' => 'Flip In X',
    'flipInY' => 'Flip In Y',
    'flipOutX' => 'Flip Out X',
    'flipOutY' => 'Flip Out Y',
    'lightSpeedIn' => 'Light Speed In',
    'lightSpeedOut' => 'Light Speed OUT',
    'rotateIn' => 'Rotate In',
    'rotateInDownLeft' => 'Rotate In Down Left',
    'rotateInDownRight' => 'Rotate In Down Right',
    'rotateInUpLeft' => 'Rotate In Up Left',
    'rotateInUpRight' => 'Rotate In Up Right',
    'rotateOut' => 'Rotate Out',
    'rotateOutDownLeft' => 'Rotate Out Down Left',
    'rotateOutDownRight' => 'Rotate Out Down Right',
    'rotateOutUpLeft' => 'Rotate Out Up Left',
    'rotateOutUpRight' => 'Rotate Out Up Right',
    'slideInDown' => 'Slide In Down',
    'slideInLeft' => 'Slide In Left',
    'slideInRight' => 'Slide In Right',
    'slideOutUp' => 'Slide Out Up',
    'slideOutDown' => 'Slide Out Down',
    'slideOutLeft' => 'Slide Out Left',
    'slideOutRight' => 'Slide Out Right',
    'slideOutUp' => 'Slide Out Up',
    'hinge' => 'Hinge',
    'rollIn' => 'Roll In',
    'rollOut' => 'Roll Out',
    'zoomIn' => 'Zoom In',
    'zoomInDown' => 'Zoom In Down',
    'zoomInLeft' => 'Zoom In Left',
    'zoomInRight' => 'Zoom In Right',
    'zoomInUp' => 'Zoom In Up',
    'zoomOut' => 'Zoom Out',
    'zoomOutDown' => 'Zoom Out Down',
    'zoomOutLeft' => 'Zoom Out Left',
    'zoomOutRight' => 'Zoom Out Right',
    'zoomOutUp' => 'Zoom Out Up',
  ];
}

/**
 * Block Styles Block Preprocess Utils.
 */

/**
 * Block Styles block preprocess for title, captio and text elements.
 */
function _tct_styles_block_preprocess($block, &$variables, $element) {
  // Title, Caption or Text.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', $element)) {
    foreach ($settings as $setting => $value) {
      if ($setting == 'font_size') {
        foreach ($value as $prefix => $val) {
          $variables['configuration']['block_style'][$element . '_' . $prefix . '_' . $setting] = $val['font_size'];
        }
      }
      else {
        $variables['configuration']['block_style'][$element . '_' . $setting] = $value;
      }
    }
  }
}

/**
 * Block Styles block preprocess for buttons elements.
 */
function _buttons_styles_block_preprocess($block, &$variables) {
  // Title, Caption or Text.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'buttons')) {
    foreach ($settings as $setting => $values) {
      $variables['configuration']['block_style'][$setting . '_color_select'] = $values['color_select'];
      $variables['configuration']['block_style'][$setting . '_color_custom'] = $values['color_custom'];
    }
  }
}

/**
 * Block Style Form Base Builder.
 */
function _block_styles_form_base_builder() {
  $block_styles_form = [
    '#type' => 'fieldset',
    '#title' => t('Style'),
    '#description' => t('Styles that can be applied to the block presentation.'),
    '#tree' => TRUE,
    '#weight' => '100',
  ];

  $color = _block_style_color_opacity('background');
  $block_styles_form['background'] = [
    '#type' => 'details',
    '#title' => t('Background Color'),
    '#tree' => TRUE,
    '#weight' => '50',
    'color_select' => $color['color_select'],
    'color_custom' => $color['color_custom'],
    'color_opacity' => $color['color_opacity'],
    'color_custom_opacity' => $color['color_custom_opacity'],
  ];

  // Animation.
  $block_styles_form['animation'] = _animation_styles_form_element_builder();

  // Classes.
  $block_styles_form['custom_classes'] = _custom_classes_form_element_builder();

  // Max width.
  $block_styles_form['max_width'] = [
    '#type' => 'details',
    '#title' => t('Max width'),
    '#tree' => TRUE,
    '#weight' => '59',
  ];

  // Margin.
  $block_styles_form['margin'] = [
    '#type' => 'details',
    '#title' => t('Margin'),
    '#tree' => TRUE,
    '#weight' => '60',
  ];

  // Padding.
  $block_styles_form['padding'] = [
    '#type' => 'details',
    '#title' => t('Padding'),
    '#tree' => TRUE,
    '#weight' => '60',
  ];

  // Align.
  $block_styles_form['align'] = [
    '#type' => 'details',
    '#title' => t('Align'),
    '#tree' => TRUE,
    '#weight' => '70',
  ];

  // Justify.
  $block_styles_form['justify'] = [
    '#type' => 'details',
    '#title' => t('Justify'),
    '#tree' => TRUE,
    '#weight' => '71',
  ];

  // Text Align.
  $block_styles_form['text_align'] = [
    '#type' => 'details',
    '#title' => t('Text Align'),
    '#tree' => TRUE,
    '#weight' => '80',
  ];

  return $block_styles_form;
}
