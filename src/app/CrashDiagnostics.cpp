// CrashDiagnostics.cpp
// Unhandled-exception crash log for Windows.

#include "CrashDiagnostics.hpp"

#include <cstdio>
#include <ctime>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <shlobj.h>
#endif

std::string CrashDiagnostics::GetLogPath()
{
#ifdef _WIN32
    char path[MAX_PATH] = {};
    if (SUCCEEDED(SHGetFolderPathA(nullptr, CSIDL_APPDATA, nullptr, 0, path)))
        return std::string(path) + "\\GameRewritten\\crash.log";
#endif
    return "crash.log";
}

void CrashDiagnostics::WriteDiagnostic(const std::string& reason)
{
    FILE* f = fopen(GetLogPath().c_str(), "a");
    if (!f) return;

    const time_t t = time(nullptr);
    char tbuf[64];
    ctime_s(tbuf, sizeof(tbuf), &t);
    fprintf(f, "[%s] CRASH: %s\n", tbuf, reason.c_str());
    fclose(f);
}

#ifdef _WIN32
long __stdcall CrashDiagnostics::UnhandledExceptionFilter(void* /*exceptionInfo*/)
{
    WriteDiagnostic("Unhandled exception caught by SEH filter");
    return 1; // EXCEPTION_EXECUTE_HANDLER
}

void CrashDiagnostics::Install()
{
    SetUnhandledExceptionFilter(
        reinterpret_cast<LPTOP_LEVEL_EXCEPTION_FILTER>(UnhandledExceptionFilter));
}
#else
void CrashDiagnostics::Install() {}
#endif
