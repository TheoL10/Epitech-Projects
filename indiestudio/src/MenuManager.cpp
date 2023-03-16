#include "../hpp/MenuManager.hpp"

MenuManager::MenuManager(std::map<std::string, Texture2D>& sprites,
                         std::map<std::string, Model>& models,
                         std::map<std::string, Music>& musics,
                         Engine* engine)
{
    _sprites = sprites;
    _musics = musics;
    _engine = engine;
    _models = models;

    this->_menuList = { {"saveSelect", new SceneSaveSelect(sprites, engine, this)},
                        {"main", new SceneMenu(sprites, engine, this)},
                        {"settings", new SceneSettings(sprites, engine, this)},
                        {"level", new SceneLevelSelect(sprites, models, engine, this)},
                        {"versus", new SceneVersus(sprites, engine, this)}
    };

    this->_entities.emplace_back(new Image2D(sprites["hills"], 0, 0, "hills1"));
    this->_entities.emplace_back(new Image2D(sprites["hills"], 1920, 0, "hills2"));

    raylib.playMusicStream(musics["menu"]);
}

MenuManager::~MenuManager()
{
    for (const auto &p : _menuList) { delete(p.second); };
}

void MenuManager::setLvls(int lvl)
{
    delete(_menuList["level"]);
    _menuList["level"] = new SceneLevelSelect(_sprites, _models, _engine, this);
    _menuList["level"]->setLvl(lvl);
}

void MenuManager::moveSprite(void)
{
    for (int i = 0; i < _entities.size(); i++) {
        if (_entities[i]->getName() == "hills1" || _entities[i]->getName() == "hills2") {
            float currCoordX = _entities[i]->getX();
            float speed = 60.0f / _engine->getFps();
            if (currCoordX <= -1920)
                _entities[i]->setX(1920 - speed);
            else
                _entities[i]->setX(currCoordX - speed);
        }
    }
}

void MenuManager::draw(void)
{
    _menuList[_currMenu]->draw();
    for (int i = 0; i < _entities.size(); i++)
        if (_currMenu != "saveSelect")
            _entities[i]->draw();
}

void MenuManager::update(void)
{
    raylib.updateMusicStream(_musics["menu"]);
    moveSprite();
    _menuList[_currMenu]->update();
}