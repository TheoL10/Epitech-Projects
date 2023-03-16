#include "../hpp/tcp_server.hpp"




using boost::asio::ip::tcp;

void workerThread::run(std::shared_ptr<boost::asio::io_service> io_service)
{
    {
        std::lock_guard < std::mutex > lock(m);
        std::cout << "[" << std::this_thread::get_id() << "] Thread starts" << std::endl;
    }
    io_service->run();
    {
        std::lock_guard < std::mutex > lock(m);
        std::cout << "[" << std::this_thread::get_id() << "] Thread ends" << std::endl;
    }
}

void chatRoom::enter(std::shared_ptr<participant> participant, const std::string & nickname)
{
    _participants.insert(participant);
    _name_table[participant] = nickname;
    std::for_each(_recent_msgs.begin(), _recent_msgs.end(),
    boost::bind(&participant::onMessage, participant, _1));
}

void chatRoom::leave(std::shared_ptr<participant> participant)
{
    _participants.erase(participant);
    _name_table.erase(participant);
}

void chatRoom::broadcast(std::array<char, MAX_MESSAGE_SIZE>& msg, std::shared_ptr<participant> participant)
{
    std::string nickname = getNickname(participant);
    std::array<char, MAX_MESSAGE_SIZE> formatted_msg;
    std::string data_string(msg.data());
    std::string ficelle = ((data_string.find(":") == std::string::npos) ? (nickname + data_string) : (data_string));
    std::cout << "ficelle: " << ficelle << std::endl;;
    memcpy(formatted_msg.data(), ficelle.c_str(), ficelle.length() + 1);
    std::cout << "formatted_msg: " << formatted_msg.data() << std::endl;
    _recent_msgs.push_back(formatted_msg);
    while (_recent_msgs.size() > max_recent_msgs)
        _recent_msgs.pop_front();
    std::for_each(_participants.begin(), _participants.end(),
    boost::bind(&participant::onMessage, _1, std::ref(formatted_msg)));
}


std::string chatRoom::getNickname(std::shared_ptr<participant> participant)
{
    return _name_table[participant];
}

personInRoom::personInRoom(boost::asio::io_service& io_service,
boost::asio::io_service::strand& strand, chatRoom& room)
: _socket(io_service), _strand(strand), _room(room) {}

tcp::socket &personInRoom::socket() 
{ 
    return _socket; 
}

void personInRoom::start()
{
    boost::asio::async_read(_socket,
    boost::asio::buffer(_nickname, _nickname.size()),
    _strand.wrap(boost::bind(&personInRoom::nicknameHandler, shared_from_this(), _1)));
}

void personInRoom::onMessage(std::array<char, MAX_MESSAGE_SIZE>& msg)
{
    bool write_in_progress = !_write_msgs.empty();
    _write_msgs.push_back(msg);
    std::cout << "putting in message queue: " << msg.data() << std::endl;
    if (!write_in_progress) {
        boost::asio::async_write(_socket,
        boost::asio::buffer(_write_msgs.front(), _write_msgs.front().size()),
        _strand.wrap(boost::bind(&personInRoom::writeHandler, shared_from_this(), _1)));
    }
}

void personInRoom::nicknameHandler(const boost::system::error_code& error)
{
    if (strlen(_nickname.data()) <= MAX_NICKNAME - 2) {
        memmove(_nickname.data() + 1, _nickname.data(), strlen(_nickname.data()) + 1);
        _nickname[0] = '/';
        // strcat(_nickname.data(), "\0");
        //std::cout << "Nickname: " << _nickname.data() << std::endl;
        // std::cout << "First char: " << _nickname.data()[0];
    }
    else
    {
        //cut off nickname if too long
        _nickname[MAX_NICKNAME - 2] = ':';
        _nickname[MAX_NICKNAME - 1] = ' ';
    }
    _room.enter(shared_from_this(), std::string(_nickname.data()));
    boost::asio::async_read(_socket,
    boost::asio::buffer(_read_msg.data(), _read_msg.size()),
    _strand.wrap(boost::bind(&personInRoom::readHandler, shared_from_this(), _1)));
    
}

void personInRoom::readHandler(const boost::system::error_code& error)
{
    if (!error)
    {
        //print the message
        std::cout << "Message received: " << _read_msg.data() << std::endl;
        std::string msga(_read_msg.data());
        if (msga == "All Ready") {
            std::cout << "All Ready" << std::endl;
            // Call UDP switch here with endpoints_ in arg
            std::cout << "First server ended\n";
            boost::asio::io_service io_service;
            Server serv(io_service, 1338);
            serv.init(_room.getNbParticipants());
        }
        _room.broadcast(_read_msg, shared_from_this());
        boost::asio::async_read(_socket,
        boost::asio::buffer(_read_msg, _read_msg.size()),
        _strand.wrap(boost::bind(&personInRoom::readHandler, shared_from_this(), _1)));
    }
    else
        _room.leave(shared_from_this());
}

void personInRoom::writeHandler(const boost::system::error_code& error)
{
    if (!error)
    {
        _write_msgs.pop_front();
        if (!_write_msgs.empty())
        {
            boost::asio::async_write(_socket,
            boost::asio::buffer(_write_msgs.front(), _write_msgs.front().size()),
            _strand.wrap(boost::bind(&personInRoom::writeHandler, shared_from_this(), _1)));
        }
    }
    else
        _room.leave(shared_from_this());
}

server::server(boost::asio::io_service& io_service,
boost::asio::io_service::strand& strand,
const tcp::endpoint& endpoint)
: _io_service(io_service), _strand(strand), _acceptor(io_service, endpoint), _endpoint(endpoint)
{
    run();
}

void server::run()
{
    std::shared_ptr<personInRoom> new_participant(new personInRoom(_io_service, _strand, _room));
    _acceptor.async_accept(new_participant->socket(), _strand.wrap(boost::bind(&server::onAccept, this, new_participant, _1)));
}

void server::onAccept(std::shared_ptr<personInRoom> new_participant, const boost::system::error_code& error)
{
    if (!error)
    {
        _endpoints.push_back(new_participant->socket().remote_endpoint());
        new_participant->start();
    }
    run();
}

int run_tcp_server(int ac, char **av)
{
    try
    {
        if (ac < 2) {
            std::cerr << "Usage: chat_server <port> [<port> ...]\n";
            return 1;
        }

        std::shared_ptr<boost::asio::io_service> io_service(new boost::asio::io_service);
        boost::shared_ptr<boost::asio::io_service::work> work(new boost::asio::io_service::work(*io_service));
        boost::shared_ptr<boost::asio::io_service::strand> strand(new boost::asio::io_service::strand(*io_service));

        std::cout << "[" << std::this_thread::get_id() << "]" << "server starts" << std::endl;

        std::list < std::shared_ptr < server >> servers;

        tcp::endpoint endpoint(tcp::v4(), std::atoi(av[1]));
        std::shared_ptr<server> a_server(new server(*io_service, *strand, endpoint));
        servers.push_back(a_server);

        boost::thread_group workers;
        boost::thread * t = new boost::thread{ boost::bind(&workerThread::run, io_service) };
        
        // bind cpu affinity for worker thread in linux
        cpu_set_t cpuset;
        CPU_ZERO(&cpuset);
        CPU_SET(1, &cpuset);
        pthread_setaffinity_np(t->native_handle(), sizeof(cpu_set_t), &cpuset);
        //

        workers.add_thread(t);
        workers.join_all();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}