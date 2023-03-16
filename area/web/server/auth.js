const express = require('express');
const routerAuth = express.Router();
const bodyParser = require('body-parser');
const bcrypt = require('bcrypt');
const auth = require('./cookies.js');
const { db_request } = require('./db.js');
const { dashboard } = require('./dashboard.js');

routerAuth.use(express.urlencoded({ extended: true }));

routerAuth.use(express.json());

routerAuth.get("/", (req, res) => {
  const authToken = req.cookies.authToken;
  console.log("here");
  if (authToken) {
    console.log("call dashboard");
    dashboard(req, res);
    return;
  }
  res.render('login');
});

routerAuth.post("/login", async (req, res) => {
  let { user, password } = req.body;

  let errors = [];
  db_request(req, res, ("SELECT * from users;"))
    .then ( (result) => {
      console.log(result)
    })
    .catch(error => {
      console.log(error);
    });
  // Check required fields
  if(!user || !password) {
    errors.push({ msg: 'Please fill in all fields' });
  }

  if (errors.length > 0) {
    res.render('login', { errors });
    return;
  }
  else {
    db_request(req, res, "SELECT * FROM users WHERE name=$1;", [user])
  .then(async precheck => {
    if (Array.isArray(precheck) && precheck.length) {
      if (!await bcrypt.compare(password, precheck[0].password)) {
        errors.push({ msg: 'Wrong credentials'});
        res.render('login', { errors });
        return;
      }
      else {
        auth.generateAuthToken({ username: user, id: precheck[0].id }, res);
        res.redirect('/');
      }
    }
    else {
      errors.push({ msg: 'Wrong credentials'});
      res.render('login', { errors });
      return;
    }
  })
  .catch(error => {
    console.log(error);
    res.status(500).send('Internal server error');
  });
  }

});

routerAuth.post("/mobile/login", async (req, res) => {
  console.log(req.body);
  let { name, pass } = req.body;
  console.log("name "+name)
  db_request(req, res, "SELECT * FROM users WHERE name=$1;", [name])
  .then(async precheck => {
    console.log(precheck);
    if (Array.isArray(precheck) && precheck.length) {
      if (!await bcrypt.compare(pass, precheck[0].password)) {
        errors.push({ msg: 'Wrong credentials'});
        res.body = { msg: 'Wrong credentials'};
        res.status(401).send('Unauthorized');
        return;
      }
      else {
        const token = auth.generateAuthToken({ username: name, id: precheck[0].id }, res);
        console.log("generated token");
        res.body = { msg : 'OK', token: token };
        console.log(token);
        res.status(200).send(res.body);
        return;
      }
    }
    else {
      res.body = { msg: 'Wrong credentials'};
      res.status(401).send('Unauthorized');
      return;
    }
  })
  .catch(error => {
    console.log(error);
    res.status(500).send('Internal server error');
  });

});

routerAuth.post("/register", async (req, res) => {
  let { name, email, phonenb, password, password2 } = req.body;

  console.log({
    name,
    email,
    phonenb,
    password,
    password2
  });

  let errors = [];

  // Check required fields
  if(!name || !email || !password || !password2 || !phonenb) {
    errors.push({ msg: 'Please fill in all fields' });
  }

  if (password != password2) {
    errors.push({ msg: 'Passwords do not match' });
  }

  if (password.length < 6) {
    errors.push({ msg: 'Password should be at least 6 characters' });
  }

  if (errors.length > 0) {
    res.render('register', { errors });
    return;
  }
  else {
    let hashedPassword = await bcrypt.hash(password, 10);
    db_request(req, res, "SELECT * FROM users WHERE name=$1;", [name])
  .then(precheck => {
    if (Array.isArray(precheck) && precheck.length) {
      console.log("User already exists");
      errors.push({ msg: 'User already exists' });
      res.render('register', { errors });
      return; 
    }
    else {
      db_request(req, res, ("INSERT INTO users(name, email, phone_number, password) SELECT $1, $2, $3, $4 WHERE NOT EXISTS (SELECT 1 FROM users WHERE name=$1) RETURNING id, password;"), [name, email, phonenb, hashedPassword])
        .then(data => {
          console.log(data);
          res.render('login');
          return;
        })
        .catch(error => {
          console.log(error);
          res.status(500).send('Internal server error');
        });
    }
  })
  .catch(error => {
    console.log(error);
    res.status(500).send('Internal server error');
  });
  }
});

routerAuth.post('/mobile/register', async (req, res) => {
  const { name, email, phone, pass } = req.body;

  if (!name || !email || !phone || !pass) {
    res.status(400).send('Missing required parameters');
    return;
  }

  try {
    const precheck = await db_request(req, res, 'SELECT * FROM users WHERE name=$1 OR email=$2 OR phone_number=$3', [name, email, phone]);

    if (precheck && precheck.length) {
      res.status(409).send('User already exists');
      return;
    }

    const hashedPassword = await bcrypt.hash(pass, 10);
    const data = await db_request(req, res, 'INSERT INTO users (name, email, phone_number, password) VALUES ($1, $2, $3, $4) RETURNING id, password', [name, email, phone, hashedPassword]);

    res.status(200).send('User created');
  } catch (error) {
    console.error(error);
          res.status(500).send('Internal server error');
        }
});


routerAuth.get('/logout', (req, res) => {
  res.clearCookie('authToken');
  res.redirect('/');
});

module.exports = {
  routerAuth
};
