#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include "Framework/Application.h"
#include "Framework/Time.h"
#include "Framework/Graphics.h"
//#include "Framework/Audio.h"
#include "Framework/Input.h"
//#include "Framework/Networks.h"
#include "Framework/Resource.h"
#include "Framework/Math.h"
#include "Framework/Ultilities.h"

#include "Logic/Scene.h"


using namespace std;

class Resource;
typedef Resource* pResource;

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
	//pAudio audio;
	pInput input;
	//pNetworks networks;
	pResource resource;

	pGameSettings gameSettings;

	pScenes scenes;
	bool changeScene;

	Game(HINSTANCE hInstance);
	~Game();

	virtual void Load(LPCWSTR dataFilePath);
	void Run(int scene = 0);

	void Update(pGameTime gameTime);
	void Render();
};

typedef Game* pGame;

#endif // !__GAME_H__
