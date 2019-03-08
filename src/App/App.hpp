#pragma once

#include "Display/Display.hpp"
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

        Display display;
        Input input;
    };

}
