<?php

/**
 * @file
 * Utils functions for block styles.
 */

/**
 * Return an font select options.
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
 * Return an array of theme's color name.
 */
function _get_theme_color_options() :array {
  return [
    'default' => t('Default'),
    'bs-primary' => t('Primary'),
    'bs-primary-050' => t('Primary 50'),
    'bs-primary-100' => t('Primary 100'),
    'bs-primary-200' => t('Primary 200'),
    'bs-primary-300' => t('Primary 300'),
    'bs-primary-400' => t('Primary 400'),
    'bs-primary-500' => t('Primary 500'),
    'bs-primary-600' => t('Primary 600'),
    'bs-primary-700' => t('Primary 700'),
    'bs-primary-800' => t('Primary 800'),
    'bs-primary-900' => t('Primary 900'),
    'bs-secondary' => t('Secondary'),
    'bs-secondary-050' => t('Secondary 50'),
    'bs-secondary-100' => t('Secondary 100'),
    'bs-secondary-200' => t('Secondary 200'),
    'bs-secondary-300' => t('Secondary 300'),
    'bs-secondary-400' => t('Secondary 400'),
    'bs-secondary-500' => t('Secondary 500'),
    'bs-secondary-600' => t('Secondary 600'),
    'bs-secondary-700' => t('Secondary 700'),
    'bs-secondary-800' => t('Secondary 800'),
    'bs-secondary-900' => t('Secondary 900'),
    'bs-accent' => t('Accent'),
    'bs-accent-050' => t('Accent 50'),
    'bs-accent-100' => t('Accent 100'),
    'bs-accent-200' => t('Accent 200'),
    'bs-accent-300' => t('Accent 300'),
    'bs-accent-400' => t('Accent 400'),
    'bs-accent-500' => t('Accent 500'),
    'bs-accent-600' => t('Accent 600'),
    'bs-accent-700' => t('Accent 700'),
    'bs-accent-800' => t('Accent 800'),
    'bs-accent-900' => t('Accent 900'),
    'bs-success' => t('Success'),
    'bs-info' => t('Info'),
    'bs-warning' => t('Warning'),
    'bs-danger' => t('Danger'),
    'bs-light' => t('Light'),
    'bs-dark' => t('Dark'),
    'bs-blue' => t('Blue'),
    'bs-indigo' => t('Indigo'),
    'bs-purple' => t('Purple'),
    'bs-pink' => t('Pink'),
    'bs-red' => t('Red'),
    'bs-orange' => t('Orange'),
    'bs-yellow' => t('Yellow'),
    'bs-green' => t('Green'),
    'bs-teal' => t('Teal'),
    'bs-cyan' => t('Cyan'),
    'bs-white' => t('White'),
    'bs-gray-dark' => t('Gray Dark'),
    'bs-gray-100' => t('Gray 100'),
    'bs-gray-200' => t('Gray 200'),
    'bs-gray-300' => t('Gray 300'),
    'bs-gray-400' => t('Gray 400'),
    'bs-gray-500' => t('Gray 500'),
    'bs-gray-600' => t('Gray 600'),
    'bs-gray-700' => t('Gray 700'),
    'bs-gray-800' => t('Gray 800'),
    'bs-gray-900' => t('Gray 900'),
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
 * Return a list of custom styled blocks.
 */
function _get_custom_styled_blocks() {
  $blocks = [
    'bt_cb_cta',
    'bt_cb_hero',
    'bt_cb_highlighted_text_image',
    'bt_cb_text_icon',
    'bt_cb_text_image',
    'bt_cb_quote',
    'bt_cb_section_title',
    'bt_cb_text',
    'bt_cb_title_icon',
    'bt_cb_title_image',
    'bt_cb_testimonial',
    'bt_cb_highlighted_text',
    'menu_block',
    'branding_block',
  ];
  return $blocks;

}

/**
 * Block Styles Block Preprocess Utils.
 */

/**
 * Preprocess for bt_cb_cta blocks.
 */
function _bt_cb_cta_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Buttons.
  _buttons_styles_block_preprocess($block, $variables);
}

/**
 * Preprocess for bt_cb_hero blocks.
 */
function _bt_cb_hero_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Buttons.
  _buttons_styles_block_preprocess($block, $variables);
}

