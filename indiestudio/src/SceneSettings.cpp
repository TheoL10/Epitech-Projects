#include "../hpp/SceneSettings.hpp"

SceneSettings::SceneSettings(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager* manager)
{
    this->_engine = engine;
    this->_sprites = sprites;
    this->_manager = manager;

    this->_entities.emplace_back(new Image2D(sprites["settings"], 0, 0, "settings"));
    this->_entities.emplace_back(new Button(sprites["buttonFps"], sprites["buttonFpsHover"], 1000, 200, 0.75f, 0.75f, 0));
    this->_entities.emplace_back(new Button(sprites["buttonFullscreen"], sprites["buttonFullscreenHover"], 1000, 350, 0.75f, 0.75f, 0));
    this->_entities.emplace_back(new Button(sprites["buttonSound"], sprites["buttonSoundHover"], 1000, 500, 0.75f, 0.75f, 0));
    this->_entities.emplace_back(new Button(sprites["buttonQuitter"], sprites["buttonQuitterHover"], 1000, 650, 0.75f, 0.75f, 0));
    this->_entities.emplace_back(new Button(sprites["button30"], sprites["button30Hover"], 1139, 202, 0.75f, 0.75f, 0));
    this->_entities.emplace_back(new Button(sprites["button60"], sprites["button60Hover"], 1259, 202, 0.75f, 0.75f,0));
    this->_entities.emplace_back(new Button(sprites["button90"], sprites["button90Hover"], 1389, 202, 0.75f, 0.75f, 0));
    this->_entities.emplace_back(new Button(sprites["button120"], sprites["button120Hover"], 1519, 202, 0.75f, 0.75f, 0));

    this->_volume.emplace_back(new Image2D(sprites["volume0"], 1003, 513, "volume0"));
    this->_volume.emplace_back(new Image2D(sprites["volume1"], 1003, 513, "volume1"));
    this->_volume.emplace_back(new Image2D(sprites["volume2"], 1003, 513, "volume2"));
    this->_volume.emplace_back(new Image2D(sprites["volume3"], 1003, 513, "volume3"));

    this->_entities[1]->setHover(true);
    this->_entities[_currFps]->setHover(true);
}

SceneSettings::~SceneSettings()
{
}

int SceneSettings::findNewIdButton(int currButton, int direction, int left, int right)
{
    if (currButton + direction < left) {
        currButton = right;
        return currButton;
    }
    if (currButton + direction > right) {
        currButton = left;
        return currButton;
    }
    currButton += direction;
    return currButton;
}

void SceneSettings::updateFps(void)
{
    if (raylib.isKeyPressed(KEY_LEFT)) {
        if (_currFps != _fpsSelected)
            _entities[_currFps]->setHover(false);
         _currFps = findNewIdButton(_currFps, -1, 5, 8);
        _entities[_currFps]->setHover(true);
    }
    if (raylib.isKeyPressed(KEY_RIGHT)) {
        if (_currFps != _fpsSelected)
            _entities[_currFps]->setHover(false);
         _currFps = findNewIdButton(_currFps, 1, 5, 8);
        _entities[_currFps]->setHover(true);
    }
    if (raylib.isKeyPressed(KEY_ENTER) || raylib.isKeyPressed(KEY_SPACE)) {
        int fps = 0;
        _entities[_fpsSelected]->setHover(false);
        _fpsSelected = _currFps;
        _entities[_fpsSelected]->setHover(true);
        if (_currFps == 5)
            fps = 30;
        if (_currFps == 6)
            fps = 60;
        if (_currFps == 7)
            fps = 90;
        if (_currFps == 8)
            fps = 120;
        _engine->setFps(fps);
    }
}

void SceneSettings::updateFS(void)
{
    if (raylib.isKeyPressed(KEY_ENTER) || raylib.isKeyPressed(KEY_SPACE)) {
        display = raylib.getCurrentMonitor();
        if (raylib.isWindowFullscreen()) {
            raylib.toggleFullscreen();
            raylib.setWindowSize(1920,1079);
        }
        else {
            raylib.toggleFullscreen();
            raylib.setWindowSize(raylib.getMonitorWidth(display), raylib.getMonitorHeight(display));
        }
    }
}
        
void SceneSettings::updateSound(void)
{
    if (raylib.isKeyPressed(KEY_RIGHT)) {
        if (_currSound < 10)
            _currSound ++;
        _rectSize = 73.8 * _currSound;
        _engine->setVolume((float)_currSound / 10);
    }
    if (raylib.isKeyPressed(KEY_LEFT)) {
        if (_currSound > 0)
            _currSound --;
        _rectSize = 73.8 * _currSound;
        _engine->setVolume((float)_currSound / 10);
    }
}

void SceneSettings::updateLeave(void)
{
    if (raylib.isKeyPressed(KEY_ENTER) || raylib.isKeyPressed(KEY_SPACE))
        _manager->setMenu("main");
}

void SceneSettings::update(void)
{
    if (raylib.isKeyPressed(KEY_BACKSPACE))
        _manager->setMenu("main");
    if (raylib.isKeyPressed(KEY_DOWN) || raylib.isKeyPressed(KEY_UP) || raylib.isKeyPressed(KEY_LEFT) || raylib.isKeyPressed(KEY_RIGHT))
        _engine->playSound("select");
    if (raylib.isKeyPressed(KEY_SPACE) || raylib.isKeyPressed(KEY_ENTER))
        _engine->playSound("validation");

    if (_currButton == 1)
        updateFps();
    if (_currButton == 2)
        updateFS();
    if (_currButton == 3)
        updateSound();
    if (_currButton == 4)
        updateLeave();

    if (raylib.isKeyPressed(KEY_DOWN)) {
         if (_currButton == 1 && _currFps != _fpsSelected) {
            _entities[_currFps]->setHover(false);
            _currFps = _fpsSelected;
         }
        _entities[_currButton]->setHover(false);
        _currButton = findNewIdButton(_currButton, 1, 1, 4);
        _entities[_currButton]->setHover(true);
    }
    if (raylib.isKeyPressed(KEY_UP)) {
        if (_currButton == 1 && _currFps != _fpsSelected) {
            _entities[_currFps]->setHover(false);
            _currFps = _fpsSelected;
        }
        _entities[_currButton]->setHover(false);
        _currButton = findNewIdButton(_currButton, -1, 1, 4);
        _entities[_currButton]->setHover(true);
    }
}

void SceneSettings::draw(void)
{
    for (int i = 0; i < _entities.size(); i++) _entities[i]->draw();
    raylib.drawRectangle(1129, 516, _rectSize, 64, LIGHTGRAY);
    if (_currSound == 0)
        _volume[0]->draw();
    if (_currSound == 1 || _currSound == 2 || _currSound == 3)
        _volume[1]->draw();
    if (_currSound == 4 || _currSound == 5 || _currSound == 6 || _currSound == 7)
        _volume[2]->draw();
    if (_currSound == 8 || _currSound == 9 || _currSound == 10)
        _volume[3]->draw();
    
}