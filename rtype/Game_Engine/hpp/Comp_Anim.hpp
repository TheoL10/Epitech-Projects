#pragma once
#include "Component.hpp"
#include "Comp_TextSprite.hpp"

class AnimComponent : public Component {
    public:
        AnimComponent(std::vector<std::shared_ptr<IComponent>>& sibling, EntityManager& admin);

        std::vector<std::shared_ptr<IComponent>>& getSiblings() {
            return _siblings;
        }

        void setAnime(bool isAnime) { _isAnime = isAnime; }
        bool getAnime() { return _isAnime; }

        void setIdleAnim(sf::IntRect rect, int nbFrame, float frequency, bool isLoop);
        void setKeysAnim(sf::Keyboard::Key key, sf::IntRect rect, int nbFrame, float frequency, bool isOnce, bool isMaintain);
        void setCurrAnim(AnimInfos curr) {
            if (curr.isIdle != _currInfos.isIdle)
                _currInfos = curr;
        }
        void setCurrAnim() {
            if (!_currInfos.isIdle)
                _currInfos = _idleInfos;
        }

        std::vector<sf::Keyboard::Key> getKeysAnim() {
            std::vector<sf::Keyboard::Key> keys;
            for (auto const& x : _keysInfos)
                keys.push_back(x.first);
            return keys;
        }
        void wantKeysAnim(sf::Keyboard::Key key, bool wantToAnim) {
            _keysInfos[key].wantToAnim = wantToAnim;
        }

        std::map<sf::Keyboard::Key, AnimInfos> getKeysInfos() { return _keysInfos; }
        AnimInfos& getCurrAnimInfos() { return _currInfos; }

    /*
        void setCurrFrame(int currFrame) {_currFrame = currFrame;}
        int getCurrFrame() { return _currFrame; }
        
        void setLoop(bool loop) { _isLoop = loop; }
        bool getLoop() { return _isLoop; }

        void setFramePerSecond(float framePerSecond) { _framePerSecond = framePerSecond; }
        float getFramePerSecond() { return _framePerSecond; }


        sf::Time getTimeBeforeLastFrame() {
            return _timeBeforeLastFrame;
        }
        void setFrameTime() { 
            _timeBeforeLastFrame = _clock.getElapsedTime();
        }
        void resetFrameTime() {
            _clock.restart();
            _timeBeforeLastFrame = sf::Time::Zero;
        }
    */



    private:
        std::vector<std::shared_ptr<IComponent>>& _siblings;
        EntityManager& _admin;

        bool _isAnime = true;

        AnimInfos _currInfos;
        AnimInfos _idleInfos;
        std::map<sf::Keyboard::Key, AnimInfos> _keysInfos;

        /*
        float _framePerSecond = 1;
        int _currFrame = 0;

        bool _isLoop = true;

        sf::Clock _clock;
        sf::Time _timeBeforeLastFrame;
        */
};