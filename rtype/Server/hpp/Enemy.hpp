#pragma once
#include "../../Game_Engine/hpp/EntityManager.hpp"
#include "myEvent.hpp"

class Enemy
{
    public:
        Enemy(std::unique_ptr<EntityManager>& admin, int x, int y);
    private:
        std::unique_ptr<EntityManager>& _admin;
};