#include "main.h"
#include <fstream>
#include <string>

void LOG(std::string text)
{
    std::ofstream file("assistant.log");
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