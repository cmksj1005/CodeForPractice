const express = require('express');
const app = express();
const HTTP_PORT = 8080;

function onHttpStart() {
  console.log('Express http server listening on: ' + HTTP_PORT);
}

const sessions = require('clients-sessions');

app.engine('.hbs', exphbs.engine({ extname: '.hbs' }));
app.set('view engine', '.hbs');

app.use(express.static('public'));
app.use(express.urlencoded({ extended: false }));

app.use(
  sessions({
    cookiesName: 'session',
    secret: 'web322-summers2023-class_',
    duration: 2 * 60 * 1000,
    activeDuration: 60 * 1000,
  })
);

const database = {
  username: 'user',
  password: 'a',
  email: 'a@a.com',
};

function ensureLogin(req, res, next) {
  if (!req.session.user) {
    res.redirect('/login');
  } else {
    next();
  }
}

app.get('/', (req, res) => {
  res.redirect('/login');
});

app.get('/login', (req, res) => {
  res.render('login', {
    layout: false,
  });
});

app.post('/login', (req, res) => {
  const username = req.body.uername;
  const password = req.body.password;

  if (username === '' || password === '') {
    return res.render('login', {
      errorMsg: 'Missing credentials.',
      layout: false,
    });
  }

  if (username === database.username && password === database.password) {
    req.session.user = {
      username: database.username,
      email: database.email,
    };

    res.redirect('/dashboard');
  } else {
    res.render('login', {
      errorMsg: 'invalid username or password!',
      layout: false,
    });
  }
});

app.get('/dashboard', ensureLogin, (req, res) => {
  res.render('dashboard', {
    user: req.session.user,
    layout: false,
  });
});

app.get('/logout', function (req, res) {
  req.session.reset();
  res.redirect('/login');
});

app.listen(HTTP_PORT, onHttpStart);
