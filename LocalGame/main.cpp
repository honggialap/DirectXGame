#include "Engine/Application.h"
#include "Engine/Debug.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	auto app = new CApplication();
	std::wstring title = L"Application Test";
	unsigned int width = 800;
	unsigned int height = 600;

	app->CreateGameWindow(hInstance, title, width, height);
	while (!app->HandleMessage())
	{
		DebugOut(L"Tick\n");
	}
}