<?php

/**
 * @file
 * Custom block style form builders functions for.
 */

/**
 * Block Content.
 */

/**
 * Module bt_cb_cta standard.
 */
function _bt_cb_cta_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['buttons'] = _buttons_styles_form_element_builder(TRUE);

  return $block_style;
}

/**
 * Module bt_cb_cta layout builder.
 */
function _bt_cb_cta_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_cta_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style = _buttons_style_layout_builder_form_builder($section_component, $block_style, TRUE);

  return $block_style;
}

/**
 * Module bt_cb_cta block layout.
 */
function _bt_cb_cta_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_cta_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $block_style = _buttons_style_block_layout_form_builder($block, $block_style, TRUE);

  return $block_style;
}

/**
 * Module bt_cb_cta layout builder sumbit.
 */
function _bt_cb_cta_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
  _buttons_style_layout_builder_form_submit($form_state, $section_component, TRUE);
}

/**
 * Module bt_cb_hero standard.
 */
function _bt_cb_hero_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['buttons'] = _buttons_styles_form_element_builder(TRUE);

  return $block_style;
}

/**
 * Module bt_cb_hero layout builder.
 */
function _bt_cb_hero_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_hero_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style = _buttons_style_layout_builder_form_builder($section_component, $block_style, TRUE);

  return $block_style;
}

/**
 * Module bt_cb_hero block layout.
 */
function _bt_cb_hero_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_hero_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $block_style = _buttons_style_block_layout_form_builder($block, $block_style, TRUE);

  return $block_style;
}

/**
 * Module bt_cb_hero layout builder sumbit.
 */
function _bt_cb_hero_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
  _buttons_style_layout_builder_form_submit($form_state, $section_component, TRUE);
}

/**
 * Module bt_cb_highlighted_text_image standard.
 */
function _bt_cb_highlighted_text_image_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['highlighted'] = [
    '#type' => 'details',
    '#title' => t('Highlighted'),
    '#tree' => TRUE,
    '#weight' => 10,
  ];

  $colors = _block_style_color('highlighted');
  $block_style['highlighted']['color_select'] = $colors['color_select'];
  $block_style['highlighted']['color_custom'] = $colors['color_custom'];

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text_image layout builder.
 */
function _bt_cb_highlighted_text_image_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_highlighted_text_image_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style['highlighted']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_select');
  $block_style['highlighted']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_custom');

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text_image block layout.
 */
function _bt_cb_highlighted_text_image_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_highlighted_text_image_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $default_values = $block->getThirdPartySetting('bt_cbc', 'highlighted');
  $block_style['highlighted']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['highlighted']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text_image layout builder sumbit.
 */
function _bt_cb_highlighted_text_image_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);

  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);
}

/**
 * Module bt_cb_text_icon standard.
 */
function _bt_cb_text_icon_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['icon'] = [
    '#type' => 'details',
    '#title' => t('Icon'),
    '#tree' => TRUE,
    '#weight' => 10,
  ];

  $block_style['icon']['#weight'] = '10';
  $colors = _block_style_color('icon');
  $block_style['icon']['color_select'] = $colors['color_select'];
  $block_style['icon']['color_custom'] = $colors['color_custom'];
  $block_style['buttons'] = _buttons_styles_form_element_builder(FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text_icon layout builder.
 */
function _bt_cb_text_icon_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_text_icon_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style = _buttons_style_layout_builder_form_builder($section_component, $block_style, FALSE);
  $block_style['icon']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_select');
  $block_style['icon']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_custom');

  return $block_style;
}

/**
 * Module bt_cb_text_icon block layout.
 */
function _bt_cb_text_icon_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_text_icon_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $block_style = _buttons_style_block_layout_form_builder($block, $block_style, FALSE);
  $default_values = $block->getThirdPartySetting('bt_cbc', 'icon');
  $block_style['icon']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['icon']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Module bt_cb_text_icon layout builder sumbit.
 */
function _bt_cb_text_icon_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
  _buttons_style_layout_builder_form_submit($form_state, $section_component, FALSE);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);
}

/**
 * Module bt_cb_text_image standard.
 */
