#include "App.hpp"

#include <iostream>

namespace UnLOGO
{

    void App::run()
    {
        init();

        while (window.isOpen()) {
            window.update();
            checkInput();
        }
    }

    void App::init()
    {
        window.create(sf::VideoMode(500, 500));
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