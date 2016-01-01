#pragma once

#include <windows.h>
#include "logger.hpp"

namespace OpenFF7
{
    void FatalExit(const char* msg)
    {
        LOG_ERROR("Fatal exit: " << msg);
        MessageBoxA(NULL, msg, "OpenFF7 fatal error", MB_OK | MB_ICONEXCLAMATION);
        exit(-1);
    }
}