function _bt_cb_text_image_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['buttons'] = _buttons_styles_form_element_builder(FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text_image layout builder.
 */
function _bt_cb_text_image_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_text_image_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style = _buttons_style_layout_builder_form_builder($section_component, $block_style, FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text_image block layout.
 */
function _bt_cb_text_image_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_text_image_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $block_style = _buttons_style_block_layout_form_builder($block, $block_style, FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text_image layout builder sumbit.
 */
function _bt_cb_text_image_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
  _buttons_style_layout_builder_form_submit($form_state, $section_component, FALSE);
}

/**
 * Module bt_cb_quote standard.
 */
function _bt_cb_quote_style_form_builder() {
  $block_style = [];
  $n = 9;
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
    $block_style[$element] = [
      '#type' => 'details',
      '#tree' => TRUE,
      '#weight' => $n + 1,
    ];
    $colors = _block_style_color($element);
    $block_style[$element]['color_select'] = $colors['color_select'];
    $block_style[$element]['color_custom'] = $colors['color_custom'];
  }
  $block_style['text']['#title'] = t('Text');
  $block_style['source']['#title'] = t('Source');
  $block_style['link']['#title'] = t('Link');
  $block_style['symbol']['#title'] = t('Symbol');

  return $block_style;

}

/**
 * Module bt_cb_quote layout builder.
 */
function _bt_cb_quote_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_quote_style_form_builder();
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
    $block_style[$element]['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', $element . '_color_select');
    $block_style[$element]['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', $element . '_color_custom');
  }
  return $block_style;
}

/**
 * Module bt_cb_quote block layout.
 */
function _bt_cb_quote_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_quote_style_form_builder();

  foreach (['text', 'source', 'link', 'symbol'] as $element) {
    $default_values = $block->getThirdPartySetting('bt_cbc', $element);
    $block_style[$element]['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
    $block_style[$element]['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';
  }
  return $block_style;
}

/**
 * Module bt_cb_quote layout builder sumbit.
 */
function _bt_cb_quote_style_layout_builder_form_submit($form_state, $section_component) {
  foreach (['text', 'source', 'link', 'symbol'] as $element) {
    $get_value = ['third_party_settings', 'bt_cbc', $element, 'color_select'];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, $element, $get_value);

    $get_value = ['third_party_settings', 'bt_cbc', $element, 'color_custom'];
    _element_style_layout_builder_configure_block_submit($form_state, $section_component, $element, $get_value);
  }
}

/**
 * Module bt_cb_section_title standard.
 */
function _bt_cb_section_title_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  return $block_style;
}

/**
 * Module bt_cb_section_title layout builder.
 */
function _bt_cb_section_title_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_section_title_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);

  return $block_style;
}

/**
 * Module bt_cb_section_title block layout.
 */
function _bt_cb_section_title_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_section_title_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);

  return $block_style;
}

/**
 * Module bt_cb_section_title layout builder sumbit.
 */
function _bt_cb_section_title_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
}

/**
 * Module bt_cb_text standard.
 */
function _bt_cb_text_style_form_builder() {
  $block_style = _title_caption_text_style_form_builder();
  $block_style['buttons'] = _buttons_styles_form_element_builder(FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text layout builder.
 */
function _bt_cb_text_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_text_style_form_builder();
  $block_style = _title_caption_text_style_layout_builder_form_builder($section_component, $block_style);
  $block_style = _buttons_style_layout_builder_form_builder($section_component, $block_style, FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text block layout.
 */
function _bt_cb_text_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_text_style_form_builder();
  $block_style = _title_caption_text_style_block_layout_form_builder($block, $block_style);
  $block_style = _buttons_style_block_layout_form_builder($block, $block_style, FALSE);

  return $block_style;
}

/**
 * Module bt_cb_text layout builder sumbit.
 */
function _bt_cb_text_style_layout_builder_form_submit($form_state, $section_component) {
  _title_caption_text_style_layout_builder_form_submit($form_state, $section_component);
  _buttons_style_layout_builder_form_submit($form_state, $section_component, FALSE);
}

/**
 * Module bt_cb_title_icon standard.
 */
function _bt_cb_title_icon_style_form_builder() {
  $block_style = [
    'title' => _title_styles_form_element_builder(),
    'caption' => _caption_styles_form_element_builder(),
  ];
  $block_style['icon'] = [
    '#type' => 'details',
    '#title' => t('Icon'),
    '#tree' => TRUE,
    '#weight' => 10,
  ];

  $colors = _block_style_color('icon');
  $block_style['icon']['color_select'] = $colors['color_select'];
  $block_style['icon']['color_custom'] = $colors['color_custom'];

  return $block_style;
}

/**
 * Module bt_cb_title_icon layout builder.
 */
function _bt_cb_title_icon_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_title_icon_style_form_builder();

  $block_style['title']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_select');
  $block_style['title']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_custom');
  $block_style['title']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_font_family');

  $block_style['caption']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_select');
  $block_style['caption']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_custom');
  $block_style['caption']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_font_family');

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_' . $prefix . '_font_size');

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_' . $prefix . '_font_size');

  }
  $block_style['icon']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_select');
  $block_style['icon']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'icon_color_custom');

  return $block_style;
}

