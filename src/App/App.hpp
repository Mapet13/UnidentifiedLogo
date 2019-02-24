#pragma once

#include "Window/Window.hpp"
#include "Input/Input.hpp"

#include <thread>
#include <tuple>

namespace UnLOGO
{

    class App
    {
    public:
        void run();

    private:
        void init();
        void checkInput();

        Window window;
        Input input;

        ModuleHolder<Window*, Input*, App*> modules;
    };

}
