#pragma once

#include "Commands/Command.hpp"
#include "Commands/CommandKeeper.hpp"

namespace UnLOGO 
{

    class ForwardCommand : public StdCommand
    {
        REGISTER(ForwardCommand, "FORWARD")
    public:
        void execute() override {}
    };

    class BackCommand : public StdCommand
    {
        REGISTER(BackCommand, "BACK")
    public:
        void execute() override {}
    };

}