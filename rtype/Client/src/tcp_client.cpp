#include "../hpp/tcp_client.hpp"

client::client(const std::array<char, MAX_NICKNAME>& nickname,
boost::asio::io_service& io_service,
tcp::resolver::iterator endpoint_iterator) :
    _io_service(io_service), _socket(io_service)
{
    strcpy(_nickname.data(), nickname.data());
    memset(_read_msg.data(), '\0', MAX_IP_PACK_SIZE);
    boost::asio::async_connect(_socket, endpoint_iterator, boost::bind(&client::onConnect, this, _1));
}

void client::write(const std::array<char, MAX_IP_PACK_SIZE>& msg)
{
    _io_service.post(boost::bind(&client::writeImpl, this, msg));
}

void client::close()
{
    _io_service.post(boost::bind(&client::closeImpl, this));
}

void client::readHandler(const boost::system::error_code& error)
{
    //handle read
    std::string tmp = _read_msg.data();
    std::cout << "tmp: " << tmp << "|" << std::endl;
    if (tmp.size() > 0 && tmp != "P") {
    // remove every charachter wich isn't a letter
        // find the first letter in tmp
        int firstLetter = tmp.find_first_of('/');
        std::cout << "tmp = " << tmp << std::endl;
        std::string nickname = tmp.substr(firstLetter + 1, tmp.find(":") - firstLetter + 1);
        std::string isReady = tmp.substr(tmp.find(":") + 1, 1);
        nickname[nickname.size() - 1] = '\0';
        std::cout << "nickname : " << nickname << " isReady : " << isReady << std::endl;
        if (std::find(_players.begin(), _players.end(), nickname) == _players.end()) {
            std::cout << "nickname is " << nickname << std::endl;
            _players.push_back(nickname);
        }
        for (std::size_t i = 0; i < _players.size(); i++) {
            if (_players[i] == nickname && isReady == "R")
                _playersReady[i] = true;
        }
        for (std::size_t i = 0; i < _playersReady.size(); i++)
            std::cout << "Ready list: " << _playersReady[i] << std::endl;
    }
    std::cout << _read_msg.data() << std::endl;
    if (!error) {
        boost::asio::async_read(_socket,
        boost::asio::buffer(_read_msg, _read_msg.size()),
        boost::bind(&client::readHandler, this, _1));
    } else
        closeImpl();
}

void client::writeImpl(std::array<char, MAX_IP_PACK_SIZE> msg)
{
    bool write_in_progress = !_write_msgs.empty();
    _write_msgs.push_back(msg);
    if (!write_in_progress) {
        boost::asio::async_write(_socket,
        boost::asio::buffer(_write_msgs.front(), _write_msgs.front().size()),
        boost::bind(&client::writeHandler, this, _1));
    }
}

void client::writeHandler(const boost::system::error_code& error)
{
    if (!error) {
        if (_write_msgs.front().data() == "\0")
            _write_msgs.pop_front();
        if (!_write_msgs.empty()) {
            boost::asio::async_write(_socket,
            boost::asio::buffer(_write_msgs.front(), _write_msgs.front().size()),
            boost::bind(&client::writeHandler, this, _1));
            _write_msgs.pop_front();
        }
    } else
        closeImpl();
}

void client::closeImpl()
{
    _socket.close();
}


void client::onConnect(const boost::system::error_code& error)
{
    if (!error) {
        boost::asio::async_write(_socket,
        boost::asio::buffer(_nickname, _nickname.size()),
        boost::bind(&client::readHandler, this, _1));
    }
}

std::string get_config(int a)
{
    std::ifstream file ("config.txt");
    std::string line;
    if (file.is_open()) {
        //line is equal to the line number a
        for (int i = 0; i < a; i++) {
            getline(file, line);
        }
        file.close();

    }
    return line;
}

