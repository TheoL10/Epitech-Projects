#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <string>

#include <type_traits>

#include "System.hpp"
#include "Component.hpp"

class Entity;

using EntityR = std::unique_ptr<Entity>&;
using ComponentR = std::shared_ptr<IComponent>;

#include "System_Physics.hpp"
#include "System_Display.hpp"
#include "System_Event.hpp"
#include "System_Shoot.hpp"
#include "System_Anim.hpp"
#include "System_Colision.hpp"

#include "EntityType.hpp"

#include "SoundManager.hpp"

class EntityManager
{
    public:
        EntityManager(unsigned int width, unsigned int height, std::string name, bool isServ);
        void update();
        std::unique_ptr<Entity>& addEntity();
        void removeEntity(std::unique_ptr<Entity>& entity);
        void removeEntityFromComp(std::shared_ptr<IComponent>& comp);
        std::vector<std::shared_ptr<IComponent>>& getComponentsList() {
            return _componentsList;
        }
        int howMuchComponents() {return _componentsList.size();}
        int howMuchSystems() {return _systemsList.size();}
        bool isOpen() { return _window.isOpen(); }
        void changeFps(int fps) { _window.setFramerateLimit(fps); }
        sf::Vector2u getSizeWindow() { return _wSize; }

        TextureManager& getTextureManager() { return _textureManager; }
        SoundManager& getSoundManager() { return _soundManager; }

        int getCurrScene() { return _currScene; }
        void setScene(int idScene) { _currScene = idScene; }

        void setKeyboardInputs(std::map<int, bool[100]> inputs) {
            _systemsList[0]->setKeyboardsInput(inputs);
        }

        int getAlliesAlive()
        {
            int nbAlly = 0;
            for (std::size_t i = 0; i < _componentsList.size(); i++) {
                if (compareType<ColisionComponent>(_componentsList[i])) {
                    if (_componentsList[i]->getEntityType() == ALLY)
                        nbAlly++;
                }
            }
            return nbAlly;
        }

        bool getIsServ() { return _isServ; }

        template <typename T>
        bool compareType(std::shared_ptr<IComponent> comp) {
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

    private:
        std::vector<std::unique_ptr<ISystem>> _systemsList;
        std::vector<std::shared_ptr<IComponent>> _componentsList;
        std::map<int, std::unique_ptr<Entity>> _entitiesList;
        int _entityId = 0;

        TextureManager _textureManager;
        SoundManager _soundManager;
        int _currScene = 0;

        sf::RenderWindow _window;
        sf::Vector2u _wSize = {0, 0};
        sf::Clock _clock;
        sf::Music _music;
        bool _isMusicPlaying = false;
        bool _isServ = false;
};

class Entity
{
    public:
        Entity(EntityManager& manager, int id) : _manager(manager), _componentsList(manager.getComponentsList()), _id(id) {}

        template <typename T, typename... TArgs>
        ComponentR& addComponent(TArgs&&... mArgs)
        {
            std::shared_ptr<T> comp = std::make_shared<T>(_components, _manager, std::forward<TArgs>(mArgs)...);
            _componentsList.emplace_back(comp);
            _components.emplace_back(comp);

            return _components.back();
        }

        template <typename T>
        ComponentR& getComponent() {
            int id = findInComponents<T>();
            return _components[id];
        }

        std::vector<std::shared_ptr<IComponent>>& getSiblings() { return _components; }
        int getId() {return _id;}
        int howMuchComponents() {return _componentsList.size();}

        template <typename T>
        static bool compareType(std::shared_ptr<IComponent> comp) {
            IComponent* x = comp.get();
            if (dynamic_cast<T*>(x) != nullptr)
                return true;
            return false;
        }

        template <typename T>
        int findInComponents() {
            for (std::size_t i = 0; i < _components.size(); i++)
                if (compareType<T>(_components[i]))
                    return i;
            return -1;
        }
            
    private:
        EntityManager& _manager;
        std::vector<std::shared_ptr<IComponent>>& _componentsList;
        int _id;
        std::vector<std::shared_ptr<IComponent>> _components;
};