#pragma once

#include <thread>

namespace UnLOGO
{

    class Input
    {
    public:
        ~Input();

        void init();
        std::string& getInput();

    private:
        void getInput(std::string& input);

        std::string input { "" };
        std::thread inputThread;
        bool initalized { false };
    };

}