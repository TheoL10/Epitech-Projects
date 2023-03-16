#include "../../Game_Engine/hpp/EntityManager.hpp"

#include "../../Game_Engine/hpp/Comp_Position.hpp"
#include "../../Game_Engine/hpp/Comp_TextSprite.hpp"
#include "../../Game_Engine/hpp/Comp_Gravity.hpp"
#include "../../Game_Engine/hpp/Comp_Move.hpp"
#include "../../Game_Engine/hpp/Comp_Shoot.hpp"
#include "../../Game_Engine/hpp/Comp_Velocity.hpp"
#include "../../Game_Engine/hpp/Comp_Vector.hpp"
#include "../../Game_Engine/hpp/Comp_Scene.hpp"
#include "../../Game_Engine/hpp/Comp_Sound.hpp"

#include "myEvent.hpp"

#include "Enemy.hpp"
#include "Enemy2.hpp"
#include "Enemy3.hpp"
#include "EnemyExplosion.hpp"

void setScene1(EntityManager& admin, std::unique_ptr<Entity>& ent)
{
    admin.removeEntity(ent);
}

void test2(ComponentR& alo)
{
    alo->setScale(4, 4);
}

int main()
{
    EntityManager admin(1920, 1080, "Jeu 1", false);

    admin.setScene(0);

    EntityR ship = admin.addEntity();
    EntityR background = admin.addEntity();
    EntityR background2 = admin.addEntity();

    ComponentR textBack = background->addComponent<TextureSpriteComp>("../../assets/sprites/background.png");
    textBack->setScale(5.12, 4.82);
    ComponentR posBack = background->addComponent<PositionComponent>();
    background->addComponent<VectorComponent>(-1, 0);
    background->addComponent<SceneComponent>(0);

    ComponentR textBack2 = background2->addComponent<TextureSpriteComp>("../../assets/sprites/background.png");
    textBack2->setScale(5.12, 4.82);
    ComponentR posBack2 = background2->addComponent<PositionComponent>(1920, 0);
    background2->addComponent<VectorComponent>(-1, 0);
    background2->addComponent<SceneComponent>(0);

    ComponentR textShip = ship->addComponent<TextureSpriteComp>("../../assets/sprites/ship_33_17.png");
    ship->addComponent<PositionComponent>(100, 200);
    ship->addComponent<MoveComponent>();
    ship->addComponent<VelocityComponent>(10, 7);
    ComponentR shootCompo = ship->addComponent<ShootComponent>("../../assets/sprites/laserBeam.png");
    shootCompo->setSize(4);
    shootCompo->setShootPerSecond(5);
    //shootCompo->setAutoShoot(true);
    //shootCompo->setVecAutoShoot({1, -1});

    ship->addComponent<ColisionComponent>(ALLY);
    ship->addComponent<MyEvent>();
    ship->addComponent<SceneComponent>(0);
    ComponentR soundCompo = ship->addComponent<SoundComponent>();
    soundCompo->setSoundShoot("../../assets/sounds/Shoot.ogg");
    soundCompo->setSoundDeath("../../assets/sounds/Explosion.ogg");

    textShip->setTextureRect({0, 0, 33, 17});
    textShip->setScale(2, 2);

    ComponentR animShip = ship->addComponent<AnimComponent>();

    //textShip->setFrameSize(33, 15);
    //textShip->setFrame(2);

    animShip->setKeysAnim(sf::Keyboard::Up, {99, 0, 33, 17}, 2, 5.0f, false, true);
    animShip->setKeysAnim(sf::Keyboard::Down, {33, 0, 33, 17}, 2, 5.0f, false, true);

    srand(time(NULL));
    sf::Clock clock;
    //for (int i = 0; i < 10; i++)
    //    Enemy alo(admin, 1600 + rand() % 100, 50 + rand() % 700);

    int nbEnemy = 0;
    int nbEnemy2 = 0;
    Enemy3 alo3(admin, 7000, 0);



    EntityR winScreen = admin.addEntity();
    winScreen->addComponent<TextureSpriteComp>("../../assets/sprites/win.png");
    winScreen->addComponent<SceneComponent>(1);


    EntityR looseScreen = admin.addEntity();
    looseScreen->addComponent<TextureSpriteComp>("../../assets/sprites/loose.png");
    looseScreen->addComponent<SceneComponent>(2);




    while (admin.isOpen()) {
        admin.update();

        // Infinite background
        if (posBack->getX() < -1920)
            posBack->setPos(1920, 0);
        if (posBack2->getX() < -1920)
            posBack2->setPos(1920, 0);
        
        if (clock.getElapsedTime().asSeconds() > 0.5f && nbEnemy <= 5) {
            clock.restart();
            Enemy alo1(admin, 1920, 50 + rand() % 950);
            nbEnemy++;
        }
        if (clock.getElapsedTime().asSeconds() > 0.1f && nbEnemy > 5 && nbEnemy2 <= 50) {
            clock.restart();
            Enemy2 alo2(admin, 3840, 50 + rand() % 950);
            nbEnemy2++;
        }

        if (alo3.getX() < 1100) {
            alo3.setVecX(0);
        
            if (clock.getElapsedTime().asSeconds() > 0.05f && alo3.getHp() > 0) {
                clock.restart();
                Enemy2 alo1(admin, 1100, 500);

                alo1.setVec(rand() % 100 * -1, (rand() % 200) - 100);
            }
        }

        if (alo3.getHp() <= 0)
            admin.setScene(1);

        if (admin.getAlliesAlive() <= 0)
            admin.setScene(2);
    }

    return 0;
}