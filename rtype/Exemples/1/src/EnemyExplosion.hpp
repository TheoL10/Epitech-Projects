#pragma once

#include "../../Game_Engine/hpp/EntityManager.hpp"
#include "../../Game_Engine/hpp/Comp_Position.hpp"
#include "../../Game_Engine/hpp/Comp_TextSprite.hpp"
#include "../../Game_Engine/hpp/Comp_Anim.hpp"
#include "../../Game_Engine/hpp/Comp_Event.hpp"
#include "../../Game_Engine/hpp/Comp_Scene.hpp"

class EntityManager;

class EnemyExplosion
{
    public:
        EnemyExplosion(EntityManager& admin, int x, int y);

        void setScale(float x, float y) {
            _scale->setScale(x, y);
        }
    private:
        ComponentR _scale;
        EntityManager& _admin;
};