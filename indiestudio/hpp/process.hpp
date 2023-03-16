#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <memory>
#include <string>

#include "Block3D.hpp"
#include "Character.hpp"

class Process {
    public:
        Process() {};
        Process(std::map<std::string, Model>& models, std::map<std::string, ModelAnimation*>& anims);
        ~Process();
        void generate_arcade_map();
        void get_story_map(int lvl);
        void setup_map(std::vector<int>);
        std::vector<std::unique_ptr<Entity>>& getMap(int, std::vector<int>);
        void set_map(int id);
        void setup_skybox();
    private:
        std::vector<std::unique_ptr<Entity>> _finaleMap;
        std::array<std::array<int, 12>, 12> _intMap;
        std::map<std::string, Model> _models;
        std::map<std::string, ModelAnimation*> _anims;
        int _one_time = 0;
};
