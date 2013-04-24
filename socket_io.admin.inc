<?php
/**
 * @file
 * Configure Socket.io settings form.
 */

function socket_io_settings_form($form, &$form_state) {
  $form['socket_io_auto_connect'] = array(
    '#type' => 'checkbox',
    '#title' => t('Automatically connect'),
    '#description' => t('If checked, the WebSocket connection will be automatically established. If not, you have to connect manually by running Drupal.socket_connect() with an optional callback as the first parameter.'),
    '#default_value' => variable_get('socket_io_auto_connect', TRUE),
  );

  $form['socket_io_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Host'),
    '#description' => t('Specify the host running the socket.io instance (Do not include http://).'),
    '#default_value' => variable_get('socket_io_host', ''),
  );

  $form['socket_io_port'] = array(
    '#type' => 'textfield',
    '#title' => t('Port'),
    '#description' => t('Specify the port nummer of the socket.io instance.'),
    '#default_value' => variable_get('socket_io_port', 80),
  );

  $form['socket_io_exclude'] = array(
    '#type' => 'radios',
    '#title' => t('Exclusion'),
    '#description' => t('Configure whether to include or exclude Socket.io by default.'),
    '#default_value' => variable_get('socket_io_exclude', 1),
    '#options' => array(
      0 => t('All pages except those listed'),
      1 => t('Only the listed pages'),
    ),
  );

  $form['socket_io_page_filters'] = array(
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#description' => t('Specify pages by using their paths. Enter one path per line. The \'*\' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page.'),
    '#default_value' => variable_get('socket_io_page_filters', '')
  );

  return system_settings_form($form);
}