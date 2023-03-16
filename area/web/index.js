//index.js

const express = require('express'); //Import the express dependency
const app = express();
const routes = require('./server/routes');
var path = require('path');
const port = 8081;                  //Save the port number where your server will be listening
const session = require('express-session');
const flash = require('express-flash');
const cookieParser = require('cookie-parser');
const { checkServices } = require('./server/service');

app.use(cookieParser());
app.use (session({
  secret: 'secret',

  resave: false,

  saveUninitialized: false,
}));

app.engine('ejs', require('ejs').renderFile);
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname,'views'));

var fs = require('fs');

app.use(express.static('public'));


app.use('/', routes);

var server = app.listen(port, function() {
  var host = server.address().address
  var port = server.address().port
  console.log("listening at http://%s:%s", host, port)
});

setInterval(checkServices, 60000);
// checkServices();