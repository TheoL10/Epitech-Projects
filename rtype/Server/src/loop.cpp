#include "../hpp/Server.hpp"

void Server::init(int nbPlayer)
{
    _player_number = nbPlayer;
    std::cout << "OUI" << std::endl;
    /*
    EntityR background = _ecs->addEntity();
    EntityR background2 = _ecs->addEntity();

    ComponentR textBack = background->addComponent<TextureSpriteComp>("assets/sprites/background.png");
    textBack->setScale(4, 4);
    ComponentR posBack = background->addComponent<PositionComponent>();
    background->addComponent<VectorComponent>(-1, 0);
    background->addComponent<SceneComponent>(0);

    ComponentR textBack2 = background2->addComponent<TextureSpriteComp>("assets/sprites/background.png");
    textBack2->setScale(4, 4);
    ComponentR posBack2 = background2->addComponent<PositionComponent>(1500, 0);
    background2->addComponent<VectorComponent>(-1, 0);
    background2->addComponent<SceneComponent>(0);

    std::cout << "UDP Server init: " << nbPlayer << std::endl;
    for (int i = 0; i < nbPlayer; i++) {
        EntityR ship = _ecs->addEntity();
        ComponentR textShip = ship->addComponent<TextureSpriteComp>("assets/sprites/ship_33_17.png");
        //ComponentR textShip = ship->addComponent<TextureSpriteComp>("assets/sprites/ship_34_15.png");
    
        ship->addComponent<PositionComponent>(950, 500);
        ship->addComponent<MoveComponent>();
        ship->addComponent<VelocityComponent>(10, 7);
    
        ComponentR shootCompo = ship->addComponent<ShootComponent>("assets/sprites/laserBeam.png");
        shootCompo->setSize(4);
    
        ship->addComponent<ColisionComponent>(ALLY);

        ComponentR eventCompo = ship->addComponent<MyEvent>();
        eventCompo->setPlayerId(i);

        ship->addComponent<SceneComponent>(0);

        ComponentR soundCompo = ship->addComponent<SoundComponent>();
        soundCompo->setSoundShoot("assets/sounds/Shoot.ogg");
        soundCompo->setSoundDeath("assets/sounds/Explosion.ogg");

        textShip->setTextureRect({0, 17 * i, 33, 17});
        textShip->setScale(2, 2);
        ComponentR animShip = ship->addComponent<AnimComponent>();
        shootCompo->setShootPerSecond(5);
        animShip->setKeysAnim(sf::Keyboard::Up, {99, 17 * i, 33, 17}, 2, 5.0f, false, true);
        animShip->setKeysAnim(sf::Keyboard::Down, {33, 17 * i, 33, 17}, 2, 5.0f, false, true);
    }
    */

    _ecs->setScene(0);
    
    EntityR background = _ecs->addEntity();
    EntityR background2 = _ecs->addEntity();

    ComponentR textBack = background->addComponent<TextureSpriteComp>("assets/sprites/background.png");
    textBack->setScale(5.12, 4.82);
    ComponentR posBack = background->addComponent<PositionComponent>();
    background->addComponent<VectorComponent>(-1, 0);
    background->addComponent<SceneComponent>(0);

    ComponentR textBack2 = background2->addComponent<TextureSpriteComp>("assets/sprites/background.png");
    textBack2->setScale(5.12, 4.82);
    ComponentR posBack2 = background2->addComponent<PositionComponent>(1920, 0);
    background2->addComponent<VectorComponent>(-1, 0);
    background2->addComponent<SceneComponent>(0);

    for (int i = 0; i < nbPlayer; i++) {
        EntityR ship = _ecs->addEntity();
        ComponentR textShip = ship->addComponent<TextureSpriteComp>("assets/sprites/ship_33_17.png");
        ship->addComponent<PositionComponent>(100, 200);
        ship->addComponent<MoveComponent>();
        ship->addComponent<VelocityComponent>(10, 7);
        ComponentR shootCompo = ship->addComponent<ShootComponent>("assets/sprites/laserBeam.png");
        shootCompo->setSize(4);
        shootCompo->setShootPerSecond(5);
        //shootCompo->setAutoShoot(true);
        //shootCompo->setVecAutoShoot({1, -1});

        ship->addComponent<ColisionComponent>(ALLY);
        ComponentR eventComp = ship->addComponent<MyEvent>();
        eventComp->setPlayerId(i);
        ship->addComponent<SceneComponent>(0);
        ComponentR soundCompo = ship->addComponent<SoundComponent>();
        soundCompo->setSoundShoot("assets/sounds/Shoot.ogg");
        soundCompo->setSoundDeath("assets/sounds/Explosion.ogg");

        textShip->setTextureRect({0, 17 * i, 33, 17});
        textShip->setScale(2, 2);

        ComponentR animShip = ship->addComponent<AnimComponent>();

        //textShip->setFrameSize(33, 15);
        //textShip->setFrame(2);

        animShip->setKeysAnim(sf::Keyboard::Up, {99, 17 * i, 33, 17}, 2, 5.0f, false, true);
        animShip->setKeysAnim(sf::Keyboard::Down, {33, 17 * i, 33, 17}, 2, 5.0f, false, true);
    }

    //srand(time(NULL));
    //sf::Clock clock;
    //for (int i = 0; i < 10; i++)
    //    Enemy alo(admin, 1600 + rand() % 100, 50 + rand() % 700);

    int nbEnemy = 0;
    int nbEnemy2 = 0;
    Enemy3 alo3(_ecs, 7000, 0);



    EntityR winScreen = _ecs->addEntity();
    winScreen->addComponent<TextureSpriteComp>("assets/sprites/win.png");
    winScreen->addComponent<SceneComponent>(1);


    EntityR looseScreen = _ecs->addEntity();
    looseScreen->addComponent<TextureSpriteComp>("assets/sprites/loose.png");
    looseScreen->addComponent<SceneComponent>(2);

    //Enemy alo(_ecs, 1500, rand() % 896);
    //udp_receive();
    srand(time(NULL));
    sf::Clock clock;
    frame_rater<60> framerate;
    while (true)
    {
        //std::cout << "In udp LOOP\n";
        udp_receive();
        _ecs->setKeyboardInputs(_inputs);
        _io_service.poll();
        _io_service.reset();

        if (_game_state == true) {
            for (int i = 0; i < _nb_players; i++)
            {
                if (_sender_state[i] == false)
                {
                    udp_receive();
                    _ecs->setKeyboardInputs(_inputs);
                    udp_send(i, 400);
                    _sender_state[i] = true;
                }
            }
            framerate.sleep();

            _ecs->update();

            //if (posBack->getX() < -1500)
            //    posBack->setPos(1500, 0);
            //if (posBack2->getX() < -1500)
            //    posBack2->setPos(1500, 0);

            //if (clock.getElapsedTime().asSeconds() > 0.1f) {
            //   clock.restart();
            //   Enemy alo(_ecs, 1500, rand() % 896);
            //}
            // Infinite background
            if (posBack->getX() < -1920)
                posBack->setPos(1920, 0);
            if (posBack2->getX() < -1920)
                posBack2->setPos(1920, 0);
            
            if (clock.getElapsedTime().asSeconds() > 0.5f && nbEnemy <= 5) {
                clock.restart();
                Enemy alo1(_ecs, 1920, 50 + rand() % 950);
                nbEnemy++;
            }
            if (clock.getElapsedTime().asSeconds() > 0.1f && nbEnemy > 5 && nbEnemy2 <= 50) {
                clock.restart();
                Enemy4 alo2(_ecs, 3840, 50 + rand() % 950);
                nbEnemy2++;
            }

            if (alo3.getX() < 1100) {
                alo3.setVecX(0);
            
                if (clock.getElapsedTime().asSeconds() > 0.05f && alo3.getHp() > 0) {
                    clock.restart();
                    Enemy2 alo1(_ecs, 1100, 500);

                    alo1.setVec(rand() % 100 * -1, (rand() % 200) - 100);
                }
            }

            if (alo3.getHp() <= 0)
                _ecs->setScene(1);

            if (_ecs->getAlliesAlive() <= 0)
                _ecs->setScene(2);
            }
    }
}