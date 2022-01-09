#include "Engine/Application.h"
#include "Engine/Time.h"
#include "Engine/Debug.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow
)
{
	auto app = new CApplication();
	auto time = new CTime();

	std::wstring title = L"Time Test";
	unsigned int width = 800;
	unsigned int height = 600;
	float exitCountdown = 5000;

	app->CreateGameWindow(hInstance, title, width, height);
	time->Start();

	while (!app->HandleMessage())
	{
		DebugOut(L"Tick\n");
		time->Tick();

		if (exitCountdown > 0) exitCountdown -= time->GetElapsedMs();
		else app->Exit();
	}
}