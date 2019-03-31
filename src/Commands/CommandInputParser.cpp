#include "CommandInputParser.hpp"

#include "Utilities/Log.hpp"

namespace UnLOGO
{

    CommandInputParser::CommandInputParser(const std::string& input)
    {

    }

    std::string CommandInputParser::getCommandType() const
    {
        return commandType;
    }

    std::any CommandInputParser::getCommandArgument(CommandKeeper::Command_t* command)
    {
        
    }

}


