#include "../hpp/SceneLevelSelect.hpp"

SceneLevelSelect::SceneLevelSelect(std::map<std::string, Texture2D>& sprites, std::map<std::string, Model>& models, Engine* engine, MenuManager *manager)
{
    this->_engine = engine;
    this->_sprites = sprites;
    this->_manager = manager;
    this->_models = models;

    this->_entities.emplace_back(new Image2D(sprites["backgroundLevel"], 0, 0, "background"));
}

SceneLevelSelect::~SceneLevelSelect()
{
}

void SceneLevelSelect::setLvl(int lvl)
{
    _lvlUnlocked = _engine->getLevelUnlock();
    this->_3Dentities.emplace_back(new Block3D(_models["level1"], 0, 0, 1.0f, "1"));
    this->_3Dentities.emplace_back(new Block3D(_models["level1.5"], 0, 0, 1.0f, "1"));
    if (_lvlUnlocked == 1) {
        this->_3Dentities.emplace_back(new Block3D(_models["lock"], 0, 0, 2.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["lock"], 0, 0, 2.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["lock"], 0, 0, 2.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["lock"], 0, 0, 2.0f, "lock"));
    }
    if (_lvlUnlocked == 2) {
        this->_3Dentities.emplace_back(new Block3D(_models["level2"], 0, 0, 1.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["level2.5"], 0, 0, 1.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["lock"], 0, 0, 2.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["lock"], 0, 0, 2.0f, "lock"));
    }
    if (_lvlUnlocked == 3) {
        this->_3Dentities.emplace_back(new Block3D(_models["level2"], 0, 0, 1.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["level2.5"], 0, 0, 1.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["level3"], 0, 0, 1.0f, "lock"));
        this->_3Dentities.emplace_back(new Block3D(_models["level3.5"], 0, 0, 1.0f, "lock"));
    }
}

void SceneLevelSelect::draw(void)
{
    for (int i = 0; i < _entities.size(); i++) _entities[i]->draw();
    raylib.drawText(("Niveau: " + std::to_string(_currLvl)).c_str(), 900, 200, 40, DARKGRAY);
    raylib.beginMode3D(_engine->getCamera());
        if (_currLvl == 1) {
            _3Dentities[0]->draw();
            _3Dentities[1]->draw();
        }
       if (_currLvl == 2) {
            _3Dentities[2]->draw();
            _3Dentities[3]->draw();
        }
        if (_currLvl == 3) {
            _3Dentities[4]->draw();
            _3Dentities[5]->draw();
        }
    raylib.endMode3D();
}

void SceneLevelSelect::changeLevel(int direction)
{
    if (_currLvl + direction < 1)
        _currLvl = 3;
    else if (_currLvl + direction > 3)
        _currLvl = 1;
    else
        _currLvl += direction;

}

void SceneLevelSelect::update(void)
{
    if (raylib.isKeyPressed(KEY_LEFT))
        changeLevel(-1);
    if (raylib.isKeyPressed(KEY_RIGHT))
        changeLevel(1);
    if (raylib.isKeyPressed(KEY_ENTER)) {
        if (_currLvl <= _lvlUnlocked) {
            _engine->setMap(_currLvl - 1);
            _engine->setCamera(1);
            _manager->setMenu("main");
            _engine->setScene("game");
        }
    }
    if (raylib.isKeyPressed(KEY_BACKSPACE))
        _manager->setMenu("main");
}