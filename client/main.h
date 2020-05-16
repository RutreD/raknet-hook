#pragma once
#include <Windows.h>
#include <process.h>
#include <stdint.h>
#include "BitStream.h"
#include "RakClient.h"
#include "HookedRakClient.h"
#include "samp.h"

bool OnReceivePacket(Packet* packet);
bool OnSendPacket(BitStream* parameters, PacketPriority priority, PacketReliability reliability, char orderingChannel);
bool OnSendRPC(int uniqueID, BitStream* parameters, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp);