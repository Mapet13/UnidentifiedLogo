#include "Window.hpp"

#include <SFML/Window/Event.hpp>

#include "Utilities/Log.hpp"

namespace UnLOGO
{

    void Window::create(const sf::VideoMode& videoMode)
    {
        window.create(videoMode, "UnLOGO");
        LOG("Window created (", videoMode.width, "x", videoMode.height, ")");
    }

    bool Window::isOpen()
    {
        return window.isOpen();
    }

    void Window::update()
    {
        window.clear();
        draw();   
        window.display();
        handleEvents();
    }

    void Window::draw()
    {

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
