#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <map>

#include "EntityType.hpp"
#include "TextureManager.hpp"

typedef struct AnimInfos_s {
    sf::IntRect rect;
    int nbFrame;
    float frequency = 1.0f;

    sf::Clock clock;
    sf::Time timeBefLastFrame;
    int currFrame = 0;

    bool isLoop = true;
    bool isOnce = false;
    bool isMaintain = false;

    bool wantToAnim = false;

    bool isIdle = true;
} AnimInfos;

class EntityManager;

class IComponent
{
    public:
        virtual ~IComponent() = default;
        virtual void init() = 0;
        virtual std::string getNameComp() = 0;
        virtual float getX() = 0;
        virtual float getY() = 0;
        virtual float getG() = 0;
        virtual sf::Sprite& getSprite() = 0;
        virtual void setPos(float x, float y) = 0;
        virtual std::vector<std::shared_ptr<IComponent>>& getSiblings() = 0;
        virtual float getVelocityX() = 0;
        virtual float getVelocityY() = 0;
        virtual void setVelocityX(float) = 0;
        virtual void setVelocityY(float) = 0;
        virtual void setFrame(int id) = 0;
        virtual void setFrameSize(int x, int y) = 0;
        virtual void setTextureRect(sf::IntRect) = 0;
        virtual void setScale(float scX, float scY) = 0;
        virtual void setMovX(float movX) = 0;
        virtual void setMovY(float movY) = 0;
        virtual float getMovX() = 0;
        virtual float getMovY() = 0;
        virtual sf::Vector2f getRealSize() = 0;
        virtual int getNbFrame() = 0;
        virtual void setLoop(bool loop) = 0;
        virtual bool getLoop() = 0;
        virtual sf::IntRect getTextRect() = 0;

        virtual bool getIsTextureSet() = 0;
        virtual void setTexture(sf::Texture text) = 0;
        virtual std::string getTextPath() = 0;

        virtual std::string getPath() = 0;
        virtual sf::Time getTimeBeforeLastShoot() = 0;
        virtual float getShootPerSecond() = 0;
        virtual float getSize() = 0;
        virtual void setShootTime() = 0;
        virtual void resetShootTime() = 0;
        virtual bool getWantToShoot() = 0;
        virtual void setWantToShoot(bool state) = 0;
        virtual void setShootPerSecond(float shootPerSec) = 0;
        virtual void setSize(float size) = 0;

        virtual float getVectorX() = 0;
        virtual float getVectorY() = 0;
        virtual void setVectorX(float x) = 0;
        virtual void setVectorY(float y) = 0;

        virtual void setAnime(bool isAnime) = 0;
        virtual void setFramePerSecond(float) = 0;
        virtual bool getAnime() = 0;
        virtual float getFramePerSecond() = 0;
        virtual sf::Time getTimeBeforeLastFrame() = 0;
        virtual void setFrameTime() = 0;
        virtual void resetFrameTime() = 0;
        virtual void setCurrFrame(int currFrame) = 0;
        virtual int getCurrFrame() = 0;

        virtual sf::Vector2f getScale() = 0;

        virtual void setEntityType(EntityType type) = 0;
        virtual EntityType getEntityType() = 0;

        virtual void onDeath() = 0;
        virtual void onRightScreen() = 0;
        virtual void onLeftScreen()  = 0;
        virtual void onColision(std::shared_ptr<IComponent>, std::shared_ptr<IComponent>, EntityType) = 0;

        virtual void setIdScene(int idScene) = 0;
        virtual int getIdScene() = 0;


        virtual std::vector<sf::Keyboard::Key> getKeysAnim() = 0;
        virtual void wantKeysAnim(sf::Keyboard::Key key, bool wantToAnim) = 0;
        virtual std::map<sf::Keyboard::Key, AnimInfos> getKeysInfos() = 0;
        virtual void setIdleAnim(sf::IntRect rect, int nbFrame, float frequency, bool isLoop) = 0;
        virtual void setKeysAnim(sf::Keyboard::Key key, sf::IntRect rect, int nbFrame, float frequency, bool isOnce, bool isMaintain) = 0;
        virtual AnimInfos& getCurrAnimInfos() = 0;
        virtual void setCurrAnim(AnimInfos curr) = 0;
        virtual void setCurrAnim() = 0;

        virtual void setPlayerId(int) = 0;
        virtual int getPlayerId() = 0;