/**
 * Module bt_cb_title_icon block layout.
 */
function _bt_cb_title_icon_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_title_icon_style_form_builder();
  $title_default_values = $block->getThirdPartySetting('bt_cbc', 'title');
  $block_style['title']['color_select']['#default_value'] = $title_default_values ? $title_default_values['color_select'] : '';
  $block_style['title']['color_custom']['#default_value'] = $title_default_values ? $title_default_values['color_custom'] : '';
  $block_style['title']['font_family']['#default_value'] = $title_default_values ? $title_default_values['font_family'] : '';

  $caption_default_values = $block->getThirdPartySetting('bt_cbc', 'caption');
  $block_style['caption']['color_select']['#default_value'] = $caption_default_values ? $caption_default_values['color_select'] : '';
  $block_style['caption']['color_custom']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';
  $block_style['caption']['font_family']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $title_default_values ? $title_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $caption_default_values ? $caption_default_values['font_size'][$prefix]['font_size'] : '';
  }

  $default_values = $block->getThirdPartySetting('bt_cbc', 'icon');
  $block_style['icon']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['icon']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Module bt_cb_title_icon layout builder sumbit.
 */
function _bt_cb_title_icon_style_layout_builder_form_submit($form_state, $section_component) {
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

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'icon', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'icon', $get_value);
}

/**
 * Module bt_cb_title_image standard.
 */
function _bt_cb_title_image_style_form_builder() {
  $block_style = [
    'title' => _title_styles_form_element_builder(),
    'caption' => _caption_styles_form_element_builder(),
  ];
  return $block_style;
}

/**
 * Module bt_cb_title_image layout builder.
 */
function _bt_cb_title_image_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_title_image_style_form_builder();
  $block_style['title']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_select');
  $block_style['title']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_custom');
  $block_style['title']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_font_family');

  $block_style['caption']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_select');
  $block_style['caption']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_color_custom');
  $block_style['caption']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_font_family');

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_' . $prefix . '_font_size');

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'caption_' . $prefix . '_font_size');

  }
  return $block_style;
}

/**
 * Module bt_cb_title_image block layout.
 */
function _bt_cb_title_image_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_title_image_style_form_builder();

  $title_default_values = $block->getThirdPartySetting('bt_cbc', 'title');
  $block_style['title']['color_select']['#default_value'] = $title_default_values ? $title_default_values['color_select'] : '';
  $block_style['title']['color_custom']['#default_value'] = $title_default_values ? $title_default_values['color_custom'] : '';
  $block_style['title']['font_family']['#default_value'] = $title_default_values ? $title_default_values['font_family'] : '';

  $caption_default_values = $block->getThirdPartySetting('bt_cbc', 'caption');
  $block_style['caption']['color_select']['#default_value'] = $caption_default_values ? $caption_default_values['color_select'] : '';
  $block_style['caption']['color_custom']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';
  $block_style['caption']['font_family']['#default_value'] = $caption_default_values ? $caption_default_values['color_custom'] : '';

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $title_default_values ? $title_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['caption']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['caption']['font_size'][$prefix]['font_size']['#default_value'] = $caption_default_values ? $caption_default_values['font_size'][$prefix]['font_size'] : '';
  }

  return $block_style;
}

/**
 * Module bt_cb_title_image layout builder sumbit.
 */
function _bt_cb_title_image_style_layout_builder_form_submit($form_state, $section_component) {
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
 * Module bt_cb_testimonial standard.
 */
function _bt_cb_testimonial_style_form_builder() {
  $block_style = [
    'title' => _title_styles_form_element_builder(),
    'text' => _text_styles_form_element_builder(),
  ];
  return $block_style;
}

/**
 * Module bt_cb_testimonial layout builder.
 */
function _bt_cb_testimonial_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_testimonial_style_form_builder();

  $block_style['title']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_select');
  $block_style['title']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_color_custom');
  $block_style['title']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_font_family');

  $block_style['text']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_select');
  $block_style['text']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_color_custom');
  $block_style['text']['font_family']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_font_family');

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'title_' . $prefix . '_font_size');

    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'text_' . $prefix . '_font_size');
  }

  return $block_style;
}

