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
        void run();

    private:
        void init();
        void checkInput(); // I think that is shoudn't be here

        Display display;
        Input input;
        CommandManager commandManager;
    };

}
