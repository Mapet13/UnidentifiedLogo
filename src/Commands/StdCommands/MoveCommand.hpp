#pragma once

#include "Commands/Command.hpp"
#include "Commands/CommandKeeper.hpp"

namespace UnLOGO 
{

    class ForwardCommand : public Command
    {
        REGISTER(ForwardCommand, "FORWARD")

    public:
        void execute(CommandParam_t param) override {}
    };

    class BackCommand : public Command
    {
        REGISTER(BackCommand, "BACK")
        
    public:
        void execute(CommandParam_t param) override {}
    };

}