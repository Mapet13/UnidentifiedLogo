#pragma once

#include <list>
#include <map>
#include <functional>

#include "SFML/Graphics/Drawable.hpp"

namespace UnLOGO
{

    class DrawableElements : public sf::Drawable
    {
        using drawFunction_t = std::function<void(sf::RenderTarget&, sf::RenderStates)>;

    public:
        static void addElement(int Prority, drawFunction_t func);

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        inline static std::map<int, std::list<drawFunction_t>> drawFunctions;
    };

}