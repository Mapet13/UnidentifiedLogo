#pragma once

#include <SFML/Graphics/Color.hpp>

namespace UnLOGO
{

    class Board
    {
    public:
        const sf::Color& getBackgroundColor() const  { return backgroundColour; };
        
        void setBackgroudColor(const sf::Color& bc)  { backgroundColour = bc; };
        void setBackgroundDefoultColor()             { backgroundColour = defaultColor; };

    private:
        const sf::Color defaultColor { sf::Color::White };
        sf::Color backgroundColour { defaultColor };
    };

}