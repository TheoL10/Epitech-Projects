#include "../hpp/Client.hpp"
#include "../hpp/tcp_client.hpp"
#include "../hpp/Particle_System.hpp"
#include "../hpp/Game.hpp"

int manage_click(sf::Vector2i pos)
{
    int temp = 0;
    if ((pos.x > 148 && pos.x < 396) && (pos.y > 133 && pos.y < 216))
        temp = 1;
    else if ((pos.x > 629 && pos.x < 768) && (pos.y > 438 && pos.y < 577))
        temp = 2;
    return temp;
}

std::string manage_keyboard(std::string string)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        if(!string.empty())
            string.pop_back();
    if (string.length() > 6)
        return string;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        string += "A";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        string += "B";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        string += "C";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        string += "D";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        string += "E";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        string += "F";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        string += "G";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        string += "H";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        string += "I";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        string += "J";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        string += "K";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        string += "L";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        string += "M";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
        string += "N";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        string += "O";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        string += "P";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        string += "Q";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        string += "R";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        string += "S";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        string += "T";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        string += "U";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        string += "V";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        string += "W";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        string += "X";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        string += "Y";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        string += "Z";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0))
        string += "0";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
        string += "1";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
        string += "2";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3))
        string += "3";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
        string += "4";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5))
        string += "5";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
        string += "6";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7))
        string += "7";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8))
        string += "8";
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9))
        string += "9";
    return string;
}

int main()
{
    int aim = 0;
    int error_text_check = 0;
    std::string nickname_temp;
    Particle_System particle_system(&window, "fire", "center", 512, 4, 30, 2);

    while (true) {
        //Username set
        sf::Texture texture;
        if (!texture.loadFromFile("assets/sprites/background_menu800.png"))
            std::cout << "Error loading texture" << std::endl;
        sf::Sprite sprite;
        sprite.setTexture(texture);
        sf::Font font;
        if (!font.loadFromFile("assets/fonts/pixelart.ttf"))
            std::cout << "Error loading font" << std::endl;
        sf::Text Text_name;
        Text_name.setFont(font);
        Text_name.setCharacterSize(40);
        Text_name.setFillColor(sf::Color::Black);
        Text_name.setPosition(165, 150);
        sf::Text error_text;
        error_text.setFont(font);
        error_text.setCharacterSize(24);
        error_text.setFillColor(sf::Color::Red);
        error_text.setPosition(350, 360);
        window.setFramerateLimit(60);
        error_text.setString("need an username");
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event))
            {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                    exit(0);
                }
                if (event.type == sf::Event::MouseButtonPressed)
                    aim = manage_click(pos);
                if(event.type == sf::Event::KeyPressed && aim == 1)
                    Text_name.setString(nickname_temp = manage_keyboard(nickname_temp));
            }
            window.clear();
            if (aim == 2 && nickname_temp.empty())
                error_text_check = 1;
            else if (aim == 2)
                break;
            window.draw(sprite);
            if (error_text_check == 1)
                window.draw(error_text);
            window.draw(Text_name);
            particle_system.update(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
            particle_system.run();
            window.display();
        }
        if (aim == 2)
            break;
    }
    if (runClient(nickname_temp) != 0)
        exit(1);
    //char a[12] = "127.0.0.1";
    //udpSocket mUDP(a, 1338);
    //Entity ent;

    //sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    //window.setFramerateLimit(60);
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    Game game;
    game.loop();

    //while (window.isOpen())
    //{
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }
    //    mUDP.sendRecv(window, ent);
//
    //    window.clear();
    //    window.display();
    //}
    //close(mUDP.getSocket());
    return (0);
}