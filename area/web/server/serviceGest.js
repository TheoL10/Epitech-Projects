const express = require('express');
const routerSG = express.Router();
const bodyParser = require('body-parser');
const bcrypt = require('bcrypt');
const auth = require('./cookies.js');
const { db_request } = require('./db.js');
const { dashboard } = require('./dashboard.js');

routerSG.use(express.urlencoded({ extended: true }));

routerSG.use(express.json());

routerSG.post('/createService', async (req, res) => {
    const authToken = auth.verifyAuthToken(req, res);
    if (!authToken) {
      res.redirect('/');
      return;
    }
    let { name, api, action, api2, reaction } = req.body;
    db_request(req, res, ("INSERT INTO services(name, action_service, action, reaction_service, reaction, user_id) SELECT $1, $2, $3, $4, $5, $6"), [name, api, action, api2, reaction, authToken.id])
    .then ( () => {
      dashboard(req, res);
    })
    .catch(error => {
      res.status(500).send('Internal server error');
    });
})

routerSG.post('/deleteService', async (req, res) => {
  const authToken = auth.verifyAuthToken(req, res);
  if (!authToken) {
    res.redirect('/');
    return;
  }
  let { id } = req.body;
  db_request(req, res, ("DELETE FROM services WHERE id=$1 AND user_id=$2"), [id, authToken.id])
  .then ( () => res.redirect('/'));
})

routerSG.post('/mobile/createService', async (req, res) => {
  console.log(req.body);
  let { name, api, action, api2, reaction, token } = req.body;
  const authToken = auth.verifyAuthToken(token, res, true);
  if (!authToken) {
    res.status(401).send('KO');
    return;
  }
  db_request(req, res, ("INSERT INTO services(name, action_service, action, reaction_service, reaction, user_id) SELECT $1, $2, $3, $4, $5, $6"), [name, api, action, api2, reaction, authToken.id])
  .then ( () => res.status(200).send('OK'));
})

routerSG.delete('/mobile/deleteService', (req, res) => {
  let { id, token } = req.body;
  const authToken = auth.verifyAuthToken(token, res, true);
  if (!authToken) {
    res.status(401).send('KO');
    return;
  }
  db_request(req, res, ("DELETE FROM services WHERE id=$1 AND user_id=$2"), [id, authToken.id])
    .then ( () => res.status(200).send('OK'));
})

routerSG.post('/mobile/getServices', (req, res) => {
  let { token } = req.body;
  const authToken = auth.verifyAuthToken(token, res, true);
  if (!authToken) {
    res.status(401).send('KO');
    return;
  }
  else {
    db_request(req, res, ("SELECT * FROM services WHERE user_id=$1"), [authToken.id])
    .then(data => {
      console.log(data);
      res.status(200).send(data);
    })
    .catch(error => {
      console.log(error);
      res.status(500).send('Internal server error');
    });
  }
})

module.exports = { routerSG };
