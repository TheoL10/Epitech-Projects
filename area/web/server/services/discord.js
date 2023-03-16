const { db_request } = require('../db.js');
const axios =  require('axios');

function getIds(jsonArray) {
  return jsonArray.map(obj => obj.id);
}

async function checkActionDiscord(service_id, user_id, actionID) {
  switch(actionID) {
    case '1':
      return checkNewGuilds(service_id, user_id);
    case '2':
      return checkProfileUpdate(service_id, user_id);
    default:
      return null;
  }
}

async function checkProfileUpdate(service_id, user_id, req = "", res = "") {
  const username = await getUserName(user_id, true);
  try {
    const data = await db_request(req, res, "SELECT * FROM oauth2 WHERE user_id='$1' AND service_id='$2'", [user_id, 1]);
    if (data.length > 0) {
      const response = await axios.get('https://discord.com/api/users/@me', {
        headers: {
          authorization: `${data[0].token_type} ${data[0].token}`
        }
      });
      const old_state = await db_request(req, res, "SELECT state FROM states WHERE service_id='$1'", [service_id]);
      if (old_state.length > 0) {
        const old = JSON.parse(old_state[0].state);
        const news = response.data;
        if (JSON.stringify(old) === JSON.stringify(news)) {
          return "NO CHANGE";
        } else {
          await db_request(req, res, "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data)]);
          return ("<@" + username + "> updated his profile !");
        }
      }
      else
        await db_request(req, res, "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data)]);
      return;
    }
    return;
  } catch (error) {
    console.log(error);
    return;
  }
};

async function getUserName(user_id, returnID = false) {
  const data = await db_request("", "", "SELECT * FROM oauth2 WHERE user_id='$1' AND service_id='$2'", [user_id, 1]);
  if (data.length > 0) {
  const response = await axios.get('https://discord.com/api/users/@me', {
    headers: {
      authorization: `${data[0].token_type} ${data[0].token}`
    }
  });
  if (returnID)
    return response.data.id;
  return response.data.username;
  }
  return "Unknown user";
}

async function checkReactionDiscord(service_id, user_id, actionID, message) {
  switch(actionID) {
    case '1':
      sendMessage(user_id, message);
      break;
    default:
      sendMessage(user_id, message);
      break;
  }
}

async function checkNewGuilds(service_id, user_id, req = "", res = "") {
  const id = await getUserName(user_id, true);
  return db_request(req, res, ("SELECT * FROM oauth2 WHERE user_id='$1' AND service_id='$2'"), [user_id, 1])
    .then(async data => {
      if (data.length > 0) {
        return axios.get('https://discord.com/api/users/@me/guilds', {
          headers: {
            authorization: `${data[0].token_type} ${data[0].token}`
          }
        })
        .then(async response => {
          const old_state = await db_request(req, res, "SELECT state FROM states WHERE service_id='$1'", [service_id]);
          if (old_state.length > 0) {
            const old = JSON.parse(old_state[0].state);
            const news =  response.data;
            if (JSON.stringify(getIds(old)) === JSON.stringify(getIds(news))) {
              return "NO CHANGE";
            }
            else {
              const result = await db_request(req, res, "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data)])
              if (getIds(old).length < getIds(news).length)
                return ("<@" + id + "> has joined a new server !");
              else
                return ("<@" + id + "> has left a server !");
            }
          }
          else
            await db_request(req, res, "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data)])
          return;
        })
        .catch(error => {
          console.log(error)
          return;
        });
      }
    })
    .catch(error => {
      console.log(error);
      return;
    });
};


async function sendMessage(user_id, messaget = "test", channelID = "300671835836776458") {
  const message = {
    content: messaget,
    tts: false, // Text-to-speech enabled
    embeds: [], // Embed objects (optional)
    // Other options...
  };
  db_request("", "", ("SELECT * FROM oauth2 WHERE user_id='$1'"), [user_id])
  .then(async data => {
      // Send the message
      axios.post(`https://discord.com/api/webhooks/1081003150275784796/AE_11PRJe_kfORfZxrF6yyHkbeBVsfEB3lfbiLFIN4M90_t9uli13vXtdwwO2npiU-rk`, message, {
        headers: {
          'Authorization': `Bearer ${data[0].token}`,
          'Content-Type': 'application/json',
        },
      })
        .then(response => {
          console.log("Sent:");
          console.log(messaget);
        })
        .catch(error => {
          console.error(error);
        });
      })
      .catch(error => {
        console.log(error);
        return;
      }
    );
}

module.exports = {
  checkNewGuilds,
  checkActionDiscord,
  checkReactionDiscord,
  sendMessage
};