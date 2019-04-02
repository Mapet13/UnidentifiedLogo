#pragma once

#include <SFML/Graphics/Color.hpp>

#include "Display/Drawable.hpp"

namespace UnLOGO
{

    class Board : public Drawable<Prority::back>
    {
    public:
        const sf::Color& getBackgroundColor() const;
        
        void setBackgroudColor(const sf::Color& bc);
        void setBackgroundDefoultColor();

    private:
        virtual void draw(sf::RenderTarget& target, [[maybe_unused]]sf::RenderStates states) const;

        const sf::Color defaultColor { sf::Color::White };
        sf::Color backgroundColour { defaultColor };
    };

}