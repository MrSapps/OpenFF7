#include "OpenFF7.hpp"
#include "Hooks.hpp"
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>

// This is how our dll gets loaded by the real FF7.exe
extern "C"
{
    // We don't even have to proxy to the real call as these functions are never used by the real FF7.exe
    // when using the external OpenGL graphics renderer.
    __declspec(dllexport) HRESULT DirectDrawCreate(void* lpGUID, void* lplpDD, void* pUnkOuter)
    {
        OpenFF7::FatalExit("Didn't expect DirectDrawCreate to ever be called");
        return 0;
    }

    __declspec(dllexport) HRESULT DirectDrawEnumerateA(void* lpCallback, void* lpContext)
    {
        OpenFF7::FatalExit("Didn't expect DirectDrawEnumerate to ever be called");
        return 0;
    }
}

int __stdcall NewWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    OpenFF7::FatalExit("WinMain");
    return 0;
}

// 0x0040B6E0 start
// 0x0040B82D WinMain
// 0x0040B82D call to WinMain from start
void HookFF7WinMain()
{
    TRACE_ENTRYEXIT;
    HookInternalFunc(0x0040B82D, (unsigned int)NewWinMain);
}

static void SetStdOutToNewConsole()
{
    // Allocate a console for this app
    AllocConsole();

    // Redirect unbuffered STDOUT to the console
    long lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
    int hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    FILE* fp = _fdopen(hConHandle, "w");
    *stdout = *fp;

    setvbuf(stdout, NULL, _IONBF, 0);
}

BOOL WINAPI DllMain(
    _In_ HINSTANCE hinstDLL,
    _In_ DWORD     fdwReason,
    _In_ LPVOID    lpvReserved
    )
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        // Open Console window for logging
        // TODO: Colours in logging don't work on AllocConsole for some reason
        SetStdOutToNewConsole();

        // When FF7 loads this proxy ddraw.dll we hijack its winmain to gain control
        HookFF7WinMain();
    }
    return TRUE;
}
