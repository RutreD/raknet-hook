#include <Windows.h>
#include <fstream>
#include <string>

void LOG(std::string text)
{
    std::ofstream file("assistant.log");
    file << text << std::endl;
    file.close();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}