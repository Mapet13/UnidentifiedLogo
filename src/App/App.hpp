#pragma once

#include "Display/Display.hpp"

#include <thread>

namespace UnLOGO
{

    class App
    {
    public:
        ~App();
        void run();

    private:
        void init();
        void getInput(std::string& input);
        void checkInput();

        Display display;
        std::string input;
        std::thread inputThread;
    };

}