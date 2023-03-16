#include "../../../Game_Engine/hpp/EntityManager.hpp"

#include "../../../Game_Engine/hpp/Comp_Position.hpp"
#include "../../../Game_Engine/hpp/Comp_TextSprite.hpp"
#include "../../../Game_Engine/hpp/Comp_Gravity.hpp"
#include "../../../Game_Engine/hpp/Comp_Move.hpp"
#include "../../../Game_Engine/hpp/Comp_Shoot.hpp"
#include "../../../Game_Engine/hpp/Comp_Velocity.hpp"
#include "../../../Game_Engine/hpp/Comp_Vector.hpp"
#include "../../../Game_Engine/hpp/Comp_Scene.hpp"

#include "myEvent.hpp"
#include "myEventEnemy.hpp"
#include "Block.hpp"
#include "Block2.hpp"
#include "Background.hpp"
#include "Door.hpp"
#include "Ladder.hpp"
#include "Platform.hpp"
#include "Enemy.hpp"

void draw_background(EntityManager &admin)
{
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 7; j++)
            Background back(admin, 0 + 150 * i, 0 + 150 * j, 1);
    Background vent(admin, 300, 150, 2);
    Background back(admin, 0, 300, 3);
}

void draw_level(EntityManager &admin)
{
    //for (int i = 0; i < 13; i++)
    //    Block map(admin, 0 + 150 * i, 0, 5);
    //for (int i = 0; i < 6; i++)
    //    Block map(admin, 150 * i, 750, 2);
    //for (int i = 0; i < 6; i++)
    //    Block map(admin, 150 * i, 900, 4);
    //Block map(admin, 900, 450, 1);
    //for (int i = 7; i < 13; i++)
    //    Block map(admin, 150 * i, 450, 2);
    //for (int i = 4; i < 7; i++) {
    //    Block map(admin, 900, 150 * i, 3);
    //    for (int j = 7; j < 13; j++)
    //        Block map(admin, 150 * j, 150 * i, 4);
    //}

    Block map(admin, 903, 450, 8372);
    Block map2(admin, -95, 750, 23);
    Block2 map3(admin, 0, 0, 2345678);
}

void draw_feature(EntityManager &admin)
{
    Door entry(admin, 0, 588, 0);
    Door exit(admin, 1450, 288, 1);
    Ladder ladder1(admin, 300, 600);
    Ladder ladder2(admin, 300, 450);
    Platform block1(admin, 378, 450);
    Platform block2(admin, 528, 450);
    Platform block3(admin, 570, 450);
    Enemy bot1(admin, 1050, 300);
}

int main()
{
    EntityManager admin(1900, 900, "Game", false);

    draw_background(admin);
    draw_level(admin);
    draw_feature(admin);

    EntityR player = admin.addEntity();

    ComponentR textPlayer = player->addComponent<TextureSpriteComp>("./sprites/Player.png");
    player->addComponent<PositionComponent>(5, 600);
    player->addComponent<MoveComponent>();
    player->addComponent<VelocityComponent>(4, 12);
    player->addComponent<GravityComponent>();
    player->addComponent<ColisionComponent>(ALLY);
    player->addComponent<MyEvent>();
    player->addComponent<SceneComponent>(0);

    textPlayer->setTextureRect({0, 0, 50, 50});
    textPlayer->setScale(3, 3);

    ComponentR posPlayer = player->addComponent<PositionComponent>(5, 600);
    int playerX;

    ComponentR animPlayer = player->addComponent<AnimComponent>();
    animPlayer->setKeysAnim(sf::Keyboard::Right, {0, 60, 50, 50}, 8, 5.0f, false, false);
    animPlayer->setKeysAnim(sf::Keyboard::Left, {0, 120, 50, 50}, 8, 5.0f, false, false);
    
    animPlayer->setKeysAnim(sf::Keyboard::Down, {100, 30, 70, 20}, 1, 0.0f, false, false);

    animPlayer->setKeysAnim(sf::Keyboard::C, {0, 180, 50, 57}, 4, 10.0f, false, false);

    ComponentR shootComp = player->addComponent<ShootComponent>("./sprites/Shoot.png");
    shootComp->setSize(4);
    shootComp->setShootPerSecond(3);

    while (admin.isOpen()) {
        admin.update();
       
        playerX = posPlayer->getX();
        if (playerX > 210 && playerX < 290) {
            animPlayer->setKeysAnim(sf::Keyboard::Up, {0, 180, 50, 57}, 4, 10.0f, false, false);
            animPlayer->setKeysAnim(sf::Keyboard::Down, {0, 180, 50, 57}, 4, 10.0f, false, false);
        }
        else {
            animPlayer->setKeysAnim(sf::Keyboard::Down, {100, 30, 70, 20}, 1, 0.0f, false, false);
            animPlayer->setKeysAnim(sf::Keyboard::Up, {0, 0, 50, 50}, 1, 10.0f, false, false);
        }

    }
    return 0;
}