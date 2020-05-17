#include "main.h"
#include <fstream>
#include <string>

void LOG(std::string text)
{
    std::ofstream file("raknet-hook.log", std::fstream::out | std::fstream::app);
    file << text << std::endl;
    file.close();
}

bool IsInitialized()
{
    DWORD g_dwSAMPAddr = reinterpret_cast<unsigned long>(GetModuleHandleA("samp.dll"));

    if (!g_dwSAMPAddr)
        return false;

    stSAMP* g_SAMP = *reinterpret_cast<stSAMP**>(g_dwSAMPAddr + SAMP_INFO_OFFSET);

    if (!g_SAMP)
        return false;

    stChatInfo* g_Chat = *reinterpret_cast<stChatInfo**>(g_dwSAMPAddr + SAMP_CHAT_INFO_OFFSET);

    if (!g_Chat)
        return false;

    stInputInfo* g_Input = *reinterpret_cast<stInputInfo**>(g_dwSAMPAddr + SAMP_CHAT_INPUT_INFO_OFFSET);

    if (!g_Input)
        return false;

    stMiscInfo* g_Misc = *reinterpret_cast<stMiscInfo**>(g_dwSAMPAddr + SAMP_MISC_INFO);

    if (!g_Misc)
        return false;

    stScoreboardInfo* g_Scoreboard = *reinterpret_cast<stScoreboardInfo**>(g_dwSAMPAddr + SAMP_SCOREBOARD_INFO);

    if (!g_Scoreboard)
        return false;

    if (!g_SAMP->pRakClientInterface)
        return false;

    g_RakClient = new RakClient(g_SAMP->pRakClientInterface);
    g_SAMP->pRakClientInterface = new HookedRakClientInterface();

    stVehiclePool* g_Vehicles = g_SAMP->pPools->pVehicle;
    stPlayerPool* g_Players = g_SAMP->pPools->pPlayer;

    return true;

}

void __cdecl MainThread(void*)
{
    while (true)
    {
        Sleep(0);
        if (IsInitialized())
            break;
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