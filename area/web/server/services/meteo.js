const { db_request } = require('./../db.js');
const axios =  require('axios');

async function checkMeteo(service_id, user_id, actionID) {
  switch (actionID) {
    case '1':
      return (getRainRisk(user_id));
      break;
    case '2':
      return (getTooCold(user_id));
      break;
    case '3':
      return (getTooHot(user_id));
    default:
      break;
  }
}

async function getTooCold(service_id) {
  return axios.get('https://api.meteo-concept.com/api/forecast/daily/3/?token=e26169ae6c5f7e0e0f49e12c91ba9dfd0f11e3d1ee0963f19bfadabe12199ea2&insee=54395', {
    }).then(async response => {
    const old_state = await db_request("", "", "SELECT state FROM states WHERE service_id='$1'", [service_id]);
    if (old_state.length > 0) {
      const old = JSON.parse(old_state[0].state);
      const news = response.data.forecast.datetime;
      if (JSON.stringify(old) === JSON.stringify(news)) {
        console.log("no changes");
        return "NO CHANGE";
      }
      else {
        await db_request("", "", "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data.forecast.datetime)]);
        if (response.data.forecast.tmin <= 10) {
          return "Bulletin météo AREA\nAujourd'hui il fera très froid, jusqu'à: "+response.data.forecast.tmin+"°C à "+response.data.city.name;
        }
        return "NO CHANGE";
      }
    }
    else {
      await db_request("", "", "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data.forecast.datetime)]);
      if (response.data.forecast.tmin <= 10) {
        return "Bulletin météo du AREA\nAujourd'hui il fera très froid, jusqu'à: "+response.data.forecast.tmin+"°C à "+response.data.city.name;
      }
      return "NO CHANGE";
    }
    }).catch(error => {
      console.log(error);
    }
  );
}

async function getTooHot() {
  return axios.get('https://api.meteo-concept.com/api/forecast/daily/3/?token=e26169ae6c5f7e0e0f49e12c91ba9dfd0f11e3d1ee0963f19bfadabe12199ea2&insee=54395', {
    }).then(async response => {
    const old_state = await db_request("", "", "SELECT state FROM states WHERE service_id='$1'", [service_id]);
    if (old_state.length > 0) {
      const old = JSON.parse(old_state[0].state);
      const news = response.data.forecast.datetime;
      if (JSON.stringify(old) === JSON.stringify(news)) {
        return "NO CHANGE";
      }
      else {
        await db_request("", "", "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data.forecast.datetime)]);
        if (response.data.forecast.tmax >= 25) {
          return "Bulletin météo du AREA\nAujourd'hui il fera très chaud, jusqu'à: "+response.data.forecast.tmax+"°C à "+response.data.city.name;
        }
        return "NO CHANGE";
      }
    }
    else {
      await db_request("", "", "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data.forecast.datetime)]);
      if (response.data.forecast.tmax >= 25) {
        return "Bulletin météo du "+response.data.forecast.datetime+"\nAujourd'hui il fera très chaud, jusqu'à: "+response.data.forecast.tmax+"°C à "+response.data.city.name;
      }
      return "NO CHANGE";
    }
    }).catch(error => {
      console.log(error);
    }
  );
}

async function getRainRisk(service_id) {
  return axios.get('https://api.meteo-concept.com/api/forecast/daily/3/?token=e26169ae6c5f7e0e0f49e12c91ba9dfd0f11e3d1ee0963f19bfadabe12199ea2&insee=54395', {
    }).then(async response => {
    const old_state = await db_request("", "", "SELECT state FROM states WHERE service_id='$1'", [service_id]);
    if (old_state.length > 0) {
      const old = JSON.parse(old_state[0].state);
      const news = response.data.forecast.datetime;
      if (JSON.stringify(old) === JSON.stringify(news)) {
        return "NO CHANGE";
      }
      else {
        await db_request("", "", "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data.forecast.datetime)]);
        if (response.data.forecast.probarain >= 0) {
          return "Bulletin météo du "+response.data.forecast.datetime+"\nAujourd'hui il y a "+response.data.forecast.probarain+"% de chance de pleuvoir à "+response.data.city.name;
        }
        return "NO CHANGE";
      }
    }
    else {
      await db_request("", "", "INSERT INTO states (service_id, state) VALUES ('$1', $2) ON CONFLICT (service_id) DO UPDATE SET state = EXCLUDED.state;", [service_id, JSON.stringify(response.data.forecast.datetime)]);
        if (response.data.forecast.probarain >= 0) {
          return "Bulletin météo du "+response.data.forecast.datetime+"\nAujourd'hui il y a "+response.data.forecast.probarain+"% de chance de pleuvoir à "+response.data.city.name;
        }
      return "NO CHANGE";
    }
    }).catch(error => {
      console.log(error);
    }
  );
}

module.exports = {
  checkMeteo,
};