        virtual void setSoundKey(sf::Keyboard::Key key, std::string path) = 0;
        virtual void setSoundDeath(std::string path) = 0;
        virtual void playSoundKeyboard(sf::Keyboard::Key key) = 0;
        virtual void playSoundDeath() = 0;
        virtual void playSoundShoot() = 0;
        virtual void setSoundShoot(std::string) = 0;
        virtual void setPathPlaying(std::string path) = 0;
        virtual std::string getPathPlaying() = 0;
        virtual void setAutoShoot(bool autoShoot) = 0;
        virtual bool getAutoShoot() = 0;
        virtual void setVecAutoShoot(sf::Vector2f vec) = 0;
        virtual sf::Vector2f getVecAutoShoot() = 0;
        virtual int getHp() = 0;
        virtual void setHp(int hp) = 0;
};


class Component : public IComponent
{
    public:
        ~Component() {};
        void init() {};
        float getX() {return 0.0;}
        float getY() {return 0.0;}
        float getG() {return 0.0;}
        float getVelocityX() {return 0.0;}
        float getVelocityY() {return 0.0;}
        void setVelocityX(float) {}
        void setVelocityY(float) {}
        std::string getNameComp() {return "";}
        sf::Sprite& getSprite() {sf::Sprite *s = new sf::Sprite; return *s;}
        void setPos(float, float) {}
        std::vector<std::shared_ptr<IComponent>>& getSiblings() {std::vector<std::shared_ptr<IComponent>> *a = new std::vector<std::shared_ptr<IComponent>>; return *a;}
        void setFrame(int) {}
        void setFrameSize(int, int) {}
        void setTextureRect(sf::IntRect) {}
        void setScale(float, float) {}
        void setMovX(float) {}
        void setMovY(float) {}
        float getMovX() { return 0.0f; }
        float getMovY() { return 0.0f; }
        sf::Vector2f getRealSize() { return sf::Vector2f(0.0f, 0.0f); }
        int getNbFrame() { return 0; };
        void setLoop(bool) {}
        bool getLoop() { return true; }
        sf::IntRect getTextRect() { return {0, 0, 0, 0}; }

        bool getIsTextureSet() { return false; };
        void setTexture(sf::Texture) {};
        std::string getTextPath() { return ""; };

        std::string getPath() { return ""; }
        sf::Time getTimeBeforeLastShoot() { return sf::Time::Zero; }
        float getShootPerSecond() { return 0.0f; }
        float getSize() { return 0.0f; }
        void setShootTime() {}
        void resetShootTime() {}
        bool getWantToShoot() { return false; }
        void setWantToShoot(bool) {}
        void setShootPerSecond(float) {}
        void setSize(float) {}

        sf::Vector2f getScale() {return {0.0f, 0.0f}; }

        float getVectorX() {return 0.0f;}
        float getVectorY() {return 0.0f;}
        void setVectorX(float) {}
        void setVectorY(float) {}

        void setAnime(bool) {}
        void setFramePerSecond(float) {}
        bool getAnime() {return false;}
        float getFramePerSecond() {return 0.0f;}
        sf::Time getTimeBeforeLastFrame() {return sf::Time::Zero;}
        void setFrameTime() {}
        void resetFrameTime() {}
        void setCurrFrame(int) {}
        int getCurrFrame() { return 0; }

        void setEntityType(EntityType) {}
        EntityType getEntityType() { return NEUTRAL; }

        void setIdScene(int) {}
        int getIdScene() { return 0; }

        void onDeath() {}
        void onRightScreen() {}
        void onLeftScreen() {}
        void onColision(std::shared_ptr<IComponent>, std::shared_ptr<IComponent>, EntityType) {}

        std::vector<sf::Keyboard::Key> getKeysAnim() {
            std::vector<sf::Keyboard::Key> keys;
            return keys;
        }
        void wantKeysAnim(sf::Keyboard::Key, bool) {}
        std::map<sf::Keyboard::Key, AnimInfos> getKeysInfos() {
            std::map<sf::Keyboard::Key, AnimInfos> map;
            return map;
        }
        void setIdleAnim(sf::IntRect, int, float, bool) {}
        void setKeysAnim(sf::Keyboard::Key, sf::IntRect, int, float, bool, bool) {}
        AnimInfos& getCurrAnimInfos() { AnimInfos *info = new AnimInfos; return *info; }
        void setCurrAnim(AnimInfos) {}
        void setCurrAnim() {}

        void setPlayerId(int) {}
        int getPlayerId() { return 0; }

        void setSoundKey(sf::Keyboard::Key, std::string) {}
        void setSoundDeath(std::string) {}
        void playSoundKeyboard(sf::Keyboard::Key) {}
        void playSoundDeath() {}
        void playSoundShoot() {}
        void setSoundShoot(std::string) {}
        void setPathPlaying(std::string) {}
        std::string getPathPlaying() { return ""; }
        void setAutoShoot(bool) {}
        bool getAutoShoot() { return false; }
        void setVecAutoShoot(sf::Vector2f) {}
        sf::Vector2f getVecAutoShoot() { return {0, 0}; }
        int getHp() { return 0; }
        void setHp(int) {}

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