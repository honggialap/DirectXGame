#include "Game.h"

Game::Game(HINSTANCE hInstance)
{
	gameSettings = new GameSettings();

	application = new Application(hInstance);
	time = new Time();
	graphics = new Graphics();
	//audio = new Audio();
	input = new Input();
	//networks = new Networks();
	resource = new Resource(graphics);
}

Game::~Game()
{
	delete resource;
	resource = nullptr;

	//sdelete networks;
	//snetworks = nullptr;

	delete input;
	input = nullptr;

	//delete audio;
	//audio = nullptr;

	delete graphics;
	graphics = nullptr;

	delete time;
	time = nullptr;

	delete application;
	application = nullptr;

	delete gameSettings;
	gameSettings = nullptr;
}

void Game::Load(LPCWSTR dataFilePath)
{
	//read game data file

	// to create game settings
	gameSettings->gameTitle = "GameTitle";
	gameSettings->maxFrameRate = 60;
	gameSettings->widthResolution = 800;
	gameSettings->heightResolution = 600;
	gameSettings->fullscreen = false;

	// then create game window
	application->CreateGameWindow(
		ToLPCWSTR(gameSettings->gameTitle),
		gameSettings->widthResolution,
		gameSettings->heightResolution,
		gameSettings->fullscreen);

	// then create graphics device
	graphics->CreateGraphicsDevice(application->gameWindow);

	// then create audio device
	//audio->CreateAudioDevice();

	// then create input device
	input->CreateInputDevice(application->gameWindow);

	// then create network device
	//networks->CreateNetworksDevice();

	// then create reader and storage for content file format (with d3d and dsound)

	// then create scene list and load game resource

}

void Game::Run()
{
	//pick 1st scene

	bool done = false;
	double frameTime = 1.0 / gameSettings->maxFrameRate * 1000; //in milliseconds

	time->Start();

	while (!done)
	{
		done = application->HandleMessage();
		time->Update();

		if (time->gameTime->elapsedMilliseconds >= frameTime)
		{
			Update(time->gameTime);
			Render();
		}
		else
			Sleep(DWORD(frameTime - time->gameTime->elapsedMilliseconds));
	}

	//clean up scene assets and then
	//Shutdown
}

void Game::Update(pGameTime gameTime)
{
}

void Game::Render()
{
	if (graphics->graphicsDevice->device->BeginScene())
	{
		//clear back buffer
		graphics->graphicsDevice->device->ColorFill(
			graphics->graphicsDevice->backBuffer,
			NULL, D3DCOLOR_XRGB(255, 255, 255));
		
		graphics->graphicsDevice->spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		//render scene

		graphics->graphicsDevice->spriteHandler->End();
		graphics->graphicsDevice->device->EndScene();
	}
	graphics->graphicsDevice->device->Present(NULL, NULL, NULL, NULL);
}
