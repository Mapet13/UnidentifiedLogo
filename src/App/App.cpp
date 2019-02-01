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
            checkInput();
        }
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