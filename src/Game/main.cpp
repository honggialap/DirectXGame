#include "Castlevania/Castlevania.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	auto game = new Castlevania(hInstance);

	string filePath = "Castlevania/Content/Data/GameData.xml";
	game->Load(ToLPCWSTR(filePath));
	game->Run("stage1");

	delete game;
	game = nullptr;

	return 0;
}