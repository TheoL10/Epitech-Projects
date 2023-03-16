/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-jules.magyari
** File description:
** myEvent
*/

#include "myEventEnemy.hpp"

void myEventEnemy::onColision(ComponentR thisComp, ComponentR colidComp, EntityType colideType)
{
    std::vector<std::shared_ptr<IComponent>> siblings1 = thisComp->getSiblings();
    std::vector<std::shared_ptr<IComponent>> siblings2 = colidComp->getSiblings();

    int posCompThis = findInSiblings<PositionComponent>(siblings1);
    int posCompColid = findInSiblings<PositionComponent>(siblings2);
    int posTextThis = findInSiblings<TextureSpriteComp>(siblings1);
    int posTextCOlid = findInSiblings<TextureSpriteComp>(siblings2);


    std::cout << colideType << std::endl;

    if (colideType == ALLY) {
        _admin.removeEntityFromComp(thisComp);

    }
}