#include "../hpp/myEvent.hpp"

void MyEvent::onLeftScreen()
{
    int idEvent = findInSiblings<EventComponent>(_siblings);
    _admin.removeEntityFromComp(_siblings[idEvent]);
}

void MyEvent::onColision(ComponentR thisComp, ComponentR colidComp, EntityType colideType)
{
    (void)colidComp;
    (void)colideType;
    int posComp = findInSiblings<PositionComponent>(_siblings);
    int soundComp = findInSiblings<SoundComponent>(_siblings);

    if (soundComp != -1) {
        _siblings[soundComp]->playSoundDeath();
    }

    EnemyExplosion a(_admin, _siblings[posComp]->getX(), _siblings[posComp]->getY());

    _admin.removeEntityFromComp(thisComp);
}