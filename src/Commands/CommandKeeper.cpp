#include "CommandKeeper.hpp"

namespace UnLOGO 
{

    std::unordered_map<std::string, CommandKeeper::Command_t> CommandKeeper::commands;

    bool CommandKeeper::Register(const std::string& name, Command_t commandPtr)
    {
        if (auto it = commands.find(name); it == commands.end()) {
            commands[name] = std::move(commandPtr);
            return true;
        }
        return false;
    }

    std::unique_ptr<Command>* CommandKeeper::Get(const std::string& name)
    {
        if (auto it = commands.find(name); it != commands.end()) 
            return &it->second;

        return nullptr;
    }

}