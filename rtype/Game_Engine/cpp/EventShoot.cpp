#include "../hpp/EventShoot.hpp"

void EventShoot::onDeath()
{
}

void EventShoot::onRightScreen()
{
    int idEvent = findInSiblings<EventComponent>(_siblings);
    _admin.removeEntityFromComp(_siblings[idEvent]);
}

void EventShoot::onLeftScreen()
{
}

void EventShoot::onColision(ComponentR thisComp, ComponentR colidComp, EntityType colideType)
{
    (void)colidComp;
    (void)colideType;
    _admin.removeEntityFromComp(thisComp);
}