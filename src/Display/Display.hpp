#pragma once

#include "Window/Window.hpp"
#include "Board/Board.hpp"
#include "DrawableElements.hpp"

namespace UnLOGO
{

    class Display
    {
    public:
        void windowCreate(const sf::VideoMode& videoMode);
        bool isWindowOpen();
        void update();

    private:
        Window window;
        DrawableElements drawableElements;
        Board board;

    };

}