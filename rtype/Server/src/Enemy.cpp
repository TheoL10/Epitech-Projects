#include "../hpp/Enemy.hpp"

Enemy::Enemy(std::unique_ptr<EntityManager>& admin, int x, int y) : _admin(admin)
{
    EntityR enemy = _admin->addEntity();
    ComponentR textComp = enemy->addComponent<TextureSpriteComp>("assets/sprites/enemy1_34_36.png");
    enemy->addComponent<PositionComponent>(x, y);
    enemy->addComponent<VectorComponent>(-1, 0);
    enemy->addComponent<VelocityComponent>(3, 1);
    ComponentR animComp = enemy->addComponent<AnimComponent>();
    enemy->addComponent<ColisionComponent>(ENEMY);
    enemy->addComponent<SceneComponent>(0);
    
    ComponentR eventComp = enemy->addComponent<MyEvent>();

    ComponentR soundComp = enemy->addComponent<SoundComponent>();
    soundComp->setSoundShoot("assets/sounds/Shoot.ogg");
    soundComp->setSoundDeath("assets/sounds/Explosion.ogg");

    //animComp->setFramePerSecond(10);
    animComp->setIdleAnim({0, 0, 33, 36}, 8, 10.0f, true);
    
    textComp->setScale(2, 2);
    textComp->setTextureRect({0, 0, 33, 36});
    //textComp->setFrameSize(33, 36);
    //textComp->setFrame(0);

    ComponentR shootComp = enemy->addComponent<ShootComponent>("assets/sprites/shoot_9_9.png");
    shootComp->setSize(4);
    shootComp->setShootPerSecond(1);
    shootComp->setAutoShoot(true);
    //shootComp->setVecAutoShoot({1, -1});
}