#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Board/Board.hpp"

namespace UnLOGO
{

    class Window
    {
    public:
        void create(const sf::VideoMode& videoMode);
        bool isOpen();
        void update();

    private:
        void draw();
        void handleEvents();

        sf::RenderWindow window;
        Board board;
    };

}