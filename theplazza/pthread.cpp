/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** pthread
*/

#include "hpp/pthread.hpp"

Pthread::Pthread()
{
}

Pthread::~Pthread()
{
}

void Pthread::create(pthread_t thread, void *(*function)(void *), void *arg)
{
    pthread_create(&thread, NULL, function, arg);
}

void Pthread::join(pthread_t thread)
{
    pthread_join(thread, NULL);
}

void Pthread::exit(void *status)
{
    pthread_exit(status);
}