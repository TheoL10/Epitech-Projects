#include "../hpp/SceneGame.hpp"
#include "../hpp/Deflagration.hpp"
#include <fstream>

SceneGame::SceneGame(std::map<std::string, Model>& models, std::map<std::string, ModelAnimation*>& anims, std::map<std::string, Texture2D>& sprites, std::map<std::string, Music>& musics, Engine* engine)
{
    _models = models;
    _anims = anims;
    _engine = engine;
    _sprites = sprites;
    _musics = musics;
}

SceneGame::~SceneGame()
{
}

void SceneGame::setSave() {
    if (_isVersus)
        return;
    if (_engine->getLevelUnlock() == 4) {
        _engine->setSaveOnce(1);
        return;
    }
    int curr = 1;
    std::string line;
    std::string newText;
    std::ifstream myfile (SAVE_PATH"save.txt");

    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            int lvl = std::atoi(line.c_str());
            if (_engine->getCurrentSave() != curr && curr == 1)
                newText += std::to_string(lvl);
            else if (curr == 1)
                newText += std::to_string(_engine->getLevelUnlock());
            if (_engine->getCurrentSave() != curr && curr == 2)
                newText += std::to_string(lvl);
            else if (curr == 2)
                newText += std::to_string(_engine->getLevelUnlock());
            if (_engine->getCurrentSave() != curr && curr == 3)
                newText += std::to_string(lvl);
            else if (curr == 3)
                newText += std::to_string(_engine->getLevelUnlock());
            if (curr >= 3)
                break;
            newText = newText + "\n";
            curr++;
        }
        myfile.close();
    }
    std::ofstream ofs(SAVE_PATH"save.txt", std::ofstream::trunc);

    ofs << newText;

    ofs.close();
    _engine->setSaveOnce(1);
    _engine->setLvl(_idMap + 2);
}

void SceneGame::setMap(int idMap, std::vector<int> listSkins)
{
    Process mapGen (_models, _anims);
    std::vector<std::unique_ptr<Entity>>& map = mapGen.getMap(idMap, listSkins);
    if (idMap == -1)
        idMap = 1;
    _idMap = idMap;
    if (_idMap == 0)
        raylib.playMusicStream(_musics["lvl1"]);
    if (_idMap == 1)
        raylib.playMusicStream(_musics["lvl2"]);
    if (_idMap == 2)
        raylib.playMusicStream(_musics["lvl3"]);
    for (int i = 0; i < map.size(); i++)
        _entities.emplace_back(std::move(map[i]));
}

int SceneGame::countPlayerRemaining(void)
{
    int count = 4;
    for (int i = 0; i < 4; i++)
        if (_isDeadList[i])
            count--;
    return count;
}

bool SceneGame::isAllIADead(void)
{
    int nbIA = 3 - _nbControlers;
    int count = 0;
    for (int i = _nbControlers + 1; i < 4; i++)
        if (_isDeadList[i])
            count++;
    return count == nbIA;
}

int SceneGame::findLastPlayer(void)
{
    int last = 0;
    for (int i = 0; i < _isDeadList.size(); i++)
        if (!_isDeadList[i])
            last = i;
    return last;
}

bool SceneGame::isAllPlayerDead(void)
{
    if (_nbControlers == 0)
        return _isDeadList[0];
    int count = 0;
    for (int i = 0; i < _nbControlers; i++)
        if (_isDeadList[i])
            count++;
    if (_isDeadList[3])
        count++;
    return count == (_nbControlers + 1);
}

void SceneGame::draw()
{
    raylib.beginMode3D(_engine->getCamera());
        for (int i = 0; i < _entities.size(); i++) _entities[i]->draw();
    raylib.endMode3D();
    raylib.drawTextureEx(_sprites["hudCard1"], {1600, 50}, 0, 1.2f, RAYWHITE);
    raylib.drawTextureEx(_sprites["hudCard2"], {20, 50}, 0, 1.2f, RAYWHITE);
    raylib.drawTextureEx(_sprites["hudCard3"], {20, 900}, 0, 1.2f, RAYWHITE);
    raylib.drawTextureEx(_sprites["hudCard4"], {1600, 900}, 0, 1.2f, RAYWHITE);
    int n = 0;
    for (int i = 0; i < _entities.size(); i++) {
        if (_entities[i].get()->getName() == "player0") {
            for (int j = 1; j < _entities[i].get()->getMaxBomb(); j++) raylib.drawTextureEx(_sprites["bombUpIcon"], {1630.0f + ((j - 1) * 15), 150}, 0, 0.6f, RAYWHITE);
            for (int j = 1; j < _entities[i].get()->getBombRange(); j++) raylib.drawTextureEx(_sprites["fireUpIcon"], {1700.0f + ((j - 1) * 15), 155}, 0, 0.6f, RAYWHITE);
            for (float j = 0.1f; j < _entities[i].get()->getSpeed(); j += 0.03f, n++) raylib.drawTextureEx(_sprites["skateIcon"], {1800.0f + (n * 15), 150}, 0, 0.6f, RAYWHITE);
        }
        else if (_entities[i].get()->getName() == "player1") {
            for (int j = 1; j < _entities[i].get()->getMaxBomb(); j++) raylib.drawTextureEx(_sprites["bombUpIcon"], {50.0f + ((j - 1) * 15), 150}, 0, 0.6f, RAYWHITE);
            for (int j = 1; j < _entities[i].get()->getBombRange(); j++) raylib.drawTextureEx(_sprites["fireUpIcon"], {120.0f + ((j - 1) * 15), 155}, 0, 0.6f, RAYWHITE);
            for (float j = 0.1f; j < _entities[i].get()->getSpeed(); j += 0.03f, n++) raylib.drawTextureEx(_sprites["skateIcon"], {220.0f + (n * 15), 150}, 0, 0.6f, RAYWHITE);
        }
        else if (_entities[i].get()->getName() == "player3") {
            for (int j = 1; j < _entities[i].get()->getMaxBomb(); j++) raylib.drawTextureEx(_sprites["bombUpIcon"], {50.0f + ((j - 1) * 15), 1000}, 0, 0.6f, RAYWHITE);
            for (int j = 1; j < _entities[i].get()->getBombRange(); j++) raylib.drawTextureEx(_sprites["fireUpIcon"], {120.0f + ((j - 1) * 15), 1005}, 0, 0.6f, RAYWHITE);
            for (float j = 0.1f; j < _entities[i].get()->getSpeed(); j += 0.03f, n++) raylib.drawTextureEx(_sprites["skateIcon"], {220.0f + (n * 15), 1000}, 0, 0.6f, RAYWHITE);
        }
        else if (_entities[i].get()->getName() == "player2") {
            for (int j = 1; j < _entities[i].get()->getMaxBomb(); j++) raylib.drawTextureEx(_sprites["bombUpIcon"], {1630.0f + ((j - 1) * 15), 1000}, 0, 0.6f, RAYWHITE);
            for (int j = 1; j < _entities[i].get()->getBombRange(); j++) raylib.drawTextureEx(_sprites["fireUpIcon"], {1700.0f + ((j - 1) * 15), 1005}, 0, 0.6f, RAYWHITE);
            for (float j = 0.1f; j < _entities[i].get()->getSpeed(); j += 0.03f, n++) raylib.drawTextureEx(_sprites["skateIcon"], {1800.0f + (n * 15), 1000}, 0, 0.6f, RAYWHITE);
        }
    }
    bool resetGame = false;
    if (isAllPlayerDead()) {
        float height = raylib.getMonitorHeight(raylib.getCurrentMonitor());
        float width = raylib.getMonitorWidth(raylib.getCurrentMonitor());
        int move = rand();
        float moving;
        float moving2;
        if (move % 2 == 0) {
            moving = -2.0f;
            moving2 = 2.0f;
        }
        else {
            moving = 2.0f;
            moving2 = -2.0f;
        }
        raylib.drawTextureEx(_sprites["endbg"], {0, 0}, 0, 1.2f, RAYWHITE);
        raylib.drawText("Défaite", 700, 500, 120, BLACK);
        if (this->_oneTime == false) {
            this->_timeEnd = raylib.getTime() + 3.0f;
            this->_oneTime = true;
        }
        if (raylib.getTime() > this->_timeEnd) {
            resetGame = true;
            _engine->setScene("menu");
            _engine->setCamera(2);
        }
    }
    if ((_nbControlers > 0 && countPlayerRemaining() == 1) || (_nbControlers == 0 && (isAllIADead()))) {
        if (_engine->getSaveOnce() == 0) {
            _engine->setLevelUnlock(_engine->getLevelUnlock() + 1, _engine->getCurrentSave());
            if (!_isVersus)
                setSave();
        }
        float height = raylib.getMonitorHeight(raylib.getCurrentMonitor());
        float width = raylib.getMonitorWidth(raylib.getCurrentMonitor());
        int move = rand();
        float moving;
        float moving2;
        if (move % 2 == 0) {
            moving = -2.0f;
            moving2 = 2.0f;
        }
        else {
            moving = 2.0f;
            moving2 = -2.0f;
        }
        raylib.drawTextureEx(_sprites["endbg"], {0, 0}, 0, 1.2f, RAYWHITE);
        std::string a = "";
        if (_nbControlers > 0)
            a = std::to_string(findLastPlayer() + 2);
        if (_nbControlers > 0 && findLastPlayer() == 3)
            a = "1";
        if (_nbControlers == 0)
            a = "1";
        raylib.drawText(("Joueur " + a + " à gagné").c_str(), 350, 500, 120, BLACK);
        if (this->_oneTime == false) {
            _engine->playSound("victoire");
            this->_timeEnd = raylib.getTime() + 3.0f;
            this->_oneTime = true;
        }
        if (raylib.getTime() > this->_timeEnd) {
            resetGame = true;
            _engine->setSaveOnce(0);
            _engine->setScene("menu");
            _engine->setCamera(2);
        }
    }
    if (resetGame)
        _engine->resetGame();
}

bool SceneGame::checkCollision(Vector3 pos1, float size1, Vector3 pos2, float size2, bool isBomb)
{
    bool colision = false;

    if (isBomb == false && pos1.x + size1 >= pos2.x && pos1.x <= pos2.x + size2 && pos1.z + size1 >= pos2.z && pos1.z <= pos2.z + size2) {
        colision = true;
    }
    return colision;
}

void SceneGame::movePlayer(std::unique_ptr<Entity>& player, Vector2 movement)
{
    bool isMoovable = true;
    Vector3 newPos = {player->getPos().x + (movement.x / (raylib.getFPS() / 60.0f)), 0, player->getPos().z + (movement.y / (raylib.getFPS() / 60.0f))};
    Vector3 invPos = {player->getPos().x - (movement.x / (raylib.getFPS() / 60.0f)), 0, player->getPos().z - (movement.y / (raylib.getFPS() / 60.0f))};
    for (int i = 0; i < _entities.size(); i++) {
        if ((_entities[i]->getName().substr(0, _entities[i]->getName().find(":")) == "wall" ||_entities[i]->getName().substr(0, _entities[i]->getName().find(":")) == "box" && _entities[i]->getIsRunning() == true) 
           && checkCollision(newPos, 0.9, _entities[i]->getPos(), 0.9, false))
            isMoovable = false;
    }

    if (isMoovable) {
        player->setX(newPos.x);
        player->setZ(newPos.z);
    }
}

void SceneGame::IABomb2(std::unique_ptr<Entity>& ia, Vector2 newPos, Vector2 newPos2, Vector2 newPos3)
{
    std::vector<int> coordBomb = ia->getCoordBomb();
    Vector3 pos_player = ia->getPos();
    float i = 0;
    float y = 0;
    for (float x = pos_player.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
    i--;
    for (float z = pos_player.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
    y--;
    pos_player.x = (i * 1.6f) + 1.6;
    pos_player.z = (y * 1.6f) + 1.6;
    int coord_p_x = rMan(pos_player.x / 1.6f, 1);
    int coord_p_z = rMan(pos_player.z / 1.6f, 1);
    if (ia->getOneTime3() == 0) {
        ia->setTimeEnd(ia->getRayLib().getTime() + 2);
        ia->setOneTime3(1);
    }
    if (ia->getRayLib().getTime() < ia->getTimeEnd() - 1) {
        movePlayer(ia, newPos2);
        ia->setRotation(3);
        ia->setModelFrame();
        movePlayer(ia, newPos);
    } else if (ia->getRayLib().getTime() > ia->getTimeEnd() - 1 && (coord_p_x == coordBomb[0] || coord_p_z == coordBomb[1]))
        movePlayer(ia, newPos3);
}

void SceneGame::IABomb1(std::unique_ptr<Entity>& ia, int oneTime)
{
    Vector3 posbomb = ia->getPos();
    float i = 0;
    float y = 0;
    for (float x = posbomb.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
    i--;
    for (float z = posbomb.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
    y--;
    posbomb.x = (i * 1.6f) + 1.6;
    posbomb.z = (y * 1.6f) + 1.6;
    int coord_bomb_x = rMan(posbomb.x / 1.6f, 1);
    int coord_bomb_z = rMan(posbomb.z / 1.6f, 1);
    std::vector<int> coordos_bomb = {0, 0};
    coordos_bomb[0] = coord_bomb_x;
    coordos_bomb[1] = coord_bomb_z;
    _entities.emplace_back(new Bomb(_models["bomb"], posbomb.x, posbomb.z, 0.9, "bomb", ia->getBombRange(), 2, ia->getName()));
    ia->setCoordBomb(coordos_bomb);
    ia->setOneTime(oneTime);
}

void SceneGame::updateIA3(std::unique_ptr<Entity>& ia, int id)
{
    Vector3 posPlayer = ia->getPos();
    float i = 0;
    float y = 0;
    for (float x = posPlayer.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
    i--;
    for (float z = posPlayer.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
    y--;
    int coord_x = rMan(((i * 1.6f) + 1.6) / 1.6f, 1);
    int coord_z = rMan(((y * 1.6f) + 1.6) / 1.6f, 1);
    for (int i = 0; i < _entities.size(); i++) {
        if (_entities[i]->getName() == "bonus") {
            if (coord_x == _entities[i]->getCoordX() && coord_z == _entities[i]->getCoordZ()) {
                _entities[i]->setIsRunning(false);
                _entities[i]->setName("broken");
                int bonus_type = _entities[i].get()->getType();
                _engine->playSound("bonus");
                if (bonus_type == 1 && ia.get()->getSpeed() < 0.19f)
                    ia.get()->setSpeed(ia.get()->getSpeed() + 0.03f);
                if (bonus_type == 2 && ia.get()->getMaxBomb() <= 3) {
                    ia.get()->setMaxBomb(ia.get()->getMaxBomb() + 1);
                    ia->addBombStock();
                }
                if (bonus_type == 3 && ia.get()->getBombRange() <= 5)
                    ia.get()->setBombRange(ia.get()->getBombRange() + 1);
            }
        }
    }
    if (ia->getIsDead() == true) {
        if (id == 0 && _isDeadList[1 - _isVersus] == false) {
            _engine->playSound("death");
            _isDeadList[1 - _isVersus] = true;
        }
        if (id == 1 && _isDeadList[2 - _isVersus] == false) {
            _engine->playSound("death");
            _isDeadList[2 - _isVersus] = true;
        }
        if (id == 2 && _isDeadList[3 - _isVersus] == false) {
            _engine->playSound("death");
            _isDeadList[3 - _isVersus] = true;
        }
        return;
    }
    if (ia->getIsRunning() == false)
        return;
    if (ia->gethasFocus() == 0) {
        Vector3 pos_player0;
        Vector3 pos_player1;
        Vector3 pos_player2;
        Vector3 pos_player3;
        for (int i = 0; i < _entities.size(); i++) {
            if (_entities[i]->getName() == "player0")
                pos_player0 = _entities[i]->getPos();
            if (_entities[i]->getName() == "player1")
                pos_player1 = _entities[i]->getPos();
            if (_entities[i]->getName() == "player2")
                pos_player2 = _entities[i]->getPos();
            if (_entities[i]->getName() == "player3")
                pos_player3 = _entities[i]->getPos();
        }
        //////////////coord//////////////
        //coord_player0
        int i = 0;
        int y = 0;
        for (float x = pos_player0.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
        i--;
        for (float z = pos_player0.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
        y--;
        int coord_player0_x = rMan((rMan(i * 1.6f + 1.6, 1)) / 1.6f, 1);
        int coord_player0_z = rMan((rMan(y * 1.6f + 1.6, 1)) / 1.6f, 1);

        //coord_player1
        i = 0;
        y = 0;
        for (float x = pos_player1.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
        i--;
        for (float z = pos_player1.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
        y--;
        int coord_player1_x = rMan((rMan(i * 1.6f + 1.6f, 1)) / 1.6f, 1);
        int coord_player1_z = rMan((rMan(y * 1.6f + 1.6f, 1)) / 1.6f, 1);

        //coord_player2
        i = 0;
        y = 0;
        for (float x = pos_player2.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
        i--;
        for (float z = pos_player2.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
        y--;
        int coord_player2_x = rMan(rMan(i * 1.6f + 1.6f, 1) / 1.6f, 1);
        int coord_player2_z = rMan(rMan(y * 1.6f + 1.6f, 1) / 1.6f, 1);

        //coord_player3
        i = 0;
        y = 0;
        for (float x = pos_player3.x; x >= 0 ; i++) { x -= 1.6f; };
        i--;
        for (float z = pos_player3.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
        y--;
        int coord_player3_x = rMan((rMan(i * 1.6f + 1.6f, 1)) / 1.6f, 1);
        int coord_player3_z = rMan((rMan(y * 1.6f + 1.6f, 1)) / 1.6f, 1);
        //////////////coord//////////////

        ///////////closest_player_to_p3//////////////
        std::vector<int> coordPlayers_x = {coord_player1_x, coord_player2_x, coord_player3_x};
        std::vector<int> coordPlayers_z = {coord_player1_z, coord_player2_z, coord_player3_z};

        std::vector<int> coordPlayersFace_x = {coord_player2_x, coord_player1_x, coord_player1_x};
        std::vector<int> coordPlayersFace_z = {coord_player2_z, coord_player1_z, coord_player1_z};

        std::vector<int> coordPlayersFace2_x = {coord_player3_x, coord_player3_x, coord_player2_x};
        std::vector<int> coordPlayersFace2_z = {coord_player3_z, coord_player3_z, coord_player2_z};

        int case_between_p3_p0 = abs(coordPlayers_x[id] - coord_player0_x) + abs(coordPlayers_z[id] - coord_player0_z);
        int case_between_p3_p1 = abs(coordPlayers_x[id] - coordPlayersFace_x[id]) + abs(coordPlayers_z[id] - coordPlayersFace_z[id]);
        int case_between_p3_p2 = abs(coordPlayers_x[id] - coordPlayersFace2_x[id]) + abs(coordPlayers_z[id] - coordPlayersFace2_z[id]);
    
        ia->setMyCoordx(coordPlayers_x[id]);
        ia->setMyCoordz(coordPlayers_z[id]);
        if (case_between_p3_p0 <= case_between_p3_p1 && case_between_p3_p0 <= case_between_p3_p2) {
            ia->setClosestPlayerx(coord_player0_x);
            ia->setClosestPlayerz(coord_player0_z);
        }
        else if (case_between_p3_p1 <= case_between_p3_p0 && case_between_p3_p1 <= case_between_p3_p2) {
            ia->setClosestPlayerx(coord_player1_x);
            ia->setClosestPlayerz(coord_player1_z);
        }
        else if (case_between_p3_p2 <= case_between_p3_p0 && case_between_p3_p2 <= case_between_p3_p1) {
            ia->setClosestPlayerx(coord_player2_x);
            ia->setClosestPlayerz(coord_player2_z);
        }
        ia->sethasFocus(1);
        ///////////closest_player_to_p3//////////////
    } else if (ia->gethasFocus() == 1) {
        std::vector<int> myCoord = ia->getMyCoord();
        std::vector<int> closest_player = ia->getClosestPlayer();
        std::string direction;

        if (myCoord[0] < closest_player[0] && ia->getOneTime() < 2) {
            Vector2 newPos = {0.1f, 0.0f}; // move down
            ia->setRotation(4);
            ia->setModelFrame();
            direction = "down";
            movePlayer(ia, newPos);
        }
        if (myCoord[0] > closest_player[0] && ia->getOneTime() < 2) {
            Vector2 newPos = {-0.1f, 0.0f}; // move up
            ia->setRotation(3);
            ia->setModelFrame();
            direction = "up";
            movePlayer(ia, newPos);
        }
        if (myCoord[1] < closest_player[1] && ia->getOneTime() < 2) {
            Vector2 newPos = {0.0f, 0.1f}; // move left
            ia->setRotation(2);
            ia->setModelFrame();
            direction = "left";
            movePlayer(ia, newPos);
        }
        if (myCoord[1] > closest_player[1] && ia->getOneTime() < 2) {
            Vector2 newPos = {0.0f, -0.1f}; // move right
            ia->setRotation(1);
            ia->setModelFrame();
            direction = "right";
            movePlayer(ia, newPos);
        }

        // BOMB SI SUR PERSO
        if (myCoord[0] == closest_player[0] && myCoord[1] == closest_player[1] && ia->getOneTime2() == 0) {
            Vector3 posbomb = ia->getPos();
            float i = 0;
            float y = 0;
            for (float x = posbomb.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
            i--;
            for (float z = posbomb.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
            y--;
            _entities.emplace_back(new Bomb(_models["bomb"], (i * 1.6f) + 1.6, (y * 1.6f) + 1.6, 0.9, "bomb", ia->getBombRange(), 2, ia->getName()));
            ia->setTimeEnd(ia->getRayLib().getTime() + 1);
            ia->setOneTime2(1);
        }
        if (ia->getChecker() == 0) {
            ia->setWasCoord(ia->getMyCoord());
            ia->setChecker(1);
        }
        if (ia->getChecker() < 85 && ia->getChecker() > 0)
            ia->setChecker(ia->getChecker() + 1);
        if (((ia->getChecker() ==  (50 + (rand() % 50)) || ia->getChecker() == 100) || ia->getChecker() == 100) && ia->getOneTime() < 2) {
            std::vector<int> wasCoord = ia->getWasCoord();

            if (myCoord[0] == wasCoord[0] && myCoord[1] == wasCoord[1])
                ia->setOneTime(2);
            else
                ia->setChecker(0);
        }
        if (ia->getOneTime() == 2) {
            //get direction drop a bomb and go opposite + wait for explosion
            if (direction == "down") {
                IABomb1(ia, 3);
            } else if (direction == "up") {
                IABomb1(ia, 4);
            } else if (direction == "left") {
                IABomb1(ia, 5);
            } else if (direction == "right") {
                IABomb1(ia, 6);
            }
        }
        if (ia->getOneTime() == 3)
            IABomb2(ia, {-0.1f, 0.0f}, {0.0f, 0.1f}, {0.0f, -0.1f});
        if (ia->getOneTime() == 4)
            IABomb2(ia, {0.1f, 0.0f}, {0.0f, -0.1f}, {0.0f, 0.1f});
        if (ia->getOneTime() == 5)
            IABomb2(ia, {0.0f, -0.1f}, {0.1f, 0.0f}, {-0.1f, 0.0f});
        if (ia->getOneTime() == 6)
            IABomb2(ia, {0.0f, 0.1f}, {-0.1f, 0.0f}, {0.1f, 0.0f});
        if (ia->getOneTime() == 0 && ia->getOneTime2()  == 0) {
            ia->setTimeEnd(ia->getRayLib().getTime() + 1.5);
            ia->setOneTime(1);
        }
        if (ia->getRayLib().getTime() > ia->getTimeEnd() && ia->getOneTime() > 2) {
            ia->sethasFocus(0);
            ia->setOneTime(0);
            ia->setOneTime2(0);
            ia->setOneTime3(0);
            ia->setChecker(0);
        }
        if (ia->getRayLib().getTime() > ia->getTimeEnd() && ia->getOneTime() < 2) {
            ia->sethasFocus(0);
            ia->setOneTime(0);
            ia->setOneTime2(0);
            ia->setChecker(0);
        }
    }
}

bool SceneGame::valideInputs(KeyboardKey key, GamepadButton pad, int idControler, std::string state)
{
    bool joystick = false;
    if (pad == GAMEPAD_BUTTON_LEFT_FACE_RIGHT && raylib.getGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) > 0.25)
        joystick = true;
    if (pad == GAMEPAD_BUTTON_LEFT_FACE_LEFT && raylib.getGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X) < -0.25)
        joystick = true;
    if (pad == GAMEPAD_BUTTON_LEFT_FACE_UP && raylib.getGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) < -0.25)
        joystick = true;
    if (pad == GAMEPAD_BUTTON_LEFT_FACE_DOWN && raylib.getGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y) > 0.25)
        joystick = true;

    if (state == "down") {
        if (_nbControlers == 0)
            return (raylib.isKeyDown(key) || (raylib.isGamepadButtonDown(idControler, pad) || joystick));
        if (_nbControlers > 0 && idControler != 3)
            return (raylib.isGamepadButtonDown(idControler, pad) || joystick);
        if (_nbControlers > 0 && idControler == 3)
            return (raylib.isKeyDown(key));
    }
    if (state == "pressed") {
        if (_nbControlers == 0)
            return (raylib.isKeyPressed(key) || (raylib.isGamepadButtonPressed(idControler, pad) || joystick));
        if (_nbControlers > 0 && idControler != 3)
            return (raylib.isGamepadButtonPressed(idControler, pad) || joystick);
        if (_nbControlers > 0 && idControler == 3)
            return (raylib.isKeyPressed(key));
    }
    return false;
}

void SceneGame::updatePlayer(std::unique_ptr<Entity>& player, int idControler)
{
    Vector3 posPlayer = player->getPos();
    float i = 0;
    float y = 0;
    for (float x = posPlayer.x - 0.8; x >= 0 ; i++) { x -= 1.6f; };
    i--;
    for (float z = posPlayer.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
    y--;
    int coord_x = rMan(((i * 1.6f) + 1.6) / 1.6f, 1);
    int coord_z = rMan(((y * 1.6f) + 1.6) / 1.6f, 1);
    for (int i = 0; i < _entities.size(); i++) {
        if (_entities[i]->getName() == "bonus") {
            if (coord_x == _entities[i]->getCoordX() && coord_z == _entities[i]->getCoordZ()) {
                _entities[i]->setIsRunning(false);
                _entities[i]->setName("broken");
                int bonus_type = _entities[i].get()->getType();
                _engine->playSound("bonus");
                if (bonus_type == 1 && player.get()->getSpeed() < 0.19f)
                    player.get()->setSpeed(player.get()->getSpeed() + 0.03f);
                if (bonus_type == 2 && player.get()->getMaxBomb() <= 3) {
                    player.get()->setMaxBomb(player.get()->getMaxBomb() + 1);
                    player->addBombStock();
                }
                if (bonus_type == 3 && player.get()->getBombRange() <= 5)
                    player.get()->setBombRange(player.get()->getBombRange() + 1);
            }
        }
    }
    if (player->getIsRunning() == false)
        return;


    if (valideInputs(KEY_RIGHT, GAMEPAD_BUTTON_LEFT_FACE_RIGHT, idControler, "down")) {
        Vector2 newPos = {0.0f, -player->getSpeed()};
        player->setRotation(1);
        player->setModelFrame();
        movePlayer(player, newPos);
    }
    if (valideInputs(KEY_LEFT, GAMEPAD_BUTTON_LEFT_FACE_LEFT, idControler, "down")) {
        Vector2 newPos = {0.0f, player->getSpeed()};
        player->setRotation(2);
        player->setModelFrame();
        movePlayer(player, newPos);
    }
    if (valideInputs(KEY_UP, GAMEPAD_BUTTON_LEFT_FACE_UP, idControler, "down")) {
        Vector2 newPos = {-player->getSpeed(), 0.0f};
        player->setRotation(3);
        player->setModelFrame();
        movePlayer(player, newPos);
    }
    if (valideInputs(KEY_DOWN, GAMEPAD_BUTTON_LEFT_FACE_DOWN, idControler, "down")) {
        Vector2 newPos = {player->getSpeed(), 0.0f};
        player->setRotation(4);
        player->setModelFrame();
        movePlayer(player, newPos);
    }

    if (player->getBombStock() > 0 && valideInputs(KEY_SPACE, GAMEPAD_BUTTON_RIGHT_FACE_DOWN, idControler, "pressed")) {
        player->removeBombStock();
        Vector3 posbomb = player->getPos();
        float x = posbomb.x - 0.8;
        float z = posbomb.z - 0.8;
        float i = 0;
        float y = 0;
        for (; x >= 0 ; i++) {
            x -= 1.6f;
        }
        i--;

        for (; z >= 0 ; y++) {
            z -= 1.6f;
        }
        y--;
        posbomb.x = (i * 1.6f) + 1.6;
        posbomb.z = (y * 1.6f) + 1.6;
        _entities.emplace_back(new Bomb(_models["bomb"], posbomb.x, posbomb.z, 0.9, "bomb", player.get()->getBombRange(), 2, player->getName()));
        _engine->playSound("bomb");
    }
    if (player->getIsDead() == true && _isDeadList[idControler] == false) {
        _isDeadList[idControler] = true;
        //_Player_0_isDead = true;
        _engine->playSound("death");
    }
}

void SceneGame::findReachBomb(std::string name, float x, float y, int cx, int cy, int i)
{
    int bonus_should_spawn = rand() % 10;
    std::string bonusType = (bonus_should_spawn == 1 ? "skate" : (bonus_should_spawn == 2 ? "bombUp" : (bonus_should_spawn == 3 ? "fireUp" : "broken")));
    if (!(name.substr(0, name.find(":")) == "wall")) {
        if (bonus_should_spawn >= 1 && bonus_should_spawn <= 3)
            _entities.emplace_back(new Bonus(_models[bonusType], x, y, (bonus_should_spawn == 2 ? 0.5f : 0.3f), "bonus", bonus_should_spawn, cx, cy));
        _entities[i]->setName("broken");
    }
}

void SceneGame::updateBomb(std::unique_ptr<Entity>& bomb)
{
    if (bomb->getIsRunning() == false)
        return;
    if (bomb->getOneTime() == 0) {
        bomb->setTimeStart(bomb->getRayLib().getTime());
        bomb->setTimeEnd(bomb->getTimeStart() + 2);
        bomb->setOneTime(1);
    }

    if (bomb->getRayLib().getTime() > bomb->getTimeEnd()) {
        for (int i = 0; i < _entities.size(); i++) {
            if (_entities[i]->getName() == bomb->getOwner()) {
                _entities[i]->addBombStock();
                break;
            }
        }
        Vector3 posperso0;
        Vector3 posperso1;
        Vector3 posperso2;
        Vector3 posperso3;
        for (int i = 0; i < _entities.size(); i++) {
            if (_entities[i]->getName() == "player0")
                posperso0 = _entities[i]->getPos();
            if (_entities[i]->getName() == "player1")
                posperso1 = _entities[i]->getPos();
            if (_entities[i]->getName() == "player2")
                posperso2 = _entities[i]->getPos();
            if (_entities[i]->getName() == "player3")
                posperso3 = _entities[i]->getPos();
        }
        float i = 0;
        float y = 0;
        float i2 = 0;
        float y2 = 0;
        float i3 = 0;
        float y3 = 0;
        float i4 = 0;
        float y4 = 0;
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (float x = posperso0.x - 0.8; x >= 0; i++) { x -= 1.6f; };
        for (float z = posperso0.z - 0.8; z >= 0 ; y++) { z -= 1.6f; };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (float x2 = posperso1.x - 0.8; x2 >= 0 ; i2++) { x2 -= 1.6f; };
        for (float z2 = posperso1.z - 0.8; z2 >= 0 ; y2++) { z2 -= 1.6f; };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (float x3 = posperso2.x - 0.8; x3 >= 0 ; i3++) { x3 -= 1.6f; };
        for (float z3 = posperso2.z - 0.8; z3 >= 0 ; y3++) { z3 -= 1.6f; };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (float x4 = posperso3.x - 0.8; x4 >= 0 ; i4++) { x4 -= 1.6f; };
        for (float z4 = posperso3.z - 0.8; z4 >= 0 ; y4++) { z4 -= 1.6f; };
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector3 posbomb = bomb->getPos();
        posbomb.x = rMan(posbomb.x, 1);
        posbomb.z = rMan(posbomb.z, 1);

        int coord_x_perso0 = rMan((rMan(((i - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_z_perso0 = rMan((rMan(((y - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_x_perso1 = rMan((rMan(((i2 - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_z_perso1 = rMan((rMan(((y2 - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_x_perso2 = rMan((rMan(((i3 - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_z_perso2 = rMan((rMan(((y3 - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_x_perso3 = rMan((rMan(((i4 - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_z_perso3 = rMan((rMan(((y4 - 1) * 1.6f) + 1.6, 1)) / 1.6f, 1);
        int coord_x = rMan(posbomb.x / 1.6f, 1);
        int coord_z = rMan(posbomb.z / 1.6f, 1);

        int coord_box_x;
        int coord_box_z;
        int j = 0;
        int reachUp = 0;
        int reachDown = 0;
        int reachLeft = 0;
        int reachRight = 0;
        int bonus_should_spawn = 0;
        for (; j <= bomb->getRadius(); j++) {
            for (int i = 0; i < _entities.size(); i++) {
                std::string name = _entities[i]->getName();
                if (name.substr(0, name.find(":")) == "box" || name.substr(0, name.find(":")) == "wall" || name.substr(0, name.find("r") + 1) == "player") {
                    coord_box_z = atoi(name.substr(name.find(";") + 1).c_str());
                    coord_box_x = atoi(name.substr(name.find(":") + 1, name.find(";") - name.find(":") + 1).c_str());

                    if ((reachRight == 0 && coord_box_z == coord_z - j && coord_box_x == coord_x) || 
                        (reachRight == 0 && coord_box_z == coord_z_perso0 - j && coord_box_x == coord_x_perso0) &&
                        name.substr(0, name.find("r") + 1) == "player")
                    {
                        findReachBomb(name, coord_x * 1.6f, (coord_z - j) * 1.6f, coord_box_x, coord_box_z, i);
                        reachRight = j;
                    } else if ((reachLeft == 0 && coord_box_z == coord_z + j && coord_box_x == coord_x)) {
                        findReachBomb(name, coord_x * 1.6f, (coord_z + j) * 1.6f, coord_box_x, coord_box_z, i);
                        reachLeft = j;
                    } else if ((reachUp == 0 && coord_box_z == coord_z && coord_box_x == coord_x - j)) {
                        findReachBomb(name, (coord_x - j) * 1.6f, coord_z * 1.6f, coord_box_x, coord_box_z, i);
                        reachUp = j;
                    } else if ((reachDown == 0 && coord_box_z == coord_z && coord_box_x == coord_x + j)) {
                        findReachBomb(name, (coord_x + j) * 1.6f, coord_z * 1.6f, coord_box_x, coord_box_z, i);
                        reachDown = j;
                    }
                    
                    if (reachDown == 0 && coord_x + j == coord_x_perso0 && coord_z == coord_z_perso0 && name == "player0") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachUp == 0 && coord_x - j == coord_x_perso0 && coord_z == coord_z_perso0 && name == "player0") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachLeft == 0 && coord_x == coord_x_perso0 && coord_z + j == coord_z_perso0 && name == "player0") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachRight == 0 && coord_x == coord_x_perso0 && coord_z - j == coord_z_perso0 && name == "player0") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    }

                    if (reachDown == 0 && coord_x + j == coord_x_perso1 && coord_z == coord_z_perso1 && name == "player1") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachUp == 0 && coord_x - j == coord_x_perso1 && coord_z == coord_z_perso1 && name == "player1") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachLeft == 0 && coord_x == coord_x_perso1 && coord_z + j == coord_z_perso1 && name == "player1") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachRight == 0 && coord_x == coord_x_perso1 && coord_z - j == coord_z_perso1 && name == "player1") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    }

                    if (reachDown == 0 && coord_x + j == coord_x_perso2 && coord_z == coord_z_perso2 && name == "player2") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachUp == 0 && coord_x - j == coord_x_perso2 && coord_z == coord_z_perso2 && name == "player2") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachLeft == 0 && coord_x == coord_x_perso2 && coord_z + j == coord_z_perso2 && name == "player2") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachRight == 0 && coord_x == coord_x_perso2 && coord_z - j == coord_z_perso2 && name == "player2") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    }

                    if (reachDown == 0 && coord_x + j == coord_x_perso3 && coord_z == coord_z_perso3 && name == "player3") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachUp == 0 && coord_x - j == coord_x_perso3 && coord_z == coord_z_perso3 && name == "player3") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachLeft == 0 && coord_x == coord_x_perso3 && coord_z + j == coord_z_perso3 && name == "player3") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    } else if (reachRight == 0 && coord_x == coord_x_perso3 && coord_z - j == coord_z_perso3 && name == "player3") {
                        _entities[i]->setPos({100.0f, -100.0f, 0.0f});
                        _entities[i]->setIsDead(true);
                    }
                }
            }
        }
        _entities.emplace_back(new Deflagration(_models["centerKaboom"], posbomb.x, posbomb.z, 0.8f, "deflagration"));

        reachRight = reachRight == 0 ? bomb->getRadius() + 1 : reachRight;
        reachDown = reachDown == 0 ? bomb->getRadius() + 1 : reachDown;
        reachLeft = reachLeft == 0 ? bomb->getRadius() + 1 : reachLeft;
        reachUp = reachUp == 0 ? bomb->getRadius() + 1 : reachUp;

        for (int i = 0; i < reachRight; i++)
            _entities.emplace_back(new Deflagration(_models["horizontalKaboom"], posbomb.x, posbomb.z - (i * 1.6f), 0.8f, "deflagration"));
        for (int i = 0; i < reachLeft; i++)
            _entities.emplace_back(new Deflagration(_models["horizontalKaboom"], posbomb.x, posbomb.z + (i * 1.6f), 0.8f, "deflagration"));
        for (int i = 0; i < reachUp; i++)
            _entities.emplace_back(new Deflagration(_models["verticalKaboom"], posbomb.x - (i * 1.6f), posbomb.z, 0.8f, "deflagration"));
        for (int i = 0; i < reachDown; i++)
            _entities.emplace_back(new Deflagration(_models["verticalKaboom"], posbomb.x + (i * 1.6f), posbomb.z, 0.8f, "deflagration"));

        int random_boom = rand() % 4;
        if (bomb->getRadius() < 5)
            _engine->playSound(random_boom == 0 ? "explode1" : random_boom == 1 ? "explode2" : random_boom == 2 ? "explode3" : "explode4");
        else
            _engine->playSound("explode5");

        bomb->setName("broken");
    }
}

void SceneGame::updateDeflagration(std::unique_ptr<Entity>& deflagration)
{
    if (deflagration->getIsRunning() == false)
        return;
    if (deflagration->getRayLib().getTime() > deflagration->getTimeEnd()) {
        deflagration->setName("broken");
    }
}

void SceneGame::updateBroken(std::unique_ptr<Entity>& broken)
{
    if (broken->getIsRunning() == false)
        return;
    broken->setScale(broken->getScale() - 0.05f);
    if (broken->getScale() <= 0.0f) {
        //broken->setIsRunning(false);
        broken->setName("finito");
    }
}

void SceneGame::update()
{
    if(IsKeyPressed(KEY_P))
        _engine->setScene("pause");
    if (_idMap == 0)
        UpdateMusicStream(_musics["lvl1"]);
    if (_idMap == 1)
        UpdateMusicStream(_musics["lvl2"]);
    if (_idMap == 2)
        UpdateMusicStream(_musics["lvl3"]);
    for (int i = 0; i < _entities.size(); i++) {
        if (_entities[i]->getName() == "player0") {
            if (_nbControlers == 0)
                updatePlayer(_entities[i], 0);
            else
                updatePlayer(_entities[i], 3);
        } else if (_entities[i]->getName() == "player1") {
            if (_nbControlers >= 1)
                updatePlayer(_entities[i], 0);
            else
                updateIA3(_entities[i], 0);
        } else if (_entities[i]->getName() == "player2") {
            if (_nbControlers >= 2)
                updatePlayer(_entities[i], 1);
            else
                updateIA3(_entities[i], 1);
        } else if (_entities[i]->getName() == "player3") {
            if (_nbControlers >= 3)
                updatePlayer(_entities[i], 2);
            else
                updateIA3(_entities[i], 2);
        } else if (_entities[i]->getName() == "bomb")
            updateBomb(_entities[i]);
        else if (_entities[i]->getName() == "deflagration")
            updateDeflagration(_entities[i]);
    }
    for (int i = _entities.size() - 1; i >= 0; i--) {
        if (_entities[i]->getName() == "broken") {
            if (_entities.size() > 800)
                _entities.erase(_entities.begin() + i);
            else
                updateBroken(_entities[i]);
        }
        if (_entities[i]->getName() == "finito")
            _entities.erase(_entities.begin() + i);
    }
}