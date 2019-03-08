#pragma once

#include "Window/Window.hpp"
#include "GUI/GUI.hpp"

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
        GUI gui;

    };

}