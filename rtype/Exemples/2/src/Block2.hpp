#pragma once
#include "../../../Game_Engine/hpp/EntityManager.hpp"
#include "myEvent.hpp"

class Block2
{
    public:
        Block2(EntityManager& admin, int x, int y, int rect);
    private:
        EntityManager& _admin;
};