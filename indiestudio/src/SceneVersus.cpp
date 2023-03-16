#include "../hpp/SceneVersus.hpp"

SceneVersus::SceneVersus(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager* manager)
{
    this->_engine = engine;
    this->_sprites = sprites;
    this->_manager = manager;

    this->_entities.emplace_back(new Image2D(sprites["backgroundVersus"], 0, 0, "background"));
    this->_entities.emplace_back(new Image2D(sprites["perso1"], 662, 226, "perso1"));
    this->_entities.emplace_back(new Image2D(sprites["perso2"], 662, 226, "perso2"));
    this->_entities.emplace_back(new Image2D(sprites["perso3"], 662, 226, "perso3"));
    this->_entities.emplace_back(new Image2D(sprites["perso4"], 662, 226, "perso4"));

    this->_entities.emplace_back(new Image2D(sprites["perso1"], 1262, 226, "perso1"));
    this->_entities.emplace_back(new Image2D(sprites["perso2"], 1262, 226, "perso2"));
    this->_entities.emplace_back(new Image2D(sprites["perso3"], 1262, 226, "perso3"));
    this->_entities.emplace_back(new Image2D(sprites["perso4"], 1262, 226, "perso4"));

    this->_entities.emplace_back(new Image2D(sprites["perso1"], 662, 536, "perso1"));
    this->_entities.emplace_back(new Image2D(sprites["perso2"], 662, 536, "perso2"));
    this->_entities.emplace_back(new Image2D(sprites["perso3"], 662, 536, "perso3"));
    this->_entities.emplace_back(new Image2D(sprites["perso4"], 662, 536, "perso4"));

    this->_entities.emplace_back(new Image2D(sprites["perso1"], 1262, 536, "perso1"));
    this->_entities.emplace_back(new Image2D(sprites["perso2"], 1262, 536, "perso2"));
    this->_entities.emplace_back(new Image2D(sprites["perso3"], 1262, 536, "perso3"));
    this->_entities.emplace_back(new Image2D(sprites["perso4"], 1262, 536, "perso4"));
}

SceneVersus::~SceneVersus()
{
}

void SceneVersus::updateManette(int id)
{
    int key = (id + 1) * 4;
    if (raylib.isGamepadButtonPressed(id, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
        _engine->playSound("select");
        _charList[id + 1] -= 1;
        if (_charList[id + 1] < (1 + key))
            _charList[id + 1] = 4 + key;
    }
    if (raylib.isGamepadButtonPressed(id, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
        _engine->playSound("select");
        _charList[id + 1] += 1;
        if (_charList[id + 1] > (4 + key))
            _charList[id + 1] = 1 + key;
    }
}

int SceneVersus::countManettes(void)
{
    int count = 0;
    if (raylib.isGamepadAvailable(0))
        count++;
    if (raylib.isGamepadAvailable(1))
        count++;
    if (raylib.isGamepadAvailable(2))
        count++;
    return count;
}

void SceneVersus::update(void)
{
    if (raylib.isKeyPressed(KEY_LEFT)) {
        _engine->playSound("select");
        _charList[0] -= 1;
        if (_charList[0] < 1)
            _charList[0] = 4;
    }
    if (raylib.isKeyPressed(KEY_RIGHT)) {
        _engine->playSound("select");
        _charList[0] += 1;
        if (_charList[0] > 4)
            _charList[0] = 1;
    }
    if (raylib.isGamepadAvailable(0))
        updateManette(0);
    if (raylib.isGamepadAvailable(1))
        updateManette(1);
    if (raylib.isGamepadAvailable(2))
        updateManette(2);
    if (raylib.isKeyPressed(KEY_ENTER)) {
        _engine->playSound("validation");
        std::vector<int> skins = {_charList[0] - 1, _charList[1] - 5, _charList[2] - 9, _charList[3] - 13};
        _engine->setupVersus(countManettes(), skins);
    }
    if (raylib.isKeyPressed(KEY_BACKSPACE))
        _manager->setMenu("main");
}

void SceneVersus::draw(void)
{
    _entities[0]->draw();
    if (!raylib.isGamepadAvailable(0))
        raylib.drawText("IA", 1300, 250, 100, DARKGRAY);
    else
        _entities[_charList[1]]->draw();

    if (!raylib.isGamepadAvailable(1))
        raylib.drawText("IA", 700, 550, 100, DARKGRAY);
    else
        _entities[_charList[2]]->draw();

    if (!raylib.isGamepadAvailable(2))
        raylib.drawText("IA", 1300, 550, 100, DARKGRAY);
    else
        _entities[_charList[3]]->draw();

    _entities[_charList[0]]->draw();

    raylib.drawText("Joueur 1", 705, 200, 20, DARKGRAY);
    raylib.drawText("Joueur 2", 1305, 200, 20, DARKGRAY);
    raylib.drawText("Joueur 3", 705, 500, 20, DARKGRAY);
    raylib.drawText("Joueur 4", 1305, 500, 20, DARKGRAY);

}