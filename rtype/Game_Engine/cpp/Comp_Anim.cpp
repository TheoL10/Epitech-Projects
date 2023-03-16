#include "../hpp/Comp_Anim.hpp"

AnimComponent::AnimComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin) : _siblings(sibling), _admin(admin)
{
    int idText = findInSiblings<TextureSpriteComp>(_siblings);

    _idleInfos.rect = _siblings[idText]->getTextRect();
    _idleInfos.nbFrame = 1;
    _idleInfos.frequency = 1.0f;
    _idleInfos.isLoop = true;

    _currInfos = _idleInfos;
}

void AnimComponent::setIdleAnim(sf::IntRect rect, int nbFrame = 1, float frequency = 1.0f, bool isLoop = true)
{
    _idleInfos.rect = rect;
    _idleInfos.nbFrame = nbFrame;
    _idleInfos.frequency = frequency;
    _idleInfos.isLoop = isLoop;

    _currInfos = _idleInfos;
}

void AnimComponent::setKeysAnim(sf::Keyboard::Key key, sf::IntRect rect, int nbFrame, float frequency, bool isOnce, bool isMaintain)
{
    _keysInfos[key].rect = rect;
    _keysInfos[key].nbFrame = nbFrame;
    _keysInfos[key].frequency = frequency;
    _keysInfos[key].isOnce = isOnce;
    _keysInfos[key].isMaintain = isMaintain;
    _keysInfos[key].isIdle = false;
}
