#include "../hpp/System_Event.hpp"

void EventSystem::update(sf::Time elapsed)
{
    _timeRatio = elapsed.asMicroseconds() / 16000.0f;
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_keysPressed[sf::Keyboard::Escape])
            _window.close();

        if (_event.type == sf::Event::KeyPressed)
            _keysPressed[_event.key.code] = true;
        if (_event.type == sf::Event::KeyReleased)
            _keysPressed[_event.key.code] = false;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            _mouseClickPosition = sf::Mouse::getPosition();
    }
    for (std::size_t i = 0; i < _componentsList.size(); i++) {
        if (compareType<MoveComponent>(_componentsList[i]))
            checkMoveComp(i);
        if (compareType<ShootComponent>(_componentsList[i]))
            checkShootComp(i);
        if (compareType<AnimComponent>(_componentsList[i]))
            checkAnimComp(i);
        if (compareType<SoundComponent>(_componentsList[i]))
            checkSoundComp(i);
        
    }
    _mouseClickPosition = {-1, -1};
}

void EventSystem::checkMoveComp(int id)
{
    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[id]->getSiblings();
    int idScene = findInSiblings<SceneComponent>(siblings);
    int idEvent = findInSiblings<EventComponent>(siblings);

    if (idEvent != -1 && _admin.getIsServ())
        setPlayersInput(siblings[idEvent]->getPlayerId());

    if (idScene != -1 && siblings[idScene]->getIdScene() != _admin.getCurrScene())
        return;

    sf::Vector2i move(0, 0);
    if (_keysPressed[sf::Keyboard::Up])
        move.y = -1;
    if (_keysPressed[sf::Keyboard::Down])
        move.y = 1;
    if (_keysPressed[sf::Keyboard::Left])
        move.x = -1;
    if (_keysPressed[sf::Keyboard::Right])
        move.x = 1;

    _componentsList[id]->setMovX(move.x * _timeRatio);
    _componentsList[id]->setMovY(move.y * _timeRatio);
}

void EventSystem::checkShootComp(int id)
{
    if (_componentsList[id]->getAutoShoot())
        return;

    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[id]->getSiblings();
    int idScene = findInSiblings<SceneComponent>(siblings);
    int idEvent = findInSiblings<EventComponent>(siblings);
    if (idEvent != -1 && _admin.getIsServ())
        setPlayersInput(siblings[idEvent]->getPlayerId());

    if (idScene != -1 && siblings[idScene]->getIdScene() != _admin.getCurrScene())
        return;

    if (_keysPressed[sf::Keyboard::Space])
        _componentsList[id]->setWantToShoot(true);
}

void EventSystem::checkAnimComp(int id)
{
    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[id]->getSiblings();
    int idEvent = findInSiblings<EventComponent>(siblings);
    if (idEvent != -1 && _admin.getIsServ()) {
        setPlayersInput(siblings[idEvent]->getPlayerId());
    }

    std::vector<sf::Keyboard::Key> animKeys = _componentsList[id]->getKeysAnim();
    for (std::size_t i = 0; i < animKeys.size(); i++)
        _componentsList[id]->wantKeysAnim(animKeys[i], _keysPressed[animKeys[i]]);
}

void EventSystem::checkSoundComp(int id)
{
    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[id]->getSiblings();
    int idEvent = findInSiblings<EventComponent>(siblings);
    if (idEvent != -1 && _admin.getIsServ())
        setPlayersInput(siblings[idEvent]->getPlayerId());

    for (int i = 0; i < 100; i++)
        if (_keysPressed[i])
            _componentsList[id]->playSoundKeyboard((sf::Keyboard::Key)i);
}

void EventSystem::setKeyboardsInput(std::map<int, bool[100]> playersInputs)
{
    for (auto const& x : playersInputs) {
        for (int i = 0; i < 100; i++)
            _playersInputs[x.first][i] = playersInputs[x.first][i];
    }

}

void EventSystem::setPlayersInput(int idPlayer)
{
    for (int i = 0; i < 100; i++)
        _keysPressed[i] = _playersInputs[idPlayer][i];
}