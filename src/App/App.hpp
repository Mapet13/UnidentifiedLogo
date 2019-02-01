#pragma once

#include "Window/Window.hpp"

#include <thread>
#include <functional>

namespace UnLOGO
{

    class App
    {
    public:
        App();
        ~App();

        void run();

    private:
        Window win;
        std::string input;
        std::thread inputThread{&App::getInput, this, std::ref(input)};

        void getInput(std::string& input);
        void checkInput();

    };

}
