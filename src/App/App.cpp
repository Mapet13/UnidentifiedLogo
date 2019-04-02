#include "App.hpp"

#include "Utilities/Log.hpp"

namespace UnLOGO
{

    App::~App()
    {
        LOG("Shutting down the application");
    }

    void App::run()
    {
        LOG("Initializing the application");
            init();
        LOG("Application has been Initialized");

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
        
            inp.clear();
        }
    }

}