#include "DirectXGame/Game.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	auto game = new Game();
	
	game->Initialize(hInstance);
	game->Run();

	delete game;

	return 0;
}