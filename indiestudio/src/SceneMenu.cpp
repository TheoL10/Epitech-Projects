#include "../hpp/SceneMenu.hpp"

SceneMenu::SceneMenu(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager* manager)
{
    this->_engine = engine;
    this->_sprites = sprites;
    this->_manager = manager;

    this->_entities.emplace_back(new Image2D(sprites["background"], 0, 0, "background"));
    this->_entities.emplace_back(new Button(sprites["buttonJouer"], sprites["buttonJouerHover"], 1000, 200, 0.75f, 1.0f, -50));
    this->_entities.emplace_back(new Button(sprites["buttonVersus"], sprites["buttonVersusHover"], 1000, 350, 0.75f, 1.0f, -50));
    this->_entities.emplace_back(new Button(sprites["buttonParametre"], sprites["buttonParametreHover"], 1000, 500, 0.75f, 1.0f, -50));
    this->_entities.emplace_back(new Button(sprites["buttonQuitter"], sprites["buttonQuitterHover"], 1000, 650, 0.75f, 1.0f, -50));
    _select = std::make_unique<Image2D>(sprites["help"], 0, 0, "help");

    this->_entities[1]->setHover(true);
}

SceneMenu::~SceneMenu()
{
}

void SceneMenu::findNewIdButton(int direction)
{
    if (_currButton + direction <= 0) {
        _currButton = 4;
        return;
    }
    if (_currButton + direction > 4) {
        _currButton = 1;
        return;
    }
    _currButton += direction;
}

void SceneMenu::update(void)
{
    if (raylib.isKeyPressed(KEY_DOWN))
    {
        _engine->playSound("select");
        _entities[_currButton]->setHover(false);
        findNewIdButton(1);
        _entities[_currButton]->setHover(true);
    }
    if (raylib.isKeyPressed(KEY_UP))
    {
        _engine->playSound("select");
        _entities[_currButton]->setHover(false);
        findNewIdButton(-1);
        _entities[_currButton]->setHover(true);
    }
    if (raylib.isKeyPressed(KEY_RIGHT) || raylib.isKeyPressed(KEY_ENTER) || raylib.isKeyPressed(KEY_SPACE))
    {
        _engine->playSound("validation");
        if (_currButton == 1)
            _manager->setMenu("level");
        if (_currButton == 2)
            _manager->setMenu("versus");
        if (_currButton == 3)
            _manager->setMenu("settings");
        if (_currButton == 4)
            _engine->leaveGame();
    }
    int key = raylib.getKeyPressed();
    if (key != 0 && is_select == true) {
        is_select = false;
    }
    if (raylib.isKeyPressed(KEY_I))
    {
        is_select = true;
    }
}