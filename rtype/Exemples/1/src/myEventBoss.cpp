#include "myEventBoss.hpp"

void MyEventBoss::onColision(ComponentR thisComp, ComponentR colidComp, EntityType colideType)
{
    (void)colidComp;
    (void)colideType;
    int hpComp = findInSiblings<HpComponent>(_siblings);
    int soundComp = findInSiblings<SoundComponent>(_siblings);
    int posComp = findInSiblings<PositionComponent>(_siblings);

    if (hpComp != -1) {

        if (colideType == ALLY)
            _siblings[hpComp]->setHp(_siblings[hpComp]->getHp() - 1);

        if (_siblings[hpComp]->getHp() <= 0) {
            if (soundComp != -1)
                _siblings[soundComp]->playSoundDeath();
            if (posComp != -1) {
                EnemyExplosion a(_admin, _siblings[posComp]->getX(), _siblings[posComp]->getY());
                a.setScale(31, 31);
            }
            _admin.removeEntityFromComp(thisComp);
        }
    }
}