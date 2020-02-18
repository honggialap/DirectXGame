#include "Game.h"

Game::Game()
{
	application = Application::GetInstance();
	time = Time::GetInstance();
}

Game::~Game()
{
}

void Game::Initialize(HINSTANCE hInstance)
{
	application->Initialize(hInstance);
	application->CreateGameWindow();

}

void Game::Shutdown()
{

	application->Shutdown();
}

void Game::Run()
{
	bool done = false;
	int framerate = 60;
	double frameTime = 1.0 / framerate * 1000;
	
	time->Start();

	while (!done)
	{
		done = application->HandleMessage();
		time->Update();
		
		if (time->GetElapsedMilliseconds() >= frameTime)
		{
			Update();
			Render();

			char buffer[100];
			sprintf_s(buffer, "%f\n", time->GetElapsedMilliseconds());
			OutputDebugStringA(buffer);
			sprintf_s(buffer, "%f\n", time->GetTotalElapsedMilliseconds());
			OutputDebugStringA(buffer);

		}
		else
		{
			Sleep(DWORD(frameTime - time->GetElapsedMilliseconds()));
		}
	}
}

void Game::Update()
{
}

void Game::Render()
{
}
