#pragma once
#include "../../../Game_Engine/hpp/EntityManager.hpp"

class Background
{
    public:
        Background(EntityManager& admin, int x, int y, int rect);
    private:
        EntityManager& _admin;
};