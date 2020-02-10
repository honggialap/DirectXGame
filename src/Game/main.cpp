#include "DirectXGame/Framework/Application/Application.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR pCmdLine, int nCmdShow)
{
	pApplication app = Application::GetInstance();

	app->Initialize(hInstance);
	app->CreateGameWindow();

	while (!app->HandleMessage())
	{
		;
	}

	return 0;
}