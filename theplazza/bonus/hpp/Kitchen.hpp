/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ThreadPool
*/

#ifndef KITCHEN_HPP_
#define KITCHEN_HPP_

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <memory>
#include <vector>
#include <functional>
#include <condition_variable>
#include "Fridge.hpp"

#define std_func std::function<void(void)>
#define func_uniptr std::unique_ptr<std_func>
#define queue_type std::queue<func_uniptr>
#define threads_vector std::vector<std::thread>

class Kitchen
{
	public:
		Kitchen(float cooking_multiplier, int time_until_replace, std::size_t thread_number = 3);
		void destroy_kitch(void);
		void push_to_queue(void);
		~Kitchen();
		void exec_func(std_func wi);
		Fridge *_fridge;
		void cook_regina(Kitchen *kitchen, int number_of_pizz);
		void cook_americana(Kitchen *kitchen, int number_of_pizz);
		void cook_fantasia(Kitchen *kitchen, int number_of_pizz);
		void cook_margarita(Kitchen *kitchen, int number_of_pizz);
		void prep_margarita(void);
		void prep_regina(void);
		void prep_americana(void);
		void prep_fantasia(void);
		void fridge_slave(void);
		std::vector<int> _status;
	private:
		int _time_until_replace;
		queue_type _func_queue;
		std::mutex _queue_locker;
		float _cooking_multiplier;
		std::condition_variable _cond_var;
		threads_vector _threads;

};

#endif /* !THREADPOOL_HPP_ */
