#include "../hpp/Enemy3.hpp"

Enemy3::Enemy3(std::unique_ptr<EntityManager>& admin, int x, int y) : _admin(admin)
{
    EntityR enemy = _admin->addEntity();
    ComponentR textComp = enemy->addComponent<TextureSpriteComp>("assets/sprites/enemy3_67_79.png");
    _pos = enemy->addComponent<PositionComponent>(x, y);
    _vec = enemy->addComponent<VectorComponent>(-1, 0);
    enemy->addComponent<VelocityComponent>(3, 1);
    ComponentR animComp = enemy->addComponent<AnimComponent>();
    enemy->addComponent<ColisionComponent>(ENEMY);
    enemy->addComponent<SceneComponent>(0);
    
    _hp = enemy->addComponent<HpComponent>(10);

    ComponentR eventComp = enemy->addComponent<MyEventBoss>();
    ComponentR soundComp = enemy->addComponent<SoundComponent>();
    //soundComp->setSoundShoot("../../assets/sounds/Shoot.ogg");
    soundComp->setSoundDeath("assets/sounds/AlienDeath.ogg");

    //animComp->setFramePerSecond(10);
    animComp->setIdleAnim({0, 0, 67, 79}, 8, 10.0f, true);
    
    textComp->setScale(14, 14);
    textComp->setTextureRect({0, 0, 67, 79});
    //textComp->setFrameSize(33, 36);
    //textComp->setFrame(0);

    //ComponentR shootComp = enemy->addComponent<ShootComponent>("../../assets/sprites/shoot_9_9.png");
    //shootComp->setSize(4);
    //shootComp->setShootPerSecond(1);
    //shootComp->setAutoShoot(true);
    //shootComp->setVecAutoShoot({1, -1});
}