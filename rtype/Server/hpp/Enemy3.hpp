#pragma once
#include "../../Game_Engine/hpp/EntityManager.hpp"
#include "myEventBoss.hpp"

class Enemy3
{
    public:
        Enemy3(std::unique_ptr<EntityManager>& admin, int x, int y);
        float getX() {
            return _pos->getX();
        }
        void setVecX(float x) {
            _vec->setVectorX(x);
        }

        int getHp() {
            return _hp->getHp();
        }
    private:
        std::unique_ptr<EntityManager>& _admin;
        ComponentR _pos;
        ComponentR _vec;
        ComponentR _hp;
};