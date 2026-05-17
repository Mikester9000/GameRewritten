// ============================================================
// FILE: src/logger/Logger.hpp
// SYSTEM: Logger.hpp
// SYSTEM: logging macros and logger implementation only

#pragma once
#include <string>
#include <windows.h>

// Simple logger — writes to Visual Studio Output window.
// Usage: LOG_INFO("message"), LOG_WARN("message"), LOG_ERROR("message")

class Logger
{
public:
    static void Info(const std::string& message);
    static void Warn(const std::string& message);
    static void Error(const std::string& message);
};

#define LOG_INFO(msg)  Logger::Info(std::string("[INFO]  ") + msg)
#define LOG_WARN(msg)  Logger::Warn(std::string("[WARN]  ") + msg)
#define LOG_ERROR(msg) Logger::Error(std::string("[ERROR] ") + msg)