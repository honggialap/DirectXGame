#include "Castlevania/Castlevania.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	auto game = new Castlevania(hInstance);
	game->Run("demo");
	delete game;
	game = nullptr;

	return 0;
}