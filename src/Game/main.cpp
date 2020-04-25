#include "MarioSample/MarioSample.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	auto game = new MarioSample(hInstance);

	string filePath = "MarioSample/Content/Data/GameData.xml";
	game->Load(ToLPCWSTR(filePath));

	game->Run();

	delete game;
	game = nullptr;

	return 0;
}