/**
 * Preprocess for bt_cb_highlighted_text_image blocks.
 */
function _bt_cb_highlighted_text_image_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Highlighted.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'highlighted')) {
    $variables['configuration']['block_style']['highlighted_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['highlighted_color_custom'] = $settings['color_custom'];
  }
}

/**
 * Preprocess for bt_cb_text_icon blocks.
 */
function _bt_cb_text_icon_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Icon.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'icon')) {
    $variables['configuration']['block_style']['icon_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['icon_color_custom'] = $settings['color_custom'];
  }
  // Buttons.
  _buttons_styles_block_preprocess($block, $variables);
}

/**
 * Preprocess for bt_cb_text_image blocks.
 */
function _bt_cb_text_image_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Buttons.
  _buttons_styles_block_preprocess($block, $variables);
}

/**
 * Preprocess for bt_cb_quote blocks.
 */
function _bt_cb_quote_styles_block_preprocess($block, &$variables) {
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
    if ($block && $settings = $block->getThirdPartySetting('bt_cbc', $element)) {
      $variables['configuration']['block_style'][$element . '_color_select'] = $settings['color_select'];
      $variables['configuration']['block_style'][$element . '_color_custom'] = $settings['color_custom'];
    }
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
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
}

/**
 * Preprocess for bt_cb_text blocks.
 */
function _bt_cb_text_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
  // Buttons.
  _buttons_styles_block_preprocess($block, $variables);
}

/**
 * Preprocess for bt_cb_title_icon blocks.
 */
function _bt_cb_title_icon_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');

  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'icon')) {
    $variables['configuration']['block_style']['icon_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['icon_color_custom'] = $settings['color_custom'];
  }
}

/**
 * Preprocess for bt_cb_title_image blocks.
 */
function _bt_cb_title_image_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Caption.
  _tct_styles_block_preprocess($block, $variables, 'caption');
}

/**
 * Preprocess for bt_cb_testimonial blocks.
 */
function _bt_cb_testimonial_styles_block_preprocess($block, &$variables) {
  // Title.
  _tct_styles_block_preprocess($block, $variables, 'title');
  // Text.
  _tct_styles_block_preprocess($block, $variables, 'text');
}

/**
 * Preprocess for bt_cb_highlighted_text blocks.
 */
function _bt_cb_highlighted_text_styles_block_preprocess($block, &$variables) {
  // Highlighted.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'highlighted')) {
    $variables['configuration']['block_style']['highlighted_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['highlighted_color_custom'] = $settings['color_custom'];
  }
}

/**
 * Preprocess for menu_block blocks.
 */
function _menu_block_styles_block_preprocess($block, &$variables) {
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
    $variables['configuration']['block_style']['name_font_size'] = $settings['font_size'];
    $variables['configuration']['block_style']['name_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['name_color_custom'] = $settings['color_custom'];
  }

  // Slogan Font Size.
  if ($block && $settings = $block->getThirdPartySetting('bt_cbc', 'slogan')) {
    $variables['configuration']['block_style']['slogan_font_size'] = $settings['font_size'];
    $variables['configuration']['block_style']['slogan_color_select'] = $settings['color_select'];
    $variables['configuration']['block_style']['slogan_color_custom'] = $settings['color_custom'];
  }

}

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

  $color = _block_style_color('background');
  $block_styles_form['background'] = [
    '#type' => 'details',
    '#title' => t('Background Color'),
    '#tree' => TRUE,
    '#weight' => '50',
    'color_select' => $color['color_select'],
    'color_custom' => $color['color_custom'],
  ];

  // Animation.
  $block_styles_form['animation'] = _animation_styles_form_element_builder();

  // Classes.
  $block_styles_form['custom_classes'] = _custom_classes_form_element_builder();

  // Padding.
  $block_styles_form['padding'] = [
    '#type' => 'details',
    '#title' => t('Padding'),
    '#tree' => TRUE,
    '#weight' => '60',
  ];

  // Blog Align.
  $block_styles_form['block_align'] = [
    '#type' => 'details',
    '#title' => t('Block Align'),
    '#tree' => TRUE,
    '#weight' => '70',
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