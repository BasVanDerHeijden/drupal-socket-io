(function($) {
  Drupal.behaviors.socket_io = {
    attach: function(context, settings) {
      Drupal.socket_connected = false;

      if (typeof io === 'undefined') {
        // Socket.io was not succesfully loaded.
        return;
      }

      Drupal.io = io;
      Drupal.socket = Drupal.io.connect(settings.socket_io.connection_string);
      Drupal.socket.on('connect', function() {
        Drupal.socket_connected = true;
      });

      Drupal.socket.on('disconnect', function() {
        Drupal.socket_connected = false;
      });
    }
  };
})(jQuery);