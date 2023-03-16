const emailjs = require('@emailjs/nodejs');
const { db_request } = require('./../db.js');
const axios =  require('axios');

async function getUserMail(user_id, returnID = false) {
    const data = await db_request("", "", "SELECT * FROM users WHERE id='$1'", [user_id, 1]);
    if (data.length > 0) {
        return data[0].email;
    }
    return "Unknown user";
}


async function sendEmail(service_id, user_id, actionID, message) {
  if (message.lastIndexOf('>') != -1) {
    message = message.substr(message.lastIndexOf('>') + 1);
    message = "Your discord account "
  }
  const templateParams = {
    notes: message,
    email: await getUserMail(user_id),
    subject: 'AREA Notification',
  };

  emailjs.send('service_w9xsj9a', 'template_4yb0ha6', templateParams, {
    publicKey: 'gzT84lKdIOKA6HLDM',
    privateKey: 'M-bMrzppPfW29ucdIzIo_'
    })
    .catch((error) => {
      console.log(error.text);
    });
};

module.exports = {
  sendEmail
};