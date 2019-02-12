#include "Input.hpp"

#include "iostream"

namespace UnLOGO
{

    Input::~Input()
    {
        //can't be call before the init
        inputThread.detach();
    }

    void Input::init()
    {
        inputThread = std::thread([this](std::string& input){ this->getInput(input); }, std::ref(input));
    }

    std::string& Input::getInput()
    {
        return input;
    }

    void Input::getInput(std::string& input)
    {
        while (true) {
            std::getline(std::cin, input);
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }

}
