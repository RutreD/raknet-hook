#include "main.h"

SAMPFramework* pSAMP = new SAMPFramework();

void LOG(std::string text)
{
    std::ofstream file("raknet-hook.log", std::fstream::out | std::fstream::app);
    file << text;
    file.close();
}

void __cdecl MainThread(void*)
{
    while (true)
    {
        if (pSAMP->tryInit())
            break;
        Sleep(0);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            _beginthread(MainThread, NULL, nullptr);
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}