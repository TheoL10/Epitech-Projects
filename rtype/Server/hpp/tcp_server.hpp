#pragma once

#include <ctime>
#include <string>
#include <deque>
#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <mutex>
#include <algorithm>
#include <iomanip>
#include <array>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>

enum : unsigned
{
	MAX_MESSAGE_SIZE = 512,
	MAX_NICKNAME = 16,
	PADDING = 24
};

using boost::asio::ip::tcp;

inline std::vector<tcp::endpoint> _endpoints;

//----------------------------------------------------------------------
#include "../hpp/EntityManager.hpp"

#include "../hpp/Comp_Position.hpp"
#include "../hpp/Comp_TextSprite.hpp"
#include "../hpp/Comp_Gravity.hpp"
#include "../hpp/Comp_Move.hpp"
#include "../hpp/Comp_Shoot.hpp"
#include "../hpp/Comp_Velocity.hpp"
#include "../hpp/Comp_Vector.hpp"

#include "../hpp/Server.hpp"

#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <stdio.h>
#include <string.h>

//----------------------------------------------------------------------

class workerThread
{
    public:
        static void run(std::shared_ptr<boost::asio::io_service> io_service);
    private:
        static std::mutex m;
};

inline std::mutex workerThread::m;

class participant
{
    public:
        virtual ~participant() {}
        virtual void onMessage(std::array<char, MAX_MESSAGE_SIZE> & msg) = 0;
};

class chatRoom {
    public:
        void enter(std::shared_ptr<participant> participant, const std::string & nickname);
        void leave(std::shared_ptr<participant> participant);
        void broadcast(std::array<char, MAX_MESSAGE_SIZE>& msg, std::shared_ptr<participant> participant);
        std::string getNickname(std::shared_ptr<participant> participant);
        int getNbParticipants() { return _participants.size(); };
        
    private:
        enum { max_recent_msgs = 100 };
        std::unordered_set<std::shared_ptr<participant>> _participants;
        std::unordered_map<std::shared_ptr<participant>, std::string> _name_table;
        std::deque<std::array<char, MAX_MESSAGE_SIZE>> _recent_msgs;
};



class personInRoom: public participant, public std::enable_shared_from_this<personInRoom>
{
    public:
        personInRoom(boost::asio::io_service& io_service,
        boost::asio::io_service::strand& strand, chatRoom& room);
        tcp::socket& socket();
        void start();
        void onMessage(std::array<char, MAX_MESSAGE_SIZE>& msg);
    private:
        void nicknameHandler(const boost::system::error_code& error);
        void readHandler(const boost::system::error_code& error);
        void writeHandler(const boost::system::error_code& error);
    tcp::socket _socket;
    boost::asio::io_service::strand& _strand;
    chatRoom& _room;
    std::array<char, MAX_NICKNAME> _nickname;
    std::array<char, MAX_MESSAGE_SIZE> _read_msg;
    std::deque<std::array<char, MAX_MESSAGE_SIZE> > _write_msgs;
};



class server
{
    public:
        server(boost::asio::io_service& io_service,
            boost::asio::io_service::strand& strand,
            const tcp::endpoint& endpoint);
            
    private:
        void run();
        void onAccept(std::shared_ptr<personInRoom> new_participant, const boost::system::error_code& error);

        boost::asio::io_service& _io_service;
        boost::asio::io_service::strand& _strand;
        tcp::acceptor _acceptor;
        chatRoom _room;
        tcp::endpoint _endpoint;
};

int run_tcp_server(int ac, char **av);