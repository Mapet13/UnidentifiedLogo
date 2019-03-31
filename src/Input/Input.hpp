#pragma once

#include <thread>

namespace UnLOGO
{
    //Main input class: getting input from console on background thread
    class Input
    {
    public:
        ~Input(); //detach thread

        void init(); //initialize input thread
        std::string& getInput();

    private:
        void getInput(std::string& input); //looped thread function

        std::string input { "" };
        std::thread inputThread;
        bool initalized { false };
    };

}