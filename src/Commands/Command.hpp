#pragma once

#include <string>
#include <memory>
#include <any>
#include <optional>

namespace UnLOGO 
{
    #define REGISTER(T, Name)                                                                                  \
        public:  static std::string GetStringName() { return Name; }                                               \
        private: inline static bool Registered = CommandKeeper::Register(Name, std::move(std::make_unique<T>()));

    #define DEFINE_(T, Name)                                                                                  \
        public:  static std::string GetStringName() { return Name; }                                               \
        private: inline static bool Registered = CommandKeeper::Register(Name, std::move(std::make_unique<T>()));

    #define CommandParam_t [[maybe_unused]] std::any

    class Command
    {
    public:
        Command() = default;
        virtual ~Command() = default;
         
        virtual void execute(CommandParam_t param) {};
    };

}
