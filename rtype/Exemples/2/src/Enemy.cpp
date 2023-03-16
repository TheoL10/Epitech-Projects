#include "Enemy.hpp"

Enemy::Enemy(EntityManager& admin, int x, int y) : _admin(admin)
{
    EntityR enemy = _admin.addEntity();
    ComponentR textComp = enemy->addComponent<TextureSpriteComp>("./sprites/Enemy.png");
    enemy->addComponent<PositionComponent>(x, y);
    enemy->addComponent<ColisionComponent>(ENEMY);
    
    ComponentR eventComp = enemy->addComponent<myEventEnemy>();
    
    textComp->setScale(3, 3);
    textComp->setTextureRect({0, 0, 50, 50});

    ComponentR shootComp = enemy->addComponent<ShootComponent>("../../assets/sprites/shoot_9_9.png");
    shootComp->setSize(4);
    shootComp->setShootPerSecond(1);
    shootComp->setAutoShoot(true);
    shootComp->setVecAutoShoot({-1, 0});
}