#include "Platform.hpp"

Platform::Platform(EntityManager& admin, int x, int y) : _admin(admin)
{
    EntityR platform = _admin.addEntity();
    ComponentR textComp = platform->addComponent<TextureSpriteComp>("./sprites/Features.png");
    platform->addComponent<PositionComponent>(x, y);
    platform->addComponent<ColisionComponent>(NEUTRAL);
    
    ComponentR eventComp = platform->addComponent<MyEvent>();
    
    textComp->setScale(3, 3);
    textComp->setTextureRect({0, 158, 50, 26});
}