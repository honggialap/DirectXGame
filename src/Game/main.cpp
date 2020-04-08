#include "DirectXGame/Game.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	auto game = new Game(hInstance);
	game->Load(NULL);
	game->Run();

	delete game;
	game = nullptr;

	return 0;
}