#include "../hpp/SceneSaveSelect.hpp"

SceneSaveSelect::SceneSaveSelect(std::map<std::string, Texture2D>& sprites, Engine* engine, MenuManager* manager)
{
    this->_engine = engine;
    this->_sprites = sprites;
    this->_manager = manager;

    this->_entities.emplace_back(new Image2D(sprites["debut"], 0, 0, "debut"));
    this->_entities.emplace_back(new Image2D(sprites["logo"], 305, 175, "logo"));
    this->_entities.emplace_back(new Image2D(sprites["debutText"], 0, 0, "debutText"));
    this->_entities.emplace_back(new Button(sprites["save"], _sprites["saveHover"], 637, 118, 1.0f, 1.0f, 0));
    this->_entities.emplace_back(new Button(sprites["save"], _sprites["saveHover"], 637, 440, 1.0f, 1.0f, 0));
    this->_entities.emplace_back(new Button(sprites["save"], _sprites["saveHover"], 637, 753, 1.0f, 1.0f, 0));

    _entities[3]->setHover(true);

    setSave();
}

SceneSaveSelect::~SceneSaveSelect()
{
}

void SceneSaveSelect::draw(void)
{
    _entities[0]->draw();
    if (_isSaveSelect == false) {
        _entities[1]->draw();
        _entities[2]->draw();
    } else {
        _entities[3]->draw();
        _entities[4]->draw();
        _entities[5]->draw();
        raylib.drawText(_save1 == 1 ? "Empty" : ("Level " + std::to_string(_save1)).c_str(), 880, 208, 48, _saveState == 3 ? WHITE : DARKGRAY);
        raylib.drawText(_save2 == 1 ? "Empty" : ("Level " + std::to_string(_save2)).c_str(), 880, 530, 48, _saveState == 4 ? WHITE : DARKGRAY);
        raylib.drawText(_save3 == 1 ? "Empty" : ("Level " + std::to_string(_save3)).c_str(), 880, 843, 48, _saveState == 5 ? WHITE : DARKGRAY);
    }
}

void SceneSaveSelect::setSave(void)
{
    int curr = 1;
    std::string line;
    std::ifstream myfile (SAVE_PATH"save.txt");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            int lvl = std::atoi(line.c_str());
            lvl = lvl > 3 ? 0 : lvl;
            lvl = lvl < 1 ? 1 : lvl;
            if (curr == 1)
                _save1 = lvl;
            if (curr == 2)
                _save2 = lvl;
            if (curr == 3)
                _save3 = lvl;
            if (curr >= 3)
                break;
            curr++;
        }
        myfile.close();
    } else {
        _save1 = 0;
        _save2 = 0;
        _save3 = 0;
    }
}

int SceneSaveSelect::findNewIdButton(int currButton, int direction, int left, int right)
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

void SceneSaveSelect::updateLogo(void)
{
    float logoY = _entities[1]->getY();
    int speed = 60 / raylib.getFPS();

    if (_logoState) {
        if (logoY > 225)
            _logoState = 0;
        _entities[1]->setY(logoY + 1);
    } else {
        if (logoY < 175)
            _logoState = 1;
        _entities[1]->setY(logoY - 1);
    }
}

void SceneSaveSelect::update(void)
{
    if (_isSaveSelect == false) {
        updateLogo();
        int key = raylib.getKeyPressed();
        if (key != 0) {
            _isSaveSelect = true;
            _engine->playSound("validation");
        }
    } else {
        if (raylib.isKeyPressed(KEY_DOWN)) {
            _engine->playSound("select");
            _entities[_saveState]->setHover(false);
            _saveState = findNewIdButton(_saveState, 1, 3, 5);
            _entities[_saveState]->setHover(true);
        }
        if (raylib.isKeyPressed(KEY_UP)) {
            _engine->playSound("select");
            _entities[_saveState]->setHover(false);
            _saveState = findNewIdButton(_saveState, -1, 3, 5);
            _entities[_saveState]->setHover(true);
        }
        if (raylib.isKeyPressed(KEY_ENTER) || raylib.isKeyPressed(KEY_SPACE)) {
            _engine->playSound("validation");
            if (_saveState == 3) {
                _engine->setLevelUnlock(_save1, 1);
                _manager->setLvl(_save1);
            }
            if (_saveState == 4) {
                _engine->setLevelUnlock(_save2, 2);
                _manager->setLvl(_save2);
            }
            if (_saveState == 5) {
                _engine->setLevelUnlock(_save3, 3);
                _manager->setLvl(_save3);
            }
            _manager->setMenu("main");
        }
    }
}