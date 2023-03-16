const pgp = require('pg-promise')();
require('dotenv').config();

process.env.DATABASE_URL =
  `postgres://${process.env.DB_USER}:${process.env.DB_PASS}@${process.env.DB_HOST}:${process.env.DB_PORT}/${process.env.DB_DATABASE}`;

const db = pgp(process.env.DATABASE_URL);

function db_request(req, res, query, params) {
  return db.any(query, params)
    .then(data => {
      // console.log(data);
      return data;
    })
    .catch(error => {
      // console.log(error);
      throw error;
    });
}


module.exports = {
  db_request: db_request
};
