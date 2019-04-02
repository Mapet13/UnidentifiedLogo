#include "App.hpp"

#include "Utilities/Log.hpp"

namespace UnLOGO
{

    App::~Application()
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

    void App::checkInput() // probably that should be resolved in more optimized way
    {
        auto& inp = input.getInput();
        if (!inp.empty()) {
            LOG(inp, "\n\n\n"); // for testing

            commandManager.manageInput(inp); // that line is a reason why that func should be in App

            inp.clear();
        }
    }

}