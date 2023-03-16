#include "Door.hpp"

Door::Door(EntityManager& admin, int x, int y, int anim) : _admin(admin)
{
    EntityR door = _admin.addEntity();
    ComponentR textComp = door->addComponent<TextureSpriteComp>("./sprites/Features.png");
    door->addComponent<PositionComponent>(x, y);
    
    ComponentR eventComp = door->addComponent<MyEvent>();
    
    textComp->setScale(3, 3);
    textComp->setTextureRect({0, 0, 50, 54});

    if (anim == 1) {
        ComponentR animDoor = door->addComponent<AnimComponent>();
        animDoor->setKeysAnim(sf::Keyboard::O, {0, 54, 50, 54}, 9, 20.0f, true, true);
    }
}