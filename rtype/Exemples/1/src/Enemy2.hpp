#pragma once
#include "../../Game_Engine/hpp/EntityManager.hpp"
#include "myEvent.hpp"

class Enemy2
{
    public:
        Enemy2(EntityManager& admin, int x, int y);

        void setVec(float x, float y){
            _vec->setVectorX(x);
            _vec->setVectorY(y);
        }
    private:
        EntityManager& _admin;
        ComponentR _vec;
};