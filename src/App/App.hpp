#pragma once

#include "Display/Display.hpp"
#include "Input/Input.hpp"

namespace UnLOGO
{

    class App
    {
    public:
        ~App();
        void run();

    private:
        void init();
        void checkInput();

        Display display;
        Input input;
    };

}