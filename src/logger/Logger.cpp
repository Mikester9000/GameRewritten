// ============================================================
// FILE: src/logger/Logger.cpp
// SYSTEM: Logger
// ROLE: logging macros and logger implementation only
// DO NOT: Modify unrelated systems or break subsystem boundaries.
// OWNS: Logger module behavior and local implementation details.
// ============================================================

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
