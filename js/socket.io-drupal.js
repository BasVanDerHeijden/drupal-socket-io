(function($) {
  $(function() {
    Drupal.socket_connected = false;

    if (typeof io === 'undefined') {
      // Socket.io was not succesfully loaded.
      return;
    }

    Drupal.io = io;

    Drupal.socket_connect = function(cb) {
      Drupal.socket = Drupal.io.connect(Drupal.settings.socket_io.connection_string);

      Drupal.socket.on('connect', function() {
        Drupal.socket_connected = true;
        if (typeof cb === 'function') {
          cb(Drupal.socket);
        }
      });  

      Drupal.socket.on('disconnect', function() {
        Drupal.socket_connected = false;
      });
    };

    if (Drupal.settings.socket_io.auto_connect) {
      Drupal.socket_connect();
    }
  });
})(jQuery);