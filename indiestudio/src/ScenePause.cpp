#include "../hpp/ScenePause.hpp"

ScenePause::ScenePause(std::map<std::string, Texture2D>& sprites, Engine* engine)
{
    this->_engine = engine;
    this->_sprites = sprites;

    this->_entities.emplace_back(new Button(sprites["pauseReprendre"], sprites["pauseReprendreHover"], 416, 529, 1.0f, 1.0f, 0));
    this->_entities.emplace_back(new Button(sprites["pauseMenu"], sprites["pauseMenuHover"], 1036, 528, 1.0f, 1.0f, 0));
    

    _entities[0]->setHover(true);
}

ScenePause::~ScenePause()
{
}

void ScenePause::update(void)
{
    if (raylib.isKeyPressed(KEY_ENTER)) {
        _engine->playSound("validation");
        if (_currButton == 0)
            _engine->setScene("game");
        if (_currButton == 1) {
            _engine->resetGame();
            _engine->setCamera(2);
            _engine->setScene("menu");
        }
    }
    if (raylib.isKeyPressed(KEY_LEFT)) {
        _engine->playSound("select");
        _entities[_currButton]->setHover(false);
        _currButton -= 1;
        if (_currButton < 0)
            _currButton = 1;
        _entities[_currButton]->setHover(true);
    }
    if (raylib.isKeyPressed(KEY_RIGHT)) {
        _engine->playSound("select");
        _entities[_currButton]->setHover(false);
        _currButton += 1;
        if (_currButton > 1)
            _currButton = 0;
        _entities[_currButton]->setHover(true);
    }
}