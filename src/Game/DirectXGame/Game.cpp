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
	resource = new Resource(graphics); //, audio);

	scenes = new Scenes(this);
	changeScene = false;
}

Game::~Game()
{
	if (scenes != nullptr)
	{
		delete scenes;
		scenes = nullptr;
	}

	if (resource != nullptr)
	{
		delete resource;
		resource = nullptr;
	}

	//if (networks != nullptr)
	//{
	//	delete networks;
	//	networks = nullptr;
	//}

	if (input != nullptr)
	{
		delete input;
		input = nullptr;
	}

	//if (audio != nullptr)
	//{
	//	delete audio;
	//	audio = nullptr;
	//}

	if (graphics != nullptr)
	{
		delete graphics;
		graphics = nullptr;
	}

	if (time != nullptr)
	{
		delete time;
		time = nullptr;
	}

	if (application != nullptr)
	{
		delete application;
		application = nullptr;
	}

	if (gameSettings != nullptr)
	{
		delete gameSettings;
		gameSettings = nullptr;
	}
}

void Game::Load(LPCWSTR dataFilePath)
{
	resource->LoadGameData(gameSettings, dataFilePath);
	
	application->CreateGameWindow(
		ToLPCWSTR(gameSettings->gameTitle),
		gameSettings->widthResolution,
		gameSettings->heightResolution,
		gameSettings->fullscreen);

	graphics->CreateGraphicsDevice(application->gameWindow);
	
	//audio->CreateAudioDevice(application->gameWindow);
	
	input->CreateInputDevice(application->gameWindow);
	
	//networks->CreateNetworksDevice();

	//resource->LoadGameContent(dataFilePath);
	//resource->LoadScenes(scenes, dataFilePath);
}

void Game::Run(int scene)
{
	//pick scene
	//scenes->currentScene = scenes->scenes[scene];

	bool done = false;
	double frameTime = 1.0 / gameSettings->maxFrameRate * 1000; //in milliseconds

	time->Start();

	while (!done)
	{
		if(changeScene)
		{



			time->Restart();
		}

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
	//scene update
}

void Game::Render()
{
	if (graphics->graphicsDevice->device->BeginScene())
	{
		//clear back buffer
		graphics->graphicsDevice->device->ColorFill(
			graphics->graphicsDevice->backBuffer,
			NULL, D3DCOLOR_XRGB(0, 0, 0));
		
		graphics->graphicsDevice->spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		//render scene

		graphics->graphicsDevice->spriteHandler->End();
		graphics->graphicsDevice->device->EndScene();
	}
	graphics->graphicsDevice->device->Present(NULL, NULL, NULL, NULL);
}
