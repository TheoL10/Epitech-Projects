#pragma once

enum : unsigned
{
	MAX_IP_PACK_SIZE = 512,
	MAX_NICKNAME = 16,
	PADDING = 24
};

#include <deque>
#include <array>
#include <thread>
#include <iostream>
#include <cstring>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <fstream>
#include <string>

using boost::asio::ip::tcp;

inline std::vector<std::string> _players;
inline std::vector<bool> _playersReady = {false, false, false, false, false, false, false, false};
inline sf::RenderWindow window(sf::VideoMode(800, 600), "TCP Connexion");

class client
{
public:
    client(const std::array<char, MAX_NICKNAME>& nickname,
    boost::asio::io_service& io_service,
    tcp::resolver::iterator endpoint_iterator);

    void write(const std::array<char, MAX_IP_PACK_SIZE>& msg);
    void close();

private:
    void onConnect(const boost::system::error_code& error);
    void readHandler(const boost::system::error_code& error);
    void writeImpl(std::array<char, MAX_IP_PACK_SIZE> msg);
    void writeHandler(const boost::system::error_code& error);
    void closeImpl();

    boost::asio::io_service& _io_service;
    tcp::socket _socket;
    std::array<char, MAX_IP_PACK_SIZE> _read_msg;
    std::deque<std::array<char, MAX_IP_PACK_SIZE>> _write_msgs;
    std::array<char, MAX_NICKNAME> _nickname;
};

int runClient(std::string username);
std::string get_config(int a);