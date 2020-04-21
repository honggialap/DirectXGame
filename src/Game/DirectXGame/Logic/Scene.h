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

	Scene(pGame game);
	~Scene();

	virtual void Load() = 0;
	virtual void Update(pGameTime gameTime) = 0;
	virtual void Render() = 0;
};

typedef Scene* pScene;

class Scenes
{
public:
	pGame game;

	vector<pScene> scenes;
	pScene currentScene;

	Scenes(pGame game);
	~Scenes();
};

typedef Scenes* pScenes;

#endif // !__SCECE_H__
