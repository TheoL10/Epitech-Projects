#include "../hpp/Comp_Sound.hpp"

SoundComponent::SoundComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin)
{}

void SoundComponent::setSoundKey(sf::Keyboard::Key key, std::string path) {
    _keySounds[key] = path;
    _admin.getSoundManager().setSoundBuffer(path);
}

void SoundComponent::setSoundDeath(std::string path)
{
    _onDeath = path;
    _admin.getSoundManager().setSoundBuffer(path);
}

void SoundComponent::setSoundShoot(std::string path)
{
    _onShoot = path;
    _admin.getSoundManager().setSoundBuffer(path);
}

void SoundComponent::playSoundKeyboard(sf::Keyboard::Key key)
{
    if (_keySounds.count(key)) {
        _admin.getSoundManager().playSound(_keySounds[key]);
        _pathPlaying = _keySounds[key];
    }
}

void SoundComponent::playSoundDeath()
{
    if (_onDeath != "") {
        _admin.getSoundManager().playSound(_onDeath);
        _pathPlaying = _onDeath;
    }
}

void SoundComponent::playSoundShoot()
{
    if (_onShoot != "") {
        _admin.getSoundManager().playSound(_onShoot);
        _pathPlaying = _onShoot;
    }
}