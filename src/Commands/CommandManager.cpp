#include "CommandManager.hpp"

#include "CommandKeeper.hpp"
#include "CommandInputParser.hpp"

#include "StdCommands/MoveCommand.hpp"

namespace UnLOGO
{
    void CommandManager::manageInput(const std::string& input)
    {
        auto parser = CommandInputParser(input); // or make it as CommandManager field
        
        auto* command = CommandKeeper::Get(parser.getCommandType());

        if (command != nullptr)
            (*command)->execute(parser.getCommandArgument(command));
    }
}