#pragma once

#include <functional>
#include "SFML/Graphics/Drawable.hpp"

#include "DrawableElements.hpp"

namespace UnLOGO
{

    enum class Prority
    {
       back = 0,
       mid = 1,
       front = 2
    };

    template <Prority prority>
    class Drawable : public sf::Drawable
    {
    public:
        Drawable() //Adds drawable's draw func into drawing container
        {
            using namespace std::placeholders;
            DrawableElements::addElement((static_cast<int>(prority)), std::bind(&Drawable::draw, this, _1, _2));
        }

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;

    };

}