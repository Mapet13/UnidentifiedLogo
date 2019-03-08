#pragma once

#include <SFML/Graphics/Color.hpp>

#include "Display/Drawable.hpp"

namespace UnLOGO
{

    class Board : public Drawable<Prority::back>
    {
    public:
        const sf::Color& getBackgroundColor() const  { return backgroundColour; };
        
        void setBackgroudColor(const sf::Color& bc)  { backgroundColour = bc; };
        void setBackgroundDefoultColor()             { backgroundColour = defaultColor; };

    private:
        virtual void draw(sf::RenderTarget& target, [[maybe_unused]]sf::RenderStates states) const
        {
            target.clear(backgroundColour);   
        }

        const sf::Color defaultColor { sf::Color::White };
        sf::Color backgroundColour { defaultColor };
    };

}