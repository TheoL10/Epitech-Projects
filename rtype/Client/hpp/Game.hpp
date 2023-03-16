#pragma once

#include "Client.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
    public:
        Game() {
            _window.create(sf::VideoMode(1920, 1080), "SFML works!");
            _window.setFramerateLimit(60);
            std::string ipstr(get_config_udp(2));
            char ip[ipstr.length() + 1];
            memcpy(ip, ipstr.c_str(), ipstr.length() + 1);
            std::string portstr(get_config_udp(3));
            int port = std::stoi(portstr) + 1;
            std::cout << "J'existe\n";
            udpSocket mUDP(ip, port);

            _mUDP = mUDP;

            for (int i = 0; i < 100; i++)
                _inputs[i] = false;

        	std::string line;
            std::ifstream myfile ("assets/idPaths.txt");
            unsigned char id = 0;
            if (myfile.is_open()) {
                while ( getline (myfile,line) ) {
                    _paths[id] = line;
                    id++;
                }
                myfile.close();
            }
        };
        std::string get_config_udp(int a)
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

        void loop();
        void actualiseSprites(test2_t received);
        void setTexture(std::string path);
    private:
        std::map<std::string, sf::Texture> _text;
        std::vector<sf::Sprite> _sprites;
        sf::RenderWindow _window;

        bool _inputs[100];
        std::map<unsigned char, std::string> _paths; 

        sf::Event _event;

        udpSocket _mUDP;    
};