#include "Background.hpp"

Background::Background(EntityManager& admin, int x, int y, int rect) : _admin(admin)
{
    EntityR background = _admin.addEntity();
    ComponentR textComp = background->addComponent<TextureSpriteComp>("./sprites/Background.png");
    background->addComponent<PositionComponent>(x, y);
    
    textComp->setScale(3, 3);
    switch(rect) {
        case 1:
            textComp->setTextureRect({0, 0, 50, 50}); break;
        case 2:
            textComp->setTextureRect({50, 0, 50, 50}); break;
        case 3:
            textComp->setTextureRect({100, 0, 50, 50}); break;
    }
}