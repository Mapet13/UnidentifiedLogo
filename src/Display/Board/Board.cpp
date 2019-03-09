#include "Board.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

namespace UnLOGO
{
    const sf::Color& Board::getBackgroundColor() const  
    { 
        return backgroundColour; 
    }
        
    void Board::setBackgroudColor(const sf::Color& bc)  
    { 
        backgroundColour = bc; 
    }
    void Board::setBackgroundDefoultColor()             
    { 
        backgroundColour = defaultColor; 
    }

    void Board::draw(sf::RenderTarget& target, [[maybe_unused]]sf::RenderStates states) const
    {
        target.clear(sf::Color::White);   
    }
}