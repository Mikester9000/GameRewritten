// ============================================================
// FILE: src/logger/Logger.cpp
// SYSTEM: Logger.cpp
// SYSTEM: logging macros and logger implementation only

#include "Logger.hpp"
#include <sstream>

void Logger::Info(const std::string& message)
{
    std::string line = message + "\n";
    OutputDebugStringA(line.c_str());
}

void Logger::Warn(const std::string& message)
{
    std::string line = message + "\n";
    OutputDebugStringA(line.c_str());
}

void Logger::Error(const std::string& message)
{
    std::string line = message + "\n";
    OutputDebugStringA(line.c_str());
}