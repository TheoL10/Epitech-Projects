#include "../hpp/Enemy2.hpp"

Enemy2::Enemy2(std::unique_ptr<EntityManager>& admin, int x, int y) : _admin(admin)
{
    EntityR enemy = _admin->addEntity();
    //ComponentR textComp = enemy->addComponent<TextureSpriteComp>("assets/sprites/enemy2_17_18.png");
    ComponentR textComp = enemy->addComponent<TextureSpriteComp>("assets/sprites/shoot_9_9.png");
    enemy->addComponent<PositionComponent>(x, y);
    _vec = enemy->addComponent<VectorComponent>(-1, 0);
    enemy->addComponent<VelocityComponent>(3, 1);
    ComponentR animComp = enemy->addComponent<AnimComponent>();
    enemy->addComponent<ColisionComponent>(ENEMY);
    enemy->addComponent<SceneComponent>(0);
    
    ComponentR eventComp = enemy->addComponent<MyEvent>();

    ComponentR soundComp = enemy->addComponent<SoundComponent>();
    //soundComp->setSoundShoot("../../assets/sounds/Shoot.ogg");
    soundComp->setSoundDeath("assets/sounds/Explosion.ogg");

    //animComp->setFramePerSecond(10);
    //animComp->setIdleAnim({0, 0, 17, 18}, 12, 10.0f, true);
    animComp->setIdleAnim({0, 0, 8, 8}, 8, 10.0f, true);
    
    textComp->setScale(8, 8);
    //textComp->setTextureRect({0, 0, 17, 18});
    textComp->setTextureRect({0, 0, 8, 8});
    //textComp->setFrameSize(33, 36);
    //textComp->setFrame(0);

    //ComponentR shootComp = enemy->addComponent<ShootComponent>("../../assets/sprites/shoot_9_9.png");
    //shootComp->setSize(4);
    //shootComp->setShootPerSecond(1);
    //shootComp->setAutoShoot(true);
    //shootComp->setVecAutoShoot({1, -1});
}