#pragma once

#include <memory>
#include <unordered_map>

#include "Command.hpp"

namespace UnLOGO 
{

    // static container of pointers to commands 
    class CommandKeeper
    {
    public:
        using Command_t = std::unique_ptr<Command>;

        CommandKeeper() = delete;

        static bool Register(const std::string& name, Command_t commandPtr);
        static Command_t* Get(const std::string& name); 

    private:
        static std::unordered_map<std::string, Command_t> commands;
    };

}