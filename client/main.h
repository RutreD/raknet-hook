#pragma once

#include <stdio.h> 
#include <d3d9.h>
#include <d3dx9.h>
#include <stdint.h>
#include <assert.h>
#include <Windows.h>
#include <process.h>

#include <fstream>
#include <string>

#include "BitStream.h"
#include "RakClient.h"
#include "HookedRakClient.h"
#include "samp.h"

extern SAMPFramework* pSAMP;

void LOG(std::string text);