#include "Ladder.hpp"

Ladder::Ladder(EntityManager& admin, int x, int y) : _admin(admin)
{
    EntityR ladder = _admin.addEntity();
    ComponentR textComp = ladder->addComponent<TextureSpriteComp>("./sprites/Features.png");
    ladder->addComponent<PositionComponent>(x, y);
    
    ComponentR eventComp = ladder->addComponent<MyEvent>();
    
    textComp->setScale(3, 3);
    textComp->setTextureRect({0, 108, 26, 50});
}