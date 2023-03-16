/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** mutex
*/

#include "hpp/mutex.hpp"

Mutex::Mutex()
{
}

Mutex::~Mutex()
{
}

void Mutex::lock(pthread_mutex_t mutex)
{
    pthread_mutex_lock(&mutex);
}

void Mutex::unlock(pthread_mutex_t mutex)
{
    pthread_mutex_unlock(&mutex);
}

int Mutex::init(pthread_mutex_t mutex)
{
    return pthread_mutex_init(&mutex, NULL);
}

int Mutex::destroy(pthread_mutex_t mutex)
{
    return pthread_mutex_destroy(&mutex);
}