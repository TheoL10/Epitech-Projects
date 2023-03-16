#pragma once
#include "../../../Game_Engine/hpp/EntityManager.hpp"
#include "myEvent.hpp"

class Ladder
{
    public:
        Ladder(EntityManager& admin, int x, int y);
    private:
        EntityManager& _admin;
};