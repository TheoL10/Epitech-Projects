#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>

#include "Component.hpp"

class ISystem
{
    public:
        virtual ~ISystem() = default;
        virtual void update() = 0;
        virtual void update(sf::Time) = 0;
        virtual std::string getNameSys() = 0;
        virtual void setKeyboardsInput(std::map<int, bool[100]>) = 0;
};

class System : public ISystem
{
    public:
        ~System() {}
        void update() {}
        void update(sf::Time) {}
        std::string getNameSys() {return "NON";}
        void setKeyboardsInput(std::map<int, bool[100]>) {}

        template <typename T>
        static bool compareType(std::shared_ptr<IComponent> comp) {
            IComponent* x = comp.get();
            if (dynamic_cast<T*>(x) != nullptr)
                return true;
            return false;
        }

        template <typename T>
        int findInSiblings(std::vector<std::shared_ptr<IComponent>>& comp) {
            for (std::size_t i = 0; i < comp.size(); i++)
                if (compareType<T>(comp[i]))
                    return i;
            return -1;
        }
};