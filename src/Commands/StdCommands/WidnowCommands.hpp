#pragma once

#include "Commands/Command.hpp"
#include "Commands/CommandKeeper.hpp"

namespace UnLOGO 
{

    class ClearScreenCommand : public StdCommand
    {
        REGISTER(ClearScreenCommand, "CLEARSCREEN")

    public:
        void execute(const std::string& rgb) override {}
    };

}