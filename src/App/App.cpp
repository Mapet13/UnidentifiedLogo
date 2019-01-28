#include "App.hpp"

#include <iostream>
#include <future>
#include <thread>

namespace UnLOGO
{

    App::App()
    {

    }

    App::~App()
    {
        inputThread.detach();
    }


    void App::run()
    {
        win.create(sf::VideoMode(500, 500));
        while (win.isOpen()) {
            win.update();
        }
    }

    void App::getInput(std::string& input)
    {
        while(true) {
            std::getline(std::cin, input);
            std::cout << input << "\n\n\n"; // for testing
            input.clear();
        }
    }

}