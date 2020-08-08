#include "Game.h"

Game::Game(HINSTANCE hInstance)
{
	exit = false;

	gameSettings = new GameSettings();
	application = new Application(hInstance);
	time = new Time();
	graphics = new Graphics();
	input = new Input();
	audio = new Audio();
	resource = new Resource(graphics, audio);
	networks = new Networks();
	
	currentScene = nullptr;
}

Game::~Game()
{
	currentScene = nullptr;
	scenes.clear();

	if (networks != nullptr)
	{
		delete networks;
		networks = nullptr;
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

	if (audio != nullptr)
	{
		delete audio;
		audio = nullptr;
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

void Game::Load()
{
	resource->LoadGameData(ToLPCWSTR(source));
	resource->LoadGameSettings(this);

	application->CreateGameWindow(
		ToLPCWSTR(gameSettings->gameTitle),
		gameSettings->widthResolution,
		gameSettings->heightResolution,
		gameSettings->fullscreen);

	graphics->CreateGraphicsDevice(application->gameWindow);
	audio->CreateAudioDevice(application->gameWindow);
	input->CreateInputDevice(application->gameWindow);
	networks->CreateNetworksDevice(application->gameWindow);

	resource->LoadContent();
	LoadScenesList();
}

void Game::LoadScenesList()
{
	auto gridMaker = new GridMaker();

	xml_node scenesNode = resource->gameDataDoc.child("GameData").child("Scenes");
	for (xml_node sceneNode = scenesNode.child("Scene");
		sceneNode;
		sceneNode = sceneNode.next_sibling("Scene"))
	{
		scenes[sceneNode.attribute("sceneID").as_string()] = sceneNode.attribute("source").as_string();
		gridMaker->MakeGrid(sceneNode.attribute("source").as_string());
	}

	delete gridMaker;
	gridMaker = nullptr;
}

void Game::Run(string sceneID)
{
	Load();
	LoadScene(sceneID);

	float frameTime = 1000.0f / gameSettings->maxFrameRate; //in milliseconds
	float currentFrameTime = 0;
	time->Start();

	bool done = false;
	while (!done)
	{
		exit = done = application->HandleMessage();

		// Change scene
		if (currentScene->done && !exit)
		{
			string nextScene = currentScene->nextScene;
			currentScene->Unload();
			delete currentScene;

			LoadScene(nextScene);

			time->Restart();
			currentFrameTime = 0;
		}

		// End game
		if (exit)
		{
			currentScene->Unload();
			delete currentScene;

			application->Exit();
			done = true;
		}

		// Game loop
		time->Update();
		currentFrameTime += time->ElapsedMilliseconds();

		if (currentFrameTime >= frameTime)
		{
			input->Update();
			Update(currentFrameTime);
			Render();
			currentFrameTime = 0;
		}
		else
			Sleep(DWORD(frameTime - currentFrameTime));
	}
}

void Game::Update(float elapsedMs)
{
	currentScene->Update(elapsedMs);
}

void Game::Render()
{
	if (graphics->graphicsDevice->device->BeginScene())
	{
		graphics->graphicsDevice->device->ColorFill(
			graphics->graphicsDevice->backBuffer,
			NULL, D3DCOLOR_XRGB(0, 0, 0));
		
		graphics->graphicsDevice->
			spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

		currentScene->Render();

		graphics->graphicsDevice->
			spriteHandler->End();

		graphics->graphicsDevice->device->EndScene();
	}
	graphics->graphicsDevice->device->Present(NULL, NULL, NULL, NULL);
}