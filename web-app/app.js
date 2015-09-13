var express = require('express');
var app = express();
var expressWs = require('express-ws')(app);
var fs = require('fs');

app.use(express.static('static'));

var server = app.listen(3000, function () {
  var host = server.address().address;
  var port = server.address().port;

  console.log('Example app listening at http://%s:%s', host, port);
});

app.ws('/echo', function(ws, req) {
});
var listener = expressWs.getWss('/echo');

var watchedFileName = "../temp_rebirth.txt";

var oldContents = null;
setInterval(function() {
	fs.readFile(watchedFileName, {encoding: "utf8"}, function(err, data) {
		if (oldContents != data) {
			oldContents = data;
			listener.clients.forEach(function(client) {
				client.send(data);
			});
		}
	});
}, 500);
