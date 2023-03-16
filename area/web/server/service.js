const { db_request } = require('./db.js');
const { checkActionDiscord, checkReactionDiscord } = require('./services/discord.js');
const { checkMeteo } = require('./services/meteo.js');
const { sendEmail } = require('./services/mail.js');

async function checkServices() {
  console.log("checking for services");
  db_request("", "", "SELECT * FROM services;")
  .then(async result => {
    if (Array.isArray(result) && result.length) {
      for (let index in result) {
        console.log(result[index]);
        let action = false;
        if (result[index].action_service == "Discord") {
          action = await checkActionDiscord(result[index].id, result[index].user_id, result[index].action);
        }
        else if (result[index].action_service == "Meteo") {
          action = await checkMeteo(result[index].id, result[index].user_id, result[index].action);
        }
        else if (result[index].action_service == "Meteo") {
        }
        if (action && action != "NO CHANGE") {
          if (result[index].reaction_service == "Discord") {
            checkReactionDiscord(result[index].id, result[index].user_id, result[index].reaction, action);
          }
          if (result[index].reaction_service == "EMail") {
            sendEmail(result[index].id, result[index].user_id, result[index].reaction, action);
          }
        }
      }
    }
  });
  return null;
}


module.exports = {
  checkServices
};