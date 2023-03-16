// routes.js

const express = require('express');
const router = express.Router();
const { dashboard } = require('./dashboard.js');
const { routerAuth } = require('./auth.js');
const { routerSG } = require('./serviceGest.js');
const { routerService } = require('./apiAuth.js');
const { db_request } = require('./db.js');

require('./service');

router.use(express.urlencoded({ extended: false }));

router.get("/", routerAuth);

router.post("/login", routerAuth);

router.post("/mobile/login", routerAuth);

router.get("/dashboard", (req, res) => { dashboard(req, res); });

router.get("/register", (req, res) =>  { res.render('register'); });

router.post("/register", routerAuth);

router.post("/mobile/register", routerAuth);

router.get('/logout', routerAuth);

router.post('/createService', routerSG);

router.post('/deleteService', routerSG);

router.post('/mobile/createService', routerSG);

router.get("/auth", (req, res) => { res.render('auth'); });

router.get("/register", (req, res) =>  { res.render('register');});

router.delete('/mobile/deleteService', routerSG);

router.post('/mobile/getServices', routerSG);

router.get('/auth/discord/callback', routerService);

router.get('/auth/discord', routerService);

router.get('/mobile/auth/discord', routerService);

router.get('/guilds', routerService);

router.get('/test', (req, res) => { res.status(200).send("OK"); });
module.exports = router;