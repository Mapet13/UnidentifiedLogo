#pragma once

#include "Window/Window.hpp"

#include <thread>

namespace UnLOGO
{

    class App
    {
    public:
        ~App();

        void run();

    private:
        Window window;
        std::string input;
        std::thread inputThread;

        void init();
        void getInput(std::string& input);
        void checkInput();

    };

}
