#include "../hpp/System_Physics.hpp"

// Iterate on components
void PhysicsSystem::update(sf::Time elapsed)
{
    (void)elapsed;
    for (std::size_t i = 0; i < _componentsList.size(); i++) {
        if (compareType<PositionComponent>(_componentsList[i])) {
            std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[i]->getSiblings();
            int idScene = findInSiblings<SceneComponent>(siblings);
            if (idScene == -1 || siblings[idScene]->getIdScene() == _admin.getCurrScene()) {
                int idGrav = findInSiblings<GravityComponent>(siblings);
                int idVel = findInSiblings<VelocityComponent>(siblings);
                int idMov = findInSiblings<MoveComponent>(siblings);
                int idVec = findInSiblings<VectorComponent>(siblings);


                float g = idGrav != -1 ? siblings[idGrav]->getG() : 0;
                float velX = idVel != -1 ? siblings[idVel]->getVelocityX() : 1;
                float velY = idVel != -1 ? siblings[idVel]->getVelocityY() : 1;
                float movX = idMov != -1 ? siblings[idMov]->getMovX() : 0;
                float movY = idMov != -1 ? siblings[idMov]->getMovY() : 0;
                float vecX = idVec != -1 ? siblings[idVec]->getVectorX() : 0;
                float vecY = idVec != -1 ? siblings[idVec]->getVectorY() : 0;


                //std::cout << "VEC " << vecX << " " << vecY << std::endl;
                
                float tmpVecX = vecX;
                float tmpVecY = vecY;

                if (vecX != 0 && vecY != 0) {
                    tmpVecX = abs(tmpVecX);
                    tmpVecY = abs(tmpVecY);

                    float max = tmpVecX > vecY ? tmpVecX : tmpVecY;
                    tmpVecX /= max;
                    tmpVecY /= max;

                    vecX = vecX < 0 ? tmpVecX * -1 : tmpVecX;
                    vecY = vecY < 0 ? tmpVecY * -1 : tmpVecY;
                }

                //std::cout << "VECALO " << vecX << " " << vecY << std::endl;

                float x = _componentsList[i]->getX() + ((movX + vecX) * velX);
                float y = _componentsList[i]->getY() + ((movY + vecY + g) * velY);
                _componentsList[i]->setPos(x, y);

                int idEvent = findInSiblings<EventComponent>(siblings);
                if (idEvent != -1) {
                    if (x < 0)
                        _onLeft[siblings[idEvent]] = idEvent;
                    if (x > _admin.getSizeWindow().x)
                        _onRight[siblings[idEvent]] = idEvent;
                }
            }
        }
    }


    for (auto& elem : _onLeft) {
        std::vector<std::shared_ptr<IComponent>> siblings = elem.first->getSiblings();
        siblings[elem.second]->onLeftScreen();
    }
    _onLeft.clear();

    for (auto& elem : _onRight) {
        std::vector<std::shared_ptr<IComponent>> siblings = elem.first->getSiblings();
        siblings[elem.second]->onRightScreen();
    }
    _onRight.clear();
}