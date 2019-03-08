#include "DrawableElements.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Drawable.hpp"

namespace UnLOGO
{

    void DrawableElements::addElement(int prority, DrawableElements::drawFunction_t func)
    {
        if (auto it = drawFunctions.find(prority); it != drawFunctions.end())
            it->second.emplace_back(func);
        else {
            drawFunctions.emplace(prority, std::list<drawFunction_t>());
            drawFunctions.find(prority)->second.emplace_back(func);
        }

    }

    void DrawableElements::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for (auto& it : drawFunctions) {
            for (auto& func : it.second)
                (this->*func)(target, states);
        }
    }

}