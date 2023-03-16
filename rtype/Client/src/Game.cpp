#include "Game.hpp"

void Game::loop()
{
    sf::Music music;
    music.openFromFile("assets/musics/Music.ogg");
    bool mus = false;
    while (_window.isOpen())
    {
        if (!mus) {
            music.play();
            mus = !mus;
        }
        _window.clear();

        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::KeyPressed)
                _inputs[_event.key.code] = true;
            if (_event.type == sf::Event::KeyReleased)
                _inputs[_event.key.code] = false;
        }

        actualiseSprites( _mUDP.sendRecv(_inputs));

        for (std::size_t i = 0; i < _sprites.size(); i++)
            _window.draw(_sprites[i]);
        _window.display();
    }

    close(_mUDP.getSocket());
}

void Game::setTexture(std::string path)
{
    if (_text.count(path) == 0)
        _text[path].loadFromFile(path);
}

void Game::actualiseSprites(test2_t received)
{
    std::vector<sf::Sprite> sprites;

    for (int i = 0; i < 500; i++) {
        sprite_infos_t infos = received._infos[i];

        if (_paths.count(infos.idPath) != 0 && !infos.isSfx) {
            sf::Sprite s;

            setTexture(_paths[infos.idPath]);
            s.setTexture(_text[_paths[infos.idPath]]);
            s.setPosition(infos.x, infos.y);
            s.setScale(infos.scX, infos.scY);
            s.setTextureRect({infos.left, infos.top, infos.width, infos.height});

            sprites.push_back(s);
        }
        if (_paths.count(infos.idPath) != 0 && infos.isSfx) {
            sf::SoundBuffer buff;
            buff.loadFromFile(_paths[infos.idPath]);

            sf::Sound sound;
            sound.setBuffer(buff);

            sound.play();
        }
    }
    _sprites = sprites;
}