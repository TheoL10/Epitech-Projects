#include "Block.hpp"

Block::Block(EntityManager& admin, int x, int y, int rect) : _admin(admin)
{
    EntityR block = _admin.addEntity();
    ComponentR textComp = block->addComponent<TextureSpriteComp>("./sprites/map.png");
    block->addComponent<PositionComponent>(x, y);
    block->addComponent<ColisionComponent>(NEUTRAL);
    
    ComponentR eventComp = block->addComponent<MyEvent>();
    
    textComp->setScale(1, 1);
    /*
    switch(rect) {
        case 1:
            textComp->setTextureRect({0, 0, 50, 50}); break;
        case 2:
            textComp->setTextureRect({50, 0, 50, 50}); break;
        case 3:
            textComp->setTextureRect({0, 50, 50, 50}); break;
        case 4:
            textComp->setTextureRect({50, 50, 50, 50}); break;
        case 5:
            textComp->setTextureRect({50, 250, 50, 50}); break;
    }*/
}