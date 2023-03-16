#pragma once
#include "../../../Game_Engine/hpp/EntityManager.hpp"
#include "myEvent.hpp"

class Block
{
    public:
        Block(EntityManager& admin, int x, int y, int rect);
    private:
        EntityManager& _admin;
};