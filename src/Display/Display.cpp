#include "Display.hpp"

namespace UnLOGO
{

    void Display::windowCreate(const sf::VideoMode& videoMode)
    {
        window.create(videoMode);
    }

    bool Display::isWindowOpen()
    {
        return window.isOpen();
    }

    void Display::update()
    {
        window.update();
        window.draw(drawableElements);
    }

}
