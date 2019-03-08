#include "Window.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Utilities/Log.hpp"

namespace UnLOGO
{

    void Window::create(const sf::VideoMode& videoMode)
    {
        window.create(videoMode, "UnLOGO");
        LOG("Window created (", videoMode.width, "x", videoMode.height, ")");
    }

    void Window::update()
    {
        window.display();
        handleEvents();
    }

    bool Window::isOpen()
    {
        return window.isOpen();
    }

    void Window::handleEvents()
    {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

        }
    }

}
