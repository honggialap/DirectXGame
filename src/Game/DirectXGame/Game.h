#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "Framework/Application.h"
#include "Framework/Time.h"
#include "Framework/Graphics.h"
#include "Framework/Audio.h"
#include "Framework/Input.h"
#include "Framework/Networks.h"
#include "Framework/Resource.h"
#include "Framework/Ultilities.h"

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

typedef GameSettings* pGameSettings;

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

	Game(HINSTANCE hInstance);
	~Game();

	void Load(LPCWSTR dataFilePath);
	void Run();

	virtual void Update(pGameTime gameTime);
	virtual void Render();
};

#endif // !__GAME_H__
