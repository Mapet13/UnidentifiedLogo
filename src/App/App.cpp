#include "App.hpp"

#include <iostream>

namespace UnLOGO
{

    void App::run()
    {
        init();

        while (display.isWindowOpen()) {
            display.update();
            checkInput();
        }
    }

    void App::init()
    {
        display.windowCreate(sf::VideoMode(500, 500));
        input.init();
    }

    void App::checkInput()
    {
        auto& inp = input.getInput();
        if (!inp.empty()) {
            std::cout << inp << "\n\n\n"; // for testing
            inp.clear();
        }
    }

}