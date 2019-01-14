#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>

#include "Config.hpp"

class Logger
{
public:

    template <typename... Args>
    void log(const char* file, int line, Args&&... args)
    {    
        #ifdef Debug
            getCurrentTime();
            std::sprintf(buffer, "[%s] [%s:%i] ", tmBuffer, file, line);
            std::cerr << buffer;
            if constexpr (sizeof...(Args) != 0) (std::cerr << ... << std::forward<Args>(args));
            std::cerr << std::endl;
        #endif
    }

private:

    void getCurrentTime()
    {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        strftime(tmBuffer, sizeof(tmBuffer), "%H:%M:%S", &tm);
    }

    char buffer[128];
    char tmBuffer[64];
};

inline Logger* logger = new Logger; 

#define LOG(...) { logger->log( __FILE__, __LINE__, __VA_ARGS__); }
