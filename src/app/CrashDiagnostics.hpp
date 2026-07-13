#pragma once
// CrashDiagnostics.hpp
// Installs an unhandled-exception filter (Windows SEH) and writes a
// minimal crash log including the last few logger lines and system info.

#include <string>

class CrashDiagnostics
{
public:
    // Call once at startup to install the exception handler.
    static void Install();

    // Returns the path to the crash log file.
    static std::string GetLogPath();

    // Write a diagnostic log manually (e.g. for assert failures).
    static void WriteDiagnostic(const std::string& reason);

private:
#ifdef _WIN32
    static long __stdcall UnhandledExceptionFilter(void* exceptionInfo);
#endif
};
