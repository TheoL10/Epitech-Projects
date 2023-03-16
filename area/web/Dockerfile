FROM node:lts-alpine

WORKDIR /client-web

COPY package*.json ./

RUN npm install

COPY . .

EXPOSE 8081
CMD [ "node", "index.js" ]