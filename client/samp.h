#pragma once

#include "main.h"

#pragma pack(push, 1)

struct stSAMP
{
	char						pad_0[44];
	void*						pRakClientInterface;
	char						m_szHostAddress[257];
	char						m_szHostname[257];
	bool						m_bDisableCollision;
	bool						m_bUpdateCameraTarget;
	bool						m_bNametagStatus;
	int							m_nPort;
	BOOL						m_bLanMode;
	uint32_t					m_aMapIcons[100];
	int							m_nGameState;
	uint32_t					m_lastConnectAttempt;
	struct stServerPresets*		m_pSettings;
	char						pad_2[5];
	struct stSAMPPools*			m_pPools;
};

#pragma pack(pop)

class SAMPFramework
{

public:
	class RakClientInterface* getRakClientInterface(void) { return g_RakClient; };

	bool tryInit(void)
	{
		DWORD dwSAMPAddr = reinterpret_cast<DWORD>(GetModuleHandleA("samp.dll"));

		stSAMP* g_SAMP = *(stSAMP**)(dwSAMPAddr + 0x26E8DC);

		if (g_SAMP == nullptr)
			return false;

		if (g_SAMP->pRakClientInterface == nullptr)
			return false;

		g_RakClient = (RakClientInterface*)g_SAMP->pRakClientInterface;
		g_SAMP->pRakClientInterface = new HookedRakClientInterface();

		return true;
	};

private:
	class RakClientInterface* g_RakClient = nullptr;
};