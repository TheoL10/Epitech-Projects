#include "../hpp/Client.hpp"

udpSocket::udpSocket( char * inServer, int inPort) {
    port = inPort;
    sByte =0;
    rByte = 0;
    memset(bufferSend, '\0', sizeof(bufferSend)+1);
    memset(bufferRecv, '\0', sizeof(bufferRecv)+1);
    memset(server, '\0', sizeof(server)+1);
    memcpy(server, inServer, strlen(inServer));
    tv.tv_sec = 0;
    tv.tv_usec = 20 * 1000; // 10 milliseconds
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
}

std::string udpSocket::event_handler(void) {
    if (moving_left && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        moving_left = false;
        return ("stop left");
    }
    if (moving_right && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moving_right = false;
        return ("stop right\0");
    }
    if (moving_up && !sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        moving_up = false;
        return ("stop up\0");
    }
    if (moving_down && !sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moving_down = false;
        return ("stop down\0");
    }
    if (shooting && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shooting = false;
        return ("stop shoot\0");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        moving_right = true;
        return ("right\0");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        moving_left = true;
        return ("left\0");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        moving_up = true;
        return ("up\0");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        moving_down = true;
        return ("down\0");
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        shooting = true;
        return ("shoot\0");
    }
    else return ("nothing");
}

std::string udpSocket::getRcv() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    //struct sockaddr_in servAddr;
    struct sockaddr_in  cliAddr;
    socklen_t cLen = sizeof(cliAddr);
    //socklen_t sLen = sizeof(servAddr);
    //servAddr.sin_family = AF_INET;
    //servAddr.sin_port = htons(port);
    //servAddr.sin_addr.s_addr = inet_addr(server);
    rByte = recvfrom(sockfd,bufferRecv,sizeof(bufferRecv),0,(struct sockaddr *)&cliAddr,&cLen);
    close(sockfd);
    return (bufferRecv);
}

test_t udpSocket::setupMessage(int code, bool _inputs[100])
{
    test_t msg;

    switch (code) {
        case (300):
            msg._code = code;
            for (int i = 0; i < 100; i++)
                msg.inputs[i] = _inputs[i];
            break;
        case (301):
            break;
    }
    return (msg);
}

test2_t udpSocket::sendRecv(bool _inputs[100]) {
        //if (inMsg == "nothing") return 0;
    struct sockaddr_in servAddr;
    struct sockaddr_in  cliAddr;

    socklen_t cLen = sizeof(cliAddr);
    socklen_t sLen = sizeof(servAddr);

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);
    servAddr.sin_addr.s_addr = inet_addr(server);

    test_t msg = setupMessage(300, _inputs);
    memcpy(&bufferSend, &msg, sizeof(msg));
    // UserLoginRequest request;
    //test_t msg2;
    //memcpy(&msg2, &bufferSend, sizeof(msg2));
    if (canAct >= (rand() % 10) || canAct == -1) {
        sByte = sendto(sockfd, bufferSend,sizeof(bufferSend),0,(struct sockaddr * )&servAddr,sLen);
        canAct = 0;
    }

    int receivedBytes = rByte = recvfrom(sockfd,bufferRecv,sizeof(bufferRecv), O_NONBLOCK,(struct sockaddr *)&cliAddr,&cLen);
    if (receivedBytes > 0)
        canAct++;
    test2_t infos;
    memcpy(&infos, bufferRecv, sizeof(infos));
    return infos;
}