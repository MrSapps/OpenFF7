#pragma once

#include "OpenFF7.hpp"
#include <sstream>

static void HookInternalFunc(unsigned int aJmpOrCallAddr, unsigned int aNewJmpOrCallTarget)
{
    TRACE_ENTRYEXIT;

    LOG_INFO("Installing hook 0x" << std::hex << aNewJmpOrCallTarget << " for jmp or call at 0x" << std::hex << aJmpOrCallAddr);

    // Unwrite protect the memory page!
    DWORD flags = PAGE_READWRITE;
    DWORD oldFlags = 0;
    if (!VirtualProtect((LPVOID)aJmpOrCallAddr, 0x90, flags, &oldFlags))
    {
        const DWORD gle = GetLastError();
        std::stringstream str;
        str << "Failed to unwrite protect the memory, failed with: " << gle;
        OpenFF7::FatalExit(str.str().c_str());
    }

    // Skip JMP subtract JMP ADDR
    *((unsigned int *)(aJmpOrCallAddr + 1)) = (unsigned int)aNewJmpOrCallTarget - (aJmpOrCallAddr + 5);

    if (!VirtualProtect((LPVOID)aJmpOrCallAddr, 0x90, oldFlags, &flags))
    {
        const DWORD gle = GetLastError();
        std::stringstream str;
        str << "Failed to write protect the memory, failed with: " << gle;
        OpenFF7::FatalExit(str.str().c_str());
    }
}
