#include "../hpp/Server.hpp"

Server::Server(boost::asio::io_service& io_service, short port)
: _socket(io_service, udp::endpoint(udp::v4(), port)), _io_service(io_service) {
    _ecs = std::make_unique<EntityManager>(1920, 1080, "Server", true);
	std::string line;
	std::ifstream myfile ("assets/idPaths.txt");
	unsigned char id = 0;
	if (myfile.is_open()) {
		while ( getline (myfile,line) ) {
			_paths[line] = id;
			id++;
		}
		myfile.close();
	}
}

void Server::readMessage(test_t rcvMsg, int current_player) {
	switch (rcvMsg._code) {
		case (300):
			for (int i = 0; i < 100; i++)
				_inputs[current_player][i] = rcvMsg.inputs[i];
			break;
		case (301):
			break;
	}
}

int findPlayer(std::vector<boost::asio::ip::udp::endpoint> _endpoint, boost::asio::ip::udp::endpoint _sender_endpoint) {
	for (std::size_t i = 0; i < _endpoint.size(); i++)
		if (_endpoint[i] == _sender_endpoint)
			return i;
	return -1;
}

int Server::udp_receive(int i) {
	void *recMsg = malloc(sizeof(test_t));
	_socket.async_receive_from(boost::asio::buffer(recMsg, sizeof(test_t)), _sender_endpoint,
	[this, recMsg, i] (boost::system::error_code ec, std::size_t recvd_bytes)
	{
		test_t convertedMsg = *(test_t *)recMsg;
		if ( !ec && recvd_bytes > 0 ) {
			//std::cout << "ALO " << _sender_endpoint << std::endl;
			if (findPlayer(_endpoint, _sender_endpoint) == i)
				_sender_state[i] = true;
			std::vector<boost::asio::ip::udp::endpoint>::iterator it = std::find(_endpoint.begin(), _endpoint.end(), _sender_endpoint);
			if (_nb_players == 0 || it == _endpoint.end()) {
				_endpoint.push_back(_sender_endpoint);
				_nb_players++;
				std::cout << "New player connected" << std::endl;
			}
			if (_nb_players == _player_number) {
				_game_state = true;
				//std::cout << "Activate gamestate\n";
			}
			readMessage(convertedMsg, findPlayer(_endpoint, _sender_endpoint));
		}
		else {
			std::cout << "Error: " << ec.message() << std::endl;
		}
		free (recMsg);
	});
	return (0);
}

test2_t Server::setup_message(int code, char debug_info[256])
{
	test2_t msg;
	msg._code = code;

	if (code != 400) {
		std::cout << "Mauvais code c'est domamge" << std::endl;
		return msg;
	}

	int idEntity = 0;
	for (std::size_t i = 0; i < _ecs->getComponentsList().size() && idEntity < 500; i++) {
		if (_ecs->compareType<TextureSpriteComp>(_ecs->getComponentsList()[i])) {
			ComponentR comp = _ecs->getComponentsList()[i];
			std::vector<std::shared_ptr<IComponent>> siblings = comp->getSiblings();
			int idPos = _ecs->findInSiblings<PositionComponent>(siblings);
			int idScene = _ecs->findInSiblings<SceneComponent>(siblings);

			if (idScene == -1 || _ecs->getCurrScene() == siblings[idScene]->getIdScene()) {

				if (idPos != -1)
					msg._infos[idEntity].x = siblings[idPos]->getX();
				else
					msg._infos[idEntity].x = 0;
				if (idPos != -1)
					msg._infos[idEntity].y = siblings[idPos]->getY();
				else
					msg._infos[idEntity].y = 0;
				msg._infos[idEntity].scX = comp->getScale().x;
				msg._infos[idEntity].scY = comp->getScale().y;
				msg._infos[idEntity].width = comp->getTextRect().width;
				msg._infos[idEntity].height = comp->getTextRect().height;
				msg._infos[idEntity].left = comp->getTextRect().left;
				msg._infos[idEntity].top = comp->getTextRect().top;
				msg._infos[idEntity].idPath = _paths[comp->getPath()];
				msg._infos[idEntity].isSfx = false;

				idEntity++;
			}
		}
		if (_ecs->compareType<SoundComponent>(_ecs->getComponentsList()[i])) {
			ComponentR comp = _ecs->getComponentsList()[i];
			if (comp->getPathPlaying() != "") {
				msg._infos[i].x = 0;
				msg._infos[i].y = 0;
				msg._infos[i].scX = 0;
				msg._infos[i].scY = 0;
				msg._infos[i].width = 0;
				msg._infos[i].height = 0;
				msg._infos[i].left = 0;
				msg._infos[i].top = 0;
				msg._infos[i].idPath = _paths[comp->getPathPlaying()];
				msg._infos[i].isSfx = true;

				comp->setPathPlaying("");
				
				idEntity++;
			}
		}
	}
	for (int i = idEntity; i < 500; i++) {
		msg._infos[i].x = 0;
		msg._infos[i].y = 0;
		msg._infos[i].scX = 0;
		msg._infos[i].scY = 0;
		msg._infos[i].width = 0;
		msg._infos[i].height = 0;
		msg._infos[i].left = 0;
		msg._infos[i].top = 0;
		msg._infos[i].idPath = 255;
		msg._infos[i].isSfx = false;
	}
	return msg;
}

int Server::udp_send(int player_id, int code) {
	boost::asio::ip::udp::endpoint sender_endpoint_ = _endpoint[player_id];
	int id = player_id;

	test2_t msg;
	msg = setup_message(code, "");

	_socket.async_send_to(boost::asio::buffer(&msg, sizeof(msg)), sender_endpoint_,
			[this, id] (boost::system::error_code ec, std::size_t recvd_bytes) {
				if ( !ec && recvd_bytes > 0 ) {
					// std::cout << "sent bytes: " << recvd_bytes << std::endl;
				}
				else
					std::cout << "error code: " << ec << std::endl;
				_sender_state[id] = false;
			});
	return (0);
}