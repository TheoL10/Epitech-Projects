#include "../hpp/EnemyExplosion.hpp"

EnemyExplosion::EnemyExplosion(EntityManager& admin, int x, int y) : _admin(admin)
{
    EntityR enemy = _admin.addEntity();
    _scale = enemy->addComponent<TextureSpriteComp>("assets/sprites/explosion_34_34.png");
    _scale->setScale(2, 2);
    _scale->setTextureRect({0, 0, 33, 34});
    enemy->addComponent<PositionComponent>(x, y);
    ComponentR animComp = enemy->addComponent<AnimComponent>();
    animComp->setIdleAnim({0, 0, 33, 34}, 6, 10.0f, 0);
    enemy->addComponent<SceneComponent>(0);
    //textComp->setFrameSize(33, 34);
    //textComp->setFrame(0);
}