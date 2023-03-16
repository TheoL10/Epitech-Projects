 #!/usr/bin/env sh

docker-compose down

docker-compose up -d db

sleep 7s

docker-compose exec db psql -U postgres -d dbname -f docker-entrypoint-initdb.d/db_schema.sql

sleep 1s

docker-compose up