/**
 * Module bt_cb_testimonial block layout.
 */
function _bt_cb_testimonial_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_testimonial_style_form_builder();

  $title_default_values = $block->getThirdPartySetting('bt_cbc', 'title');
  $block_style['title']['color_select']['#default_value'] = $title_default_values ? $title_default_values['color_select'] : '';
  $block_style['title']['color_custom']['#default_value'] = $title_default_values ? $title_default_values['color_custom'] : '';
  $block_style['title']['font_family']['#default_value'] = $title_default_values ? $title_default_values['font_family'] : '';

  $text_default_values = $block->getThirdPartySetting('bt_cbc', 'text');
  $block_style['text']['color_select']['#default_value'] = $text_default_values ? $text_default_values['color_select'] : '';
  $block_style['text']['color_custom']['#default_value'] = $text_default_values ? $text_default_values['color_custom'] : '';
  $block_style['text']['font_family']['#default_value'] = $text_default_values ? $text_default_values['font_family'] : '';

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

  foreach ($screens as $prefix => $breakpoint) {
    $block_style['title']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['title']['font_size'][$prefix]['font_size']['#default_value'] = $title_default_values ? $title_default_values['font_size'][$prefix]['font_size'] : '';

    $block_style['text']['font_size'][$prefix] = _block_style_font_size($breakpoint);
    $block_style['text']['font_size'][$prefix]['font_size']['#default_value'] = $text_default_values ? $text_default_values['font_size'][$prefix]['font_size'] : '';
  }

  return $block_style;
}

/**
 * Module bt_cb_testimonial layout builder sumbit.
 */
function _bt_cb_testimonial_style_layout_builder_form_submit($form_state, $section_component) {
  // title.
  _title_styles_layout_builder_form_element_sumbit($form_state, $section_component);
  // text.
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
 * Module bt_cb_highlighted_text standard.
 */
function _bt_cb_highlighted_text_style_form_builder() {
  $block_style['highlighted'] = [
    '#type' => 'details',
    '#title' => t('Highlighted'),
    '#tree' => TRUE,
    '#weight' => 10,
  ];

  $colors = _block_style_color('highlighted');
  $block_style['highlighted']['color_select'] = $colors['color_select'];
  $block_style['highlighted']['color_custom'] = $colors['color_custom'];

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text layout builder.
 */
function _bt_cb_highlighted_text_style_layout_builder_form_builder(&$section_component) {
  $block_style = _bt_cb_highlighted_text_style_form_builder();
  $block_style['highlighted']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_select');
  $block_style['highlighted']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'highlighted_color_custom');

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text block layout.
 */
function _bt_cb_highlighted_text_style_block_layout_form_builder($block) {
  $block_style = _bt_cb_highlighted_text_style_form_builder();

  $default_values = $block->getThirdPartySetting('bt_cbc', 'highlighted');
  $block_style['highlighted']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['highlighted']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Module bt_cb_highlighted_text layout builder sumbit.
 */
function _bt_cb_highlighted_text_style_layout_builder_form_submit($form_state, $section_component) {
  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'highlighted', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'highlighted', $get_value);
}

/**
 * Block System.
 */

/**
 * Block menu_block standard.
 */
function _menu_block_style_form_builder() {
  // Menu type.
  $block_style['type'] = [
    '#type' => 'select',
    '#options' => [
      'default' => t('Default'),
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

  return $block_style;
}

/**
 * Block menu_block layout builder.
 */
function _menu_block_style_layout_builder_form_builder(&$section_component) {
  $block_style = _menu_block_style_form_builder();
  // Type.
  $block_style['type']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'type');

  // Gap.
  $block_style['gap']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'gap');

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

  return $block_style;
}

/**
 * Block menu_block block layout.
 */
function _menu_block_style_block_layout_form_builder($block) {
  $block_style = _menu_block_style_form_builder();

  // Type.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'type');
  $block_style['type']['#default_value'] = $default_values ? $default_values : '';

  // Gap.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'gap');
  $block_style['gap']['#default_value'] = $default_values ? $default_values : '';

  // Item.
  $default_values = $block->getThirdPartySetting('bt_cbc', 'item');
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

  return $block_style;
}

/**
 * Block menu_block layout builder sumbit.
 */
function _menu_block_style_layout_builder_form_submit($form_state, $section_component) {
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

}

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
  ];

  // Logo.
  $block_style['logo_size'] = [
    '#type' => 'textfield',
    '#title' => t('Logo Size'),
    '#description' => t("CSS Property. Examples: 100px; 10vh; 30%;"),
  ];

  // Name.
  $block_style['name'] = [
    '#type' => 'details',
    '#title' => t('Name'),
    '#tree' => TRUE,
  ];

  // Name color.
  $colors = _block_style_color('name');
  $block_style['name']['color_select'] = $colors['color_select'];
  $block_style['name']['color_custom'] = $colors['color_custom'];

  // Name font_size.
  $block_style['name']['font_size'] = [
    '#type' => 'textfield',
    '#title' => t('Name Font Size'),
    '#description' => t("CSS Property. Examples: 2rem; 32px;"),
  ];

  // Slogan.
  $block_style['slogan'] = [
    '#type' => 'details',
    '#title' => t('Slogan'),
    '#tree' => TRUE,
  ];

  // Slogan color.
  $colors = _block_style_color('slogan');
  $block_style['slogan']['color_select'] = $colors['color_select'];
  $block_style['slogan']['color_custom'] = $colors['color_custom'];

  // Slogan font_size.
  $block_style['slogan']['font_size'] = [
    '#type' => 'textfield',
    '#title' => t('Slogan Font Size'),
    '#description' => t("CSS Property. Examples: 2rem; 32px;"),
  ];

  return $block_style;
}

