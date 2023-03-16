const auth = require('./cookies.js');
const { db_request } = require('./db.js');
const { checkServices } = require('./service');

function dashboard(req, res) {
    const authToken = auth.verifyAuthToken(req, res);
    if (!authToken) {
      res.redirect('/');
      return;
    }
    console.log("dashboard");
    try {
      const userData = auth.verifyAuthToken(req, res);
      db_request(req, res, "SELECT id FROM users WHERE name=$1;", [userData.username])
        .then(async result => {
          if (Array.isArray(result) && result.length) {
            db_request(req, res, "SELECT * FROM services WHERE user_id=$1", [result[0].id])
              .then(async resultS => {
                if (Array.isArray(resultS) && resultS.length) {
                  res.render('dashboard', { services: resultS, name: userData.username });
                  return;
                }
                res.render('dashboard', { name: userData.username });
              })
              .catch(error => {
                console.log(error);
                res.render('dashboard', { name: userData.username });
              });
          } else {
            res.render('login');
          }
        }).catch(error => {
          console.log(error);
          res.render('login');
        });
    } catch (err) {
      console.log("error");
      console.log(err);
      res.redirect('/');
    }
  }

module.exports = {
  dashboard
};