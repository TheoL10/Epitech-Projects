const express = require('express');
const routerService = express.Router();
const { db_request } = require('./db.js');
const auth = require('./cookies.js');
const querystring = require('querystring');
const axios =  require('axios');

const CLIENT_ID = '1080553353685254176';
const CLIENT_SECRET = 'mIKIUngRk1C6yjvWfOR8Fp5UIflRyMdi';
const REDIRECT_URI = 'http://localhost:8081/auth/discord/callback';

// Route to initiate the OAuth2 flow
routerService.get('/auth/discord', async (req, res) => {
  const state = Math.random().toString(36).substring(2);
  req.session.state = state;
  if (req.query.token) {
    await mobileAuth(req, res);
    console.log('mobile auth');
    return;
  }
  // Generate a random state value and store it in the session

  // Redirect the user to Discord's authorization page
  const queryParams = querystring.stringify({
    response_type: 'code',
    client_id: CLIENT_ID,
    scope: 'identify guilds gdm.join messages.read',
    redirect_uri: REDIRECT_URI,
    state: state,
  });
  res.redirect(`https://discord.com/api/oauth2/authorize?client_id=1080553353685254176&redirect_uri=http%3A%2F%2Flocalhost%3A8081%2Fauth%2Fdiscord%2Fcallback&response_type=code&state=${state}&scope=identify%20guilds%20gdm.join%20messages.read`);
});

async function mobileAuth(req, res) {
  // Generate a random state value and store it in the session
  console.log(req.session.state);
  const token = req.query.token;
  console.log(req.query.token);
  if (!auth.verifyTokenAlone(req.query.token)) {
    res.status(401).send('Invalid token');
    return;
  }
  const resp = auth.verifyTokenAlone(req.query.token);
  auth.generateAuthToken({ username: resp.username, id: resp.id }, res);

  // Redirect the user to Discord's authorization page
  const queryParams = querystring.stringify({
    response_type: 'code',
    client_id: CLIENT_ID,
    scope: 'identify guilds gdm.join messages.read',
    redirect_uri: REDIRECT_URI,
    state: req.session.state,
  });
  res.redirect(`https://discord.com/api/oauth2/authorize?client_id=1080553353685254176&redirect_uri=http%3A%2F%2Flocalhost%3A8081%2Fauth%2Fdiscord%2Fcallback&response_type=code&state=${req.session.state}&scope=identify%20guilds%20gdm.join%20messages.read`);
};

// Route to handle the callback from Discord's authorization page
routerService.get('/auth/discord/callback', async (req, res) => {
  console.log(await req.session.state);
  // Verify that the state value returned from Discord matches the one stored in the session
  if (req.query.state !== req.session.state) {
    // res.status(401).send('Invalid state value');
    res.redirect('/');
    return;
  }

  try {
    // Exchange the authorization code returned from Discord for an access token
    const response = await axios.post('https://discord.com/api/oauth2/token', querystring.stringify({
      grant_type: 'authorization_code',
      client_id: CLIENT_ID,
      client_secret: CLIENT_SECRET,
      code: req.query.code,
      redirect_uri: REDIRECT_URI,
    }), {
      headers: {
        'Content-Type': 'application/x-www-form-urlencoded'
      }
    });
    // Use the access token to make a request to the Discord API
    const userResponse = await axios.get('https://discord.com/api/users/@me', {
      headers: {
        authorization: `${response.data.token_type} ${response.data.access_token}`
      }
    });
    console.log(req.query);
    console.log("userResponse: ");
    console.log(userResponse);
    let token = "none";
    if (req.query.token) {
      token = req.query.token;
      if (!auth.verifyAuthToken(req, res)) {
        res.status(401).send('Invalid token');
        return;
      }
    }
    const authToken = auth.verifyAuthToken(req, res);
    if (!authToken) {
      res.redirect('/');
      return;
    }
    db_request(req, res, ("SELECT * FROM oauth2 WHERE user_id=$1 AND service_id='$2'"), [(token === "none" ? authToken.id : token), 1])
      .then(data => {
        if (data.length > 0) {
          db_request(req, res, ("UPDATE oauth2 SET token=$1, token_type=$2 WHERE user_id=$3 AND service_id='$4'"), [response.data.access_token, response.data.token_type, (token === "none" ? authToken.id : token), 1])
          .then(data => {
            res.redirect('/');
            return;
          })
        }
        else {
          db_request(req, res, ("INSERT INTO oauth2(user_id, token, service_id, token_type, api_uid) VALUES ($1, $2, $3, $4, $5)"), [(token === "none" ? authToken.id : token), response.data.access_token, 1, response.data.token_type, userResponse.data.id])
            .then(data => {
              res.redirect('/');
              return;
            })
            .catch(error => {
              console.log(error);
              res.status(500).send('Internal server error');
              return;
            });
        }})
      .catch(error => {
        console.log(error);
        res.status(500).send('Internal server error');
        return;
    });
  } catch (err) {
    console.error(err);
    res.status(500).send('An error occurred');
    return;
  }
});

module.exports = { routerService };