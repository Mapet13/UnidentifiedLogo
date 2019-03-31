#pragma once

#include <string>
#include <any>

#include "CommandKeeper.hpp"

namespace UnLOGO
{
    class CommandInputParser
    {
    public:
        CommandInputParser(const std::string& input); // takes input (and parse it?)

        std::string getCommandType() const;
        std::any getCommandArgument(CommandKeeper::Command_t* command); //get command formate style

    private:
        std::string commandType;

    };

}
