#pragma once
#include "../../../Game_Engine/hpp/EntityManager.hpp"
#include "myEvent.hpp"

class Door
{
    public:
        Door(EntityManager& admin, int x, int y, int anim);
    private:
        EntityManager& _admin;
};