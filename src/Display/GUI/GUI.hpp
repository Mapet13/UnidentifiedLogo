#pragma once

#include "Display/Board/Board.hpp"

namespace UnLOGO
{

    class GUI
    {
    public:
        const sf::Color& getBackgroundColor() const  { return board.getBackgroundColor(); };
        void setBackgroudColor(const sf::Color& bc)  { board.setBackgroudColor(bc); };
        void setBackgroundDefoultColor()             { board.setBackgroundDefoultColor(); };

    private:
        Board board;

    };

}