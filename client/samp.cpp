#include "main.h"

auto cSAMP::IsInitialized() -> bool {

	g_dwSAMPAddr = reinterpret_cast<unsigned long>(LoadLibraryA("SAMP.DLL"));

	if (!g_dwSAMPAddr)
		return false;

	g_SAMP = *reinterpret_cast<stSAMP**>(g_dwSAMPAddr + SAMP_INFO_OFFSET);

	if (!g_SAMP)
		return false;

	g_Chat = *reinterpret_cast<stChatInfo**>(g_dwSAMPAddr + SAMP_CHAT_INFO_OFFSET);

	if (!g_Chat)
		return false;

	g_Input = *reinterpret_cast<stInputInfo**>(g_dwSAMPAddr + SAMP_CHAT_INPUT_INFO_OFFSET);

	if (!g_Input)
		return false;

	g_Misc = *reinterpret_cast<stMiscInfo**>(g_dwSAMPAddr + SAMP_MISC_INFO);

	if (!g_Misc)
		return false;

	g_Scoreboard = *reinterpret_cast<stScoreboardInfo**>(g_dwSAMPAddr + SAMP_SCOREBOARD_INFO);

	if (!g_Scoreboard)
		return false;

	if (!g_SAMP->pRakClientInterface)
		return false;

	g_RakClient = new RakClient(g_SAMP->pRakClientInterface);
	g_SAMP->pRakClientInterface = new HookedRakClientInterface();

	// g_SAMP->pRakClientInterface = new cHookedRakNet();

	g_Vehicles = g_SAMP->pPools->pVehicle;
	g_Players = g_SAMP->pPools->pPlayer;

	return true;

}

auto cSAMP::AddChatMessage(unsigned long d3dColor, char* pText, ...) -> void
{

	char* ap;

	char TextFormatted[512];
	memset(TextFormatted, 0, sizeof(TextFormatted));

	va_start(ap, pText);
	vsnprintf(TextFormatted, sizeof(TextFormatted) - 1, pText, ap);
	va_end(ap);

	reinterpret_cast<void(__thiscall*)(void*, int, char*, char*, unsigned long, unsigned long)>(g_dwSAMPAddr + SAMP_FUNC_ADDTOCHATWND)(g_Chat, 8, TextFormatted, 0, d3dColor, 0);

}

auto cSAMP::registerChatCommand(const char* pText, void* pFunc) -> void {
	reinterpret_cast<void(__thiscall*)(void*, const char*, CMDPROC)>(g_dwSAMPAddr + SAMP_FUNC_ADDCLIENTCMD)(g_Input, pText, reinterpret_cast<CMDPROC>(pFunc));
}

auto cSAMP::ToggleCursor(bool bToggle) -> void {
	reinterpret_cast<void(__thiscall*)(void*, int, bool)>(g_dwSAMPAddr + SAMP_FUNC_TOGGLECURSOR)(g_Misc, bToggle ? 3 : 0, !bToggle);
}

auto cSAMP::doesPlayerExists(short playerID) -> bool {

	return (g_Players->pRemotePlayer[playerID]
		&& g_Players->pRemotePlayer[playerID]->pPlayerData
		&& g_Players->pRemotePlayer[playerID]->pPlayerData->pSAMP_Actor
		&& g_Players->pRemotePlayer[playerID]->pPlayerData->pSAMP_Actor->pGTA_Ped);

}

auto cSAMP::getSampBase() -> unsigned long {
	return g_dwSAMPAddr;
}

auto cSAMP::setLocalPlayerName(char* pName) -> void {
	reinterpret_cast<void(__thiscall*)(void*, const char*, int)>(g_dwSAMPAddr + SAMP_FUNC_NAMECHANGE)(&g_Players->pVTBL_txtHandler, pName, strlen(pName));
}

auto cSAMP::restartGame() -> void {
	reinterpret_cast<void(__thiscall*)(void*)>(g_dwSAMPAddr + SAMP_FUNC_RESTARTGAME)(g_SAMP);
}

auto cSAMP::Say(const char* pMessage) -> void {
	reinterpret_cast<void(__thiscall*)(void*, const char*)>(g_dwSAMPAddr + pMessage[0] == '/' ? SAMP_FUNC_SENDCMD : SAMP_FUNC_SAY)(g_Players->pLocalPlayer, pMessage);
}

auto cSAMP::SendSpawn() -> void {
	reinterpret_cast<void(__thiscall*)(void*)>(g_dwSAMPAddr + SAMP_FUNC_SPAWN)(g_Players->pLocalPlayer);
}

auto cSAMP::SendSetInterior(unsigned char interiorID) -> void {
	reinterpret_cast<void(__thiscall*)(void*, unsigned char)>(g_dwSAMPAddr + SAMP_FUNC_SENDINTERIOR)(g_Players->pLocalPlayer, interiorID);
}

auto cSAMP::SendSpecialAction(unsigned char byteSpecialAction) -> void {
	reinterpret_cast<void(__thiscall*)(void*, unsigned char)>(g_dwSAMPAddr + SAMP_FUNC_SETSPECIALACTION)(g_Players->pLocalPlayer, byteSpecialAction);
}

auto cSAMP::SendDeath() -> void {
	reinterpret_cast<void(__thiscall*)(void*)>(g_dwSAMPAddr + SAMP_FUNC_DEATH)(g_Players->pLocalPlayer);
}

auto cSAMP::UpdateScoreboardData() -> void {
	reinterpret_cast<void(__thiscall*)(void*)>(g_dwSAMPAddr + SAMP_FUNC_UPDATESCOREBOARDDATA)(g_SAMP);
}

auto cSAMP::ToggleOffScoreboard() -> void {
	reinterpret_cast<void(__thiscall*)(void*, bool)>(g_dwSAMPAddr + SAMP_FUNC_DISABLE_SCOREBOARD)(g_Scoreboard, true);
}
