#include "Scene.h"

Scene::Scene(pGame game)
{
	this->game = game;
	done = false;
	exit = false;

	gameObjects = new GameObjects(game, this);
}

Scene::~Scene()
{
	this->game = nullptr;

	if (gameObjects != nullptr)
	{
		gameObjects->Clear();
		delete gameObjects;
		gameObjects = nullptr;
	}
}

Scenes::Scenes(pGame game)
{
	this->game = game;
	this->currentScene = nullptr;
}

Scenes::~Scenes()
{
	this->game = nullptr;
}

void Scenes::Add(string id, pScene scene)
{
	scenes[id] = scene;
}

void Scenes::NextScene()
{
	currentScene = scenes[currentScene->nextScene];
}

void Scenes::Clear()
{
	//current scene -> unload
	//game objects -> clear
}
