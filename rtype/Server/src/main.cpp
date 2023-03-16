#include "../hpp/tcp_server.hpp"

using boost::asio::ip::udp;

int main(int argc, char **argv)
{
    // rtype::TCPServer server {rtype::IPV::V4, std::stoi(argv[1])};
    // std::cout << "Starting first server" << std::endl;
    // server.run();

    if (run_tcp_server(argc, argv) != 0)
        return 1;
    return 0;
}