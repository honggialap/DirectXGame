#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "Include.h"

#include "Framework/Application.h"
#include "Framework/Time.h"
#include "Framework/Graphics.h"
#include "Framework/Audio.h"
#include "Framework/Input.h"
#include "Framework/Networks.h"
#include "Framework/Resource.h"

#include "Logic/Scene.h"

using namespace std;

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
	pAudio audio;
	pInput input;
	pNetworks networks;
	pResource resource;

	pGameSettings gameSettings;

	pScenes scenes;

	Game(HINSTANCE hInstance);
	~Game();

	virtual void Load(LPCWSTR dataFilePath);
	virtual void Run(string scene = "StartScene");

	void Update(pGameTime gameTime);
	void Render();
};

#endif // !__GAME_H__
