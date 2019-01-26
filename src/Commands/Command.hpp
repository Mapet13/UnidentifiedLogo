#pragma once

#include <string>
#include <memory>

namespace UnLOGO 
{

    #define REGISTER(T, Name)                                                                             \
    public:                                                                                               \
        static std::string GetStringName() { return Name; }                                               \
    private:                                                                                              \
        inline static bool Registered = CommandKeeper::Register(Name, std::move(std::make_unique<T>()));

    class Command
    {
    public:
        Command() = default;
        virtual ~Command() = default;
         
        //TODO: find a better way to do it
        virtual void execute() {};
        virtual void execute(int) {};
        virtual void execute(const std::string&) {};
    };

    class UsrCommand : public Command
    {};
    class StdCommand : public Command
    {};

}
