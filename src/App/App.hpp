#pragma once

#include "Modules/ModuleHolder.hpp"
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

        ModuleHolder::Modules = new std::tuple<Window*, Input*, App*>(window*, input*, this);
    };

}
