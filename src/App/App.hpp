#pragma once

#include "Display/Display.hpp"
#include "Input/Input.hpp"
#include "Commands/CommandManager.hpp"

#include <thread>
#include <tuple>

namespace UnLOGO
{

    class App
    {
    public:
        ~Application();
        void run();

    private:
        void init();
        void checkInput(); // I think that is shouldn't be here || I guess that maybe it is a correct place xD

        Display display;
        Input input;
        CommandManager commandManager;
    };

}
