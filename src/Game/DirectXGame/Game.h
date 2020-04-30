#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "Include.h"

#include "Framework/Application.h"
#include "Framework/Time.h"
#include "Framework/Graphics.h"
#include "Framework/Input.h"
#include "Framework/Resource.h"

#include "Logic/Scene.h"

class GameSettings
{
public:
	string gameTitle;
	int maxFrameRate;
	bool fullscreen;
	int widthResolution;
	int heightResolution;
};

class Game
{
public:
	pApplication application;
	pTime time;
	pGraphics graphics;
	pInput input;
	pResource resource;

	pGameSettings gameSettings;

	pScenes scenes;

	Game(HINSTANCE hInstance);
	~Game();

	virtual void Load(LPCWSTR dataFilePath);
	virtual void LoadPrefabs() = 0;
	virtual void LoadScenes() = 0;
	void Run(string sceneID);

	void Update(pGameTime gameTime);
	void Render();
};

#endif // !__GAME_H__