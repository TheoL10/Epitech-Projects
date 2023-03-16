/*
** EPITECH PROJECT, 2022
** TEK
** File description:
** process
*/

#include "hpp/process.hpp"

Process::Process()
{
}

Process::~Process()
{
}

pid_t Process::forkerino()
{
    return (fork());
}