#include "Game.h"

Game::Game(HINSTANCE hInstance)
{
	gameSettings = new GameSettings();

	application = new Application(hInstance);
	time = new Time();
	graphics = new Graphics();
	input = new Input();
	resource = new Resource(graphics);

	scenes = new Scenes(this);
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

	if (input != nullptr)
	{
		delete input;
		input = nullptr;
	}

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
	resource->LoadGameSettings(gameSettings, dataFilePath);
	
	application->CreateGameWindow(
		ToLPCWSTR(gameSettings->gameTitle),
		gameSettings->widthResolution,
		gameSettings->heightResolution,
		gameSettings->fullscreen);

	graphics->CreateGraphicsDevice(application->gameWindow);
	input->CreateInputDevice(application->gameWindow);
}

void Game::Run(string sceneID)
{
	bool done = false;
	double frameTime = 1.0 / gameSettings->maxFrameRate * 1000; //in milliseconds

	scenes->currentScene = scenes->scenes[sceneID];
	scenes->currentScene->Load();

	time->Start();

	while (!done)
	{
		done = application->HandleMessage();
		
		if (scenes->currentScene->done)
		{
			scenes->currentScene->Unload();

			if (scenes->currentScene->exit)
			{
				scenes->Clear();
				application->Exit();
				done = application->HandleMessage();
				break;
			}

			scenes->NextScene();
			scenes->currentScene->Load();
			time->Restart();
		}
		
		time->Update();

		if (time->gameTime->elapsedMilliseconds >= frameTime)
		{
			Update(time->gameTime);
			Render();
		}
		else
			Sleep(DWORD(frameTime - time->gameTime->elapsedMilliseconds));
	}
}

void Game::Update(pGameTime gameTime)
{
	scenes->currentScene->Update(gameTime);
}

void Game::Render()
{
	if (graphics->graphicsDevice->device->BeginScene())
	{
		graphics->graphicsDevice->device->ColorFill(
			graphics->graphicsDevice->backBuffer,
			NULL, D3DCOLOR_XRGB(0, 0, 0));
		
		graphics->graphicsDevice->spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		scenes->currentScene->Render();

		graphics->graphicsDevice->spriteHandler->End();
		graphics->graphicsDevice->device->EndScene();
	}
	graphics->graphicsDevice->device->Present(NULL, NULL, NULL, NULL);
}
