#include "App.hpp"

namespace UnLOGO
{
    App::App()
    {

    }

    void App::run()
    {
        win.create(sf::VideoMode(500, 500));
        winThread.join();
    }

    void App::winLoop()
    {
        while (win.isOpen()) {
            win.update();
        }
    }
}