<?php

/**
 * @file
 * Block style for breadcrumb_block.
 */

/**
 * Module breadcrumb_block standard.
 */
function _breadcrumb_block_style_form_builder() {
  $block_style = [
    'link' => [
      '#type' => 'details',
      '#title' => t('Link'),
      '#tree' => TRUE,
      '#weight' => 1,
    ],
  ];

  // Link color.
  $colors = _block_style_color('link');
  $block_style['link']['color_select'] = $colors['color_select'];
  $block_style['link']['color_select']['#title'] = t('Link Color');

  $block_style['link']['color_custom'] = $colors['color_custom'];
  $block_style['link']['color_custom']['#title'] = t('Link Color Custom');
  $block_style['link']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][link][color_select]"]' => ['value' => 'customColor'],
  ];

  // Link color hover.
  $block_style['link']['hover']['color_select'] = $colors['color_select'];
  $block_style['link']['hover']['color_select']['#title'] = t('Link Hover Color');

  $block_style['link']['hover']['color_custom'] = $colors['color_custom'];
  $block_style['link']['hover']['color_custom']['#title'] = t('Link Hover Color Custom');
  $block_style['link']['hover']['color_custom']['#states']['visible'] = [
    ':input[name="third_party_settings[bt_cbc][link][hover][color_select]"]' => ['value' => 'customColor'],
  ];

  return $block_style;
}

/**
 * Module breadcrumb_block layout builder.
 */
function _breadcrumb_block_style_layout_builder_form_builder(&$section_component) {
  $block_style = _breadcrumb_block_style_form_builder();

  $block_style['link']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'link_color_select');
  $block_style['link']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'link_color_custom');
  $block_style['link']['hover']['color_select']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'link_hover_color_select');
  $block_style['link']['hover']['color_custom']['#default_value'] = $section_component->getThirdPartySetting('bt_cbc', 'link_hover_color_custom');

  return $block_style;
}

/**
 * Module breadcrumb_block block layout.
 */
function _breadcrumb_block_style_block_layout_form_builder($block) {
  $block_style = _breadcrumb_block_style_form_builder();

  $link_default_values = $block->getThirdPartySetting('bt_cbc', 'link');
  $block_style['link']['color_select']['#default_value'] = $link_default_values ? $link_default_values['color_select'] : '';
  $block_style['link']['color_custom']['#default_value'] = $link_default_values ? $link_default_values['color_custom'] : '';

  $block_style['link']['hover']['color_select']['#default_value'] = $link_default_values ? $link_default_values['hover']['color_select'] : '';
  $block_style['link']['hover']['color_custom']['#default_value'] = $link_default_values ? $link_default_values['hover']['color_custom'] : '';

  return $block_style;
}

/**
 * Module breadcrumb_block layout builder sumbit.
 */
function _breadcrumb_block_style_layout_builder_form_submit($form_state, $section_component) {
  // Link color.
  $get_value = ['third_party_settings', 'bt_cbc', 'link', 'color_select'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'link', $get_value);

  $get_value = ['third_party_settings', 'bt_cbc', 'link', 'color_custom'];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'link', $get_value);

  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'link',
    'hover',
    'color_select',
  ];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'link', $get_value);

  $get_value = [
    'third_party_settings',
    'bt_cbc',
    'link',
    'hover',
    'color_custom',
  ];
  _element_style_layout_builder_configure_block_submit($form_state, $section_component, 'link', $get_value);
}

/**
 * Preprocess for breadcrumb_block blocks.
 */
function _breadcrumb_block_styles_block_preprocess($block, &$variables) {
  // Link.
  $variables['configuration']['block_style']['link_color_select'] = $settings['color_select'];
  $variables['configuration']['block_style']['link_color_custom'] = $settings['color_custom'];

  $variables['configuration']['block_style']['link_hover_color_select'] = $settings['hover']['color_select'];
  $variables['configuration']['block_style']['link_hover_color_custom'] = $settings['hover']['color_custom'];
}