/**
 * Block branding_block layout builder.
 */
function _branding_block_style_layout_builder_form_builder(&$section_component) {
  $block_style = _branding_block_style_form_builder();
  $block_style['type']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'type');
  $block_style['logo_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'logo_size');

  $block_style['name']['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'name_font_size');
  $block_style['name']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'name_color_select');
  $block_style['name']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'name_color_custom');

  $block_style['slogan']['font_size']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'slogan_font_size');
  $block_style['slogan']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'slogan_color_select');
  $block_style['slogan']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'slogan_color_custom');

  return $block_style;
}

/**
 * Block branding_block block layout.
 */
function _branding_block_style_block_layout_form_builder($block) {
  $block_style = _branding_block_style_form_builder();

  $default_values = $block->getThirdPartySetting('bt_cbc', 'type');
  $block_style['type']['#default_value'] = $default_values ? $default_values : '';

  $default_values = $block->getThirdPartySetting('bt_cbc', 'logo_size');
  $block_style['logo_size']['#default_value'] = $default_values ? $default_values : '';

  $default_values = $block->getThirdPartySetting('bt_cbc', 'name');
  $block_style['name']['font_size']['#default_value'] = $default_values ? $default_values['font_size'] : '';
  $block_style['name']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['name']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  $default_values = $block->getThirdPartySetting('bt_cbc', 'slogan');
  $block_style['slogan']['font_size']['#default_value'] = $default_values ? $default_values['font_size'] : '';
  $block_style['slogan']['color_select']['#default_value'] = $default_values ? $default_values['color_select'] : '';
  $block_style['slogan']['color_custom']['#default_value'] = $default_values ? $default_values['color_custom'] : '';

  return $block_style;
}

/**
 * Block branding_block layout builder sumbit.
 */
function branding_block_style_layout_builder_form_submit($form_state, $section_component) {
  $get_value = ['third_party_settings', 'bt_cbc', 'type'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'type', $component_style);
  }

  $get_value = ['third_party_settings', 'bt_cbc', 'logo_size'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'logo_size', $component_style);
  }

  $get_value = ['third_party_settings', 'bt_cbc', 'name' , 'font_size'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'name_font_size', $component_style);
  }

  $get_value = ['third_party_settings', 'bt_cbc', 'slogan', 'font_size'];
  if ($component_style = $form_state->getValue($get_value)) {
    $section_component->setThirdPartySetting('bt_cbc', 'slogan_font_size', $component_style);
  }
}

/**
 * UTILS.
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

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

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

  $screens = [
    'sm' => t('min-width: 576px'),
    'md' => t('min-width: 768px'),
    'lg' => t('min-width: 992px'),
    'xl' => t('min-width: 1200px'),
    'xxl' => t('min-width: 1400px'),
  ];

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
