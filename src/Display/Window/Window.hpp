#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace UnLOGO
{

    class Window
    {
    public:
        void create(const sf::VideoMode& videoMode);
        void update();
        bool isOpen();
        void draw(const sf::Drawable& drawable);

    private:
        void handleEvents();

        sf::RenderWindow window;
    };

}