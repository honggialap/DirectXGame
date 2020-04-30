#pragma once
#ifndef __SCECE_H__
#define __SCENE_H__

#include "../Include.h"

#include "../Game.h"
#include "../Framework/Time.h"

class Scene
{
public:
	pGame game;
	
	string id;
	string sceneData;
	string nextScene;

	bool done;
	bool exit;

	pGameObjects gameObjects;

	Scene(pGame game);
	~Scene();

	virtual void Load() = 0;
	virtual void Unload() = 0;

	virtual void Spawn(string gameObjectId) = 0;
	virtual void Despawn(string gameObjectId) = 0;

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

	void Add(string id, pScene scene);
	void NextScene();
	void Clear();
};

typedef Scenes* pScenes;

#endif // !__SCECE_H__
