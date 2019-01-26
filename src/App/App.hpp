#pragma once

#include "Window/Window.hpp"

#include <thread>

namespace UnLOGO
{
    class App
    {
    public:
        App();

        void run();

    private:
        void winLoop();

        Window win;
        std::thread winThread {&App::winLoop, this};

    };
}
