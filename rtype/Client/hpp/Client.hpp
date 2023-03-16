#pragma once

#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <sys/types.h>
#include <sys/socket.h>
#include <vector>
#include <array>
#include <boost/asio.hpp>
#include <map>

typedef struct __attribute__ ((packed)) test_s {
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


class udpSocket
{
    public:
        udpSocket() {};
        udpSocket( char * inServer, int inPort);
        ~udpSocket() {}

        std::string event_handler(void);
        std::string getRcv();
        test2_t sendRecv(bool _inputs[100]);

        char* getRecvMsg() { return bufferRecv; }
        ssize_t getRecvBytes() { return rByte; }
        int getSocket() { return sockfd; }
        test_t setupMessage(int code, bool _inputs[100]);


    private:
        int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        int     port;
        ssize_t sByte;
        ssize_t rByte;
        char    server[100];
        char bufferSend[sizeof(test_t)];
        char bufferRecv[sizeof(test2_t)];
        bool moving_right;
        bool moving_left;
        bool moving_up;
        bool moving_down;
        bool shooting;
        int canAct = -1;
        timeval tv;
};

