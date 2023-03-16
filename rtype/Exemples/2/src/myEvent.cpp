/*
** EPITECH PROJECT, 2022
** B-CPP-500-NCY-5-1-rtype-jules.magyari
** File description:
** myEvent
*/

#include "myEvent.hpp"

void MyEvent::onColision(ComponentR thisComp, ComponentR colidComp, EntityType colideType)
{
    std::vector<std::shared_ptr<IComponent>> siblings1 = thisComp->getSiblings();
    std::vector<std::shared_ptr<IComponent>> siblings2 = colidComp->getSiblings();

    int posCompThis = findInSiblings<PositionComponent>(siblings1);
    int posCompColid = findInSiblings<PositionComponent>(siblings2);
    int posTextThis = findInSiblings<TextureSpriteComp>(siblings1);
    int posTextCOlid = findInSiblings<TextureSpriteComp>(siblings2);


    if (colideType == NEUTRAL) {
        float posThisX = siblings1[posCompThis]->getX();
        float posThisY = siblings1[posCompThis]->getY();
        float posThisWidth = siblings1[posTextThis]->getRealSize().x;
        float posThisHeight = siblings1[posTextThis]->getRealSize().y;

        float posColidY = siblings2[posCompColid]->getY();
        float posColidX = siblings2[posCompColid]->getX();
        float posColidWidth = siblings2[posTextThis]->getRealSize().x;
        float posColidHeight = siblings2[posTextThis]->getRealSize().y;


        float point = (posThisY + (80 / 100) * posThisHeight);
        //std::cout << posThisX + posThisWidth << " " << posColidX << std::endl;

        float newPosX = posThisX;
        float newPosY = posColidY - posThisHeight;

        //std::cout << posThisX + posThisWidth << " " << posColidX << "    " << point << " " << posColidY << " "<< posColidY + posColidHeight << std::endl;


        if (posThisX + posThisWidth >= posColidX && point >= posColidY && point <= posColidY + posColidHeight) {
            newPosX = posColidX - posThisWidth;
            newPosY = posThisY;
            //siblings1[posCompThis]->setPos(posColidX - posThisWidth, posThisY);
        }

        //std::cout << newPosY << " " << posThisY << std::endl;
        siblings1[posCompThis]->setPos(newPosX, newPosY);

    }
    //if (colideType == ENEMY)
    //    std::cout <<"AAAAAAAA " << colideType << std::endl;
}