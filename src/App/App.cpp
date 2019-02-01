#include "App.hpp"

#include <iostream>

namespace UnLOGO
{

    App::~App()
    {
        inputThread.detach();
    }


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
        inputThread = std::thread(&App::getInput, this, std::ref(input));
    }

    void App::getInput(std::string& input)
    {
        while(true) {
            std::getline(std::cin, input);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

    void App::checkInput()
    {
        if(!input.empty()) {
            std::cout << input << "\n\n\n"; // for testing
            input.clear();
        }
    }

}