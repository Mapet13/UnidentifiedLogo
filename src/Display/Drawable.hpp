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
        Drawable()
        {
            DrawableElements::addElement((static_cast<int>(prority)), &Drawable::draw);
        }

    };

}