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

#include "Tool/GridMaker.h"

struct GameSettings
{
	string gameTitle;
	int maxFrameRate;
	bool fullscreen;
	int widthResolution;
	int heightResolution;
};

class Game
{
	// Framework components
public:
	pGameSettings gameSettings;
	pApplication application;
	pTime time;
	pGraphics graphics;
	pAudio audio;
	pInput input;
	pResource resource;
	pNetworks networks;

	// Game
protected:
	bool exit;
	string source;

public:
	Game(HINSTANCE hInstance);
	~Game();
	void Run(string sceneID);
	void Exit() { exit = true; }
protected:
	void Load();
	void LoadScenesList();

	// Scene
protected:
	unordered_map<string, string> scenes;
	pScene currentScene;

	virtual void LoadScene(string sceneID) = 0;
	void Update(float elapsedMs);
	void Render();
};

#endif // !__GAME_H__