const jwt = require('jsonwebtoken');

// Set the secret key for signing the token
const secretKey = 'mysecretkey';

function generateAuthToken(userData, res) {
  // Create the token with the data and secret key
  const token = jwt.sign(userData, secretKey, { expiresIn: '1d' });

  // Send the token back to the client in a cookie or HTTP response
  res.setHeader('Set-Cookie', ['authToken=' + token]);
  return(token);
}

function verifyTokenAlone(token) {
  // Get the token from the client
  let authToken;
  authToken = token;

  if (!authToken) {
    return false;
  }

  try {
    // Verify the authenticity of the token and get the user data
    const userData = jwt.verify(authToken, secretKey);

    return userData;
  } catch (err) {
    return false;
  }
}

function verifyAuthToken(req, res, isTokenRequired = false) {
  // Get the token from the client
  let authToken;
  if (isTokenRequired)
    authToken = req;
  else
    authToken = req.cookies.authToken;

  if (!authToken) {
    return false;
  }

  try {
    // Verify the authenticity of the token and get the user data
    const userData = jwt.verify(authToken, secretKey);

    return userData;
  } catch (err) {
    return false;
  }
}

module.exports = {
  generateAuthToken,
  verifyAuthToken,
  verifyTokenAlone,
};
