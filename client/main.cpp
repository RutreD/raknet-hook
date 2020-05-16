#include "main.h"
#include <fstream>
#include <string>

cSAMP* SAMP = new cSAMP();

void LOG(std::string text)
{
    std::ofstream file("raknet-hook.log");
    file << text << std::endl;
    file.close();
}

/*void HandleRPCPacketFunc(unsigned char id, RPCParameters* rpcParams, void(*callback) (RPCParameters*))
{
    if (rpcParams != nullptr && rpcParams->numberOfBitsOfData >= 8)
    {
        switch (id)
        {
            case RPC_SetPlayerHealth:
            case RPC_ClientMessage:
                break;
        }
    }
}*/

bool OnReceivePacket(Packet* packet)
{
    LOG("NEW PACKET");
    return true;
}

bool OnSendPacket(BitStream* parameters, PacketPriority priority, PacketReliability reliability, char orderingChannel)
{
    return true;
}

bool OnSendRPC(int uniqueID, BitStream* parameters, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp)
{
    return true;
}

void __cdecl MainThread(void*)
{
    while (true)
    {
        static bool init = false;
        if (SAMP->IsInitialized() && !init)
        {
            init = true;
            LOG("init");
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            LOG("load");
            _beginthread(MainThread, NULL, nullptr);
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}