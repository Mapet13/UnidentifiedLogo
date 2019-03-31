#include "App.hpp"

#include "Utilities/Log.hpp"

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
            LOG(inp, "\n\n\n"); // for testing

            commandManager.manageInput(inp);

            inp.clear();
        }
    }

}