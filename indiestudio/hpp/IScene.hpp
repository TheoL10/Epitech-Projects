#pragma once

#include "Entity.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <memory>

class IScene
{
    public:
        virtual ~IScene() = default;
        virtual void draw() = 0;
        virtual void update() = 0;
        virtual void setMap(int) = 0;
        virtual void setMap(int, std::vector<int>) = 0;
        virtual void setLvl(int) = 0;
        virtual void setLvls(int) = 0;
        virtual void setControlers(int) = 0;
};