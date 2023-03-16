#include "../hpp/System_Anim.hpp"

void AnimSystem::update(sf::Time elapsed)
{
    (void)elapsed;
    for (std::size_t i = 0; i < _componentsList.size(); i++) {
        if (compareType<AnimComponent>(_componentsList[i])) {
            std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[i]->getSiblings();
            int idScene = findInSiblings<SceneComponent>(siblings);
            if (idScene == -1 || siblings[idScene]->getIdScene() == _admin.getCurrScene()) {
                if (_componentsList[i]->getAnime()) {
                    manageAnim(i);
                    makeAnim(i);
                }
            }
        }
    }
}

void AnimSystem::manageAnim(int id)
{
    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[id]->getSiblings();

    std::map<sf::Keyboard::Key, AnimInfos> keysInfos = _componentsList[id]->getKeysInfos();

    sf::Keyboard::Key key = sf::Keyboard::Unknown;

    for (auto const& x : keysInfos) {
        if (x.second.wantToAnim) {
            key = x.first;
            break;
        }
    }

    if (key != sf::Keyboard::Unknown)
        _componentsList[id]->setCurrAnim(keysInfos[key]);
    else
        _componentsList[id]->setCurrAnim();
}

void AnimSystem::makeAnim(int id)
{
    std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[id]->getSiblings();
    int idText = findInSiblings<TextureSpriteComp>(siblings);

    AnimInfos& infos = _componentsList[id]->getCurrAnimInfos();

    sf::Time frameTime = sf::seconds(1.0f / infos.frequency);
    if (infos.clock.getElapsedTime() > frameTime) {
        infos.clock.restart();

        if (infos.isMaintain && (infos.currFrame + 1) == infos.nbFrame)
            infos.currFrame = infos.nbFrame - 1;
        else
            infos.currFrame = (infos.currFrame + 1) % infos.nbFrame;


        siblings[idText]->setTextureRect({
            infos.rect.left + infos.currFrame * infos.rect.width, 
            infos.rect.top,
            infos.rect.width,
            infos.rect.height
        });


        // Cas ou idle est joué qu'une fois
        if (infos.isIdle && !infos.isLoop && (infos.currFrame + 1) == infos.nbFrame) {
            _admin.removeEntityFromComp(_componentsList[id]);
        }

        // Cas ou key est joué qu'une fois
        if (!infos.isIdle && infos.isOnce && (infos.currFrame + 1) == infos.nbFrame) {
            _componentsList[id]->setCurrAnim();
        }
    }


    //infos.isLoop = !infos.isLoop;
/*
    int nbFrame = siblings[idText]->getNbFrame();

    bool isLoop = _componentsList[id]->getLoop();

    _componentsList[id]->setFrameTime();

    float _framePerSecond = _componentsList[id]->getFramePerSecond();
    sf::Time currTime = _componentsList[id]->getTimeBeforeLastFrame();
    sf::Time frameTime = sf::seconds(1.0f / _framePerSecond);

   

    if (currTime > frameTime) {
         _componentsList[id]->resetFrameTime();

        int currFrame = _componentsList[id]->getCurrFrame();

        if (!isLoop && (currFrame + 1) >= nbFrame) {
            _admin.removeEntityFromComp(_componentsList[id]);
            return;
        }

        int newCurrFrame = (currFrame + 1) % nbFrame;

        siblings[idText]->setFrame(newCurrFrame);

        _componentsList[id]->setCurrFrame(newCurrFrame);
    }
*/
}