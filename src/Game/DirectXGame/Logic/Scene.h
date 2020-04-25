#pragma once
#ifndef __SCECE_H__
#define __SCENE_H__

#include <unordered_map>

#include "../Framework/Time.h"

class Game;
typedef Game* pGame;

class Scene
{
public:
	pGame game;
	string nextScene;

	bool done;
	bool exit;

	Scene(pGame game);
	~Scene();

	virtual void Load() = 0;
	virtual void Unload() = 0;

	virtual void Update(pGameTime gameTime) = 0;
	virtual void Render() = 0;
};

typedef Scene* pScene;

class Scenes
{
public:
	pGame game;

	unordered_map<string, pScene> scenes;
	pScene currentScene;

	Scenes(pGame game);
	~Scenes();

	void NextScene();
	void Clear();
};

typedef Scenes* pScenes;

#endif // !__SCECE_H__
