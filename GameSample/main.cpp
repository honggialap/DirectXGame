#include "Engine/Game.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	auto game = new CGame();
	game->Load(hInstance, "Data/GameData.xml");
	game->Run();
}