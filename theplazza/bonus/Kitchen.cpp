/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Kitchen
*/

#include "hpp/Kitchen.hpp"

void Kitchen::push_to_queue(void)
{
	while(true) {
		func_uniptr func{nullptr};
		{
			std::unique_lock<std::mutex> lock(_queue_locker);
			_cond_var.wait(lock, [&]() {return (!_func_queue.empty());});
			func = std::move(_func_queue.front());
			_func_queue.pop();
		}
		if(!func)
			break;
		(*func)();
	}
}

Kitchen::Kitchen(float cooking_multiplier, int time_until_replace, std::size_t thread_number)
{
	_threads.reserve(thread_number);
	_cooking_multiplier = cooking_multiplier;
	_time_until_replace = time_until_replace;
	_fridge = new Fridge;

	for(auto i = 0; i < thread_number; ++i)
		_threads.push_back(std::thread([this]() {push_to_queue();}));
}

void Kitchen::exec_func(std_func wi)
{
	auto work_item = std::make_unique<std_func>(std::move(wi));
	std::unique_lock<std::mutex> lock(_queue_locker);
	_func_queue.push(std::move(work_item));
	_cond_var.notify_one();
}

void Kitchen::destroy_kitch(void) {
	std::unique_lock<std::mutex> lock(_queue_locker);
	for(auto& t : _threads)
		_func_queue.push(func_uniptr{nullptr});
}

Kitchen::~Kitchen()
{
	destroy_kitch();
	for(auto& t : _threads)
		t.join();
}

void Kitchen::fridge_slave(void)
{
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(_time_until_replace >= 500 ? _time_until_replace : 500)); //replace 5 with variable given as parameter
		_fridge->refill_once();
		// printf("Just refilled: %d %d %d %d %d %d %d %d\n", _fridge->_doe, _fridge->_eggplant, _fridge->_goat_cheese, _fridge->_gruyere, _fridge->_ham, _fridge->_mushroom, _fridge->_steak, _fridge->_afk);
		if (_fridge->getAfk() == 50)
			return;
	}
}