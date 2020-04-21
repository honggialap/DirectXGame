#include "DirectXGame/Game.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	auto game = new Game(hInstance);

	string filePath = "Castlevania/Content/Data/GameData.xml";
	game->Load(ToLPCWSTR(filePath));

	game->Run();

	delete game;
	game = nullptr;

	return 0;
}