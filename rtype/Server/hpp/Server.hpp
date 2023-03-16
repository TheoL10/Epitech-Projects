#pragma once

#include "../../Game_Engine/hpp/EntityManager.hpp"
#include "../../Game_Engine/hpp/Comp_Anim.hpp"
#include "../../Game_Engine/hpp/Comp_Colision.hpp"
#include "../../Game_Engine/hpp/Comp_Event.hpp"
#include "../../Game_Engine/hpp/Comp_Gravity.hpp"
#include "../../Game_Engine/hpp/Comp_Move.hpp"
#include "../../Game_Engine/hpp/Comp_Position.hpp"
#include "../../Game_Engine/hpp/Comp_Scene.hpp"
#include "../../Game_Engine/hpp/Comp_Shoot.hpp"
#include "../../Game_Engine/hpp/Comp_TextSprite.hpp"
#include "../../Game_Engine/hpp/Comp_Vector.hpp"
#include "../../Game_Engine/hpp/Comp_Velocity.hpp"
#include "../../Game_Engine/hpp/Comp_Sound.hpp"
#include "myEvent.hpp"
#include "myEventBoss.hpp"
#include "Enemy.hpp"
#include "Enemy2.hpp"
#include "Enemy3.hpp"
#include "Enemy4.hpp"
#include "EnemyExplosion.hpp"

#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <boost/asio.hpp>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <ratio>
#include <thread>
#include <vector>

using boost::asio::ip::udp;

typedef struct  __attribute__ ((packed)) test_s {
    int _code;
    bool inputs[100];
} test_t;

typedef struct sprite_infos_s {
    float x;
    float y;
    float scX;
    float scY;
    int width;
    int height;
    int left;
    int top;
    unsigned char idPath;
    bool isSfx;
} sprite_infos_t;

typedef struct  __attribute__ ((packed)) test2_s {
    int _code;
    sprite_infos_t _infos[500];
} test2_t;

template<std::intmax_t FPS>
class frame_rater {
    public:
        frame_rater() :                 // initialize the object keeping the pace
            _time_between_frames{1},     // std::ratio<1, FPS> seconds
            _tp{std::chrono::steady_clock::now()}
        {}

        void sleep() {
            // add to time point
            _tp += _time_between_frames;
            // and sleep until that time point
            std::this_thread::sleep_until(_tp);
        }

    private:
        // a duration with a length of 1/FPS seconds
        std::chrono::duration<double, std::ratio<1, FPS>> _time_between_frames;
        // the time point we'll add to in every loop
        std::chrono::time_point<std::chrono::steady_clock, decltype(_time_between_frames)> _tp;
}; //A refaire

class Server {
    public:
        Server(boost::asio::io_service& io_service, short port);
        int start_tcp_connection() {return 0;}
        void init(int nbPlayer);

        int udp_send(int player_id, int code);
        test2_t setup_message(int code, char debug_info[256]);
        void readMessage(test_t msg, int current_player);
        int udp_receive(int i = 99);
    private:
        udp::socket _socket;
        std::vector<boost::asio::ip::udp::endpoint> _endpoint;
        boost::asio::ip::udp::endpoint _sender_endpoint;
        boost::asio::io_service& _io_service;
        void *_data_received;
        void *_data_to_send;
        char data[1024];
        std::vector<bool> _sender_state = {false, false, false, false};

        bool _game_state = false; //false if game hasn't started, else true
        std::unique_ptr<EntityManager> _ecs;
        frame_rater<60> _framerate;
        unsigned short _nb_players = 0;

        std::map<int, bool[100]> _inputs;
        std::map<std::string, unsigned char> _paths;
        int _player_number;
};