int runClient(std::string username)
{
    try {
        boost::asio::io_service io_service;
        tcp::resolver resolver(io_service);
        tcp::resolver::query query(get_config(2), get_config(3));
        tcp::resolver::iterator iterator = resolver.resolve(query);
        std::array<char, MAX_NICKNAME> nickname;
        strcpy(nickname.data(), username.c_str());
        std::cout << "username: " << username << std::endl;

        client cli(nickname, io_service, iterator);

        std::thread t(boost::bind(&boost::asio::io_service::run, &io_service));

        std::array<char, MAX_IP_PACK_SIZE> msg;
        bool isPressed = false;
        int once = 0;
        while (window.isOpen()) {
            //game loop here

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                isPressed = true;
            if (isPressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                isPressed = false;
                std::string to_send = username + ":R\0";
                strcpy(msg.data(), to_send.c_str());
                cli.write(msg);
            }
            if (once == 0) {
                std::string to_send = username + ":P\0";
                strcpy(msg.data(), to_send.c_str());
                cli.write(msg);
            }
            once++;
            if (_players.size() > 0) {

                std::size_t nbPlayerReady = 0;

                for (std::size_t i = 0; i < _playersReady.size(); i++) {
                    if (_playersReady[i] == true)
                        nbPlayerReady++;
                }

                if (nbPlayerReady == _players.size()) {
                    std::cout << "All players are ready" << std::endl;
                    //launch game
                    strcpy(msg.data(), "All Ready\0");
                    cli.write(msg);
                    // close socket and switch
                    cli.close();
                    break;
                }
                sf::RectangleShape rectangle(sf::Vector2f(300, 50));
                rectangle.setFillColor(sf::Color::White);
                rectangle.setPosition(250, 0);
                sf::Font font;
                if (!font.loadFromFile("assets/fonts/arial.ttf"))
                    std::cout << "Error loading font\n";
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(24);
                text.setFillColor(sf::Color::Black);
                text.setPosition(270, 55);
                sf::Texture texture;
                if (!texture.loadFromFile("assets/sprites/galaxy_800.png"))
                    std::cout << "Error loading texture" << std::endl;
                sf::Sprite sprite;
                sprite.setTexture(texture);
                sf::Texture texture2;
                if (!texture2.loadFromFile("assets/sprites/encoche_menu.png"))
                    std::cout << "Error loading texture" << std::endl;
                sf::Sprite sprite2;
                sprite2.setTexture(texture2);
                sprite2.setPosition(250, 30);
                window.draw(sprite);

                //int nb_player = 0;

                for (std::size_t i = 0; i < _players.size(); i++) {
                    std::string is_ready = _playersReady[i] ? "Ready" : "Not Ready";
                    text.setString(_players[i] + " " + is_ready);
                    sprite2.setScale(1.2, 1);
                    window.draw(sprite2);
                    window.draw(text);
                    sprite2.move(0, 90);
                    text.move(0, 90);
                }
                window.display();
            }
            if (_players.size() == 0) {
                sf::Texture texture2;
                if (!texture2.loadFromFile("assets/sprites/encoche_menu.png"))
                    std::cout << "Error loading texture" << std::endl;
                sf::Sprite sprite2;
                sprite2.setTexture(texture2);
                sprite2.setPosition(300, 0);
                sf::RectangleShape rectangle(sf::Vector2f(300, 50));
                rectangle.setFillColor(sf::Color::White);
                rectangle.setPosition(250, 0);
                sf::Font font;
                if (!font.loadFromFile("assets/fonts/arial.ttf"))
                    std::cout << "Error loading font\n";
                sf::Text text;
                text.setFont(font);
                text.setCharacterSize(24);
                text.setFillColor(sf::Color::Black);
                text.setPosition(250, 0);
                std::string is_ready = "Not Ready";
                text.setString("Player0 " + is_ready);
                window.draw(sprite2);
                window.draw(text);
                window.display();
            }
        }
        window.close();
        cli.close();
        t.join();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return 0;
}