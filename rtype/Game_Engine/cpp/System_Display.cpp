#include "../hpp/System_Display.hpp"

void DisplaySystem::update(sf::Time elapsed)
{
    (void)elapsed;
    _window.clear();
    for (std::size_t i = 0; i < _componentsList.size(); i++) {
        if (compareType<TextureSpriteComp>(_componentsList[i])) {
            std::vector<std::shared_ptr<IComponent>> siblings = _componentsList[i]->getSiblings();
            int idScene = findInSiblings<SceneComponent>(siblings);
            if (idScene == -1 || siblings[idScene]->getIdScene() == _admin.getCurrScene()) {
                int idPos = findInSiblings<PositionComponent>(siblings);

                float x = idPos != -1 ? siblings[idPos]->getX() : 0;
                float y = idPos != -1 ? siblings[idPos]->getY() : 0;

                _componentsList[i]->getSprite().setPosition(sf::Vector2f(x, y));

                if (!_admin.getIsServ())
                    _window.draw(_componentsList[i]->getSprite());
            }
        }
    }
    _window.display();
}