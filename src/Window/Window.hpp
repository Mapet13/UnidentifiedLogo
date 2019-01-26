#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace UnLOGO
{

    class Window
    {
    public:
        void create(const sf::VideoMode& videoMode);
        bool isOpen();
        void update();

    private:
        sf::RenderWindow window;

        void draw();
        void handleEvents();
    };

}